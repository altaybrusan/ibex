#include "logmgr.h"

#include <QObject>
#include "singleton.h"

#include "log4qt/consoleappender.h"
#include "log4qt/fileappender.h"
#include "log4qt/rollingfileappender.h"
#include "log4qt/logger.h"
#include "log4qt/loggerrepository.h"

#include "log4qt/logmanager.h"
#include "log4qt/patternlayout.h"
#include "log4qt/ttcclayout.h"

using namespace Log4Qt;

LogMgr::LogMgr(QObject *parent) : QObject(parent)
{
    _appLogger = Log4Qt::LogManager::logger("APPLICATION");
    _sysLogger = Log4Qt::LogManager::logger("SYSTEM");
}

LogMgr* LogMgr::createInstance()
{
    return new LogMgr();
}

LogMgr::~LogMgr()
{
  Shutdown();
}

LogMgr* LogMgr::instance()
{
    return Singleton<LogMgr>::instance(LogMgr::createInstance);
}

void LogMgr::Initialize()
{
    PatternLayout* appPatternLayout = new PatternLayout("[ %d{yyyy-MM-dd ][ HH:mm:ss} ] %-5p %c{1} - %m%n",this);
    appPatternLayout->setName(QLatin1String("Application Layout"));
    appPatternLayout->activateOptions();
    RollingFileAppender* appRollingFileAppender = new RollingFileAppender(appPatternLayout,"APP_ROLLING_FILE_APPENDER",true,this);
    appRollingFileAppender->setFile("./log/appLog.txt");
    appRollingFileAppender->setMaxBackupIndex(2);
    appRollingFileAppender->setAppendFile(true);
    appRollingFileAppender->setMaxFileSize("2MB");
    appRollingFileAppender->activateOptions();
    _appLogger->addAppender(appRollingFileAppender);
    _appLogger->setLevel(Log4Qt::Level::ALL_INT);


    // System logger initializtion and configuration
    // Console and RollingFileAppenders are attached.




    TTCCLayout *console_layout = new TTCCLayout();
    console_layout->setName(QLatin1String("Console Layout"));
    console_layout->activateOptions();

    ConsoleAppender *console_appender = new ConsoleAppender(console_layout, ConsoleAppender::STDOUT_TARGET);
    console_appender->setName(QLatin1String("Console Appender"));
    console_appender->activateOptions();
    _sysLogger->addAppender(console_appender);

    PatternLayout* sysPatternLayout = new PatternLayout("[ %d{yyyy-MM-dd ][ HH:mm:ss} ] %-5p %c{1} - %m%n",this);
    sysPatternLayout->setName(QLatin1String("System Layout"));
    sysPatternLayout->activateOptions();
    RollingFileAppender* sysRollingFileAppender = new RollingFileAppender(sysPatternLayout,"SYS_ROLLING_FILE_APPENDER",true,this);
    sysRollingFileAppender->setFile("./log/sysLog.txt");
    sysRollingFileAppender->setMaxBackupIndex(2);
    sysRollingFileAppender->setAppendFile(true);
    sysRollingFileAppender->setMaxFileSize("2MB");
    sysRollingFileAppender->activateOptions();
    _sysLogger->addAppender(sysRollingFileAppender);

    _sysLogger->setLevel(Log4Qt::Level::ALL_INT);
    Log4Qt::LogManager::setHandleQtMessages(true);
}

void LogMgr::Shutdown()
{
    _sysLogger->removeAllAppenders();
    _appLogger->removeAllAppenders();
    _sysLogger->loggerRepository()->shutdown();
    _appLogger->loggerRepository()->shutdown();

}

void LogMgr::LogSysDebug(QString msg)
{

    _sysLogger->debug(msg);
}

void LogMgr::LogSysInfo(QString msg)
{

    _sysLogger->info(msg);
}

void LogMgr::LogSysWarn(QString msg)
{

    _sysLogger->warn(msg);
}

void LogMgr::LogSysError(QString msg)
{
    _sysLogger->error(msg);

}

void LogMgr::LogSysFail(QString msg)
{
    _sysLogger->fatal(msg);

}

void LogMgr::LogAppDebug(QString msg)
{
    _appLogger->debug(msg);

}

void LogMgr::LogAppInfo(QString msg)
{
    _appLogger->info(msg);

}

void LogMgr::LogAppWarn(QString msg)
{
    _appLogger->warn(msg);

}

void LogMgr::LogAppError(QString msg)
{
    _appLogger->error(msg);

}

void LogMgr::LogAppFail(QString msg)
{
    _appLogger->fatal(msg);

}
