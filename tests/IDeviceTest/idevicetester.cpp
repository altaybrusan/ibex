#include <QString>
#include <QtTest>
#include <idevice.h>

// simulator class: implement IDevice interface.
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
};

class IDeviceTester : public QObject
{
    Q_OBJECT

public:
    IDeviceTester();

private Q_SLOTS:
    void SimulateIDeviceImplementation();
};

IDeviceTester::IDeviceTester()
{
}

void IDeviceTester::SimulateIDeviceImplementation()
{
    GeneratorSimulator _gen;
    QCOMPARE(_gen.GetDeviceType(),DEVICE_TYPE::GENERATOR);

}

QTEST_APPLESS_MAIN(IDeviceTester)

#include "idevicetester.moc"
