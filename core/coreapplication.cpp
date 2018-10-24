#include "coreapplication.h"
#include <QApplication>
#include "Utils/logmgr.h"
#include <QMessageBox>

bool CoreApplication::notify(QObject *receiver, QEvent *event)
{
    try {
        return QApplication::notify(receiver, event);
    } catch (std::exception &e) {
        QString str;
        str.sprintf("Error %s sending event %s to object %s (%s)",
                    e.what(),
                    typeid(*event).name(),
                    qPrintable(receiver->objectName()),
                    typeid(*receiver).name());

        LogMgr::instance()->LogSysFail(str);
        QMessageBox::critical(nullptr,"System crashed","A critical problem happened. Please check the system log file");
        exit(1);
        //qFatal(str);// shut down the Application
    } catch (...) {
        QString str;
        str.sprintf("Error <unknown> sending event %s to object %s (%s)",
                    typeid(*event).name(),
                    qPrintable(receiver->objectName()),
                    typeid(*receiver).name());

        LogMgr::instance()->LogSysFail(str);
        QMessageBox::critical(nullptr,"System crashed","A critical problem happened. Please check the system log file");
        exit(1);
        //qFatal(str);// shut down the Application
    }

    // qFatal aborts, so this isn't really necessary
    // but you might continue if you use a different logging lib
    return false;
}
