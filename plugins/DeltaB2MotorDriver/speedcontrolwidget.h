#ifndef SPEEDCONTROLWIDGET_H
#define SPEEDCONTROLWIDGET_H

#include <QWidget>

namespace Ui {
class speedControlWidget;
}

class speedControlWidget : public QWidget
{
    Q_OBJECT

public:
    explicit speedControlWidget(QWidget *parent = 0);
    ~speedControlWidget();

private:
    Ui::speedControlWidget *ui;
};

#endif // SPEEDCONTROLWIDGET_H
