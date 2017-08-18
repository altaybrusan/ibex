#include <QString>
#include <QtTest>

class TestsPlatform : public QObject
{
    Q_OBJECT

public:
    TestsPlatform();

private Q_SLOTS:
    void testCommon();
};

TestsPlatform::TestsPlatform()
{
}

void TestsPlatform::testCommon()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TestsPlatform)

#include "testsplatform.moc"
