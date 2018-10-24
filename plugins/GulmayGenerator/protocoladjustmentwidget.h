#ifndef PROTOCOLADJUSTMENTWIDGET_H
#define PROTOCOLADJUSTMENTWIDGET_H

#include <QWidget>

namespace Ui {
class ProtocolAdjustmentWidget;
}

class ProtocolAdjustmentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProtocolAdjustmentWidget(QWidget *parent = 0);
    ~ProtocolAdjustmentWidget();

private:
    Ui::ProtocolAdjustmentWidget *ui;
};

#endif // PROTOCOLADJUSTMENTWIDGET_H
