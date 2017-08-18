#ifndef PLATFORM_H
#define PLATFORM_H
//#include <QWidget>

#include <QObject>
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
    };
}

#endif // PLATFORM_H


