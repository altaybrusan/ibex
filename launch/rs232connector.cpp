#include "rs232connector.h"
#include "iconnector.h"
#include <QSettings>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMap>
#include <QMetaEnum>

RS232Connector::RS232Connector(QObject *parent) : QObject(parent),
    connection(new QSerialPort(this)),
    connectionSettings(new QMap<QString, QString>())
{

}

void RS232Connector::UpdateConnectionSettings(const QMap<QString, QString>* settings)
{
    if(settings == nullptr)
    {

        emit NotifyConnectionError(tr("Connection settings can not be empty."));
        return;
    }

    try
    {
        //WHY THE PARAMETERS NAME ARE HARD CODED. IS IT GOOD IDEA?!
        auto _name = settings->value("Name","");
        connection->setPortName(_name);

        connection->setBaudRate(settings->value("BaudRate","").toInt());

        QSerialPort::DataBits _dataBits = static_cast<QSerialPort::DataBits>(
                    settings->value("DataBits","").toInt());
        connection->setDataBits(_dataBits);

        QSerialPort::Parity _parity = static_cast<QSerialPort::Parity>(
                    settings->value("Parity","").toInt());
        connection->setParity(_parity);

        QSerialPort::StopBits _stopBit = static_cast<QSerialPort::StopBits>(
                    settings->value("StopBits","").toInt());
        connection->setStopBits(_stopBit);

        QSerialPort::FlowControl _flowControl = static_cast<QSerialPort::FlowControl>(
                    settings->value("FlowControl","").toInt());
        connection->setFlowControl(_flowControl);
    }
    catch(...)
    {
        emit NotifyConnectionError("Settings are not correct.");

    }

}

const QMap<QString, QString>* RS232Connector::GetConnectionSettings()
{

        (*connectionSettings)["Name"]= connection->portName();
        (*connectionSettings)["BaudRate"]= QString::number(connection->baudRate());
        QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::DataBits>();
        (*connectionSettings)["DataBits"]=  QString(metaEnum.valueToKey(connection->dataBits()));
        metaEnum = QMetaEnum::fromType<QSerialPort::Parity>();
        (*connectionSettings)["Parity"]=  QString(metaEnum.valueToKey(connection->parity()));
        metaEnum = QMetaEnum::fromType<QSerialPort::StopBits>();
        (*connectionSettings)["StopBits"]=  QString(metaEnum.valueToKey(connection->stopBits()));
        metaEnum = QMetaEnum::fromType<QSerialPort::FlowControl>();
        (*connectionSettings)["FlowControl"]=  QString(metaEnum.valueToKey(connection->flowControl()));

        return connectionSettings;
}

void RS232Connector::OpenConnectionAsService()
{

}

void RS232Connector::OpenConnection()
{
    if (!connection->open(QIODevice::ReadWrite))
    {
        emit NotifyConnectionError(QString("connection error: %1").
                                  arg(connection->errorString()));
        return;

    }

    emit NotifyConnectionOpened();
    return;
}

void RS232Connector::CloseConnection()
{
    if(!connection && connection->isOpen())
    {
        connection->close();
        emit NotifyConnectionClosed();
    }

    return;

}
