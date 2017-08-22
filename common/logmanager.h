#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <QObject>
#include "logger.h"
#include "rollingfileappender.h"


namespace Common {

    /*! For the standard levels:
     * ALL < DEBUG < INFO < WARN < ERROR < FATAL < OFF.
     */
    enum LogLevel
    {
        /* All levels including custom levels. */
        ALL,
        /*useful to debug an application*/
        DEBUG,
        /*Designates error events that might still
        *  allow the application to continue running.*/
        ERROR,
        /*Designates very severe error events that
        *  will presumably lead the application to abort.*/
        FATAL,
        /*Designates informational messages that
        *  highlight the progress of the application at coarse-grained level.*/
        INFO,
        /*	The highest possible rank and is intended to turn off logging.*/
        OFF,
        /*	Designates finer-grained informational events than the DEBUG.*/
        TRACE,
        /*Designates potentially harmful situations.*/
        WARN
    };

    class LogManager:public QObject
    {
        Q_OBJECT

    public:
        LogManager(QObject *parent,QString logDest,QString logFileName);
        void LogMessage(LogLevel level, QString message);
        void SetLevel(LogLevel level);
        void DisableLogger();
        void DisableConsoleLogger();
        void EnableConsoleLogger();
        void EnableLogger();
        void SetMesageFormatter(QString format);


    signals:
        void NotifyStatusMessage(QString message);

    private:
        void SetFilePath();
        bool CheckLoggingDestination(QString logDir);
        void SendErrorMessage(const QString& msg);
        void UpdateLogLevel(LogLevel level);
        void AddRoleAppender();
        void AddConsoleAppender();
        void RemovevConsoleAppender();

        Log4Qt::Logger _logger;
        Log4Qt::LayoutSharedPtr _layout;
        Log4Qt::RollingFileAppender * _rollFileAppender;
        LogLevel _level;
        bool _active;
        QString _format;
        QString _logFileName;
        QString _LogFileDest;
        QString _RoleFileSize;
    };
}


#endif // LOGMANAGER_H


