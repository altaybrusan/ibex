#ifndef RS232CONNECTOR_H
#define RS232CONNECTOR_H

#include <QObject>
#include "iconnector.h"
class QSettings;
class QSerialPort;

class RS232Connector : public QObject,IConnector
{
    Q_OBJECT
    Q_INTERFACES(IConnector)

public:
    template<typename T>
    void WriteToConnection(const T& message, const QString parameter=0)
    {
        QByteArray messageByteArray = QVariant(message).toString().toUtf8();
        connection->write(messageByteArray);
        if(!connection->waitForBytesWritten(WAIT_TIME))
        {
            emit NotifyConnectionError(" write into port timeout.");
        }
    }

    template<typename V>
    V ReadFromConnection(const QString parameter=0)
    {
        // What if any data on the buffer is available from previous?!
        QByteArray responseData = connection->readAll();
        QString response = QString::fromLatin1(responseData);

        if (connection->waitForReadyRead(WAIT_TIME))
        {
            responseData = connection->readAll();

            while (connection->waitForReadyRead(WAIT_TIME))
                responseData += connection->readAll();
        }
        else
        {
            emit NotifyConnectionError("read from port timeout.");
            return qvariant_cast<V>("Read Time Out");
        }

        response = QString(responseData);
        //return response;
        return qvariant_cast<V>(response);
    }

    explicit RS232Connector(QObject *parent = nullptr);
    void UpdateConnectionSettings(const QMap<QString, QString>* settings) override;
    const QMap<QString, QString>* GetConnectionSettings() override;
    void OpenConnectionAsService() override;
    void OpenConnection() override;
    void CloseConnection() override;
    ~RS232Connector();

signals:
    void NotifyMessage(const QString message) const  override;
    void NotifyConnectionError(const QString error) const override;
    void NotifyConnectionOpened() override;
    void NotifyConnectionClosed() override;

public slots:

private:
    QSerialPort *connection;
    QMap<QString, QString> *connectionSettings;

    // based on device specification this parameter can be changed.
    static const int WAIT_TIME=500;





};

#endif // RS232CONNECTOR_H
