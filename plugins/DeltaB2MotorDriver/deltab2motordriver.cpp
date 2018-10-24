#include "deltab2motordriver.h"
#include "speedcontrolwidget.h"
#include "idevice.h"

DeltaB2MotorDriver::DeltaB2MotorDriver()
{
}

DEVICE_TYPE DeltaB2MotorDriver::GetDeviceType() const
{
    return DEVICE_TYPE::ACTUATOR;
}

void DeltaB2MotorDriver::UpdateSettingsParser(const ISettingsParser *parser)
{

}

void DeltaB2MotorDriver::UpdateParentWidget(QWidget *parent)
{

}

QWidget *DeltaB2MotorDriver::GetWidget()
{
    speedControlWidget* _Widget= new speedControlWidget();
    _userInterface = _Widget;
    return _userInterface;
}
