#ifndef MODBUSCONNECTOR_H
#define MODBUSCONNECTOR_H
#include <QObject>
#include "iconnector.h"
#include <QModbusRtuSerialMaster>
class QSettings;

class ModBusConnector: public QObject,IConnector
{
Q_OBJECT

public:
    explicit ModBusConnector(QObject *parent = nullptr);
    template<typename T>
    void WriteToConnection(const T& message, const QString parameter=0)
    {

        QRegExp re("\\d*");  // a digit (\d), zero or more times (*)
        if (!re.exactMatch(message))
        {
            emit NotifyMessage(tr("invalid message"));
            return;
        }
        if (!re.exactMatch(parameter))
        {
            emit NotifyMessage(tr("invalid parameter"));
            return;
        }

        quint16 value = parameter.toShort();
        QVector<quint16> writeBuffer(1);
        writeBuffer[0] = value;
        QModbusDataUnit adu(QModbusDataUnit::HoldingRegisters, message, writeBuffer);


        if (auto *reply = device->sendWriteRequest(adu, SLAVE_ADDRESS))
        {

            if (!reply->isFinished())
            {
                connect(reply, &QModbusReply::finished, this,&ModBusConnector::writeReady);
            }
            else
            {
                delete reply; // broadcast replies return immediately
            }

        }
        else
        {
            QString _errorMsg=device->errorString();
            emit NotifyMotorDriverError(_errorMsg);
        }

    }
    template<typename V>
    V ReadFromConnection(const QString parameter=0)
    {
        if (!re.exactMatch(parameter))
        {
            emit NotifyMessage(tr("invalid parameter"));
            return;
        }

        int registerAddress = parameter.toInt();
        QVector<quint16> readBuffer(1);
        QModbusDataUnit adu(QModbusDataUnit::HoldingRegisters,registerAddress, readBuffer);

        if (auto *reply = device->sendReadRequest(adu, SLAVE_ADDRESS))
        {

            if (!reply->isFinished())
            {
                connect(reply, &QModbusReply::finished,this, &ModBusConnector::readReady);
            }
            else
                delete reply; // broadcast replies return immediately
        }
        else
        {
            QString _errorMsg = device->errorString();
            emit NotifyMessage(_errorMsg);
        }

       return ;//qvariant_cast<V>();
    }

    void UpdateConnectionSettings(const QMap<QString, QString> *settings) override;
    const QMap<QString, QString> *GetConnectionSettings() override;
    void OpenConnectionAsService() override;
    void OpenConnection() override;
    void CloseConnection() override;

signals:
    void NotifyMessage(const QString message) const override;
    void NotifyConnectionError(const QString error) const override;
    void NotifyConnectionOpened() override;
    void NotifyConnectionClosed() override;

private:
    void writeReady();
    void ReadReady();
    QModbusRtuSerialMaster *device;
    QMap<QString,QString> *settings;
    QMap<QString, QString> *connectionSettings;
    int SLAVE_ADDRESS;
};

#endif // MODBUSCONNECTOR_H
