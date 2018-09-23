#include "worklistdialog.h"
#include "ui_worklistdialog.h"
#include <QTcpSocket>
// From Dcmtk:
#include <dcmtk/config/osconfig.h>    /* make sure OS specific configuration is included first */

#include "dcmtk/ofstd/ofstdinc.h"
#include "dcmtk/ofstd/ofstd.h"
#include "dcmtk/ofstd/ofconapp.h"
#include <dcmtk/ofstd/ofstream.h>
#include <dcmtk/dcmdata/dctk.h>
#include <dcmtk/dcmdata/dcfilefo.h>
#include "dcmtk/dcmnet/dfindscu.h"
#include <dcmtk/dcmdata/dcistrmz.h>    /* for dcmZlibExpectRFC1950Encoding */

#include "dcmtk/ofstd/ofstdinc.h"

#include "dcmtk/dcmnet/dimse.h"
#include "dcmtk/dcmnet/diutil.h"
#include "dcmtk/dcmdata/dcdict.h"
#include "dcmtk/dcmdata/dcuid.h"      /* for dcmtk version name */
#include "dcmtk/dcmdata/dcuid.h"

#include <QtXml>
#include <QFile>
#include <QMap>
#include <QSqlField>
#include <QSqlRecord>
#include "dicomtaglist.h"

#define OFFIS_CONSOLE_APPLICATION "findscu"

static OFLogger findscuLogger = OFLog::getLogger("dcmtk.apps." OFFIS_CONSOLE_APPLICATION);

static char rcsid[] = "$dcmtk: " OFFIS_CONSOLE_APPLICATION " v"
        OFFIS_DCMTK_VERSION " " OFFIS_DCMTK_RELEASEDATE " $";

/* default application titles */
#define APPLICATIONTITLE        "FINDSCU"
#define PEERAPPLICATIONTITLE    "ANY-SCP"
#define SITE_INSTANCE_UID_ROOT  007
#define SHORTCOL 4
#define LONGCOL 20

OFList<OFString>      fileNameList;
OFBool                opt_abortAssociation = OFFalse;
const char *          opt_abstractSyntax = UID_FINDModalityWorklistInformationModel;
int                   opt_acse_timeout = 3000;
T_DIMSE_BlockingMode  opt_blockMode = DIMSE_BLOCKING;
OFCmdSignedInt        opt_cancelAfterNResponses = -1;
int                   opt_dimse_timeout = 0;
int                   opt_outputResponsesToLogger = 0;
DcmFindSCUExtractMode opt_extractResponses=FEM_singleXMLFile;
OFBool                opt_extractResponsesToFile = OFTrue;
OFString              opt_outputDirectory = ".";
OFCmdUnsignedInt      opt_maxReceivePDULength = ASC_DEFAULTMAXPDU;
E_TransferSyntax      opt_networkTransferSyntax = EXS_Unknown;
const char *          opt_ourTitle = APPLICATIONTITLE;
const char *          opt_peer="localhost";
const char *          opt_peerTitle = PEERAPPLICATIONTITLE;
OFCmdUnsignedInt      opt_port = 107;
OFCmdUnsignedInt      opt_repeatCount = 1;
OFBool                opt_secureConnection = OFFalse; /* default: no secure connection */
OFList<OFString>      overrideKeys;
OFString              opt_extractXMLFilename="Out.xml";
QTcpSocket * socket;
DcmFindSCU findscu;


void  WorkListDialog::InitializeTableViewColumns()
{

    ui->tableView->setColumnHidden(studyid,true);
    ui->tableView->setColumnHidden(accessionnum,false);
    ui->tableView->setColumnHidden(patientid, false);
    ui->tableView->setColumnHidden(patientname,false);
    ui->tableView->setColumnHidden(otherpatientid,true);
    ui->tableView->setColumnHidden(otherpatientname, true);
    ui->tableView->setColumnHidden(age,true);
    ui->tableView->setColumnHidden(occupation,true);
    ui->tableView->setColumnHidden(dob, false);
    ui->tableView->setColumnHidden(sex, false);
    ui->tableView->setColumnHidden(medicalalert,true);
    ui->tableView->setColumnHidden(contrastallergies, true);
    ui->tableView->setColumnHidden(smokingstatus,true);
    ui->tableView->setColumnHidden(patientcomments,true);
    ui->tableView->setColumnHidden(patienthistory,true);
    ui->tableView->setColumnHidden(pregnancystatus,true);
    ui->tableView->setColumnHidden(lastmenstrualdate,true);
    ui->tableView->setColumnHidden(specialneeds,true);
    ui->tableView->setColumnHidden(patientstate,true);
    ui->tableView->setColumnHidden(admittingtime,true);
    ui->tableView->setColumnHidden(admissionid,false);
    ui->tableView->setColumnHidden(visitdate,true);
    ui->tableView->setColumnHidden(visitstatus,true);
    ui->tableView->setColumnHidden(visitcomments,false);
    ui->tableView->setColumnHidden(refphysician,false);
    ui->tableView->setColumnHidden(scheduledstartdatetime,true);
    ui->tableView->setColumnHidden(scheduledaetitle,false);
    ui->tableView->setColumnHidden(regsource,true);
    ui->tableView->setColumnHidden(studyinstanceuid,true);
    ui->tableView->setColumnHidden(studystatus,false);
    ui->tableView->setColumnHidden(studypriority,true);
    ui->tableView->setColumnHidden(studycomments,true);
    ui->tableView->setColumnHidden(requestingphysician, false);
    ui->tableView->setColumnHidden(requestedproceduredescription,true);
    ui->tableView->setColumnHidden(requestedcontrastagent,true);
    ui->tableView->setColumnHidden(studystartdatetime,true);
    ui->tableView->setColumnHidden(studycompletiondatetime,true);
    ui->tableView->setColumnHidden(scheduledprocedurestepid,true);
    ui->tableView->setColumnHidden(scheduledprocedurestepdescription,false);
    ui->tableView->setColumnHidden(requestedprocedureid, false);
    ui->tableView->setColumnHidden(premedication, true);
    ui->tableView->setColumnHidden(procedurecode, false);
    ui->tableView->setColumnHidden(procedurecodevalue,false);
    ui->tableView->setColumnHidden(procedurecodemeaning,true);
    ui->tableView->setColumnHidden(mppsinstanceuid,true);
    ui->tableView->setColumnHidden(mppsstatus,true);
    ui->tableView->setColumnHidden(modality,true);
    ui->tableView->setColumnHidden(operatorname,false);
    ui->tableView->setColumnHidden(reserve1,true);
    ui->tableView->setColumnHidden(reserve2,true);
    ui->tableView->setColumnHidden(reserve3,true);
}
void  WorkListDialog::IntializeTableViewModel()
{
    model->setHeaderData(studyid, Qt::Horizontal, tr("Study ID"));
    model->setHeaderData(accessionnum,Qt::Horizontal, tr("Accession"));
    model->setHeaderData(patientid,Qt::Horizontal, tr("Patıent ID"));
    model->setHeaderData(patientname,Qt::Horizontal, tr("Patient Name"));
    model->setHeaderData(otherpatientid,Qt::Horizontal, tr("Other Patient ID"));
    model->setHeaderData(otherpatientname, Qt::Horizontal, tr("Other Patient Name"));
    model->setHeaderData(age,Qt::Horizontal, tr("Age"));
    model->setHeaderData(occupation,Qt::Horizontal, tr("Occupation"));
    model->setHeaderData(dob,Qt::Horizontal, tr("Date Of Birth"));
    model->setHeaderData(sex,Qt::Horizontal, tr("Gender"));
    model->setHeaderData(medicalalert,Qt::Horizontal, tr("Medical Alert"));
    model->setHeaderData(contrastallergies,Qt::Horizontal, tr("Contrast Alergies"));
    model->setHeaderData(smokingstatus,Qt::Horizontal, tr("Smoking Status"));
    model->setHeaderData(patientcomments,Qt::Horizontal, tr("Patient Comments"));
    model->setHeaderData(patienthistory,Qt::Horizontal, tr("Patient History"));
    model->setHeaderData(pregnancystatus,Qt::Horizontal, tr("Pragnancy"));
    model->setHeaderData(lastmenstrualdate,Qt::Horizontal, tr("Last Menstrual Date"));
    model->setHeaderData(specialneeds,Qt::Horizontal, tr("Special Needs"));
    model->setHeaderData(patientstate,Qt::Horizontal, tr("Patient State"));
    model->setHeaderData(admittingtime,Qt::Horizontal, tr("Admitting Time"));
    model->setHeaderData(admissionid,Qt::Horizontal, tr("Admission ID"));
    model->setHeaderData(visitdate,Qt::Horizontal, tr("Visit Date"));
    model->setHeaderData(visitstatus,Qt::Horizontal, tr("Visit Status"));
    model->setHeaderData(visitcomments,Qt::Horizontal, tr("Visit Comments"));
    model->setHeaderData(refphysician,Qt::Horizontal, tr("Referring Physician"));
    model->setHeaderData(scheduledstartdatetime,Qt::Horizontal, tr("Scheduled Start Date And Time"));
    model->setHeaderData(scheduledaetitle,Qt::Horizontal, tr("Scheduled AE-title"));
    model->setHeaderData(regsource,Qt::Horizontal, tr("Regsource"));
    model->setHeaderData(studyinstanceuid,Qt::Horizontal, tr("Study Instance uid"));
    model->setHeaderData(studystatus,Qt::Horizontal, tr("Study Status"));
    model->setHeaderData(studypriority, Qt::Horizontal, tr("Study Priority"));
    model->setHeaderData(studycomments, Qt::Horizontal, tr("Study Comments"));
    model->setHeaderData(requestingphysician,Qt::Horizontal, tr("Requesting Physician"));
    model->setHeaderData(requestedproceduredescription,Qt::Horizontal, tr("Requested Procedure Description"));
    model->setHeaderData(requestedcontrastagent, Qt::Horizontal, tr("requested contrast agent"));
    model->setHeaderData(studystartdatetime,Qt::Horizontal, tr("study start date time"));
    model->setHeaderData(studycompletiondatetime,Qt::Horizontal, tr("Study completion date and time"));
    model->setHeaderData(scheduledprocedurestepid,Qt::Horizontal, tr("Scheduled Procedure Step id"));
    model->setHeaderData(scheduledprocedurestepdescription,Qt::Horizontal, tr("Scheduled Procedure Step Description"));
    model->setHeaderData(requestedprocedureid,Qt::Horizontal, tr("requested procedure id"));
    model->setHeaderData(premedication, Qt::Horizontal,  tr("premedication"));
    model->setHeaderData(procedurecode,Qt::Horizontal,   tr("procedure code"));
    model->setHeaderData(procedurecodevalue,Qt::Horizontal,tr("procedure code value"));
    model->setHeaderData(procedurecodemeaning,Qt::Horizontal,tr("procedure code meaning"));
    model->setHeaderData(mppsinstanceuid,Qt::Horizontal,tr("mpps instance uid"));
    model->setHeaderData(mppsstatus, Qt::Horizontal, tr("mpps status"));
    model->setHeaderData(modality, Qt::Horizontal, tr("modality"));
    model->setHeaderData(operatorname,Qt::Horizontal,  tr("operator name"));
    model->setHeaderData(reserve1,  Qt::Horizontal,    tr("reserve1"));
    model->setHeaderData(reserve2, Qt::Horizontal,  tr("reserve2"));
    model->setHeaderData(reserve3 ,Qt::Horizontal,   tr("reserve3"));

}

void WorkListDialog::ParsRISResponseAndInsertIntoTableModel()
{

    QFile settingFile("./out.xml");

    if(!settingFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can not open WORKLIST RESPONSE file";
        return;
    }
    else
    {
        //get the root element
        QDomDocument document;

        if(!document.setContent(&settingFile))
        {
            qDebug() << "Failed to load document";
            return;
        }
        settingFile.close();

        QDomElement root = document.firstChildElement();
        //Extract records
        QDomNodeList _recordList = root.elementsByTagName("data-set");

        for(int recordIndex = 0; recordIndex < _recordList.count(); recordIndex++)
        {
            QDomNode _record = _recordList.at(recordIndex);

            //Extract elements inside each record.
            QDomNodeList _elementsList = _record.toElement().elementsByTagName("element");

            // create a QSqlRecord for each record inside recordList.
            QSqlRecord record= model->record();

            // initialize the record with dummy data
            for(int a=0;a<=record.count();a++)
            {
                record.setValue(a,QString::number(recordIndex));
            }

            for(int elementIndex= 0; elementIndex<_elementsList.count();elementIndex++)
            {

                int temp = WorkListFieldTag.key(_elementsList.at(elementIndex).toElement().attribute("tag"),-1);

                // check if the tag of the elemt exists within database
                if(temp!=-1)
                {
                    record.setValue(temp,_elementsList.at(elementIndex).firstChild().nodeValue());
                }
                else
                {
                    record.setValue(elementIndex,QString::number(elementIndex));
                }
                //                qDebug()<<"The tag: "<<nodeList.at(j).toElement().attribute("tag")
                //                        <<"with the value: "<<nodeList.at(j).firstChild().nodeValue()
                //                        <<"The id is: "<<WorkListFieldTag.key(nodeList.at(j).toElement().attribute("tag"),-1);
            }
            model->insertRecord(-1,record);
//            qDebug()<<"----------------------";
//            for(int k=0;k< record.count();k++)
//            {
//                qDebug()<<"The field is: "<< record.fieldName(k)<<" value:"<<record.value(k).toString();
//            }

        }

        model->select();
    }
}
WorkListDialog::WorkListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorkListDialog)
{
    ui->setupUi(this);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    qDebug()<<"constructing socket object";
    socket = new QTcpSocket();

    _database = QSqlDatabase::addDatabase("QSQLITE");
    _database.setDatabaseName("./database/database.db");
    if (!_database.open())
    {
        qDebug() << "Failed to open the database";
        return ;
    }
    else
    {
        qDebug()<<"Database connection is made...";
    }

    model = new QSqlTableModel(new QSqlTableModel(this,_database));
    model->setTable("WorkListTbl");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);



    IntializeTableViewModel();
    ui->tableView->setModel(model);
    InitializeTableViewColumns();

}

WorkListDialog::~WorkListDialog()
{
    _database.close();
    delete ui;
}

void WorkListDialog::on_reloadBtn_clicked()
{
    /*
    ** By default. don't let "dcmdata" remove trailing padding or
    ** perform other manipulations. We want to see the real data.
    */
    OFBool opt_automaticDataCorrection = OFFalse;

    OFString temp_str;
    //    OFConsoleApplication app(OFFIS_CONSOLE_APPLICATION , "DICOM query (C-FIND) SCU", rcsid);
    /* evaluate command line */
    //    prepareCmdLineArgs(argc, argv, OFFIS_CONSOLE_APPLICATION);

    if (opt_outputResponsesToLogger == 0)
    {
        // never show C-FIND responses
        OFLog::getLogger(DCMNET_LOGGER_NAME ".responses").setLogLevel(OFLogger::OFF_LOG_LEVEL);
    }
    else
    {
        // always show C-FIND responses
        OFLog::getLogger(DCMNET_LOGGER_NAME ".responses").setLogLevel(OFLogger::INFO_LOG_LEVEL);
    }


    /* print resource identifier */
    OFLOG_DEBUG(findscuLogger, rcsid << OFendl);

    /* make sure data dictionary is loaded */
    if (!dcmDataDict.isDictionaryLoaded())
    {
        qDebug()<<"no data dictionary loaded, check environment variable: "
               << DCM_DICT_ENVIRONMENT_VARIABLE;
    }

    /* make sure that output directory can be used (if needed) */
    if (opt_extractResponsesToFile)
    {
        if (!OFStandard::dirExists(opt_outputDirectory))
        {
            qDebug()<<"specified output directory does not exist";
        }
        else if (!OFStandard::isWriteable(opt_outputDirectory))
        {
            qDebug()<<"specified output directory is not writeable";
        }
    }

    // declare findSCU handler and initialize network
    OFCondition cond = findscu.initializeNetwork(opt_acse_timeout);

    if (cond.bad())
    {
        DimseCondition::dump(temp_str, cond);
        qDebug()<< QString::fromLatin1(temp_str.c_str()).toLatin1().data();
    }


    overrideKeys.push_back("0008,0005");
    overrideKeys.push_back("0008,0010");
    overrideKeys.push_back("0008,0050");
    overrideKeys.push_back("0008,0060");
    overrideKeys.push_back("0008,0090");
    overrideKeys.push_back("0008,1110");

    overrideKeys.push_back("0010,0010");
    overrideKeys.push_back("0010,0020");
    overrideKeys.push_back("0010,0030");
    overrideKeys.push_back("0010,0040");
    overrideKeys.push_back("0010,1030");
    overrideKeys.push_back("0010,2000");
    overrideKeys.push_back("0010,2110");

    overrideKeys.push_back("0040,1001");

    // do the main work: negotiate network association, perform C-FIND transaction,
    // process results, and finally tear down the association.
    cond = findscu.performQuery(
                opt_peer,
                opt_port,
                opt_ourTitle,
                opt_peerTitle,
                opt_abstractSyntax,
                opt_networkTransferSyntax,
                opt_blockMode,
                opt_dimse_timeout,
                opt_maxReceivePDULength,
                opt_secureConnection,
                opt_abortAssociation,
                opt_repeatCount,
                opt_extractResponses,
                opt_cancelAfterNResponses,
                &overrideKeys,
                NULL, /* we want to use the default callback */
                &fileNameList,
                opt_outputDirectory.c_str(),
                opt_extractXMLFilename.c_str());

    if(cond.bad())
    {
        qDebug()<<"Cannot perform query";
    }


    ////////////////////////////////////////////////
    QFile file("./Out.xml");

    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug()<<"Can not open worklist configuration file";
        return;
    }
    else
    {
        qDebug()<<"worklist configuration file successfully opened.";
        //get the root element
        QDomDocument document;

        if(!document.setContent(&file))
        {
            qDebug() << "Failed to load document";
            return;
        }
        file.close();
        //QDomElement root = document.firstChildElement();
        //QStringList strList = ListElements3(root,"element","tag");
        ParsRISResponseAndInsertIntoTableModel();

    }



    //#ifdef HAVE_WINSOCK_H
    //    WSACleanup();
    //#endif
}

void WorkListDialog::on_tableView_doubleClicked(const QModelIndex &index)
{
    selectedRecord = model->record(index.row());
    this->close();
    emit NotifyRecoredSelected(selectedRecord);

}
