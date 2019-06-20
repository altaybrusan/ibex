#ifndef LOADIMAGEDIALOG_H
#define LOADIMAGEDIALOG_H

#include <QDialog>
#include "View/imageviewer.h"

namespace Ui {
    class LoadImageDialog;
}


class LoadImageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoadImageDialog(QWidget *parent,ImageViewer & viewer);
    void Show();
    ~LoadImageDialog();

private slots:
    void on_openBtn_clicked();

private:
    void LoadImage(QString filePath);
    Ui::LoadImageDialog *ui;
    ImageViewer& m_viewer;

};

#endif // LOADIMAGEDIALOG_H
