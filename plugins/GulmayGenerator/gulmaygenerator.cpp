#include "gulmaygenerator.h"
#include "idevice.h"
#include "protocoladjustmentwidget.h"
#include <QVBoxLayout>
#include <QScrollArea>

GulmayGenerator::GulmayGenerator()
{
}

DEVICE_TYPE GulmayGenerator::GetDeviceType() const
{

    return DEVICE_TYPE::GENERATOR;
}

void GulmayGenerator::UpdateSettingsParser(const ISettingsParser* parser)
{
    _settingParser = parser;
}

void GulmayGenerator::UpdateParentWidget(QWidget *parent)
{

}

QWidget *GulmayGenerator::GetWidget()
{
    //this section must go to launch
    ProtocolAdjustmentWidget* _pWidget= new ProtocolAdjustmentWidget();
    _userInterface = _pWidget;
    return _userInterface;
}

