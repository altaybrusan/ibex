#ifndef BUTTERWORTHLOWPASSFILTERWIDGET_H
#define BUTTERWORTHLOWPASSFILTERWIDGET_H

#include <QWidget>
#include "vtkSmartPointer.h"
#include "vtkImageData.h"

namespace Ui {
    class ButterworthLowPassFilterWidget;
}

class BandPassFilterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BandPassFilterWidget(QWidget *parent = 0);
    ~BandPassFilterWidget();

    void CalculateFFT(vtkSmartPointer<vtkImageData> inputData);
    void SetEnableBtn(bool result);

signals:
    void NotifyStartHighFrequencyFiltering();

private slots:
    void on_highPassFilterBtn_clicked();

private:
    Ui::ButterworthLowPassFilterWidget *ui;
};


#endif // BANDPASSFILTERWIDGET_H
