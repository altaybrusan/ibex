#include "platform.h"
#include <QObject>
#include "singleton.h"

namespace Common {

    Platform::Platform(QObject *parent):
        QObject(parent)
    {

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
