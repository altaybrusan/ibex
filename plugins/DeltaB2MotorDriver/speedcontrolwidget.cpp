#include "speedcontrolwidget.h"
#include "ui_speedcontrolwidget.h"


speedControlWidget::speedControlWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::speedControlWidget)
{
    ui->setupUi(this);
}

speedControlWidget::~speedControlWidget()
{
    delete ui;
}
