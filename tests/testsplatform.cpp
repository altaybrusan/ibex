#include <QString>
#include <QtTest>
//#include "../common/platform.h"

class TestsPlatform : public QObject
{
    Q_OBJECT

    public:

    private Q_SLOTS:
        void testPlatformInstantiation();
};


void TestsPlatform::testPlatformInstantiation()
{
    //QVERIFY2(Common::Platform::instance()->metaObject()->className()!="Platform", "Failure");
}

QTEST_APPLESS_MAIN(TestsPlatform)

#include "testsplatform.moc"
