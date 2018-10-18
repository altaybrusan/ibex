#include "butterworthlowpassfilterwidget.h"
#include "ui_bandpassfilterwidget.h"
#include "ctkRangeSlider.h"



BandPassFilterWidget::BandPassFilterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ButterworthLowPassFilterWidget)
{
    ui->setupUi(this);
    ui->rangeSlider->setPositions(0,100);
}

BandPassFilterWidget::~BandPassFilterWidget()
{
    delete ui;
}

void BandPassFilterWidget::SetEnableBtn(bool result)
{
    ui->highPassFilterBtn->setEnabled(result);
    ui->highPassFilterBtn->repaint();
}




void BandPassFilterWidget::on_highPassFilterBtn_clicked()
{
    SetEnableBtn(false);

    //ui->highPassFilterBtn->setDisabled(true);

    emit NotifyStartHighFrequencyFiltering();
}
