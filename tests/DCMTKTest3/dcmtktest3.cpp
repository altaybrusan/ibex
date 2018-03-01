// this document is based on findscu.cc from dcmtk
// WITH_ZLIB is not supported
// WITH_OPENSSL is not supported
// HAVE_GUSI_H is not supported


#include <QString>
#include <QtTest>

#include <QTcpSocket>
//#ifdef _WIN32
//#include <winsock.h>
//#endif

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

#define OFFIS_CONSOLE_APPLICATION "findscu"

static OFLogger findscuLogger = OFLog::getLogger("dcmtk.apps." OFFIS_CONSOLE_APPLICATION);

static char rcsid[] = "$dcmtk: " OFFIS_CONSOLE_APPLICATION " v"
        OFFIS_DCMTK_VERSION " " OFFIS_DCMTK_RELEASEDATE " $";

/* default application titles */
#define APPLICATIONTITLE        "FINDSCU"
#define PEERAPPLICATIONTITLE    "ANY-SCP"

#define SHORTCOL 4
#define LONGCOL 20

class DCMTKTest3 : public QObject
{
    Q_OBJECT

public:
    DCMTKTest3();

private Q_SLOTS:
    void initTestCase();
    void testModalityWorkListConnection();
    void cleanupTestCase();

private:
    OFList<OFString>      fileNameList;
    OFBool                opt_abortAssociation = OFFalse;
    const char *          opt_abstractSyntax = UID_FINDModalityWorklistInformationModel;
    int                   opt_acse_timeout = 3000;
    T_DIMSE_BlockingMode  opt_blockMode = DIMSE_BLOCKING;
    OFCmdSignedInt        opt_cancelAfterNResponses = -1;
    int                   opt_dimse_timeout = 0;
    int                   opt_outputResponsesToLogger = 0;
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
    QTcpSocket * socket;
        DcmFindSCU findscu;

};

DCMTKTest3::DCMTKTest3()
{


}

void DCMTKTest3::initTestCase()
{
    qDebug()<<"constructing socket object";
    socket = new QTcpSocket();
}

void DCMTKTest3::testModalityWorkListConnection()
{
    /*
    ** By default. don't let "dcmdata" remove trailing padding or
    ** perform other manipulations. We want to see the real data.
    */
    OFBool opt_automaticDataCorrection = OFFalse;




//#ifdef HAVE_WINSOCK_H
//    WSAData winSockData;
//    /* we need at least version 1.1 */
//    WORD winSockVersionNeeded = MAKEWORD( 1, 1 );
//    WSAStartup(winSockVersionNeeded, &winSockData);
//#endif

    //char tempstr[20];
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
        //        OFLOG_WARN(findscuLogger, "no data dictionary loaded, check environment variable: "
        //                   << DCM_DICT_ENVIRONMENT_VARIABLE);
    }

    /* make sure that output directory can be used (if needed) */
    if (opt_extractResponsesToFile)
    {
        if (!OFStandard::dirExists(opt_outputDirectory))
        {
            //            OFLOG_FATAL(findscuLogger, "specified output directory does not exist");
            //            return 1;
            QVERIFY2(false,"specified output directory does not exist");
        }
        else if (!OFStandard::isWriteable(opt_outputDirectory))
        {
            //            OFLOG_FATAL(findscuLogger, "specified output directory is not writeable");
            //            return 1;
            QVERIFY2(false,"specified output directory is not writeable");
        }
    }



//     socket->setSocketOption ( QAbstractSocket::LowDelayOption, 1 );
//     qDebug()<<"trying to make connection";
//     socket->connectToHost ("127.0.0.1" ,  107 );

//   if ( socket->waitForConnected ( 10000 ) )
//   {
//       qDebug()<<"closing connection";
//       socket->disconnectFromHost();
//   }
//   else
//   {
//       // may be you need to restart RIS. DVTK emulator in this testcase
//       QVERIFY2(false,"Cannot connect to server.");
//   }

   // enabled or disable removal of trailing padding
   //dcmEnableAutomaticInputDataCorrection.set(opt_automaticDataCorrection);

    // declare findSCU handler and initialize network

    OFCondition cond = findscu.initializeNetwork(opt_acse_timeout);

    if (cond.bad()) {
        //        OFLOG_ERROR(findscuLogger, DimseCondition::dump(temp_str, cond));
        //        return 1;
        DimseCondition::dump(temp_str, cond);
        QVERIFY2(false,QString::fromLatin1(temp_str.c_str()).toLatin1().data());
    }

    /* findscu -W
     * -k 0008,0005
     * -k 0008,0010
     * -k 0008,0050
     * -k 0008,0060
     * -k 0008,0090
     * -k 0008,1110
     * -k 0010,0010
     * -k 0010,0020
     * -k 0010,0030
     * -k 0010,0040
     * -k 0010,1030
     * -k 0010,2000
     * -k 0010,2110
     * localhost 107
     * -Xs Out.xml
*/

    overrideKeys.push_back("0008,0005");
    overrideKeys.push_back("0008,0010");
    overrideKeys.push_back("0008,0050");

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
                static_cast<DcmFindSCUExtractMode>(opt_extractResponsesToFile),//static_cast<DcmFindSCUExtractMode>
                opt_cancelAfterNResponses,
                &overrideKeys,
                NULL, /* we want to use the default callback */
                &fileNameList,
                opt_outputDirectory.c_str());

    if(cond.bad())
    {
        QVERIFY2(false,"Cannot perform query");
    }

//    // destroy network structure
//    cond = findscu.dropNetwork();
//    if (cond.bad())
//    {
//        DimseCondition::dump(temp_str, cond);
//        qDebug()<<QString::fromLatin1(temp_str.c_str());
//    }

//#ifdef HAVE_WINSOCK_H
//    WSACleanup();
    //#endif
}

void DCMTKTest3::cleanupTestCase()
{
    //delete socket;
}

QTEST_MAIN(DCMTKTest3)

#include "dcmtktest3.moc"
