#include "modbusconnector.h"
#include <QDebug>
#include <QSerialPort>
#include <QModbusRtuSerialMaster>
#include <QSettings>
#include <QMetaEnum>
#include <QMap>

static const int WAIT_TIME = 25;
static const int NUMBER_OF_TRIES = 3;

ModBusConnector::ModBusConnector(QObject *parent):
    QObject(parent),
    settings(new QMap<QString,QString>())
{

}

void ModBusConnector::UpdateConnectionSettings(const QMap<QString, QString> *settings)
{
    // the settings are kept in global level.
    if(settings->count( ) != 6)
    {
        emit NotifyConnectionError(tr("Number of settings parameter is not correct"));
        return;
    }
    try
    {
        //keep a local copy
        (*this->settings)["Name"] = settings->value("Name","");
        (*this->settings)["DataBits"] = settings->value("DataBits","");
        (*this->settings)["BaudRate"] = settings->value("BaudRate","");
        (*this->settings)["Parity"] = settings->value("Parity","");
        (*this->settings)["StopBits"] = settings->value("StopBits","");
        (*this->settings)["SlaveAddress"] = settings->value("SlaveAddress","");

        // Set connection parameters.
        if (device->state() != QModbusDevice::ConnectedState)
        {

            device->setConnectionParameter(
                        QModbusDevice::SerialPortNameParameter,
                        this->settings->value("Name",""));

            QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::DataBits>();
            auto _val = settings->value("DataBits","").toInt();
            QSerialPort::DataBits _dataBits = static_cast<QSerialPort::DataBits>(_val);
            device->setConnectionParameter(
                        QModbusDevice::SerialDataBitsParameter,
                        _dataBits);

            metaEnum = QMetaEnum::fromType<QSerialPort::BaudRate>();
            _val =settings->value("BaudRate","").toInt();
            QSerialPort::BaudRate _baudRate = static_cast<QSerialPort::BaudRate>(_val);
            device->setConnectionParameter(
                        QModbusDevice::SerialBaudRateParameter,
                        _baudRate);


            metaEnum = QMetaEnum::fromType<QSerialPort::Parity>();
            _val = settings->value("Parity","").toInt();
            QSerialPort::Parity _parity = static_cast<QSerialPort::Parity>(_val);
            device->setConnectionParameter(
                        QModbusDevice::SerialParityParameter,
                        _parity);

            metaEnum = QMetaEnum::fromType<QSerialPort::StopBits>();
            _val = settings->value("StopBits","").toInt();
            QSerialPort::StopBits _stopBit = static_cast<QSerialPort::StopBits>(_val);
            device->setConnectionParameter(
                        QModbusDevice::SerialStopBitsParameter,
                        _stopBit);

            SLAVE_ADDRESS =settings->value("SlaveAddress","").toInt();

        }
    }
    catch(...)
    {
        emit NotifyConnectionError("Settings are not correct.");
    }

    device->setTimeout(WAIT_TIME);
    device->setNumberOfRetries(NUMBER_OF_TRIES);

}

const QMap<QString, QString> *ModBusConnector::GetConnectionSettings()
{
    return connectionSettings;
}

void ModBusConnector::OpenConnectionAsService()
{

}

void ModBusConnector::OpenConnection()
{
    if(!device->connectDevice())
    {
        emit NotifyConnectionError(QString("Connection state: %1").arg(QString::number(device->state())));
    }
}

void ModBusConnector::CloseConnection()
{
    device->disconnectDevice();
}

void ModBusConnector::writeReady()
{
    auto reply = qobject_cast<QModbusReply *>(sender());
    if (!reply)
        return;

    if (reply->error() == QModbusDevice::ProtocolError) {
        QString _errorMsg = "Write response error: " + reply->errorString()
                + " (Mobus exception: " + reply->rawResult().exceptionCode()+")";
        emit NotifyConnectionError(_errorMsg);

    }
    else if (reply->error() != QModbusDevice::NoError)
    {

        QString _errorMsg = QString("Write response error: %1 ( code: %2 )").arg( reply->errorString()).arg(QString::number(reply->error()));
        emit NotifyConnectionError(_errorMsg);
    }
    reply->deleteLater();
}

void ModBusConnector::ReadReady()
{
    auto reply = qobject_cast<QModbusReply *>(sender());
    if (!reply)
        return;

    if (reply->error() == QModbusDevice::NoError) {
        const QModbusDataUnit unit = reply->result();
        //QString _address=unit.startAddress();

        for (uint i = 0; i < unit.valueCount(); i++)
        {
            const QString _address= QString::number(unit.startAddress());
            const QString _value=QString::number(unit.value(i));
            emit NotifyMessage((_address+":%1").arg(_value));
        }

    }
    else if (reply->error() == QModbusDevice::ProtocolError)
    {

        QString _errorMsg = (tr("Read response error: %1 (Mobus exception: 0x%2)").
                   arg(reply->errorString()).
                   arg(reply->rawResult().exceptionCode(), -1, 16), 5000);
        emit NotifyConnectionError(_errorMsg);
    }
    else
    {
        QString _errorMsg = "Read response error: "+ reply->errorString() + "(code:)" + reply->error();
        emit NotifyConnectionError(_errorMsg);
    }

    reply->deleteLater();
}
