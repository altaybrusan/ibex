#include "basiclogmanager.h"
#include <QDir>
#include <QObject>
#include <QDebug>

#include "logmanager.h"
#include "consoleappender.h"
#include "logger.h"
#include "consoleappender.h"
#include "patternlayout.h"
#include "rollingfileappender.h"
#include "loggerrepository.h"

namespace Common {

    using namespace Log4Qt;
    static auto CONSOLE_APPENDER_NAME= QStringLiteral("Console_Appender");
    static auto ROLEFILE_APPENDER_NAME= QStringLiteral("Role Appender");

    /*! \note The \b BasicLogManager is a wrapper around Log4qt.
     * The main appender is rolling file and also provide
     * an auxillary ConsoleAppender.
     * \note For the next application development iterations \b BasicLogManager
     * should implement ILogmanager
     * and generalize the Logger and let it load the settings.
     *
     *  @param parent the QObject parent object.
     *  @param logDest the destination folder in which the log file(s) is (are) saved.
     *  @param logFileName the log file name
     */
    BasicLogManager::BasicLogManager(QObject* parent, QString logDest, QString logFileName) :
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
        //static_cast<PatternLayout *>(_layout.data())->setConversionPattern(_format);

        // Check if the destination log folder exists or not
        if(!CheckLoggingDestination(_LogFileDest))
        {
            QString _msg="Internal resource path missing: " + logDest;
            SendErrorMessage(tr(_msg.toStdString().c_str()));
            return;
        }

        // The RoleFileLogManager is a builder pattern. It knows the steps to
        // make a logger object
        UpdateLayout();
        AddRoleAppender();
        AddConsoleAppender();
    }

        void BasicLogManager::LogMessage(LogLevel level, QString message)
        {
            switch (level) {
            case LogLevel::ALL:
                _logger->log(Level::ALL_INT,message);
                break;
            case LogLevel::DEBUG:
                _logger->log(Level::DEBUG_INT,message);
                break;
            case LogLevel::ERROR:
                _logger->log(Level::ERROR_INT,message);
                break;
            case LogLevel::FATAL:
                _logger->log(Level::FATAL_INT,message);
                break;
            case LogLevel::INFO:
                _logger->log(Level::INFO_INT,message);
                break;
            case LogLevel::OFF:
                _logger->log(Level::OFF_INT,message);
                break;
            default:
                break;
            }

        }

        void BasicLogManager::EnableLogger()
        {
            UpdateLogLevel(_level);
        }
        void BasicLogManager::DisableLogger()
        {            
            _logger->setLevel(Level::OFF_INT);
        }

        void BasicLogManager::EnableConsoleLogger()
        {
            AddConsoleAppender();
        }
        void BasicLogManager::DisableConsoleLogger()
        {
            auto _Ptr=_logger->appender(CONSOLE_APPENDER_NAME);
            if(!_Ptr.isNull())
                _logger->removeAppender(_Ptr);
          }

        void BasicLogManager::UpdateMesageFormatter(QString format)
        {
            _format = format;
            UpdateLayout();
        }
        void BasicLogManager::UpdateLogLevel(LogLevel level)
        {
            switch (level) {
            case LogLevel::ALL:
                _logger->setLevel(Log4Qt::Level::ALL_INT);
                _level=LogLevel::ALL;
                break;
            case LogLevel::DEBUG:
                _logger->setLevel(Log4Qt::Level::DEBUG_INT);
                _level=LogLevel::DEBUG;
                break;
            case LogLevel::ERROR:
                _logger->setLevel(Log4Qt::Level::ERROR_INT);
                _level=LogLevel::ERROR;
                break;
            case LogLevel::FATAL:
                _logger->setLevel(Log4Qt::Level::FATAL_INT);
                _level=LogLevel::FATAL;
                break;
            case LogLevel::INFO:
                _logger->setLevel(Log4Qt::Level::INFO_INT);
                _level=LogLevel::INFO;
                break;
            case LogLevel::OFF:
                _logger->setLevel(Log4Qt::Level::OFF_INT);
                _level=LogLevel::OFF;
                break;
            case LogLevel::TRACE:
                _logger->setLevel(Log4Qt::Level::TRACE_INT);
                _level=LogLevel::TRACE;
                break;
            case LogLevel::WARN:
                _logger->setLevel(Log4Qt::Level::WARN_INT);
                _level=LogLevel::WARN;
                break;

            default:
                break;
            }
        }
        void BasicLogManager::UpdateLayout()
        {
            if(_layout.isNull())
                _layout = new Log4Qt::PatternLayout(this);
            static_cast<Log4Qt::PatternLayout *>(_layout.data())->setConversionPattern(_format);
        }

        bool BasicLogManager::CheckLoggingDestination(QString logDir)
        {
            QDir _logdir(logDir);
            if(!_logdir.exists())
            {
                return false;
            }
            return true;
        }
        void BasicLogManager::SendErrorMessage(const QString &msg)
        {
            emit NotifyStatusMessage(msg);
        }


        void BasicLogManager::AddRoleAppender()
        {
            Log4Qt::RollingFileAppender * roleFileAppender =new Log4Qt::RollingFileAppender(_layout, _LogFileDest + _logFileName, true);
            roleFileAppender->setLayout(_layout);
            roleFileAppender->setName(ROLEFILE_APPENDER_NAME);
            roleFileAppender->setImmediateFlush(true);
            roleFileAppender->setMaxFileSize(_RoleFileSize);
            roleFileAppender->setMaxBackupIndex(2);
            roleFileAppender->activateOptions();

            _logger->addAppender(roleFileAppender);

        }
        void BasicLogManager::AddConsoleAppender()
        {
            // check if appender had already added or not.
            if(_logger->appender(CONSOLE_APPENDER_NAME).isNull())
            {
                // if not then add new appender.
                ConsoleAppender *consoleAppender = new ConsoleAppender(_layout, ConsoleAppender::STDOUT_TARGET);
                consoleAppender->setName(CONSOLE_APPENDER_NAME);
                consoleAppender->activateOptions();

                _logger->addAppender(consoleAppender);

            }


        }

        BasicLogManager::~BasicLogManager()
        {
            _logger->removeAllAppenders();
            _logger->loggerRepository()->shutdown();
        }


}
