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
    if(settings == NULL)
    {
        emit NotifyConnectionError(tr("Connection settings can not be empty."));
        return;
    }
    if(settings->size()!=6)
    {
        emit NotifyConnectionError(tr("Number of settings parameter is not correct"));
        return;
    }

    try
    {
        //WHY THE PARAMETERS NAME ARE HARD CODED. IS IT GOOD IDEA?!
        // the validation can be separated into another function.
        auto _name = settings->value("Name","");
        connection->setPortName(_name);

        // the way the baudrate is transfered is different than the others.
        // this is the way I validate it. maybe other option better.
        QSerialPort::BaudRate _baudRate = static_cast<QSerialPort::BaudRate>(
                    settings->value("BaudRate","").toInt());
        QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::BaudRate>();
        QString _baudrateChecker= QString(metaEnum.valueToKey(_baudRate));

        if(_baudrateChecker == "UnknownBaud")
        {
            emit NotifyConnectionError(tr("BaudRate is not valid."));
            return;
        }
        connection->setBaudRate(_baudRate);

        metaEnum = QMetaEnum::fromType<QSerialPort::DataBits>();
        QSerialPort::DataBits _dataBits = static_cast<QSerialPort::DataBits>( //enum value to enum
                    metaEnum.keyToValue(                                      // char* to enum value
                        settings->value("DataBits","").toLatin1().data()));   // QString to char*

        if(_dataBits== QSerialPort::UnknownDataBits)
        {
            emit NotifyConnectionError("DataBits is not valid.");
            return;
        }
        connection->setDataBits(_dataBits);

        metaEnum = QMetaEnum::fromType<QSerialPort::Parity>();
        QSerialPort::Parity _parity = static_cast<QSerialPort::Parity>( //enum value to enum
                    metaEnum.keyToValue(                                      // char* to enum value
                        settings->value("Parity","").toLatin1().data()));   // QString to char*

        if(_parity == QSerialPort::UnknownParity)
        {
            emit NotifyConnectionError(tr("Parity is not valid."));
            return;
        }
        connection->setParity(_parity);

        metaEnum = QMetaEnum::fromType<QSerialPort::StopBits>();
        QSerialPort::StopBits _stopBits = static_cast<QSerialPort::StopBits>( //enum value to enum
                    metaEnum.keyToValue(                                      // char* to enum value
                        settings->value("StopBits","").toLatin1().data()));   // QString to char*
        if(_stopBits== QSerialPort::UnknownStopBits)
        {
            emit NotifyConnectionError(tr("StopBits is not valid."));
            return;
        }
        connection->setStopBits(_stopBits);

//        QSerialPort::FlowControl _flowControl = static_cast<QSerialPort::FlowControl>(
//                    settings->value("FlowControl","").toInt());
//        metaEnum = QMetaEnum::fromType<QSerialPort::FlowControl>();
//        QString _flowcontrolChecker= QString(metaEnum.valueToKey(_flowControl));

        metaEnum = QMetaEnum::fromType<QSerialPort::FlowControl>();
        QSerialPort::FlowControl _flowControl = static_cast<QSerialPort::FlowControl>( //enum value to enum
                    metaEnum.keyToValue(                                      // char* to enum value
                        settings->value("FlowControl","").toLatin1().data()));   // QString to char*

        if(_flowControl == QSerialPort::UnknownFlowControl)
        {
            emit NotifyConnectionError(tr("FlowControl is not valid."));
            return;
        }
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
    if(connection != NULL && connection->isOpen())
    {
        connection->close();
        emit NotifyConnectionClosed();
    }

    return;
}

RS232Connector::~RS232Connector()
{
    CloseConnection();
    delete connection;
}
