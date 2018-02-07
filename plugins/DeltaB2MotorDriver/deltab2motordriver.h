#ifndef DELTAB2MOTORDRIVER_H
#define DELTAB2MOTORDRIVER_H

#include "deltab2motordriver_global.h"
#include "isettingsparser.h"
#include "idevice.h"

class DELTAB2MOTORDRIVERSHARED_EXPORT DeltaB2MotorDriver:public QObject, IDevice
{

    Q_OBJECT
    Q_PLUGIN_METADATA(IID "tr.edu.boun.IDevice")
    Q_INTERFACES(IDevice)

public:
    DeltaB2MotorDriver();
    DEVICE_TYPE GetDeviceType() const override;
    void UpdateSettingsParser(const ISettingsParser *parser) override;
    void UpdateParentWidget(QWidget *parent) override;
    QWidget *GetWidget() override;

private:
    const ISettingsParser* _settingParser;
    QWidget* _userInterface;

};

#endif // DELTAB2MOTORDRIVER_H
