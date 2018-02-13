#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include <QMap>
#include <QString>
#include <QtTest>
#include <QSignalSpy>
#include <QMetaEnum>
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include "rs232connector.h"
#include <QDebug>

class RS232ConnectorTester : public QObject
{
    Q_OBJECT

public:
    RS232ConnectorTester();

private Q_SLOTS:
    void cleanup();
    void testUpdateWithValidConnectionSettings_data();
    void testUpdateWithValidConnectionSettings();
    void testUpdateWithNotValidConnectionSettings_data();
    void testUpdateWithNotValidConnectionSettings();
    void testUpdateWithEmptyConnectionSettings();
    void testIncompleteParameterSet();
    void testOpenConnectionAfterCorrectSettingup();
    void testOpenConnectionWithoutSettingup();
    void testReopenConnection();

private:

    RS232Connector* connector;
};

RS232ConnectorTester::RS232ConnectorTester()
{
    connector = new RS232Connector(this);

}

void RS232ConnectorTester::cleanup()
{
    QString testName= QString(QTest::currentTestFunction());
    if (testName.contains("Open")) {
        connector->CloseConnection();
        connector =new RS232Connector(this);
    }
}

void RS232ConnectorTester::testUpdateWithValidConnectionSettings_data()
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
void RS232ConnectorTester::testUpdateWithValidConnectionSettings()
{
    // Fetch data
    QFETCH(QString, Name);
    QFETCH(QSerialPort::BaudRate,BaudRate);
    QFETCH(QSerialPort::DataBits,DataBits);
    QFETCH(QSerialPort::Parity,Parity);
    QFETCH(QSerialPort::StopBits,StopBits);
    QFETCH(QSerialPort::FlowControl,FlowControl);

    //attach spy object
    QSignalSpy spy(connector, SIGNAL(NotifyConnectionError(QString)));

    QMap<QString,QString>* connectionSettings = new QMap<QString,QString>();
    (*connectionSettings)["Name"]= Name;
    (*connectionSettings)["BaudRate"]= QString::number(BaudRate);
    QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::DataBits>();
    (*connectionSettings)["DataBits"]= QString(metaEnum.valueToKey(DataBits));
    metaEnum = QMetaEnum::fromType<QSerialPort::Parity>();
    (*connectionSettings)["Parity"]=  QString(metaEnum.valueToKey(Parity));
    metaEnum = QMetaEnum::fromType<QSerialPort::StopBits>();
    (*connectionSettings)["StopBits"]=  QString(metaEnum.valueToKey(StopBits));
    metaEnum = QMetaEnum::fromType<QSerialPort::FlowControl>();
    (*connectionSettings)["FlowControl"]=  QString(metaEnum.valueToKey(FlowControl));
    connector->UpdateConnectionSettings(connectionSettings);
//    QList<QVariant> arguments = spy.takeFirst();
//    qDebug()<<"............."<<arguments.at(0).toString();
    QVERIFY(spy.count()==0);



}

void RS232ConnectorTester::testUpdateWithNotValidConnectionSettings_data()
{
    QTest::addColumn<QString>("Name");
            QTest::addColumn<QSerialPort::BaudRate>("BaudRate");
            QTest::addColumn<QSerialPort::DataBits>("DataBits");
            QTest::addColumn<QSerialPort::Parity>("Parity");
            QTest::addColumn<QSerialPort::StopBits>("StopBits");
            QTest::addColumn<QSerialPort::FlowControl>("FlowControl");

            QTest::newRow("not valid BaudRate") << "COM3"
                                        <<QSerialPort::UnknownBaud
                                        <<QSerialPort::Data8
                                        <<QSerialPort::NoParity
                                        <<QSerialPort::OneStop
                                        <<QSerialPort::NoFlowControl;


            QTest::newRow("not valid DataBits") << "COM3"
                                        <<QSerialPort::Baud9600
                                        <<QSerialPort::UnknownDataBits
                                        <<QSerialPort::NoParity
                                        <<QSerialPort::OneStop
                                        <<QSerialPort::NoFlowControl;

            QTest::newRow("not valid Parity") << "COM3"
                                        <<QSerialPort::Baud9600
                                        <<QSerialPort::Data8
                                        <<QSerialPort::UnknownParity
                                        <<QSerialPort::OneStop
                                        <<QSerialPort::NoFlowControl;

            QTest::newRow("not valid StopBit") << "COM3"
                                        <<QSerialPort::Baud9600
                                        <<QSerialPort::Data8
                                        <<(QSerialPort::NoParity)
                                        <<QSerialPort::UnknownStopBits
                                        <<QSerialPort::NoFlowControl;

            QTest::newRow("not valid FlowControl") << "COM3"
                                        <<QSerialPort::Baud9600
                                        <<QSerialPort::Data8
                                        <<QSerialPort::NoParity
                                        <<QSerialPort::OneStop
                                        <<QSerialPort::UnknownFlowControl;
}
void RS232ConnectorTester::testUpdateWithNotValidConnectionSettings()
{
    // Fetch data
    QFETCH(QString, Name);
    QFETCH(QSerialPort::BaudRate,BaudRate);
    QFETCH(QSerialPort::DataBits,DataBits);
    QFETCH(QSerialPort::Parity,Parity);
    QFETCH(QSerialPort::StopBits,StopBits);
    QFETCH(QSerialPort::FlowControl,FlowControl);

    //attach spy object
    QSignalSpy spy(connector, SIGNAL(NotifyConnectionError(QString)));

    QMap<QString,QString>* connectionSettings = new QMap<QString,QString>();

    (*connectionSettings)["Name"]= Name;
    (*connectionSettings)["BaudRate"] =QString::number(BaudRate);

    QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::DataBits>();
    (*connectionSettings)["DataBits"] =
            QString(metaEnum.valueToKey(DataBits));

    metaEnum = QMetaEnum::fromType<QSerialPort::Parity>();
    (*connectionSettings)["Parity"] =
            QString(metaEnum.valueToKey(Parity));

    metaEnum = QMetaEnum::fromType<QSerialPort::StopBits>();
    (*connectionSettings)["StopBits"] =
            QString(metaEnum.valueToKey(StopBits));

    metaEnum = QMetaEnum::fromType<QSerialPort::FlowControl>();
    (*connectionSettings)["FlowControl"] =
            QString(metaEnum.valueToKey(FlowControl));

    connector->UpdateConnectionSettings(connectionSettings);
    QVERIFY(spy.count() == 1);
    QList<QVariant> arguments = spy.takeFirst();
    qDebug()<<">>>Connection error message: "<<arguments.at(0).toString();


}

void RS232ConnectorTester::testUpdateWithEmptyConnectionSettings()
{
    //attach spy object
    QSignalSpy spy(connector, SIGNAL(NotifyConnectionError(QString)));
    QMap<QString,QString>* emptyConnectionSettings= NULL;
    connector->UpdateConnectionSettings(emptyConnectionSettings);
    QVERIFY(spy.count()==1); // should issue just one error signal
    QList<QVariant> arguments = spy.takeFirst();

    QVERIFY(arguments.at(0).toString() == tr("Connection settings can not be empty."));

}

void RS232ConnectorTester::testIncompleteParameterSet()
{

    //attach spy object
    QSignalSpy spy(connector, SIGNAL(NotifyConnectionError(QString)));

    QMap<QString,QString>* connectionSettings = new QMap<QString,QString>();
    (*connectionSettings)["Name"]= "COM3";

    connector->UpdateConnectionSettings(connectionSettings);
    QList<QVariant> arguments = spy.takeFirst();
    qDebug()<<">>>Connection error message: "<<arguments.at(0).toString();

    QVERIFY(spy.count()==0);// no error after the first one is dequed.

}

void RS232ConnectorTester::testOpenConnectionAfterCorrectSettingup()
{
    QSignalSpy spy(connector,SIGNAL(NotifyConnectionOpened()));

    if(QSerialPortInfo::availablePorts().count()==0)
    {
        QSKIP("No serialports exist on this device.");
    }

    QMap<QString,QString>* connectionSettings = new QMap<QString,QString>();

    (*connectionSettings)["Name"]= QSerialPortInfo::availablePorts().first().portName();;
    (*connectionSettings)["BaudRate"]= QString::number(9600);
    QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::DataBits>();
    (*connectionSettings)["DataBits"]= QString(metaEnum.valueToKey(QSerialPort::Data8));
    metaEnum = QMetaEnum::fromType<QSerialPort::Parity>();
    (*connectionSettings)["Parity"]=  QString(metaEnum.valueToKey(QSerialPort::NoParity));
    metaEnum = QMetaEnum::fromType<QSerialPort::StopBits>();
    (*connectionSettings)["StopBits"]=  QString(metaEnum.valueToKey(QSerialPort::OneStop));
    metaEnum = QMetaEnum::fromType<QSerialPort::FlowControl>();
    (*connectionSettings)["FlowControl"]=  QString(metaEnum.valueToKey(QSerialPort::NoFlowControl));
    connector->UpdateConnectionSettings(connectionSettings);

    connector->OpenConnection();

    // should receive exactly one message.
    QVERIFY(spy.count()==1);
}
void RS232ConnectorTester::testOpenConnectionWithoutSettingup()
{

    QSignalSpy spy(connector,SIGNAL(NotifyConnectionError(QString)));
    connector->OpenConnection();
    QVERIFY(spy.count() == 1);
    // should receive exactly one message.
    QList<QVariant> arguments = spy.takeFirst();
    qDebug()<<">>>"<<arguments.at(0).toString();
    // th qt message is miss-leading,
    // if no device is available:
    // The system cannot find the path specified.

}

void RS232ConnectorTester::testReopenConnection()
{
    QSignalSpy spy(connector,SIGNAL(NotifyConnectionOpened()));
    QSignalSpy spy2(connector,SIGNAL(NotifyConnectionClosed()));

    if(QSerialPortInfo::availablePorts().count()==0)
    {
        QSKIP("No serialports exist on this device.");
    }

    QMap<QString,QString>* connectionSettings = new QMap<QString,QString>();

    (*connectionSettings)["Name"]= QSerialPortInfo::availablePorts().first().portName();;
    (*connectionSettings)["BaudRate"]= QString::number(9600);
    QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::DataBits>();
    (*connectionSettings)["DataBits"]= QString(metaEnum.valueToKey(QSerialPort::Data8));
    metaEnum = QMetaEnum::fromType<QSerialPort::Parity>();
    (*connectionSettings)["Parity"]=  QString(metaEnum.valueToKey(QSerialPort::NoParity));
    metaEnum = QMetaEnum::fromType<QSerialPort::StopBits>();
    (*connectionSettings)["StopBits"]=  QString(metaEnum.valueToKey(QSerialPort::OneStop));
    metaEnum = QMetaEnum::fromType<QSerialPort::FlowControl>();
    (*connectionSettings)["FlowControl"]=  QString(metaEnum.valueToKey(QSerialPort::NoFlowControl));
    connector->UpdateConnectionSettings(connectionSettings);

    connector->OpenConnection();

    // should receive exactly one message.
    QVERIFY(spy.count()==1);

    //reopen connection
    connector->OpenConnection();
    QVERIFY(spy2.count() == 0 );
}



QTEST_MAIN(RS232ConnectorTester)

#include "rs232connectortester.moc"
