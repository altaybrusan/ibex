#ifndef COMPAREFILTERWIDGET_H
#define COMPAREFILTERWIDGET_H

#include <QWidget>
#include "vtkSmartPointer.h"
#include "vtkImageData.h"

namespace Ui {
    class CompareFilterWidget;
}

class CompareFilterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CompareFilterWidget(QWidget *parent = 0);
    ~CompareFilterWidget();

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
    Ui::CompareFilterWidget *ui;

};


#endif // COMPAREFILTERWIDGET_H
