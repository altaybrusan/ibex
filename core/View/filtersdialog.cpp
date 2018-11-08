#include "filtersdialog.h"
#include "ui_filtersdialog.h"
#include "Utils/logmgr.h"

FiltersDialog::FiltersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FiltersDialog)
{
    ui->setupUi(this);
}

void FiltersDialog::AddItemToList(QString filterName)
{
    QListWidgetItem* item = new QListWidgetItem(filterName,ui->filtersListWidget);

    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Checked);
    connect(ui->filtersListWidget,&QListWidget::itemChanged,this,
            [&](QListWidgetItem* item)
    {
        int row = ui->filtersListWidget->row(item);
        LogMgr::instance()->LogSysDebug("The plugin number " + QString::number(row)+" is un/checked");
        emit NotifyItemCheckChanged(row,item->checkState());
    });
}

FiltersDialog::~FiltersDialog()
{
    delete ui;
}

void FiltersDialog::on_buttonBox_accepted()
{
    this->close();
}

void FiltersDialog::on_buttonBox_rejected()
{
    this->close();
}
