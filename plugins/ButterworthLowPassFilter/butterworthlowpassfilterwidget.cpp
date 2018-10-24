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

void ButterworthLowPassFilterWidget::SetBoundaries(double min, double max)
{
    ui->xCutOffDSBox->setMinimum(min);
    ui->xCutOffDSBox->setMaximum(max);

    ui->yCutOffDSBox->setMinimum(min);
    ui->yCutOffDSBox->setMaximum(max);

    ui->xCutOffDSBox->repaint();
    ui->yCutOffDSBox->repaint();

}

void ButterworthLowPassFilterWidget::SetX(double value)
{
    ui->xCutOffDSBox->setValue(value);
}

void ButterworthLowPassFilterWidget::SetY(double value)
{
    ui->yCutOffDSBox->setValue(value);
}

void ButterworthLowPassFilterWidget::SetStep(double value)
{
    ui->xCutOffDSBox->setSingleStep(value);
    ui->yCutOffDSBox->setSingleStep(value);
    ui->xCutOffDSBox->repaint();
    ui->yCutOffDSBox->repaint();
}

void ButterworthLowPassFilterWidget::on_applyBtn_clicked()
{
    SetEnableBtn(false);

    //ui->highPassFilterBtn->setDisabled(true);

    emit NotifyStartHighFrequencyFiltering();

}


double ButterworthLowPassFilterWidget::GetX()
{
    return ui->xCutOffDSBox->value();
}

double ButterworthLowPassFilterWidget::GetY()
{
    return ui->yCutOffDSBox->value();
}
