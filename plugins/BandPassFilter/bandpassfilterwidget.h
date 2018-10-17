#ifndef BANDPASSFILTERWIDGET_H
#define BANDPASSFILTERWIDGET_H

#include <QWidget>
#include "vtkSmartPointer.h"
#include "vtkImageData.h"

namespace Ui {
    class BandPassFilterWidget;
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
    void NotifyBandMaxisUpdated(int value);
    void NotifyStartHighFrequencyFiltering();

private slots:
    void on_rangeSlider_maximumValueChanged(int max);
    void on_highPassFilterBtn_clicked();

private:
    Ui::BandPassFilterWidget *ui;
};


#endif // BANDPASSFILTERWIDGET_H
