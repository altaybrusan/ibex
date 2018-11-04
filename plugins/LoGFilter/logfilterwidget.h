#ifndef LOGFILTERWIDGET_H
#define LOGFILTERWIDGET_H

#include <QWidget>
#include "vtkSmartPointer.h"
#include "vtkImageData.h"

namespace Ui {
    class LoGFilterWidget;
}

class LoGFilterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoGFilterWidget(QWidget *parent = 0);
    ~LoGFilterWidget();

    void SetEnableBtn(bool result);
    void SetBoundaries(int min, int max);
    void SetGaussianKernelLength(int value);
    void SetStep(int value);
    int  GetGaussianKernelLength();
    void SetWidgetEnabled(bool enable);

signals:
    void NotifyApplyFiltering();

private slots:
    void on_applyBtn_clicked();


private:
    Ui::LoGFilterWidget *ui;

};


#endif // LOGFILTERWIDGET_H
