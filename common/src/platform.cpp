#include "platform.h"
#include <QObject>
#include <QCoreApplication>
#include <QDir>
#include "singleton.h"
#include"basiclogmanager.h"


namespace Common {

    /*!
      \bug instead of hard coded destination string the logmanager should
      get a QDir and check if it exists or not. Working with QString is naive
      way to pass path and error prone.
     */
    static auto LOG_DIR= QStringLiteral("../log/");
    static auto LOG_FILE_NAME= QStringLiteral("basic.log");

    Platform::Platform(QObject *parent):
        QObject(parent)
    {
        InstantiateLogManager();

    }

    Platform* Platform::createInstance()
    {
        return new Platform();
    }

    void Platform::InstantiateLogManager()
    {
        QDir dir(LOG_DIR);
        if (!dir.exists()) {
            dir.mkpath(LOG_DIR);
        }
        _manager= new BasicLogManager(this,LOG_DIR,LOG_FILE_NAME);
        // The qt unit test can not run on exe file so the tests are
        // written here.
        TestLogManager();


    }

    void Platform::TestLogManager()
    {









    }

    Platform::~Platform()
    {
    }

    Platform* Platform::instance()
    {
        return Singleton<Platform>::instance(Platform::createInstance);
    }

}
