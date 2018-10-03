#include <QString>
#include <QtTest>
#include <QDebug>


enum Color { red, green, blue };

class GeneralQtFeaturesTester : public QObject
{
    Q_OBJECT

public:
    GeneralQtFeaturesTester();


private Q_SLOTS:
    void testDefineEnum();
    void testNullPointer();
    void testBooleanValues();

};


GeneralQtFeaturesTester::GeneralQtFeaturesTester()
{
}

void GeneralQtFeaturesTester::testDefineEnum()
{
    Color r = red;
    QCOMPARE(r,Color::red);
}

void GeneralQtFeaturesTester::testNullPointer()
{
    qDebug()<<"Null means"<<NULL;

    int i=5;
    int* p=&i;

    if(p == NULL)
    {
        qDebug()<<"p is null";
    }
    else
    {
        qDebug()<<"p is not null";
    }

    int* q=0;
    if(q)
    {
        qDebug()<<"q is empty";
    }
    else
    {
        qDebug()<<"q is not empty";
    }


    int* r;
    qDebug()<<"r value is: "<<r;
    // As you see r is not initialized but it is not equal to zero
    // remember NULL=0=false
    if(r) // just can check if r is NULL (i.e. 0) or not
    {
        qDebug()<<"r is NOT INITIALIZED";
    }
    else
    {
        qDebug()<<"r is NULL";
    }

}

void GeneralQtFeaturesTester::testBooleanValues()
{
    int val =  4<5;
    qDebug()<<"True means: "<<val;
    val = 4>5;
    qDebug()<<"Fals means: "<<val;

}

QTEST_APPLESS_MAIN(GeneralQtFeaturesTester)

#include "generalqtfeaturestest.moc"
