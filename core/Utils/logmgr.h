#ifndef LOGMRG_H
#define LOGMRG_H

#include <QObject>
#include "log4qt/consoleappender.h"
#include "log4qt/fileappender.h"
#include "log4qt/rollingfileappender.h"
#include "log4qt/logger.h"
#include "log4qt/loggerrepository.h"

#include "log4qt/logmanager.h"
#include "log4qt/patternlayout.h"
#include "log4qt/ttcclayout.h"

class LogMgr : public QObject
{
    Q_OBJECT
public:
    ~LogMgr();
    static LogMgr* instance();
    void Initialize();
    void Shutdown();

    void LogSysDebug(QString msg);
    void LogSysInfo(QString msg);
    void LogSysWarn(QString msg);
    void LogSysError(QString msg);
    void LogSysFail(QString msg);

    void LogAppDebug(QString msg);
    void LogAppInfo(QString msg);
    void LogAppWarn(QString msg);
    void LogAppError(QString msg);
    void LogAppFail(QString msg);


private:
    LogMgr(QObject* parent = 0);
    static LogMgr* createInstance();
    Log4Qt::Logger* _sysLogger;
    Log4Qt::Logger* _appLogger;




};

#endif // LOGMRG_H
