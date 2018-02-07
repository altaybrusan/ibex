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

//    QVBoxLayout *layout = new QVBoxLayout;
//     layout->addWidget(_pWidget);
//     parent->setLayout(layout);
//     parent->show();




    _userInterface = _pWidget;//parent;
    //_pWidget.setParent(_userInterface);


    return _userInterface;
}

