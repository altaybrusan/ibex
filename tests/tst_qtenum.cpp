#include <QString>
#include <QtTest>

enum Color { red, green, blue };


class TestsQtEnum : public QObject
{
    Q_OBJECT

public:
    TestsQtEnum();
    ~TestsQtEnum();

private Q_SLOTS:
    void testEnumApplicationInQt5();

};

TestsQtEnum::TestsQtEnum()
{
    //qDebug()<<"...........Hello from test constructor";
}
TestsQtEnum::~TestsQtEnum()
{
    //qDebug()<<"...........Goodby from test Destructor";
}

void TestsQtEnum::testEnumApplicationInQt5()
{
    Color r = red;
    QCOMPARE(r,Color::red);
}


//QTEST_APPLESS_MAIN(TestsQtEnum)

#include "tst_testsqtenum.moc"
