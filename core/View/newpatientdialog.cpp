#include "newpatientdialog.h"
#include "ui_newpatientdialog.h"
#include <QRegExpValidator>
#include <QPushButton>
#include <QDateTime>
#include "Utils/dicomtools.h"

NewPatientDialog::NewPatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPatientDialog)
{
    ui->setupUi(this);

    // prevent from leading space.

    QRegExp rx("^(?!\\s*$).+");
    validator = new QRegExpValidator(rx, this);
    ui->admissionNumberLineEdit->setValidator(validator);
    ui->patientIdLineEdit->setValidator(validator);
    ui->lastNameLineEdit->setValidator(validator);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled( false );
    connect(ui->lastNameLineEdit,SIGNAL(textChanged(QString)),this,SLOT(ActivateOkBtn()));
    connect(ui->patientIdLineEdit,SIGNAL(textChanged(QString)),this,SLOT(ActivateOkBtn()));
    connect(ui->accessionNumberLineEdit,SIGNAL(textChanged(QString)),this,SLOT(ActivateOkBtn()));

//    scene = new QGraphicsScene(this);
//    QImage sourceImage;
//    sourceImage.load(":/assets/images/human.jpg");
//    scene->addPixmap(QPixmap::fromImage(sourceImage));

//    ui->graphicsView->setScene(scene);

//    head =new BodyPartSelectionSquare(60,2,50,60,this);
//    head->setToolTip("head");
//    head->SetSelectionSquareName(iBEX::BODY_PART::HEAD);

//    thorax=new BodyPartSelectionSquare(55,64,60,55,this);
//    thorax->setToolTip("thorax");
//    thorax->SetSelectionSquareName(iBEX::BODY_PART::THORAX);

//    abdomen=new BodyPartSelectionSquare(55,121,60,35,this);
//    abdomen->setToolTip("abdomen");
//    abdomen->SetSelectionSquareName(iBEX::BODY_PART::ABDOMEN);

//    pelvis=new BodyPartSelectionSquare(52,158,64,30,this);
//    pelvis->setToolTip("pelvis");
//    pelvis->SetSelectionSquareName(iBEX::BODY_PART::PELVIS);

//    fermur=new BodyPartSelectionSquare(52,190,64,44,this);
//    fermur->setToolTip("fermur");
//    fermur->SetSelectionSquareName(iBEX::BODY_PART::FERMUR);

//    knee=new BodyPartSelectionSquare(52,236,64,40,this);
//    knee->setToolTip("knee");
//    knee->SetSelectionSquareName(iBEX::BODY_PART::KNEE);

//    tibia=new BodyPartSelectionSquare(52,278,64,50,this);
//    tibia->setToolTip("tibia");
//    tibia->SetSelectionSquareName(iBEX::BODY_PART::TIBIA);

//    ankle=new BodyPartSelectionSquare(52,330,64,15,this);
//    ankle->setToolTip("ankel");
//    ankle->SetSelectionSquareName(iBEX::BODY_PART::ANKEL);

//    foot=new BodyPartSelectionSquare(52,347,66,11,this);
//    foot->setToolTip("foot");
//    foot->SetSelectionSquareName(iBEX::BODY_PART::FOOT);

//    finger=new BodyPartSelectionSquare(8,194,28,14,this);
//    finger->setToolTip("finger");
//    finger->SetSelectionSquareName(iBEX::BODY_PART::FINGER);

//    hand=new BodyPartSelectionSquare(8,176,28,16,this);
//    hand->setToolTip("hand");
//    hand->SetSelectionSquareName(iBEX::BODY_PART::HAND);

//    wrist=new BodyPartSelectionSquare(8,165,28,10,this);
//    wrist->setToolTip("wrist");
//    wrist->SetSelectionSquareName(iBEX::BODY_PART::WRIST);

//    shoulder=new BodyPartSelectionSquare(35,55,20,25,this);
//    shoulder->setToolTip("shoulder");
//    shoulder->SetSelectionSquareName(iBEX::BODY_PART::SHOULDER);

//    elbow=new BodyPartSelectionSquare(28,110,20,25,this);
//    elbow->setToolTip("elbow");
//    elbow->SetSelectionSquareName(iBEX::BODY_PART::ELBOW);

//    scene->addItem(head);
//    scene->addItem(thorax);
//    scene->addItem(abdomen);
//    scene->addItem(pelvis);
//    scene->addItem(fermur);
//    scene->addItem(knee);
//    scene->addItem(tibia);
//    scene->addItem(ankle);
//    scene->addItem(foot);

//    scene->addItem(finger);
//    scene->addItem(hand);
//    scene->addItem(wrist);
//    scene->addItem(shoulder);
//    scene->addItem(elbow);

//    foreach (auto item, scene->items()) {

//        _temp = nullptr;
//        _temp = dynamic_cast<BodyPartSelectionSquare*>(item);

//        if(_temp)
//        {
//            connect(_temp,
//                    SIGNAL(NotifyBodyPartIsStatusChanged(iBEX::BODY_PART,bool)),
//                    this,
//                    SLOT(OnBodyPartStatusChanged(iBEX::BODY_PART,bool)));
//        }
//    }

//    ui->accessionNumberLineEdit->setText(DicomTools::GenerateAccessionNumber());
}

//QString NewPatientDialog::GetPatientInfo(NewPatientDialog::DemographyKeys field)
//{
//    return demographics.value(field);
//}

//QStringList NewPatientDialog::GetSelectedProceduresList()
//{
//    return _selectedBodyPartList;
//}

NewPatientDialog::~NewPatientDialog()
{
    delete ui;
}

void NewPatientDialog::ActivateOkBtn()
{
//    if(
//        !ui->accessionNumberLineEdit->text().isEmpty() &&
//        !ui->lastNameLineEdit->text().isEmpty() &&
//        !ui->patientIdLineEdit->text().isEmpty())
//        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled( true );
//    else
//        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled( false );

//    demographics[DemographyKeys::LastName]=ui->lastNameLineEdit->text();
//        demographics[DemographyKeys::FirstName]=ui->firstNameLineEdit->text();
//        demographics[DemographyKeys::MiddleName]=ui->middleNameLineEdit->text();
//        demographics[DemographyKeys::PatientID]=ui->patientIdLineEdit->text();
//        demographics[DemographyKeys::DOB]=ui->dateEdit->date().toString(Qt::ISODate);

//        switch(ui->genderComboBox->currentIndex())
//        {
//        case 0:
//            demographics[DemographyKeys::Gender] = "M";
//            break;
//        case 1:
//            demographics[DemographyKeys::Gender] = "F";
//            break;
//        case 2:
//            demographics[DemographyKeys::Gender] = "U";
//            break;
//        }

//        demographics[DemographyKeys::ReferrinPhysician]= ui->referringPhysicianLineEdit->text();
//        demographics[DemographyKeys::AdmissionNumber]= ui->admissionNumberLineEdit->text();
//        demographics[DemographyKeys::AccessionNumber]= ui->accessionNumberLineEdit->text();

}
// when a click on a body part scene happens this SLOT is called multiple times.
void NewPatientDialog::OnBodyPartStatusChanged(iBEX::BODY_PART bodyPart, bool isSelected)
{
//    QMetaEnum metaEnum = QMetaEnum::fromType<iBEX::BODY_PART>();
//    QString bodyPartStr(metaEnum.valueToKey(static_cast<int>(bodyPart)));

//    if(isSelected)
//    {
//        if(!_selectedBodyPartList.contains(bodyPartStr))
//        {
//            _selectedBodyPartList.append(bodyPartStr);
//        }
//    }
//    else
//    {
//        if(_selectedBodyPartList.contains(bodyPartStr))
//        {
//            _selectedBodyPartList.removeAll(bodyPartStr);
//        }
//    }

//    if(_numberOfselectedBodyParts != _selectedBodyPartList.count())
//    {
//        _numberOfselectedBodyParts = _selectedBodyPartList.count();
//        qDebug()<<"---------------------------";
//        foreach (auto item, _selectedBodyPartList) {

//            qDebug()<<"The selected bodypart: "<<item;
//        }
//      //qDebug()<<"Number of elements: "<< _selectedBodyPartList.count();
//    }

}




void NewPatientDialog::on_buttonBox_accepted()
{    

//    qDebug()<<demographics[DemographyKeys::LastName];
//    qDebug()<<demographics[DemographyKeys::FirstName];
//    qDebug()<<demographics[DemographyKeys::MiddleName];
//    qDebug()<<demographics[DemographyKeys::PatientID];
//    qDebug()<<demographics[DemographyKeys::DOB];
//    qDebug()<<demographics[DemographyKeys::Gender];
//    qDebug()<<demographics[DemographyKeys::ReferrinPhysician];
//    qDebug()<<demographics[DemographyKeys::AdmissionNumber];
//      qDebug()<<"ACCESSION: "<<demographics[DemographyKeys::AccessionNumber];
}

void NewPatientDialog::on_lastNameLineEdit_editingFinished()
{
//    demographics[DemographyKeys::LastName]=ui->lastNameLineEdit->text();
}

void NewPatientDialog::on_firstNameLineEdit_editingFinished()
{
//     demographics[DemographyKeys::FirstName]=ui->firstNameLineEdit->text();
}

void NewPatientDialog::on_middleNameLineEdit_editingFinished()
{
//    demographics[DemographyKeys::MiddleName]=ui->middleNameLineEdit->text();
}

void NewPatientDialog::on_patientIdLineEdit_editingFinished()
{
//    demographics[DemographyKeys::PatientID]=ui->patientIdLineEdit->text();

}

void NewPatientDialog::on_dateEdit_editingFinished()
{
//    demographics[DemographyKeys::DOB]=ui->dateEdit->date().toString(Qt::ISODate);

}

void NewPatientDialog::on_genderComboBox_currentIndexChanged(int index)
{
//    switch(index)
//    {
//    case 0:
//        demographics[DemographyKeys::Gender] = "M";
//        break;
//    case 1:
//        demographics[DemographyKeys::Gender] = "F";
//        break;
//    case 2:
//        demographics[DemographyKeys::Gender] = "U";
//        break;
//    }
}

void NewPatientDialog::on_referringPhysicianLineEdit_editingFinished()
{
//    demographics[DemographyKeys::ReferrinPhysician]= ui->referringPhysicianLineEdit->text();

}

void NewPatientDialog::on_admissionNumberLineEdit_editingFinished()
{
    //demographics[DemographyKeys::AdmissionNumber]= ui->admissionNumberLineEdit->text();

}

void NewPatientDialog::on_accessionNumberLineEdit_editingFinished()
{
    //demographics[DemographyKeys::AccessionNumber]= ui->accessionNumberLineEdit->text();
}


