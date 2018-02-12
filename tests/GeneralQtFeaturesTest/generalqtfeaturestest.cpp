#include <QString>
#include <QtTest>


enum Color { red, green, blue };

class GeneralQtFeaturesTester : public QObject
{
    Q_OBJECT

public:
    GeneralQtFeaturesTester();

private Q_SLOTS:
    void DefineEnumTest();
};

GeneralQtFeaturesTester::GeneralQtFeaturesTester()
{
}

void GeneralQtFeaturesTester::DefineEnumTest()
{
    Color r = red;
    QCOMPARE(r,Color::red);
}

QTEST_APPLESS_MAIN(GeneralQtFeaturesTester)

#include "generalqtfeaturestest.moc"
