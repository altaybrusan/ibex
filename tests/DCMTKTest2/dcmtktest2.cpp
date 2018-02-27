// this test is based on dcmsend.cc from dcmtk

#include <QString>
#include <QtTest>

#include "dcmtk/config/osconfig.h"   /* make sure OS specific configuration is included first */

#include "dcmtk/ofstd/ofstd.h"       /* for OFStandard functions */
#include "dcmtk/ofstd/ofconapp.h"    /* for OFConsoleApplication */
#include "dcmtk/ofstd/ofstream.h"    /* for OFStringStream et al. */
#include "dcmtk/dcmdata/dcdict.h"    /* for global data dictionary */
#include "dcmtk/dcmdata/dcuid.h"     /* for dcmtk version name */
#include "dcmtk/dcmdata/cmdlnarg.h"  /* for prepareCmdLineArgs */
#include "dcmtk/dcmdata/dcostrmz.h"  /* for dcmZlibCompressionLevel */
#include "dcmtk/dcmnet/dstorscu.h"   /* for DcmStorageSCU */

#include "dcmtk/dcmjpeg/djdecode.h"  /* for JPEG decoders */
#include "dcmtk/dcmjpls/djdecode.h"  /* for JPEG-LS decoders */
#include "dcmtk/dcmdata/dcrledrg.h"  /* for RLE decoder */
#include "dcmtk/dcmjpeg/dipijpeg.h"  /* for dcmimage JPEG plugin */
#include "dcmtk/dcmnet/diutil.h"


#define OFFIS_CONSOLE_APPLICATION "testscu2"
static OFLogger echoscuLogger = OFLog::getLogger("dcmtk.apps." OFFIS_CONSOLE_APPLICATION);


/* default application entity titles */
#define APPLICATIONTITLE     "DCMSEND"
#define PEERAPPLICATIONTITLE "ANY-SCP"


/* (EXIT_SUCCESS and EXIT_FAILURE are standard codes) */

// general
#define EXITCODE_NO_ERROR                         0
#define EXITCODE_COMMANDLINE_SYNTAX_ERROR         1      // this code is the default for printError()

// input file errors
#define EXITCODE_CANNOT_READ_INPUT_FILE          20      // placeholder, currently not used
#define EXITCODE_NO_INPUT_FILES                  21
#define EXITCODE_INVALID_INPUT_FILE              22
#define EXITCODE_NO_VALID_INPUT_FILES            23

// output file errors
#define EXITCODE_CANNOT_WRITE_OUTPUT_FILE        40      // placeholder, currently not used
#define EXITCODE_CANNOT_WRITE_REPORT_FILE        43

// network errors
#define EXITCODE_CANNOT_INITIALIZE_NETWORK       60
#define EXITCODE_CANNOT_NEGOTIATE_ASSOCIATION    61
#define EXITCODE_CANNOT_SEND_REQUEST             62
#define EXITCODE_CANNOT_ADD_PRESENTATION_CONTEXT 65

#define SHORTCOL 4
#define LONGCOL 21


class DCMTKTest2 : public QObject
{
    Q_OBJECT

public:
    DCMTKTest2();

private Q_SLOTS:
    void testSendingSingleDicomFileToPacs();
    void testSendingDirectoryContents();
};

DCMTKTest2::DCMTKTest2()
{
}

void DCMTKTest2::testSendingSingleDicomFileToPacs()
{
    /* Setup DICOM connection parameters */
    OFLog::configure(OFLogger::DEBUG_LOG_LEVEL);
    //OFOStringStream optStream;

    const char *opt_peer = "localhost";
    const char *opt_peerTitle = "CONQUESTSRV1";
    const char *opt_ourTitle = "DEMO_APPLICATIONTITLE";

    E_FileReadMode opt_readMode = ERM_fileOnly;

    OFCmdUnsignedInt opt_port = 5678;
    //OFCmdUnsignedInt opt_timeout = 0;
    OFCmdUnsignedInt opt_dimseTimeout = 0;
    OFCmdUnsignedInt opt_acseTimeout = 30;
    OFCmdUnsignedInt opt_maxReceivePDULength = ASC_DEFAULTMAXPDU;
    //OFCmdUnsignedInt opt_maxSendPDULength = 0;
    T_DIMSE_BlockingMode opt_blockMode = DIMSE_BLOCKING;

    OFBool opt_showPresentationContexts = OFFalse;
    OFBool opt_haltOnInvalidFile = OFTrue;
    OFBool opt_haltOnUnsuccessfulStore = OFTrue;
    OFBool opt_allowIllegalProposal = OFTrue;
    OFBool opt_checkUIDValues = OFTrue;
    OFBool opt_multipleAssociations = OFTrue;
    DcmStorageSCU::E_DecompressionMode opt_decompressionMode = DcmStorageSCU::DM_losslessOnly;

    OFBool opt_dicomDir = OFFalse;
    OFBool opt_scanDir = OFFalse;
    //OFBool opt_recurse = OFFalse;
    const char *opt_reportFilename = "";


    /* command line parameters */
    // paramCount = cmd.getParamCount();
    // cmd.getParam(1, opt_peer);
    // app.checkParam(cmd.getParamAndCheckMinMax(2, opt_port, 1, 65535));


    /* make sure data dictionary is loaded */
    if (!dcmDataDict.isDictionaryLoaded())
    {
        qDebug()<<"no data dictionary loaded, check environment variable: ";
    }

    /* start with the real work */
    if (opt_scanDir)
        qDebug()<< "determining input files ...";
    /* iterate over all input filenames/directories */
    OFList<OFString> inputFiles;
    const char *paramString = "C:\\Users\\Altay\\Documents\\Qt\\Projects\\ibex\\tests\\test-image\\row1.dcm";
    inputFiles.push_back(paramString);

    DcmStorageSCU storageSCU;
    OFCondition status;
    unsigned long numInvalidFiles = 0;

    /* set parameters used for processing the input files */
    storageSCU.setReadFromDICOMDIRMode(opt_dicomDir);
    storageSCU.setHaltOnInvalidFileMode(opt_haltOnInvalidFile);

    /* iterate over all input filenames */
    const char *currentFilename = NULL;
    OFListIterator(OFString) if_iter = inputFiles.begin();
    OFListIterator(OFString) if_last = inputFiles.end();
    while (if_iter != if_last)
    {
        currentFilename = (*if_iter).c_str();
        /* and add them to the list of instances to be transmitted */
        status = storageSCU.addDicomFile(currentFilename, opt_readMode, opt_checkUIDValues);
        if (status.bad())
        {
            /* check for empty filename */
            if (strlen(currentFilename) == 0)
            {

                QVERIFY2(false,"empty file name");

            }

            /* if something went wrong, we either terminate or ignore the file */
            if (opt_haltOnInvalidFile)
            {
                QString msg ="bad DICOM file: " + QString(currentFilename) + " : " + QString(status.text());
                QVERIFY2(false,msg.toLatin1().data());
            }
            else
            {
                QString msg ="bad DICOM file: " + QString(currentFilename)  + ": " + QString(status.text()) + ", ignoring file";
                QVERIFY2(false,msg.toLatin1().data());
            }
            ++numInvalidFiles;
        }
        ++if_iter;
    }

    /* check whether there are any valid input files */
    QVERIFY2(storageSCU.getNumberOfSOPInstances() != 0,"no valid input files to be processed");

    qDebug()<< "in total, there are " << storageSCU.getNumberOfSOPInstances()
            << " SOP instances to be sent, " << numInvalidFiles << " invalid files are ignored";


    //       if (storageSCU.getNumberOfSOPInstances() == 0)
    //       {
    //           OFLOG_FATAL(dcmsendLogger, "no valid input files to be processed");
    //           cleanup();
    //           return EXITCODE_NO_VALID_INPUT_FILES;
    //       } else {
    //           OFLOG_DEBUG(dcmsendLogger, "in total, there are " << storageSCU.getNumberOfSOPInstances()
    //               << " SOP instances to be sent, " << numInvalidFiles << " invalid files are ignored");
    //       }

    /* set network parameters */
    storageSCU.setPeerHostName(opt_peer);
    storageSCU.setPeerPort(OFstatic_cast(Uint16, opt_port));
    storageSCU.setPeerAETitle(opt_peerTitle);
    storageSCU.setAETitle(opt_ourTitle);
    storageSCU.setMaxReceivePDULength(OFstatic_cast(Uint32, opt_maxReceivePDULength));
    storageSCU.setACSETimeout(OFstatic_cast(Uint32, opt_acseTimeout));
    storageSCU.setDIMSETimeout(OFstatic_cast(Uint32, opt_dimseTimeout));
    storageSCU.setDIMSEBlockingMode(opt_blockMode);
    storageSCU.setVerbosePCMode(opt_showPresentationContexts);
    storageSCU.setDatasetConversionMode(opt_decompressionMode != DcmStorageSCU::DM_never);
    storageSCU.setDecompressionMode(opt_decompressionMode);
    storageSCU.setHaltOnUnsuccessfulStoreMode(opt_haltOnUnsuccessfulStore);
    storageSCU.setAllowIllegalProposalMode(opt_allowIllegalProposal);

    /* output information on the single/multiple associations setting */
    if (opt_multipleAssociations)
    {
        //OFLOG_DEBUG(dcmsendLogger, "multiple associations allowed (option --multi-associations used)");
        qDebug()<<"multiple associations allowed (option --multi-associations used)";
    } else {
        //OFLOG_DEBUG(dcmsendLogger, "only a single associations allowed (option --single-association used)");
        qDebug()<<"only a single associations allowed (option --single-association used)";
    }

    /* add presentation contexts to be negotiated (if there are still any) */
    while ((status = storageSCU.addPresentationContexts()).good())
    {
        if (opt_multipleAssociations)
        {
            /* output information on the start of the new association */
            //               if (dcmsendLogger.isEnabledFor(OFLogger::DEBUG_LOG_LEVEL))
            //               {
            //                   OFLOG_DEBUG(dcmsendLogger, OFString(65, '-') << OFendl
            //                       << "starting association #" << (storageSCU.getAssociationCounter() + 1));
            //               } else {
            //                   OFLOG_INFO(dcmsendLogger, "starting association #" << (storageSCU.getAssociationCounter() + 1));
            //               }
            qDebug()<< "starting association #" << storageSCU.getAssociationCounter();
        }
        //           OFLOG_INFO(dcmsendLogger, "initializing network ...");

        qDebug()<<"initializing network ...";
        /* initialize network */
        status = storageSCU.initNetwork();
        if (status.bad())
        {
            qDebug()<<"cannot initialize network: " << status.text();
            //               OFLOG_FATAL(dcmsendLogger, "cannot initialize network: " << status.text());
            //               cleanup();
            //return EXITCODE_CANNOT_INITIALIZE_NETWORK;
        }
        //           OFLOG_INFO(dcmsendLogger, "negotiating network association ...");
        qDebug()<<"negotiating network association ...";
        /* negotiate network association with peer */
        status = storageSCU.negotiateAssociation();
        if (status.bad())
        {
            // check whether we can continue with a new association
            if (status == NET_EC_NoAcceptablePresentationContexts)
            {
                //OFLOG_ERROR(dcmsendLogger, "cannot negotiate network association: " << status.text());
                qDebug()<<"cannot negotiate network association: " << status.text();
                // check whether there are any SOP instances to be sent
                const size_t numToBeSent = storageSCU.getNumberOfSOPInstancesToBeSent();
                if (numToBeSent > 0)
                {
                    //                       OFLOG_WARN(dcmsendLogger, "trying to continue with a new association "
                    //                           << "in order to send the remaining " << numToBeSent << " SOP instances");
                    qDebug()<< "trying to continue with a new association in order to send the remaining " << numToBeSent << " SOP instances";

                }
            } else {
                //                   OFLOG_FATAL(dcmsendLogger, "cannot negotiate network association: " << status.text());
                //                   cleanup();
                //                   return EXITCODE_CANNOT_NEGOTIATE_ASSOCIATION;
                qDebug()<< "cannot negotiate network association: " << status.text();

            }
        }
        if (status.good())
        {
            //               OFLOG_INFO(dcmsendLogger, "sending SOP instances ...");
            qDebug()<<"sending SOP instances ...";
            /* send SOP instances to be transferred */
            status = storageSCU.sendSOPInstances();
            if (status.bad())
            {
                //OFLOG_FATAL(dcmsendLogger, "cannot send SOP instance: " << status.text());
                qDebug()<<"cannot send SOP instance: " << status.text();

                // handle certain error conditions (initiated by the communication peer)
                if (status == DUL_PEERREQUESTEDRELEASE)
                {
                    // peer requested release (aborting)
                    storageSCU.closeAssociation(DCMSCU_PEER_REQUESTED_RELEASE);
                    QVERIFY2(false,"peer requested release");
                }
                else if (status == DUL_PEERABORTEDASSOCIATION)
                {
                    // peer aborted the association
                    storageSCU.closeAssociation(DCMSCU_PEER_ABORTED_ASSOCIATION);
                    QVERIFY2(false,"peer aborted the association");

                }
                //                   cleanup();
                //                   return EXITCODE_CANNOT_SEND_REQUEST;
                QVERIFY(false);
            }
        }
        /* close current network association */
        storageSCU.releaseAssociation();
        /* check whether multiple associations are permitted */
        if (!opt_multipleAssociations)
            break;
    }

    /* if anything went wrong, report it to the logger */
    if (status.bad() && (status != NET_EC_NoPresentationContextsDefined))
    {
        //OFLOG_ERROR(dcmsendLogger, "cannot add presentation contexts: " << status.text());
        //cleanup();
        //return EXITCODE_CANNOT_ADD_PRESENTATION_CONTEXT;
        QString message= QString("cannot add presentation contexts: %1 ").arg( QString::fromUtf8(status.text()));
        QVERIFY2(false,message.toLatin1().data());
        //QVERIFY2(false,QString("cannot add presentation contexts: %1 ").arg( QString::fromUtf8(status.text())));
    }

    /* create a detailed report on the transfer of instances ... */
    if ((opt_reportFilename != NULL) && (strlen(opt_reportFilename) > 0))
    {
        /* ... and write it to the specified text file */
        status = storageSCU.createReportFile(opt_reportFilename);
        if (status.bad())
        {
            //cleanup();
            //return EXITCODE_CANNOT_WRITE_REPORT_FILE; // TODO: do we really want to exit?
            QVERIFY2(false,"EXITCODE_CANNOT_WRITE_REPORT_FILE");
        }
    }


    /* output some status information on the overall sending process */
    //       if (dcmsendLogger.isEnabledFor(OFLogger::INFO_LOG_LEVEL))
    //       {
    //           OFString summaryText;
    //           storageSCU.getStatusSummary(summaryText);
    //           OFLOG_INFO(dcmsendLogger, OFendl << summaryText);
    //       }

    /* make sure that everything is cleaned up properly */
    //       cleanup();
    //       return EXITCODE_NO_ERROR;
}

void DCMTKTest2::testSendingDirectoryContents()
{
    /* Setup DICOM connection parameters */
    OFLog::configure(OFLogger::DEBUG_LOG_LEVEL);
    OFOStringStream optStream;

    const char *opt_peer = "localhost";
    const char *opt_peerTitle = "CONQUESTSRV1";
    const char *opt_ourTitle = "DEMO_APPLICATIONTITLE";

    E_FileReadMode opt_readMode = ERM_fileOnly;

    OFCmdUnsignedInt opt_port = 5678;
    //OFCmdUnsignedInt opt_timeout = 0;
    OFCmdUnsignedInt opt_dimseTimeout = 0;
    OFCmdUnsignedInt opt_acseTimeout = 30;
    OFCmdUnsignedInt opt_maxReceivePDULength = ASC_DEFAULTMAXPDU;
    //OFCmdUnsignedInt opt_maxSendPDULength = 0;
    T_DIMSE_BlockingMode opt_blockMode = DIMSE_BLOCKING;
    OFBool opt_dicomDir = OFTrue;
    OFBool opt_scanDir = OFTrue;
    OFBool opt_recurse = OFTrue;
    const char *opt_scanPattern = "";
    //const char *opt_reportFilename = "";

    OFBool opt_showPresentationContexts = OFFalse;
    OFBool opt_haltOnInvalidFile = OFFalse; // you can skip over invalid files within folder
    OFBool opt_haltOnUnsuccessfulStore = OFTrue;
    OFBool opt_allowIllegalProposal = OFTrue;
    OFBool opt_checkUIDValues = OFTrue;
    OFBool opt_multipleAssociations = OFTrue;
    DcmStorageSCU::E_DecompressionMode opt_decompressionMode = DcmStorageSCU::DM_losslessOnly;
    const char *opt_reportFilename = "";


    /* command line parameters */
    // paramCount = cmd.getParamCount();
    // cmd.getParam(1, opt_peer);
    // app.checkParam(cmd.getParamAndCheckMinMax(2, opt_port, 1, 65535));


    /* make sure data dictionary is loaded */
    if (!dcmDataDict.isDictionaryLoaded())
    {
        qDebug()<<"no data dictionary loaded, check environment variable: ";
    }

    /* start with the real work */
    if (opt_scanDir)
        qDebug()<< "determining input files ...";
    /* iterate over all input filenames/directories */
    OFList<OFString> inputFiles;
    const char *paramString = "C:\\Users\\Altay\\Documents\\Qt\\Projects\\ibex\\tests\\test-image\\";;

    /* search directory recursively (if required) */
    if (OFStandard::dirExists(paramString)) // is it directory
    {
        if (opt_scanDir) // should I check direcories
            OFStandard::searchDirectoryRecursively(paramString, inputFiles, opt_scanPattern, "" /* dirPrefix */, opt_recurse);
        else
            qDebug()<< "ignoring directory because option --scan-directories is not set: ";
    } else
        inputFiles.push_back(paramString);// of paramString is just a file

    /* check whether there are any input files at all */
    if (inputFiles.empty())
    {
        QVERIFY2(false, "no input files to be processed");
    }

    DcmStorageSCU storageSCU;
    OFCondition status;
    unsigned long numInvalidFiles = 0;

    /* set parameters used for processing the input files */
    storageSCU.setReadFromDICOMDIRMode(opt_dicomDir);
    storageSCU.setHaltOnInvalidFileMode(opt_haltOnInvalidFile);

    /* iterate over all input filenames */
    const char *currentFilename = NULL;
    OFListIterator(OFString) if_iter = inputFiles.begin();
    OFListIterator(OFString) if_last = inputFiles.end();
    while (if_iter != if_last)
    {
        currentFilename = (*if_iter).c_str();
        /* and add them to the list of instances to be transmitted */
        status = storageSCU.addDicomFile(currentFilename, opt_readMode, opt_checkUIDValues);
        if (status.bad())
        {
            /* check for empty filename */
            if (strlen(currentFilename) == 0)
            {
                //QVERIFY2(false,"empty file name");
                if (opt_haltOnInvalidFile)
                {
                    QString message= "bad DICOM file: " + QString(currentFilename) + ": " + QString(status.text());
                    QVERIFY2(false, message.toLatin1().data() );

                } else
                {
                    QString message= "bad DICOM file: " + QString(currentFilename) + ": " + QString(status.text()) + ", ignoring file";
                    QVERIFY2(false, message.toLatin1().data());
                }
                ++numInvalidFiles;
            }

            /* if something went wrong, we either terminate or ignore the file */
            if (opt_haltOnInvalidFile)
            {
                QString msg ="bad DICOM file: " + QString(currentFilename) + " : " + QString(status.text());
                QVERIFY2(false,msg.toLatin1().data());
            }
            else
            {
                QString msg ="bad DICOM file: " + QString(currentFilename)  + ": " + QString(status.text()) + ", ignoring file";
                //QVERIFY2(false,msg.toLatin1().data());
                qDebug()<<msg;
            }
            ++numInvalidFiles;
        }
        ++if_iter;
    }

    /* check whether there are any valid input files */
    QVERIFY2(storageSCU.getNumberOfSOPInstances() != 0,"no valid input files to be processed");

    qDebug()<< "in total, there are " << storageSCU.getNumberOfSOPInstances()
            << " SOP instances to be sent, " << numInvalidFiles << " invalid files are ignored";

    /* set network parameters */
    storageSCU.setPeerHostName(opt_peer);
    storageSCU.setPeerPort(OFstatic_cast(Uint16, opt_port));
    storageSCU.setPeerAETitle(opt_peerTitle);
    storageSCU.setAETitle(opt_ourTitle);
    storageSCU.setMaxReceivePDULength(OFstatic_cast(Uint32, opt_maxReceivePDULength));
    storageSCU.setACSETimeout(OFstatic_cast(Uint32, opt_acseTimeout));
    storageSCU.setDIMSETimeout(OFstatic_cast(Uint32, opt_dimseTimeout));
    storageSCU.setDIMSEBlockingMode(opt_blockMode);
    storageSCU.setVerbosePCMode(opt_showPresentationContexts);
    storageSCU.setDatasetConversionMode(opt_decompressionMode != DcmStorageSCU::DM_never);
    storageSCU.setDecompressionMode(opt_decompressionMode);
    storageSCU.setHaltOnUnsuccessfulStoreMode(opt_haltOnUnsuccessfulStore);
    storageSCU.setAllowIllegalProposalMode(opt_allowIllegalProposal);

    /* output information on the single/multiple associations setting */
    if (opt_multipleAssociations)
    {
        qDebug()<<"multiple associations allowed (option --multi-associations used)";
    }
    else
    {
        qDebug()<<"only a single associations allowed (option --single-association used)";
    }

    /* add presentation contexts to be negotiated (if there are still any) */
    while ((status = storageSCU.addPresentationContexts()).good())
    {
        if (opt_multipleAssociations)
        {
            qDebug()<< "starting association #" << storageSCU.getAssociationCounter();
        }

        qDebug()<<"initializing network ...";
        /* initialize network */
        status = storageSCU.initNetwork();
        if (status.bad())
        {
            qDebug()<<"cannot initialize network: " << status.text();
            QVERIFY2(false,"EXITCODE_CANNOT_INITIALIZE_NETWORK");
        }

        qDebug()<<"negotiating network association ...";
        /* negotiate network association with peer */
        status = storageSCU.negotiateAssociation();
        if (status.bad())
        {
            // check whether we can continue with a new association
            if (status == NET_EC_NoAcceptablePresentationContexts)
            {
                qDebug()<<"cannot negotiate network association: " << status.text();
                // check whether there are any SOP instances to be sent
                const size_t numToBeSent = storageSCU.getNumberOfSOPInstancesToBeSent();
                if (numToBeSent > 0)
                {
                    qDebug()<< "trying to continue with a "
                               "new association in order to send the remaining "
                            << numToBeSent << " SOP instances";
                }
            }
            else
            {
                qDebug()<< "cannot negotiate network association: " << status.text();
                QVERIFY2(false,"EXITCODE_CANNOT_NEGOTIATE_ASSOCIATION");
            }
        }
        if (status.good())
        {
            qDebug()<<"sending SOP instances ...";
            /* send SOP instances to be transferred */
            status = storageSCU.sendSOPInstances();
            if (status.bad())
            {
                qDebug()<<"cannot send SOP instance: " << status.text();
                // handle certain error conditions (initiated by the communication peer)
                if (status == DUL_PEERREQUESTEDRELEASE)
                {
                    // peer requested release (aborting)
                    storageSCU.closeAssociation(DCMSCU_PEER_REQUESTED_RELEASE);
                }
                else if (status == DUL_PEERABORTEDASSOCIATION)
                {
                    // peer aborted the association
                    storageSCU.closeAssociation(DCMSCU_PEER_ABORTED_ASSOCIATION);
                }
                QVERIFY2(false,"EXITCODE_CANNOT_SEND_REQUEST");
            }
        }
        /* close current network association */
        storageSCU.releaseAssociation();
        /* check whether multiple associations are permitted */
        if (!opt_multipleAssociations)
            break;
    }

    /* if anything went wrong, report it to the logger */
    if (status.bad() && (status != NET_EC_NoPresentationContextsDefined))
    {
        QString message= QString("cannot add presentation contexts: %1 ").arg( QString::fromUtf8(status.text()));
        QVERIFY2(false,message.toLatin1().data());
    }

    /* create a detailed report on the transfer of instances ... */
    if ((opt_reportFilename != NULL) && (strlen(opt_reportFilename) > 0))
    {
        /* ... and write it to the specified text file */
        status = storageSCU.createReportFile(opt_reportFilename);
        if (status.bad())
        {
          QVERIFY2(false,"EXITCODE_CANNOT_WRITE_REPORT_FILE");
        }
    }

}

QTEST_APPLESS_MAIN(DCMTKTest2)

#include "dcmtktest2.moc"
