#include "teledynedetector.h"
#include "detectorsettingswidget.h"

TeledyneDetector::TeledyneDetector()
{
}

DEVICE_TYPE TeledyneDetector::GetDeviceType() const
{
    return DEVICE_TYPE::DETECTOR;

}

void TeledyneDetector::UpdateSettingsParser(const ISettingsParser *parser)
{

}

void TeledyneDetector::UpdateParentWidget(QWidget *parent)
{

}

QWidget *TeledyneDetector::GetWidget()
{
    _userInterface =new DetectorSettingsWidget;
    return _userInterface;
}
