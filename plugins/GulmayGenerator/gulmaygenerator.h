#ifndef GULMAYGENERATOR_H
#define GULMAYGENERATOR_H

#include "gulmaygenerator_global.h"
#include "isettingsparser.h"
#include "idevice.h"


class GULMAYGENERATORSHARED_EXPORT GulmayGenerator:public QObject, IDevice
{

    Q_OBJECT
    Q_PLUGIN_METADATA(IID "tr.edu.boun.IDevice")
    Q_INTERFACES(IDevice)


public:
    GulmayGenerator();

    // IDevice interface
    DEVICE_TYPE GetDeviceType() const override;
    void UpdateSettingsParser(const ISettingsParser* parser) override;
    void UpdateParentWidget(QWidget *parent) override;
    QWidget *GetWidget() override;

private:
    const ISettingsParser* _settingParser;
    QWidget* _userInterface;
};

#endif // GULMAYGENERATOR_H
