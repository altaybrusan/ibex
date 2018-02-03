#ifndef IDEVICE_H
#define IDEVICE_H

#include <QObject>
#include <QString>
#include <QMessageBox>
#include "isettingsparser.h"

// this is not best practice. chage it for the next
// iteration.
enum DEVICE_TYPE { GENERATOR , DETECTOR , ACTUATOR };
//// Turn this into state design pattern later.
/// warning: the launcher should not decide about the widget state.
//enum DEVICE_STATE {PREPARATION,READY,ACTIVE,CALIBRATING,ERROR};

class IDevice
{

public:
    virtual DEVICE_TYPE GetDeviceType() const = 0;
//    state is internal affier.
//    virtual DEVICE_STATE GetDeviceState() const = 0;

    template<typename T>
    void WriteToDevice(const T& message) = 0;

    template<typename U,typename V>
    V ReadFromDevice(const U& param) = 0;

    template<typename C>
    void Execute(const C& command) = 0;

    // There may be a device outside there, with no external setting parser requirment
    // for example all the settings are hardwired inside the device firmware, so the
    // the relation ia aggregation and NOT COMPOSITION (no need for internal constructor parameter).
    virtual void UpdateSettingsParser(const ISettingsParser* parser ) = 0;

    // the launcher provide a widget for the plugin.
    // based on its internal state the plugin draw on its canvas.
    // Some devices may not require any UI. So do not ask for UI at constructor!
    virtual void UpdateParentWidget(QWidget* parent)= 0;
    virtual QWidget* GetWidget() = 0;

//    // not best practice
//    virtual QWidget* GetPreparationStateUI() = 0;
//    virtual QWidget* GetReadyStateUI() = 0;
//    virtual QWidget* GetActiveStateUI() = 0;
//    virtual QWidget* GetCalibratingStateUI() = 0;
//    virtual QWidget* GetErrorStateUI() = 0;

    virtual ~IDevice()
    {

    }

//inherited by all sub-classes
signals:

    void NotifyMessage(const QString message) const;
    // simple message as error! not best practice.
    void NotifyError(const QString error) const;
    void NotifyDialog(const QMessageBox& messageBox);

};


Q_DECLARE_INTERFACE(IDevice, "tr.edu.boun.IDevice")



#endif // IDEVICE_H
