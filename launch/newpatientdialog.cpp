#include "newpatientdialog.h"
#include "ui_newpatientdialog.h"
#include <QRegExpValidator>
#include <QPushButton>

// no view for each body part
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

    scene = new QGraphicsScene(this);
    QImage sourceImage;
    sourceImage.load(":/assets/images/human.jpg");
    scene->addPixmap(QPixmap::fromImage(sourceImage));

    ui->graphicsView->setScene(scene);

    head =new BodyPartSelectionSquare(60,2,50,60,this);
    head->setToolTip("head");
    head->SetSelectionSquareName(iBEX::BodyPart::HEAD);

    thorax=new BodyPartSelectionSquare(55,64,60,55,this);
    thorax->setToolTip("thorax");
    thorax->SetSelectionSquareName(iBEX::BodyPart::THORAX);

    abdomen=new BodyPartSelectionSquare(55,121,60,35,this);
    abdomen->setToolTip("abdomen");
    abdomen->SetSelectionSquareName(iBEX::BodyPart::ABDOMEN);

    pelvis=new BodyPartSelectionSquare(52,158,64,30,this);
    pelvis->setToolTip("pelvis");
    pelvis->SetSelectionSquareName(iBEX::BodyPart::PELVIS);

    fermur=new BodyPartSelectionSquare(52,190,64,44,this);
    fermur->setToolTip("fermur");
    fermur->SetSelectionSquareName(iBEX::BodyPart::FERMUR);

    knee=new BodyPartSelectionSquare(52,236,64,40,this);
    knee->setToolTip("knee");
    knee->SetSelectionSquareName(iBEX::BodyPart::KNEE);

    tibia=new BodyPartSelectionSquare(52,278,64,50,this);
    tibia->setToolTip("tibia");
    tibia->SetSelectionSquareName(iBEX::BodyPart::TIBIA);

    ankel=new BodyPartSelectionSquare(52,330,64,15,this);
    ankel->setToolTip("ankel");
    ankel->SetSelectionSquareName(iBEX::BodyPart::ANKEL);

    foot=new BodyPartSelectionSquare(52,347,66,11,this);
    foot->setToolTip("foot");
    foot->SetSelectionSquareName(iBEX::BodyPart::FOOT);

    finger=new BodyPartSelectionSquare(8,194,28,14,this);
    finger->setToolTip("finger");
    finger->SetSelectionSquareName(iBEX::BodyPart::FINGER);

    hand=new BodyPartSelectionSquare(8,176,28,16,this);
    hand->setToolTip("hand");
    hand->SetSelectionSquareName(iBEX::BodyPart::HAND);

    wrist=new BodyPartSelectionSquare(8,165,28,10,this);
    wrist->setToolTip("wrist");
    wrist->SetSelectionSquareName(iBEX::BodyPart::WRIST);

    shoulder=new BodyPartSelectionSquare(35,55,20,25,this);
    shoulder->setToolTip("shoulder");
    shoulder->SetSelectionSquareName(iBEX::BodyPart::SHOULDER);

    elbow=new BodyPartSelectionSquare(28,110,20,25,this);
    elbow->setToolTip("elbow");
    elbow->SetSelectionSquareName(iBEX::BodyPart::ELBOW);

    scene->addItem(head);
    scene->addItem(thorax);
    scene->addItem(abdomen);
    scene->addItem(pelvis);
    scene->addItem(fermur);
    scene->addItem(knee);
    scene->addItem(tibia);
    scene->addItem(ankel);
    scene->addItem(foot);

    scene->addItem(finger);
    scene->addItem(hand);
    scene->addItem(wrist);
    scene->addItem(shoulder);
    scene->addItem(elbow);



    foreach (auto item, scene->items()) {

        _temp = nullptr;
        _temp = dynamic_cast<BodyPartSelectionSquare*>(item);

        if(_temp)
        {
            connect(_temp,
                    SIGNAL(NotifyBodyPartIsStatusChanged(iBEX::BodyPart,bool)),
                    this,
                    SLOT(OnBodyPartStatusChanged(iBEX::BodyPart,bool)));
        }
    }
}

NewPatientDialog::~NewPatientDialog()
{
    delete ui;
}

void NewPatientDialog::ActivateOkBtn()
{
    if(
        !ui->accessionNumberLineEdit->text().isEmpty() &&
        !ui->lastNameLineEdit->text().isEmpty() &&
        !ui->patientIdLineEdit->text().isEmpty())
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled( true );
    else
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled( false );

}
// when a click on a body part scene happens this SLOT is called multiple times.
void NewPatientDialog::OnBodyPartStatusChanged(iBEX::BodyPart bodyPart, bool isSelected)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<iBEX::BodyPart>();
    QString bodyPartStr(metaEnum.valueToKey(static_cast<int>(bodyPart)));

    if(isSelected)
    {
        if(!_selectedBodyPartList.contains(bodyPartStr))
        {
            _selectedBodyPartList.append(bodyPartStr);
        }
    }
    else
    {
        if(_selectedBodyPartList.contains(bodyPartStr))
        {
            _selectedBodyPartList.removeAll(bodyPartStr);
        }
    }

    if(_numberOfselectedBodyParts != _selectedBodyPartList.count())
    {
        _numberOfselectedBodyParts = _selectedBodyPartList.count();
        qDebug()<<"---------------------------";
        foreach (auto item, _selectedBodyPartList) {

            qDebug()<<"The selected bodypart: "<<item;
        }
      //qDebug()<<"Number of elements: "<< _selectedBodyPartList.count();
    }

}




void NewPatientDialog::on_buttonBox_accepted()
{
    demographics[DemographyKeys::LastName]=ui->lastNameLineEdit->text();
    demographics[DemographyKeys::FirstName]=ui->firstNameLineEdit->text();
    demographics[DemographyKeys::MiddleName]=ui->middleNameLineEdit->text();
    demographics[DemographyKeys::PatientID]=ui->patientIdLineEdit->text();
    demographics[DemographyKeys::DOB]=ui->dateEdit->date().toString(Qt::ISODate);

    switch(ui->genderComboBox->currentIndex())
    {
    case 0:
        demographics[DemographyKeys::Gender] = "M";
        break;
    case 1:
        demographics[DemographyKeys::Gender] = "F";
        break;
    case 2:
        demographics[DemographyKeys::Gender] = "U";
        break;
    }

    demographics[DemographyKeys::ReferrinPhysician]= ui->referringPhysicianLineEdit->text();
    demographics[DemographyKeys::AdmissionNumber]= ui->admissionNumberLineEdit->text();
    demographics[DemographyKeys::AccessionNumber]= ui->accessionNumberLineEdit->text();

    qDebug()<<demographics[DemographyKeys::LastName];
    qDebug()<<demographics[DemographyKeys::FirstName];
    qDebug()<<demographics[DemographyKeys::MiddleName];
    qDebug()<<demographics[DemographyKeys::PatientID];
    qDebug()<<demographics[DemographyKeys::DOB];
    qDebug()<<demographics[DemographyKeys::Gender];
    qDebug()<<demographics[DemographyKeys::ReferrinPhysician];
    qDebug()<<demographics[DemographyKeys::AdmissionNumber];
    qDebug()<<demographics[DemographyKeys::AccessionNumber];
}
