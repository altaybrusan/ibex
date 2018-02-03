#include "gulmaygenerator.h"
#include "idevice.h"
#include "protocoladjustmentwidget.h"

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

    _userInterface = parent;
    ProtocolAdjustmentWidget _pWidget;
    _pWidget.setParent(_userInterface);


}

QWidget *GulmayGenerator::GetWidget()
{

    return _userInterface;
}

