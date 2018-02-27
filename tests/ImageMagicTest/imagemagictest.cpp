#include <QString>
#include <QtTest>
#include <Magick++.h>
#include <iostream>
using namespace std;
using namespace Magick;

class ImageMagicTest : public QObject
{
    Q_OBJECT

public:
    ImageMagicTest();

private Q_SLOTS:
    void testTiffToBmpConversion();
};

ImageMagicTest::ImageMagicTest()
{

}

void ImageMagicTest::testTiffToBmpConversion()
{
//    char **argv =new char*[1];
//    InitializeMagick(*argv);
//    // Construct the image object. Separating image construction from the
//      // the read operation ensures that a failure to read the image file
//      // doesn't render the image object useless.
      Image image;
//      try {
//        // Read a file into image object
//        image.read( "logo.jpg" );


//        // Write the image to a file
//        image.write( "x.gif" );
//      }
//      catch( Exception &error_ )
//        {
//          QVERIFY2(true,error_.what());
//        }
}

QTEST_APPLESS_MAIN(ImageMagicTest)

#include "imagemagictest.moc"
