#include <QString>
#include <QDebug>
#include <QtTest/QtTest>
#include "../src/platform.h"

using namespace Common;
static auto LOG_DIR= QStringLiteral("../log/");
static auto LOG_FILE_NAME= QStringLiteral("basic.log");
class Testplatform : public QObject
{
    Q_OBJECT

public:
    Testplatform();

private Q_SLOTS:
    void initTestCase(); // will be called before the first test function is executed.
    void cleanupTestCase(); // will be called after the last test function was executed.
    void init(); // will be called before each test function is executed.
    void cleanup(); // will be called after every test function.

    void TestSystemDate();
    void TestSystemTime();

private:
    Platform* _platform;

};

Testplatform::Testplatform()
{

}

void Testplatform::initTestCase()
{
    _platform = Platform::instance();
}
void Testplatform::cleanupTestCase()
{

}
void Testplatform::init()
{

}
void Testplatform::cleanup()
{

}


void Testplatform::TestSystemDate()
{
    QString _val =_platform->GetSystemDate();
    QVERIFY2(_val == "24/08/2017" , "The date is in Turkish format");
}

void Testplatform::TestSystemTime()
{
    QString _val =_platform->GetSystemTime();
    QVERIFY2(_val == "6:24:25" , _val.toStdString().c_str());
}




QTEST_MAIN(Testplatform)
#include "testplatform.moc"
