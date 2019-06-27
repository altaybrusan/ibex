#include "comparefilterwidget.h"
#include "ui_comparefilterwidget.h"
#include "ctkRangeSlider.h"




CompareFilterWidget::CompareFilterWidget(QWidget *parent) :
    QWidget(parent),    
    ui(new Ui::CompareFilterWidget)
{
    ui->setupUi(this);

}


CompareFilterWidget::~CompareFilterWidget()
{
    delete ui;
}

void CompareFilterWidget::SetEnableBtn(bool result)
{

    ui->applyBtn->setEnabled(result);
    ui->applyBtn->repaint();
}

void CompareFilterWidget::SetBoundaries(int min, int max)
{
    ui->parameterSpinBox->setMinimum(min);
    ui->parameterSpinBox->setMaximum(max);
    ui->parameterSpinBox->repaint();

}


void CompareFilterWidget::SetStep(int value)
{
    ui->parameterSpinBox->setSingleStep(value);
    ui->parameterSpinBox->repaint();
}

int CompareFilterWidget::GetGaussianKernelLength()
{
    return ui->parameterSpinBox->value();
}

void CompareFilterWidget::on_applyBtn_clicked()
{
    emit NotifyApplyFiltering();
}


void CompareFilterWidget::SetWidgetEnabled(bool enable)
{
    ui->parameterSpinBox->setEnabled(enable);
    ui->applyBtn->setEnabled(enable);
    ui->frame->repaint();
}
