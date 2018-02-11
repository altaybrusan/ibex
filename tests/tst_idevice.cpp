#include <QString>
#include <QtTest>
#include "idevice.h"
#include "isettingsparser.h"

class GeneratorSimulator:public QObject,IDevice
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "tr.edu.boun.IDevice")
    Q_INTERFACES(IDevice)

    QString _msg;
    int _kvp;


public:
    DEVICE_TYPE GetDeviceType() const override
    {
        return DEVICE_TYPE::GENERATOR;
    }

    void WriteToDevice(QString& message)
    {
        _msg = message;
    }

    void WriteToDevice(int& message)
    {
        _kvp = message;
    }

    int ReadFromDevice(const int& param)
    {
        qDebug()<< " Asked parameter is: "<<param;
        return _kvp;
    }

    QString ReadFromDevice(const QString& param)
    {
        qDebug()<< " Asked parameter is: "<<param;
        return _msg;
    }

    void UpdateSettingsParser(const ISettingsParser* parser ) override
    {
        //parser.GetSettings();

        return;
    }

    void Execute(QString& command)
    {
        qDebug()<<" Requested command is: " << command;

        return;
    }

    void UpdateParentWidget(QWidget *parent) override
    {

    }
    QWidget *GetWidget() override
    {
        return new QWidget();
    }

    ~GeneratorSimulator()
    {

    }


signals:
    QString NotifyNewMessage();

};

class TestIDevice : public QObject
{
    Q_OBJECT

public:
    TestIDevice()
    {

    }
    ~TestIDevice()
    {

    }

private Q_SLOTS:
    void testTestIDeviceCreation()
    {
        GeneratorSimulator _gen;
        QCOMPARE(_gen.GetDeviceType(),DEVICE_TYPE::GENERATOR);
        //QCOMPARE(_gen.GetDeviceType(),DEVICE_TYPE::ACTUATOR);
    }

};


//QTEST_APPLESS_MAIN(TestIDevice)

#include "tst_idevice.moc"
