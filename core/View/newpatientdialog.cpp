#include "newpatientdialog.h"
#include "ui_newpatientdialog.h"

#include <QRegExpValidator>
#include <QPushButton>
#include <QSharedPointer>
#include <QDateTime>
#include <QMetaEnum>

#include "Utils/dicomtools.h"
#include "Model/registrationformmodel.h"
#include "Utils/logmgr.h"
#include "Model/DICOM_ENUMS.h"


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
    connect(ui->lastNameLineEdit,SIGNAL(textChanged(QString)),this,SLOT(RefreshOkBtn()));
    connect(ui->patientIdLineEdit,SIGNAL(textChanged(QString)),this,SLOT(RefreshOkBtn()));
    connect(ui->accessionNumberLineEdit,SIGNAL(textChanged(QString)),this,SLOT(RefreshOkBtn()));


    scene = new QGraphicsScene(this);
    QImage sourceImage;
    sourceImage.load(":/assets/images/human.jpg");
    scene->addPixmap(QPixmap::fromImage(sourceImage));

    ui->graphicsView->setScene(scene);

    head =new BodyPartSelectionSquare(60,2,50,60,this);
    head->setToolTip("head");
    head->SetSelectionSquareName(iBEX::BODY_PART::HEAD);

    thorax=new BodyPartSelectionSquare(55,64,60,55,this);
    thorax->setToolTip("thorax");
    thorax->SetSelectionSquareName(iBEX::BODY_PART::THORAX);

    abdomen=new BodyPartSelectionSquare(55,121,60,35,this);
    abdomen->setToolTip("abdomen");
    abdomen->SetSelectionSquareName(iBEX::BODY_PART::ABDOMEN);

    pelvis=new BodyPartSelectionSquare(52,158,64,30,this);
    pelvis->setToolTip("pelvis");
    pelvis->SetSelectionSquareName(iBEX::BODY_PART::PELVIS);

    fermur=new BodyPartSelectionSquare(52,190,64,44,this);
    fermur->setToolTip("fermur");
    fermur->SetSelectionSquareName(iBEX::BODY_PART::FERMUR);

    knee=new BodyPartSelectionSquare(52,236,64,40,this);
    knee->setToolTip("knee");
    knee->SetSelectionSquareName(iBEX::BODY_PART::KNEE);

    tibia=new BodyPartSelectionSquare(52,278,64,50,this);
    tibia->setToolTip("tibia");
    tibia->SetSelectionSquareName(iBEX::BODY_PART::TIBIA);

    ankle=new BodyPartSelectionSquare(52,330,64,15,this);
    ankle->setToolTip("ankel");
    ankle->SetSelectionSquareName(iBEX::BODY_PART::ANKEL);

    foot=new BodyPartSelectionSquare(52,347,66,11,this);
    foot->setToolTip("foot");
    foot->SetSelectionSquareName(iBEX::BODY_PART::FOOT);

    finger=new BodyPartSelectionSquare(8,194,28,14,this);
    finger->setToolTip("finger");
    finger->SetSelectionSquareName(iBEX::BODY_PART::FINGER);

    hand=new BodyPartSelectionSquare(8,176,28,16,this);
    hand->setToolTip("hand");
    hand->SetSelectionSquareName(iBEX::BODY_PART::HAND);

    wrist=new BodyPartSelectionSquare(8,165,28,10,this);
    wrist->setToolTip("wrist");
    wrist->SetSelectionSquareName(iBEX::BODY_PART::WRIST);

    shoulder=new BodyPartSelectionSquare(35,55,20,25,this);
    shoulder->setToolTip("shoulder");
    shoulder->SetSelectionSquareName(iBEX::BODY_PART::SHOULDER);

    elbow=new BodyPartSelectionSquare(28,110,20,25,this);
    elbow->setToolTip("elbow");
    elbow->SetSelectionSquareName(iBEX::BODY_PART::ELBOW);

    scene->addItem(head);
    scene->addItem(thorax);
    scene->addItem(abdomen);
    scene->addItem(pelvis);
    scene->addItem(fermur);
    scene->addItem(knee);
    scene->addItem(tibia);
    scene->addItem(ankle);
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
            &BodyPartSelectionSquare::NotifyBodyPartSelectionChanged,
            this, &NewPatientDialog::OnBodyPartStatusChanged);
        }
    }

    ui->accessionNumberLineEdit->setText(DicomTools::GenerateAccessionNumber());
}

void NewPatientDialog::SetFormModel(RegistrationFormModel &formModel)
{
    m_model= &formModel;
    QMetaEnum _metaEnum = QMetaEnum::fromType<iBEX::GENDER>();
    for(int indx=0;indx<_metaEnum.keyCount();indx++)
    {
         QString _str = QString::fromUtf8(_metaEnum.valueToKey(indx));
         ui->genderComboBox->addItem(_str);
    }

    _metaEnum = QMetaEnum::fromType<iBEX::PATIENT_POSISTION>();
    for(int indx=0;indx<_metaEnum.keyCount();indx++)
    {
         QString _str = QString::fromUtf8(_metaEnum.valueToKey(indx));
         ui->viewComboBox->addItem(_str);
    }
}

void NewPatientDialog::WireConnections()
{

}

void NewPatientDialog::ResetForm()
{
    ui->lastNameLineEdit->clear();
    ui->middleNameLineEdit->clear();
    ui->firstNameLineEdit->clear();
    ui->patientIdLineEdit->clear();
    ui->genderComboBox->setCurrentIndex(0);
    ui->referringPhysicianLineEdit->clear();
    ui->accessionNumberLineEdit->setText(DicomTools::GenerateAccessionNumber());
    ui->admissionNumberLineEdit->clear();
    ui->viewComboBox->setCurrentIndex(0);

}


NewPatientDialog::~NewPatientDialog()
{
    delete ui;
}

void NewPatientDialog::RefreshOkBtn()
{
    if( !ui->accessionNumberLineEdit->text().isEmpty() &&
        !ui->lastNameLineEdit->text().isEmpty() &&
        !ui->patientIdLineEdit->text().isEmpty())
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled( true );
    else
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled( false );

    // protect against nullptr during construction time
    if(m_model!= nullptr)
    {
        m_model->UpdatePatientFirstName(ui->lastNameLineEdit->text());
        m_model->UpdatePatientLastName(ui->firstNameLineEdit->text());
        m_model->UpdatePatientMiddleName(ui->middleNameLineEdit->text());
        m_model->UpdatePatientId(ui->patientIdLineEdit->text());
        m_model->UpdatePatientDOB(ui->dateEdit->date().toString(Qt::ISODate));

        QMetaEnum _metaEnum =QMetaEnum::fromType<iBEX::GENDER>();
        QString _genderStr = QString::fromUtf8(_metaEnum.valueToKey(ui->genderComboBox->currentIndex()));
        m_model->UpdatePatientGender(_genderStr);
        m_model->UpdateReferringPhysician(ui->referringPhysicianLineEdit->text());
        m_model->UpdateAdmissionNumber(ui->admissionNumberLineEdit->text());
        m_model->UpdateAccessionNumber(ui->accessionNumberLineEdit->text());
        LogMgr::instance()->LogSysDebug(tr("NewPatientFormModel is updated."));

    }

}
// when a click on a body part scene happens this SLOT is called multiple times.
void NewPatientDialog::OnBodyPartStatusChanged(iBEX::BODY_PART bodyPart, bool isSelected)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<iBEX::BODY_PART>();
    QString bodyPartStr= QString::fromUtf8(metaEnum.valueToKey(static_cast<int>(bodyPart)));
    AnatomicRegionElement _element;
    _element.SetBodyPart(bodyPart);
    _element.setCodeMeaning(bodyPartStr);
    //_element.setCodeMeaning(...);

    if(isSelected)
    {
        if(!m_model->IsContainRegion(_element))
        {
            int _index = ui->viewComboBox->currentIndex();
            LogMgr::instance()->LogSysInfo("Current view index is:"+ QString::number(_index));
            iBEX::PATIENT_POSISTION _view = static_cast<iBEX::PATIENT_POSISTION>(_index);
            _element.SetBodyPartView(_view);
            m_model->AppendRegion(_element);
        }
    }
    else
    {
        if(m_model->IsContainRegion(_element))
        {
            m_model->RemoveRegion(_element);
        }
    }

}

void NewPatientDialog::on_buttonBox_accepted()
{
    LogMgr::instance()->LogAppInfo(tr("the patient registration form is completed"));
    LogMgr::instance()->LogSysInfo(tr("patient registration is completed"));
    emit NotifyRegistrationFormCompleted();
}

void NewPatientDialog::on_lastNameLineEdit_editingFinished()
{
    m_model->UpdatePatientLastName(ui->lastNameLineEdit->text());
}

void NewPatientDialog::on_firstNameLineEdit_editingFinished()
{
    m_model->UpdatePatientFirstName(ui->firstNameLineEdit->text());
}

void NewPatientDialog::on_middleNameLineEdit_editingFinished()
{

    m_model->UpdatePatientMiddleName(ui->middleNameLineEdit->text());
}

void NewPatientDialog::on_patientIdLineEdit_editingFinished()
{
    m_model->UpdatePatientId(ui->patientIdLineEdit->text());
}

void NewPatientDialog::on_dateEdit_editingFinished()
{
    m_model->UpdatePatientDOB(ui->dateEdit->date().toString(Qt::ISODate));
}

void NewPatientDialog::on_genderComboBox_currentIndexChanged(int index)
{
    switch(index)
    {
    case 0:
        m_model->UpdatePatientGender("M");
        break;
    case 1:
        m_model->UpdatePatientGender("F");
        break;
    case 2:
        m_model->UpdatePatientGender("U");
        break;
    }
}

void NewPatientDialog::on_referringPhysicianLineEdit_editingFinished()
{
    m_model->UpdateReferringPhysician(ui->referringPhysicianLineEdit->text());
}

void NewPatientDialog::on_admissionNumberLineEdit_editingFinished()
{
    m_model->UpdateAdmissionNumber(ui->admissionNumberLineEdit->text());
}

void NewPatientDialog::on_accessionNumberLineEdit_editingFinished()
{
    m_model->UpdateAccessionNumber(ui->accessionNumberLineEdit->text());
}



void NewPatientDialog::on_buttonBox_rejected()
{
    m_model->ClearForm();
}
