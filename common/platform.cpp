#include "platform.h"
#include <QObject>
#include <QCoreApplication>
#include "singleton.h"

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


namespace Common {

    Platform::Platform(QObject *parent):
        QObject(parent)
    {
        auto logger = Log4Qt::Logger::rootLogger();

        // Create a layout
        //auto logger = Log4Qt::Logger::rootLogger();
        Log4Qt::TTCCLayout *layout = new Log4Qt::TTCCLayout();
        layout->setName(QLatin1String("My Layout"));
        layout->setThreadPrinting(false);

        layout->setDateFormat("dd.MM.yyyy hh:mm:ss");
        layout->setCategoryPrefixing(false);
        layout->setContextPrinting(false);
        layout->activateOptions();
//        // Create a console appender
//        Log4Qt::ConsoleAppender *consoleAppender = new Log4Qt::ConsoleAppender(layout, Log4Qt::ConsoleAppender::STDOUT_TARGET);
//        consoleAppender->setName(QLatin1String("My Appender"));
//        consoleAppender->activateOptions();
//        // Add appender on root logger
//        logger->addAppender(consoleAppender);
        // Create a file appender

//        Log4Qt::LayoutSharedPtr layout(new Log4Qt::TTCCLayout(logger));
//        static_cast<Log4Qt::TTCCLayout *>(layout.data())->setDateFormat("dd.MM.yyyy hh:mm:ss.zzz");
//        //static_cast<Log4Qt::TTCCLayout *>(layout.data())->setContextPrinting(true);


//        layout->activateOptions();
////        Log4Qt::LayoutSharedPtr binlayout(new Log4Qt::BinaryToTextLayout(layout, rootLogger));


        Log4Qt::LayoutSharedPtr layout2(new Log4Qt::PatternLayout(this));
        static_cast<Log4Qt::PatternLayout *>(layout2.data())->setConversionPattern("[%d{yyyy-MM-dd}] %5p %m%n");


        Log4Qt::RollingFileAppender * rFileAppender =new Log4Qt::RollingFileAppender(layout, QCoreApplication::applicationDirPath() + "/basic.log", true);


        rFileAppender->setLayout(layout2);
        rFileAppender->setName("My rolling file appender");
        rFileAppender->setImmediateFlush(true);
        rFileAppender->setMaxFileSize("1KB");
        rFileAppender->setMaxBackupIndex(2);


        rFileAppender->activateOptions();
//        Log4Qt::FileAppender *fileAppender = new Log4Qt::FileAppender(layout, QCoreApplication::applicationDirPath() + "/basic.log", true);
//        fileAppender->setLayout(layout);
//        fileAppender->setName(QLatin1String("My file appender"));
//        fileAppender->setImmediateFlush(true);
//        fileAppender->activateOptions();

        // Add appender on root logger
        //logger->addAppender(fileAppender);
        logger->addAppender(rFileAppender);

        // Set level to info
        logger->setLevel(Log4Qt::Level::INFO_INT);

        // Enable handling of Qt messages
        Log4Qt::LogManager::setHandleQtMessages(true);


        QString introMessage="Demo message";
        if (!introMessage.isEmpty())
            logger->info(introMessage);
        for(int i=0;i<1000;i++)
        {
            logger->info(introMessage+"  "+QString::number(i));
        }

        qWarning("Handling Qt messages is enabled");


        logger = Log4Qt::Logger::rootLogger();
        logger->removeAllAppenders();
        logger->loggerRepository()->shutdown();



    }

    Platform* Platform::createInstance()
    {
        return new Platform();
    }

    Platform::~Platform()
    {
    }

    Platform* Platform::instance()
    {
        return Singleton<Platform>::instance(Platform::createInstance);
    }

}
