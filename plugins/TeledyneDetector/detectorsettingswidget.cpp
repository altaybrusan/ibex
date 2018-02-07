#include "detectorsettingswidget.h"
#include "ui_detectorsettingswidget.h"

DetectorSettingsWidget::DetectorSettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetectorSettingsWidget)
{
    ui->setupUi(this);
}

DetectorSettingsWidget::~DetectorSettingsWidget()
{
    delete ui;
}
