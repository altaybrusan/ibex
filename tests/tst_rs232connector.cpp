#ifndef TESTRS232CONNECTOR
#define TESTRS232CONNECTOR
#endif
#include <QMap>
#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QMetaEnum>
#include <QtSerialPort/QSerialPort>
#include "rs232connector.h"

class TestRS232Connector : public QObject
{
    Q_OBJECT

public:
    TestRS232Connector()
    {

    }
    ~TestRS232Connector()
    {

    }

private Q_SLOTS:
    void initTestCase()
    {
        //connector=new RS232Connector();
    }

    void TestUpdateConnectionSettings()
    {
        QFETCH(QString, Name);
        QFETCH(QSerialPort::BaudRate,BaudRate);
        QFETCH(QSerialPort::DataBits,DataBits);
        QFETCH(QSerialPort::Parity,Parity);
        QFETCH(QSerialPort::StopBits,StopBits);
        QFETCH(QSerialPort::FlowControl,FlowControl);

        QMap<QString,QString>* connectionSettings;

        (*connectionSettings)["Name"]= Name;
        (*connectionSettings)["BaudRate"]= QString::number(BaudRate);
        QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::DataBits>();
        (*connectionSettings)["DataBits"]=  QString(metaEnum.valueToKey(DataBits));
        metaEnum = QMetaEnum::fromType<QSerialPort::Parity>();
        (*connectionSettings)["Parity"]=  QString(metaEnum.valueToKey(Parity));
        metaEnum = QMetaEnum::fromType<QSerialPort::StopBits>();
        (*connectionSettings)["StopBits"]=  QString(metaEnum.valueToKey(StopBits));
        metaEnum = QMetaEnum::fromType<QSerialPort::FlowControl>();
        (*connectionSettings)["FlowControl"]=  QString(metaEnum.valueToKey(FlowControl));



    }
    void TestUpdateConnectionSettings_data()
    {
        QTest::addColumn<QString>("Name");
        QTest::addColumn<QSerialPort::BaudRate>("BaudRate");
        QTest::addColumn<QSerialPort::DataBits>("DataBits");
        QTest::addColumn<QSerialPort::Parity>("Parity");
        QTest::addColumn<QSerialPort::StopBits>("StopBits");
        QTest::addColumn<QSerialPort::FlowControl>("FlowControl");

        QTest::newRow("valid port") << "COM3"
                                    <<QSerialPort::Baud9600
                                    <<QSerialPort::Data8
                                    <<QSerialPort::NoParity
                                    <<QSerialPort::OneStop
                                    <<QSerialPort::NoFlowControl;


    }
private:

    RS232Connector* connector;
};


QTEST_APPLESS_MAIN(TestRS232Connector)

#include "tst_rs232connector.moc"
