#ifndef DETECTORSETTINGSWIDGET_H
#define DETECTORSETTINGSWIDGET_H

#include <QWidget>

namespace Ui {
class DetectorSettingsWidget;
}

class DetectorSettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DetectorSettingsWidget(QWidget *parent = 0);
    ~DetectorSettingsWidget();

private:
    Ui::DetectorSettingsWidget *ui;
};

#endif // DETECTORSETTINGSWIDGET_H
