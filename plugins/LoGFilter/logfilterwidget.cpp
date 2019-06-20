#include "logfilterwidget.h"
#include "ui_logfilterwidget.h"
#include "ctkRangeSlider.h"




LoGFilterWidget::LoGFilterWidget(QWidget *parent) :
    QWidget(parent),    
    ui(new Ui::LoGFilterWidget)
{
    ui->setupUi(this);

}


LoGFilterWidget::~LoGFilterWidget()
{
    delete ui;
}

void LoGFilterWidget::SetEnableBtn(bool result)
{

    ui->applyBtn->setEnabled(result);
    ui->applyBtn->repaint();
}

void LoGFilterWidget::SetBoundaries(int min, int max)
{
    ui->kernelSizeSpinBox->setMinimum(min);
    ui->kernelSizeSpinBox->setMaximum(max);
    ui->kernelSizeSpinBox->repaint();

}


void LoGFilterWidget::SetStep(int value)
{
    ui->kernelSizeSpinBox->setSingleStep(value);
    ui->kernelSizeSpinBox->repaint();
}

int LoGFilterWidget::GetGaussianKernelLength()
{
    return ui->kernelSizeSpinBox->value();
}

void LoGFilterWidget::on_applyBtn_clicked()
{
    //SetEnableBtn(false);
    emit NotifyApplyFiltering();
}


void LoGFilterWidget::SetWidgetEnabled(bool enable)
{
    ui->kernelSizeSpinBox->setEnabled(enable);
    ui->applyBtn->setEnabled(enable);
    ui->frame->repaint();
}
