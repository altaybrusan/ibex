#include <QGuiApplication>
#include "platform.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Common::Platform::instance();
    return app.exec();
}
