#ifndef IDEVICE_H
#define IDEVICE_H

#endif // IDEVICE_H
#include <QObject>
#include <QString>

enum DEVICE_TYPE { GENERATOR , DETECTOR , ACTUATOR };

class IDevice
{

public:
    virtual DEVICE_TYPE GetDeviceType() const = 0;
//    virtual void SetMessage(const QString &msg) = 0;

    template<typename T>
    void WriteToDevice(const T& message) = 0;

    template<typename U,typename V>
    V ReadFromDevice(const U& param) = 0;

    template<typename C>
    void Execute(const C& command) = 0;

    virtual ~IDevice()
    {

    }


signals:
    QString NotifyNewMessage();

};


Q_DECLARE_INTERFACE(IDevice, "tr.edu.boun.IDevice")
