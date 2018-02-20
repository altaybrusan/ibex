#include <QString>
#include <QDebug>
#include <QtTest>
#include <QCoreApplication>
#include "dcmtk/config/osconfig.h"    /* make sure OS specific configuration is included first */
#include "testscu.h"
#include "dcmtk/dcmnet/diutil.h"

#define OFFIS_CONSOLE_APPLICATION "testscu"

static OFLogger echoscuLogger = OFLog::getLogger("dcmtk.apps." OFFIS_CONSOLE_APPLICATION);

static char rcsid[] = "$dcmtk: " OFFIS_CONSOLE_APPLICATION " v"
        OFFIS_DCMTK_VERSION " " OFFIS_DCMTK_RELEASEDATE " $";

// our application entity title used for calling the peer machine
#define APPLICATIONTITLE     "TEST-SCU"

// host name of the peer machine
#define PEERHOSTNAME         "127.0.0.1"

// TCP/IP port to connect to the peer machine
#define PEERPORT 5678

// application entity title of the peer machine
#define PEERAPPLICATIONTITLE "CONQUESTSRV1"

// MOVE destination AE Title
#define MOVEAPPLICATIONTITLE "TEST-SCU"

class DCMTKTestTest : public QObject
{
    Q_OBJECT

public:
    DCMTKTestTest();

private Q_SLOTS:
    void testConnectingPACS();

private:
    static Uint8 findUncompressedPC(const OFString& sopClass,
                                    DcmSCU& scu)
    {
        Uint8 pc;
        pc = scu.findPresentationContextID(sopClass, UID_LittleEndianExplicitTransferSyntax);
        if (pc == 0)
            pc = scu.findPresentationContextID(sopClass, UID_BigEndianExplicitTransferSyntax);
        if (pc == 0)
            pc = scu.findPresentationContextID(sopClass, UID_LittleEndianImplicitTransferSyntax);
        return pc;
    }

};

DCMTKTestTest::DCMTKTestTest()
{
}

void DCMTKTestTest::testConnectingPACS()
{
    /* Setup DICOM connection parameters */
    OFLog::configure(OFLogger::DEBUG_LOG_LEVEL);
    DcmTestSCU scu;
    // set AE titles
    scu.setAETitle(APPLICATIONTITLE);
    scu.setPeerHostName(PEERHOSTNAME);
    scu.setPeerPort(PEERPORT);
    scu.setPeerAETitle(PEERAPPLICATIONTITLE);
    // Use presentation context for FIND/MOVE in study root, propose all uncompressed transfer syntaxes
    OFList<OFString> ts;
    ts.push_back(UID_LittleEndianExplicitTransferSyntax);
    ts.push_back(UID_BigEndianExplicitTransferSyntax);
    ts.push_back(UID_LittleEndianImplicitTransferSyntax);
    scu.addPresentationContext(UID_FINDStudyRootQueryRetrieveInformationModel, ts);
    scu.addPresentationContext(UID_MOVEStudyRootQueryRetrieveInformationModel, ts);
    scu.addPresentationContext(UID_VerificationSOPClass, ts);

    /* Initialize network */
    OFCondition result = scu.initNetwork();
    QString _msg;

    qDebug()<<"Initialize network";
    _msg="Unable to set up the network: " + QString(result.text());
    QVERIFY2(result.bad() == false,_msg.toStdString().c_str());


    /* Negotiate Association */
    qDebug()<<"Negotiate Association";
    result = scu.negotiateAssociation();
    _msg="Unable to negotiate association: " + QString(result.text());
    QVERIFY2(result.bad() == false,_msg.toStdString().c_str());


     /* Let's look whether the server is listening:
        Assemble and send C-ECHO request
      */
    qDebug()<<"send C-ECHO request";
    result = scu.sendECHORequest(0);
    _msg="Could not process C-ECHO with the server: " + QString(result.text());
    QVERIFY2(result.bad() == false,_msg.toStdString().c_str());

//    /* Assemble and send C-FIND request */
//    qDebug()<<"send C-FIND request";
//    OFList<QRResponse*> findResponses;
//    DcmDataset req;
//    req.putAndInsertOFStringArray(DCM_QueryRetrieveLevel, "STUDY");
//    req.putAndInsertOFStringArray(DCM_StudyInstanceUID, "");
//    T_ASC_PresentationContextID presID = findUncompressedPC(UID_FINDStudyRootQueryRetrieveInformationModel, scu);
//    QVERIFY2(presID==0,"There is no uncompressed presentation context for Study Root FIND");
//    if (presID == 0)
//    {
//        DCMNET_ERROR();
//        //return 1;
//    }
//    result = scu.sendFINDRequest(presID, &req, &findResponses);
//    if (result.bad()){}
//    //return 1;
//    else
//        DCMNET_INFO("There are " << findResponses.size() << " studies available");

    //     /* Assemble and send C-MOVE request, for each study identified above*/
    //     presID = findUncompressedPC(UID_MOVEStudyRootQueryRetrieveInformationModel, scu);
    //     if (presID == 0)
    //     {
    //       DCMNET_ERROR("There is no uncompressed presentation context for Study Root MOVE");
    //       //return 1;
    //     }
    //     OFListIterator(QRResponse*) study = findResponses.begin();
    //     Uint32 studyCount = 1;
    //     OFBool failed = OFFalse;
    //     // Every while loop run will get all image for a specific study
    //     while (study != findResponses.end() && result.good())
    //     {
    //       // be sure we are not in the last response which does not have a dataset
    //       if ( (*study)->m_dataset != NULL)
    //       {
    //         OFString studyInstanceUID;
    //         result = (*study)->m_dataset->findAndGetOFStringArray(DCM_StudyInstanceUID, studyInstanceUID);
    //         // only try to get study if we actually have study instance uid, otherwise skip it
    //         if (result.good())
    //         {
    //           req.putAndInsertOFStringArray(DCM_StudyInstanceUID, studyInstanceUID);
    //           // fetches all images of this particular study
    //           result = scu.sendMOVERequest(presID, MOVEAPPLICATIONTITLE, &req, NULL /* we are not interested into responses*/);
    //           if (result.good())
    //           {
    //             DCMNET_INFO("Received study #" << std::setw(7) << studyCount << ": " << studyInstanceUID);
    //             studyCount++;
    //           }
    //         }
    //       }
    //       study++;
    //     }
    //     if (result.bad())
    //     {
    //       DCMNET_ERROR("Unable to retrieve all studies: " << result.text());
    //     }
    //     while (!findResponses.empty())
    //     {
    //       delete findResponses.front();
    //       findResponses.pop_front();
    //     }
    //     /* Release association */
    //     scu.closeAssociation(DCMSCU_RELEASE_ASSOCIATION);
}

QTEST_MAIN(DCMTKTestTest)

#include "dcmtktesttest.moc"
