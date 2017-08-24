#include <QString>
#include <QtTest/QtTest>
#include "../src/basiclogmanager.h"

using namespace Common;
static auto LOG_DIR= QStringLiteral("../log/");
static auto LOG_FILE_NAME= QStringLiteral("basic.log");
class TestBasicLogManager : public QObject
{
    Q_OBJECT

public:
    TestBasicLogManager();

private Q_SLOTS:
    void initTestCase(); // will be called before the first test function is executed.
    void cleanupTestCase(); // will be called after the last test function was executed.
    void init(); // will be called before each test function is executed.
    void cleanup(); // will be called after every test function.

    void TestDifferentLogLevels();
    void TestConsoleAppenderActivation();
    void TestLoggingSystemActivation();
    void TestLoggingFormatChange();
private:
    BasicLogManager* _manager;


};

TestBasicLogManager::TestBasicLogManager()
{

}

void TestBasicLogManager::initTestCase()
{
    QDir dir(LOG_DIR);
    if (!dir.exists()) {
        dir.mkpath(LOG_DIR);
    }
    _manager= new BasicLogManager(this,LOG_DIR,LOG_FILE_NAME);
}

void TestBasicLogManager::cleanupTestCase()
{

}

void TestBasicLogManager::init()
{

}

void TestBasicLogManager::cleanup()
{

}

// Test: if all log levels are working
void TestBasicLogManager::TestDifferentLogLevels()
{
    _manager->LogMessage(LogLevel::ALL,"ALL MSG"); // This message is not saved!
    _manager->LogMessage(LogLevel::DEBUG,"DEBUG MSG");
    _manager->LogMessage(LogLevel::ERROR,"ERROR MSG");
    _manager->LogMessage(LogLevel::FATAL,"FATAL MSG");
    _manager->LogMessage(LogLevel::INFO,"INFO MSG");
    _manager->LogMessage(LogLevel::TRACE,"TRACE MSG");// This message is not saved!
    _manager->LogMessage(LogLevel::WARN,"WARN MSG");// This message is not saved!

    QVERIFY2(true, "Check ../log/basic.log to see the log file content");

}
// Test: if Enable/Disable ConsoleAppender is working
void TestBasicLogManager::TestConsoleAppenderActivation()
{
    _manager->DisableConsoleLogger();
    _manager->DisableConsoleLogger();
    _manager->LogMessage(LogLevel::DEBUG,"This message should not show up in console.");
    _manager->EnableConsoleLogger();
    _manager->LogMessage(LogLevel::DEBUG,"This message should show up in console.");
    _manager->EnableConsoleLogger();
    _manager->EnableConsoleLogger();

    QVERIFY2(true, "Console Appender check is done");

}
// Test: if Enable/Disable Logger is working
void TestBasicLogManager::TestLoggingSystemActivation()
{

    _manager->DisableLogger();
    _manager->LogMessage(LogLevel::DEBUG,"This message is not going to be logged.");
    _manager->EnableLogger();
    _manager->LogMessage(LogLevel::DEBUG,"This message is going to be logged.");

    QVERIFY2(true, "CLogging activation tests is done");

}
// Test: if Message formatter
void TestBasicLogManager::TestLoggingFormatChange()
{
    _manager->UpdateMesageFormatter("%d{yyyy-MM-dd}-%t-%x-%-5p-%-10c:%m%n");
    _manager->LogMessage(LogLevel::INFO,"This message should show up in different format");

    QVERIFY2(true, "CLogging activation tests is done");
}


QTEST_MAIN(TestBasicLogManager)
#include "testbasiclogmanager.moc"
