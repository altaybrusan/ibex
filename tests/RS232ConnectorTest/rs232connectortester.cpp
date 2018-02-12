#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include <QMap>
#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QMetaEnum>
#include <QtSerialPort/QSerialPort>
#include "rs232connector.h"

class RS232ConnectorTester : public QObject
{
    Q_OBJECT

public:
    RS232ConnectorTester();

private Q_SLOTS:
    void testCreatingConnector_data();
    void testCreatingConnector();

private:

    RS232Connector* connector;
};

RS232ConnectorTester::RS232ConnectorTester()
{
    connector = new RS232Connector(this);
}

void RS232ConnectorTester::testCreatingConnector_data()
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

void RS232ConnectorTester::testCreatingConnector()
{
    QFETCH(QString, Name);
    QFETCH(QSerialPort::BaudRate,BaudRate);
    QFETCH(QSerialPort::DataBits,DataBits);
    QFETCH(QSerialPort::Parity,Parity);
    QFETCH(QSerialPort::StopBits,StopBits);
    QFETCH(QSerialPort::FlowControl,FlowControl);

    QMap<QString,QString>* connectionSettings=new QMap<QString,QString>();

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

QTEST_MAIN(RS232ConnectorTester)

#include "rs232connectortester.moc"
