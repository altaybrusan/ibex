#include "protocoladjustmentwidget.h"
#include "ui_protocoladjustmentwidget.h"


ProtocolAdjustmentWidget::ProtocolAdjustmentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProtocolAdjustmentWidget)
{
    ui->setupUi(this);
}

ProtocolAdjustmentWidget::~ProtocolAdjustmentWidget()
{
    delete ui;
}
