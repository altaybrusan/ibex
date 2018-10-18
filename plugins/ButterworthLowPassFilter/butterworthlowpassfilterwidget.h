#ifndef BUTTERWORTHLOWPASSFILTERWIDGET_H
#define BUTTERWORTHLOWPASSFILTERWIDGET_H

#include <QWidget>
#include "vtkSmartPointer.h"
#include "vtkImageData.h"

namespace Ui {
    class ButterworthLowPassFilterWidget;
}

class ButterworthLowPassFilterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ButterworthLowPassFilterWidget(QWidget *parent = 0);
    ~ButterworthLowPassFilterWidget();

    void CalculateFFT(vtkSmartPointer<vtkImageData> inputData);
    void SetEnableBtn(bool result);

signals:
    void NotifyStartHighFrequencyFiltering();

private slots:

    void on_applyBtn_clicked();

private:
    Ui::ButterworthLowPassFilterWidget *ui;
};


#endif // BUTTERWORTHLOWPASSFILTERWIDGET_H
