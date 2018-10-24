#ifndef COREAPPLICATION_H
#define COREAPPLICATION_H
#include <QApplication>


class CoreApplication:public QApplication
{
public:
    CoreApplication (int & argc, char ** argv):QApplication(argc, argv){}
    bool notify (QObject * receiver, QEvent * event);
};

#endif // COREAPPLICATION_H
