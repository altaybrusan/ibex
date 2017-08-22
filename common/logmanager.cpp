#include <QDir>
#include "logmanager.h"
#include "consoleappender.h"
#include "logger.h"
#include "ttcclayout.h"


#include "basicconfigurator.h"
#include "consoleappender.h"
#include "dailyrollingfileappender.h"
#include "fileappender.h"
#include "configuratorhelper.h"
#include "datetime.h"
#include "factory.h"
#include "initialisationhelper.h"
#include "optionconverter.h"
#include "patternformatter.h"
#include "properties.h"
#include "logmanager.h"
#include "loggerrepository.h"
#include "patternlayout.h"
#include "propertyconfigurator.h"
#include "rollingfileappender.h"
#include "simplelayout.h"
#include "ttcclayout.h"
#include "denyallfilter.h"
#include "levelmatchfilter.h"
#include "levelrangefilter.h"
#include "stringmatchfilter.h"

using namespace Log4Qt;

namespace Common {
    /*! \note The LogManager is a wrapper around Log4qt.
     * The main appender is rolling file and also provide
     * an auxillary ConsoleAppender.
     * \note For the next iterations LogManager should implement ILogmanager
     * and generalize the Logger and let it load the settings.
     *  @param parent the QObject parent object.
     *  @param logDest the destination folder in which the log file(s) is (are) saved.
     *  @param logFileName the log file name
    */
    LogManager::LogManager(QObject* parent = 0, QString logDest, QString logFileName) :
        QObject(parent),
        _logger(Logger::rootLogger()),
        _layout(new Log4Qt::PatternLayout(this)),
        _level(LogLevel::ALL),
        _active(true),
        _format("[%d{yyyy-MM-dd}] %5p %m%n"),
        _logFileName(logFileName),
        _LogFileDest(logDest),
        _RoleFileSize("5MB")
    {
        static_cast<PatternLayout *>(_layout.data())->setConversionPattern(_format);

        // Check if the destination log folder exists or not
        if(!CheckLoggingDestination(_LogFileDest))
        {
            SendErrorMessage(tr("Internal resource path missing: "+ _logdir.canonicalPath()));
            return;
        }

        // The log manager is a builder pattern. It knows the steps to
        // make a logger object
        UpdateLayout();
        AddRoleAppender();
        AddConsoleAppender();

    }

    void LogManager::LogMessage(LogLevel level, QString message)
    {

    }

    void LogManager::SetLevel(LogLevel level)
    {

    }

    void LogManager::EnableLogger()
    {
        UpdateLogLevel(_level);
    }

    void LogManager::DisableLogger()
    {
        _logger.setLevel(Level::OFF_INT);
    }

    void LogManager::DisableConsoleLogger()
    {
        RemoveConsoleAppender();
    }

    void LogManager::EnableConsoleLogger()
    {
        AddConsoleAppender();
    }



    void LogManager::SetMesageFormatter(QString format)
    {
        _format(format);
        UpdateLayout();
    }

    bool LogManager::CheckLoggingDestination(QString logDir)
    {
        QDir _logdir(logDir);
        if(!_logdir.exists())
        {
            return false;
        }
        return true;
    }

    void LogManager::SendErrorMessage(const QString &msg)
    {
        emit NotifyStatusMessage(msg);
    }

    void LogManager::UpdateLogLevel(LogLevel level)
    {
        switch (level) {
        case LogLevel::ALL:
            _logger.setLevel(Log4Qt::Level::ALL_INT);
            break;
        case LogLevel::DEBUG:
            _logger.setLevel(Log4Qt::Level::DEBUG_INT);
            break;
        case LogLevel::ERROR:
            _logger.setLevel(Log4Qt::Level::ERROR_INT);
            break;
        case LogLevel::FATAL:
            _logger.setLevel(Log4Qt::Level::FATAL_INT);
            break;
        case LogLevel::INFO:
            _logger.setLevel(Log4Qt::Level::INFO_INT);
            break;
        case LogLevel::OFF:
            _logger.setLevel(Log4Qt::Level::OFF_INT);
            break;
        case LogLevel::TRACE:
            _logger.setLevel(Log4Qt::Level::TRACE_INT);
            break;
        case LogLevel::WARN:
            _logger.setLevel(Log4Qt::Level::WARN_INT);
            break;

        default:
            break;
        }
    }

    void LogManager::UpdateLayout()
    {
        _layout(new Log4Qt::PatternLayout(this));
        static_cast<Log4Qt::PatternLayout *>(_layout.data())->setConversionPattern(_format);

    }

    void LogManager::AddRoleAppender()
    {
        Log4Qt::RollingFileAppender * roleFileAppender =new Log4Qt::RollingFileAppender(layout, _LogFileDest + _logFileName, true);

        roleFileAppender->setLayout(layout);
        roleFileAppender->setName("Role appender");
        roleFileAppender->setImmediateFlush(true);
        roleFileAppender->setMaxFileSize(_RoleFileSize);
        roleFileAppender->setMaxBackupIndex(2);
        roleFileAppender->activateOptions();

        _logger.addAppender(roleFileAppender);

    }

    void LogManager::AddConsoleAppender()
    {
        ConsoleAppender *consoleAppender = new ConsoleAppender(_layout, ConsoleAppender::STDOUT_TARGET);
        consoleAppender->setName(QLatin1String("Console Appender"));
        consoleAppender->activateOptions();

        _logger->addAppender(consoleAppender);

    }

    void LogManager::RemoveConsoleAppender()
    {
        _logger.removeAppender("Console Appender");
    }



}
