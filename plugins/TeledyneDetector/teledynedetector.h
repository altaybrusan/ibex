#ifndef TELEDYNEDETECTOR_H
#define TELEDYNEDETECTOR_H

#include "teledynedetector_global.h"
#include "isettingsparser.h"
#include "idevice.h"

class TELEDYNEDETECTORSHARED_EXPORT TeledyneDetector:public QObject, IDevice
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "tr.edu.boun.IDevice")
    Q_INTERFACES(IDevice)


public:
    TeledyneDetector();

    // IDevice interface
public:
    DEVICE_TYPE GetDeviceType() const override;
    void UpdateSettingsParser(const ISettingsParser *parser) override;
    void UpdateParentWidget(QWidget *parent) override;
    QWidget *GetWidget() override;

private:
    const ISettingsParser* _settingParser;
    QWidget* _userInterface;
};

#endif // TELEDYNEDETECTOR_H
