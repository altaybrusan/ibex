#ifndef PLATFORM_H
#define PLATFORM_H

#include <QObject>
#include "basiclogmanager.h"


namespace Common {


    class Platform:public QObject
    {
        Q_OBJECT
    public:
        ~Platform();
        static Platform* instance();

    private:
        Platform(QObject* parent = 0);
        static Platform* createInstance();
        void InstantiateLogManager();
        void TestLogManager();


        BasicLogManager* _manager;

    };
}

#endif // PLATFORM_H


