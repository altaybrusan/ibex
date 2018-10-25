// From Dcmtk:
#include "dcmtk/config/osconfig.h"      /* make sure OS specific configuration is included first */
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

// From Qt
#include <QtXml>
#include <QFile>
#include <QMap>
#include <QSqlRecord>

#include "worklistmgr.h"
#include "Model/worklisttbl.h"
#include "View/worklistdialog.h"
#include "Model/worklistmodel.h"
#include "Utils/logmgr.h"
#include "Model/worklistquerymodel.h"
#include "Utils/settingsprovider.h"

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
const char *          opt_peer="";
const char *          opt_peerTitle = PEERAPPLICATIONTITLE;
OFCmdUnsignedInt      opt_port = 107;
OFCmdUnsignedInt      opt_repeatCount = 1;
OFBool                opt_secureConnection = OFFalse; /* default: no secure connection */
OFList<OFString>      overrideKeys;
OFString              opt_extractXMLFilename="Out.xml";
DcmFindSCU findscu;


WorklistMgr::WorklistMgr(QObject *parent, WorklistDialog &dialog, WorklistModel& model, QString settingFile) :
    QObject(parent),
    m_dialog(dialog),
    m_model(model),
    m_settingsFileName(settingFile)
{
    SettingsProvider _provider(this);
    _provider.UpdateSettingFile(m_settingsFileName);

    if(!_provider.OpenSettingFile())
    {
        LogMgr::instance()->LogSysError(tr("Can not open Worklist server setting file."));
        return;
    }

    if(!_provider.LoadSettingFile())
    {
        LogMgr::instance()->LogSysError(tr("worklist server setting file is not valid."));
        return;
    }

    LogMgr::instance()->LogSysInfo(tr("worklist settings are loaded successfully."));

    auto root =_provider.GetRootElement();
    QStringList strList = _provider.ListElements(root,"Server","IP");
    LogMgr::instance()->LogSysInfo(strList.at(0));
    opt_peer = ((QString)strList.at(0)).toStdString().c_str();


//    strList = _provider.ListElements(root,"Server","Port");
//    m_worklisSettingstDlg.SetWorklistServerPort(strList.at(0));

//    strList = _provider.ListElements(root,"Server","AETitle");
//    m_worklisSettingstDlg.SetWorklistServerAETitle(strList.at(0));

    connect(&m_dialog,SIGNAL(NotifyFetchRISRequestTriggered()),this,SLOT(OnFetchRISRequestReceived()));
}

void WorklistMgr::OnFetchRISRequestReceived()
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
  ParsRISResponseAndInsertIntoTableModel();

}

void WorklistMgr::OnNewRowIsSelected(int row)
{
    //selectedRecord = model->record(index.row());
    //this->close();
}

void WorklistMgr::OnActivateWorklistDialog()
{

  m_model.MakeModel();
  m_dialog.SetViewModel(m_model.GetModel());
  InitializeWorklistTableModel();
  InitializeWorklistTableView();
  LogMgr::instance()->LogSysInfo("worklist model is not empty");
  m_dialog.show();
}

void WorklistMgr::InitializeWorklistTableView()
{
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::studyid,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::accessionnum,false);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::patientid, false);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::patientname,false);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::otherpatientid,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::otherpatientname, true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::age,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::occupation,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::dob, false);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::sex, false);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::medicalalert,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::contrastallergies, true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::smokingstatus,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::patientcomments,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::patienthistory,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::pregnancystatus,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::lastmenstrualdate,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::specialneeds,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::patientstate,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::admittingtime,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::admissionid,false);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::visitdate,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::visitstatus,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::visitcomments,false);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::refphysician,false);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::scheduledstartdatetime,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::scheduledaetitle,false);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::regsource,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::studyinstanceuid,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::studystatus,false);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::studypriority,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::studycomments,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::requestingphysician, false);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::requestedproceduredescription,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::requestedcontrastagent,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::studystartdatetime,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::studycompletiondatetime,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::scheduledprocedurestepid,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::scheduledprocedurestepdescription,false);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::requestedprocedureid, false);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::premedication, true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::procedurecode, false);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::procedurecodevalue,false);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::procedurecodemeaning,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::mppsinstanceuid,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::mppsstatus,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::modality,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::operatorname,false);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::reserve1,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::reserve2,true);
    m_dialog.SetColumnHidden(WORKLIST_FIELDS::reserve3,true);
}

void WorklistMgr::InitializeWorklistTableModel()
{
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::studyid, tr("Study ID"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::accessionnum, tr("Accession"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::patientid, tr("Patient ID"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::patientname, tr("Patient Name"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::otherpatientid, tr("Other Patient ID"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::otherpatientname, tr("Other Patient Name"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::age, tr("Age"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::occupation, tr("Occupation"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::dob, tr("Date Of Birth"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::sex, tr("Gender"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::medicalalert, tr("Medical Alert"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::contrastallergies, tr("Contrast Alergies"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::smokingstatus, tr("Smoking Status"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::patientcomments, tr("Patient Comments"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::patienthistory, tr("Patient History"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::pregnancystatus, tr("Pragnancy"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::lastmenstrualdate, tr("Last Menstrual Date"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::specialneeds, tr("Special Needs"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::patientstate, tr("Patient State"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::admittingtime, tr("Admitting Time"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::admissionid, tr("Admission ID"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::visitdate, tr("Visit Date"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::visitstatus, tr("Visit Status"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::visitcomments, tr("Visit Comments"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::refphysician, tr("Referring Physician"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::scheduledstartdatetime, tr("Scheduled Start Date And Time"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::scheduledaetitle, tr("Scheduled AE-title"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::regsource, tr("Regsource"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::studyinstanceuid, tr("Study Instance uid"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::studystatus, tr("Study Status"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::studypriority, tr("Study Priority"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::studycomments, tr("Study Comments"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::requestingphysician, tr("Requesting Physician"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::requestedproceduredescription, tr("Requested Procedure Description"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::requestedcontrastagent, tr("requested contrast agent"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::studystartdatetime, tr("study start date time"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::studycompletiondatetime, tr("Study completion date and time"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::scheduledprocedurestepid, tr("Scheduled Procedure Step id"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::scheduledprocedurestepdescription, tr("Scheduled Procedure Step Description"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::requestedprocedureid, tr("Requested Procedure id"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::premedication,  tr("Premedication"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::procedurecode,   tr("Procedure Code"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::procedurecodevalue,tr("Procedure Code Value"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::procedurecodemeaning,tr("Procedure Code Meaning"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::mppsinstanceuid,tr("mpps Instance uid"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::mppsstatus, tr("MPPS Status"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::modality, tr("Modality"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::operatorname,  tr("Operator Name"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::reserve1,    tr("Reserve1"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::reserve2,  tr("Reserve2"));
    m_dialog.SetColumnTitle(WORKLIST_FIELDS::reserve3 ,   tr("Reserve3"));

}

void WorklistMgr::ParsRISResponseAndInsertIntoTableModel()
{
    QFile settingFile("./out.xml");
    WorklistQueryModel _queryModel;
    if(!settingFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        LogMgr::instance()->LogSysError(tr("Can not open WORKLIST RESPONSE file"));
        return;
    }
    else
    {
        //get the root element
        QDomDocument document;

        if(!document.setContent(&settingFile))
        {
            LogMgr::instance()->LogSysError(tr("Failed to load document")) ;
            return;
        }
        settingFile.close();

        QDomElement root = document.firstChildElement();

        //Extract records: this xml parser is hard coded
        // in the next iteration feed it from builder.
        QDomNodeList _recordList = root.elementsByTagName("data-set");
        for(int recordIndex = 0; recordIndex < _recordList.count(); recordIndex++)
        {
            QDomNode _record = _recordList.at(recordIndex);

            //Extract elements inside each record.
            QDomNodeList _elementsList = _record.toElement().elementsByTagName("element");

            // create a QSqlRecord for each record inside recordList.
            QSqlRecord record= m_model.GetModel()->record();

            // initialize the record with dummy data
            for(int a=0;a<=record.count();a++)
            {
                record.setValue(a,QString::number(recordIndex));
            }

            for(int elementIndex= 0; elementIndex<_elementsList.count();elementIndex++)
            {
                int temp = _queryModel.WorkListFieldTags.key(_elementsList.at(elementIndex).toElement().attribute("tag"),-1);

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
            m_model.GetModel()->insertRecord(-1,record);
            //            qDebug()<<"----------------------";
            //            for(int k=0;k< record.count();k++)
            //            {
            //                qDebug()<<"The field is: "<< record.fieldName(k)<<" value:"<<record.value(k).toString();
            //            }

        }

        m_model.GetModel()->select();
    }
}

