#include "butterworthlowpassfilterwidget.h"
#include "ui_butterworthlowpassfilterwidget.h"
#include "ctkRangeSlider.h"



ButterworthLowPassFilterWidget::ButterworthLowPassFilterWidget(QWidget *parent) :
    QWidget(parent),    
    ui(new Ui::ButterworthLowPassFilterWidget)
{
    ui->setupUi(this);
}


ButterworthLowPassFilterWidget::~ButterworthLowPassFilterWidget()
{
    delete ui;
}

void ButterworthLowPassFilterWidget::SetEnableBtn(bool result)
{

    ui->applyBtn->setEnabled(result);
    ui->applyBtn->repaint();
}

void ButterworthLowPassFilterWidget::on_applyBtn_clicked()
{
    SetEnableBtn(false);

    //ui->highPassFilterBtn->setDisabled(true);

    emit NotifyStartHighFrequencyFiltering();

}
