#include <QDir>
#include <QObject>
#include <QDateTime>
#include <QCoreApplication>

#include "platform.h"
#include "singleton.h"
#include "basiclogmanager.h"


namespace Common {

    /*!
      \bug instead of hard coded destination string the logmanager should
      get a QDir and check if it exists or not. Working with QString is naive
      way to pass path and error prone.
     */
    static auto LOG_DIR= QStringLiteral("../log/");
    static auto LOG_FILE_NAME= QStringLiteral("basic.log");
    static auto DATE_FORMAT= QStringLiteral("dd/MM/yyyy");
    static auto TIME_FORMAT= QStringLiteral("hh:mm:ss");
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

    }

    Platform::~Platform()
    {
    }

    Platform* Platform::instance()
    {
        return Singleton<Platform>::instance(Platform::createInstance);
    }

    /*!
      The \fn GetSystemDate returns the system date in a \b specific
      Format.
      \note In the next application development iterations, this
      function must be generalized to return other formats such as
      ISO, long and short date formats.
      \note These types of settings should be kept in an XML and during
      system loading time all of them should be read out of that.
    */
    QString Platform::GetSystemDate()
    {
        return QDateTime::currentDateTime().toString(DATE_FORMAT);
    }

    /*!
      The \fn GetSystemTime returns the system time in a \b specific
      Format.
      \note In the next application development iterations, this
      function must be generalized to return other formats.
      \note These types of settings should be kept in an XML and during
      system loading time all of them should be read out of that.
    */
    QString Platform::GetSystemTime()
    {
        return QDateTime::currentDateTime().toString(TIME_FORMAT);
    }


}
