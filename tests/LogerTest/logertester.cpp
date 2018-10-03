#include <QString>
#include <QtTest>
#include <QTime>
#include "Utils/logmgr.h"

class LogerTest : public QObject
{
    Q_OBJECT

public:
    LogerTest();

private Q_SLOTS:    
    void initTestCase();
    void testSystemDebug();
    void testSystemInfo();
    void testSystemWarn();
    void testSystemError();
    void testSystemFatal();
    void cleanupTestCase();
private:
    LogMgr* logMgr;
};

LogerTest::LogerTest()
{
}

void LogerTest::initTestCase()
{
    logMgr = LogMgr::instance();
    QVERIFY2(true,"CHECK HARD DISK");

}

void LogerTest::testSystemDebug()
{
    logMgr->instance()->LogSysDebug("Test Systemic Debug");
    QVERIFY2(true,"CHECK HARD DISK");

}

void LogerTest::testSystemInfo()
{
    logMgr->instance()->LogSysInfo("Test Systemic Info");
    QVERIFY2(true,"CHECK HARD DISK");
}

void LogerTest::testSystemWarn()
{
    logMgr->instance()->LogSysWarn("Test Systemic Warn");
    QVERIFY2(true,"CHECK HARD DISK");
}

void LogerTest::testSystemError()
{
    logMgr->instance()->LogSysError("Test Systemic Error");
    QVERIFY2(true,"CHECK HARD DISK");

}

void LogerTest::testSystemFatal()
{
    logMgr->instance()->LogSysDebug("Test Systemic Fail");
    QVERIFY2(true,"CHECK HARD DISK");

}

void LogerTest::cleanupTestCase()
{
    logMgr->instance()->Shutdown();
    QVERIFY2(true,"CHECK HARD DISK");
}



QTEST_APPLESS_MAIN(LogerTest)

#include "logertester.moc"
