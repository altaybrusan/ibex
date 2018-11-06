#include "newpatientdialog.h"
#include "ui_newpatientdialog.h"
#include <QDomDocument>

namespace StartupTool
{
    NewPatientDialog::NewPatientDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::NewPatientDialog)
    {
        ui->setupUi(this);

        _bodyPartModel=new QStringListModel(this);

        // This section is very very very bad practice please refactor it.
        QDomDocument doc;
        _bodyPartFile = new QFile(":/config/xml/BodyPartDescription.xml");
        if (!_bodyPartFile->open(QIODevice::ReadOnly) || !doc.setContent(_bodyPartFile))
        {
            //should through exception. Please refactor it for the next iteration
            qDebug()<<"Can not find the BodyPartDescription.xml";
        }
        QDomNodeList _nodeList = doc.elementsByTagName("Data");

        QStringList list;
        for (int i = 0; i < _nodeList.size(); i++)
        {
           list<< _nodeList.at(i).attributes().namedItem("key").nodeValue();
        }
        _bodyPartModel->setStringList(list);
        ui->bodyPartListComboBox->setModel(_bodyPartModel);

        _dataProvider = new DataProvider::DataBase();

        // till now the the body part combo box items have been loaded

    }

    NewPatientDialog::~NewPatientDialog()
    {
        delete ui;
    }
    void NewPatientDialog::on_acceptBtn_clicked()
    {
         QMap<QString,QString> _form;
         _form["patientname"]= ui->lastNameLineEdit->text()+"^"+
                               ui->firstNameLineEdit->text()+"^"+
                               ui->middleNameLineEdit->text();

         _form["accessionnum"]=ui->accessionNumberLineEdit->text();
         _form["admissionid"]=ui->admissionNumberLineEdit->text();
         _form["patientid"]=ui->patientIdLineEdit->text();
         _form["refphysician"]=ui->referringPhysicianLineEdit->text();
         _form["sex"]=ui->genderComboBox->itemText(ui->genderComboBox->currentIndex());
        QMap<QString,QString> _procList;
        _dataProvider->WriteNewRecord("WorkItem",_form,_procList);
    }

}



