#include "gulmaygenerator.h"
#include "idevice.h"
#include "protocoladjustmentwidget.h"
#include <QVBoxLayout>

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

    //this section must go to launch
    ProtocolAdjustmentWidget* _pWidget= new ProtocolAdjustmentWidget(parent);
    QVBoxLayout *layout = new QVBoxLayout;
     layout->addWidget(_pWidget);
     parent->setLayout(layout);
     parent->show();


    //_userInterface = parent;

    //_pWidget.setParent(_userInterface);


}

QWidget *GulmayGenerator::GetWidget()
{

    return _userInterface;
}

