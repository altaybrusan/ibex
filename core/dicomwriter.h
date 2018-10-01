#ifndef DICOMWRITER_H
#define DICOMWRITER_H
#include "dcmtk/config/osconfig.h"    /* make sure OS specific configuration is included first */

#define INCLUDE_CSTDLIB
#define INCLUDE_CSTDIO
#define INCLUDE_CSTRING
#include "dcmtk/ofstd/ofstdinc.h"

BEGIN_EXTERN_C
#ifdef HAVE_FCNTL_H
#include <fcntl.h>       /* for O_RDONLY */
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>   /* required for sys/stat.h */
#endif
#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>    /* for stat, fstat */
#endif
END_EXTERN_C

#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk/dcmdata/cmdlnarg.h"
#include "dcmtk/ofstd/ofconapp.h"
#include "dcmtk/dcmdata/dcuid.h"       /* for dcmtk version name */
#include "dcmtk/ofstd/ofstd.h"
#include "dcmtk/dcmdata/dcistrmz.h"    /* for dcmZlibExpectRFC1950Encoding */

#ifdef WITH_ZLIB
#include <zlib.h>        /* for zlibVersion() */
#endif

#define OFFIS_CONSOLE_APPLICATION "dcm2pdf"

static OFLogger dcm2pdfLogger = OFLog::getLogger("dcmtk.apps." OFFIS_CONSOLE_APPLICATION);

static char rcsid[] = "$dcmtk: " OFFIS_CONSOLE_APPLICATION " v"
  OFFIS_DCMTK_VERSION " " OFFIS_DCMTK_RELEASEDATE " $";

#define FILENAME_PLACEHOLDER "#f"

static OFString replaceChars(const OFString &srcstr, const OFString &pattern, const OFString &substitute)
    /*
     * This function replaces all occurrences of pattern in srcstr with substitute and returns
     * the result as a new OFString variable. Note that srcstr itself will not be changed.
     *
     * Parameters:
     *   srcstr     - [in] The source string.
     *   pattern    - [in] The pattern string which shall be substituted.
     *   substitute - [in] The substitute for pattern in srcstr.
     */
{
  OFString result = srcstr;
  size_t pos = 0;

  while (pos != OFString_npos)
  {
    pos = result.find(pattern, pos);

    if (pos != OFString_npos)
    {
      result.replace(pos, pattern.size(), substitute);
      pos += substitute.size();
    }
  }

  return result;
}

#define SHORTCOL 3
#define LONGCOL 20



static int tstpdf2Dcm()
{

     const char *opt_ifname = "D:\\Trash\\demo.pdf";
     const char *opt_ofname = "D:\\Trash\\out.dcm";
     const char    *opt_execString = NULL;
     E_FileReadMode opt_readMode = ERM_autoDetect;
     E_TransferSyntax opt_ixfer = EXS_Unknown;

     /* print resource identifier */
     OFLOG_DEBUG(dcm2pdfLogger, rcsid << OFendl);

     /* make sure data dictionary is loaded */
     if (!dcmDataDict.isDictionaryLoaded())
      {
        OFLOG_WARN(dcm2pdfLogger, "no data dictionary loaded, check environment variable: "
              << DCM_DICT_ENVIRONMENT_VARIABLE);
      }

      // open inputfile
      if ((opt_ifname == NULL) || (strlen(opt_ifname) == 0))
      {
          OFLOG_FATAL(dcm2pdfLogger, "invalid filename: <empty string>");
          return 1;
      }

       DcmFileFormat fileformat;
       DcmDataset * dataset = fileformat.getDataset();

       OFLOG_INFO(dcm2pdfLogger, "open input file " << opt_ifname);

       OFCondition error = fileformat.loadFile(opt_ifname, opt_ixfer, EGL_noChange, DCM_MaxReadLength, opt_readMode);

       if (error.bad())
       {
           OFLOG_FATAL(dcm2pdfLogger, error.text() << ": reading file: " << opt_ifname);
           return 1;
       }

       OFString sopClass;
       error = dataset->findAndGetOFString(DCM_SOPClassUID, sopClass);
       if (error.bad() || sopClass != UID_EncapsulatedPDFStorage)
       {
           OFLOG_FATAL(dcm2pdfLogger, "not an Encapsulated PDF Storage object: " << opt_ifname);
           return 1;
       }

       DcmElement *delem = NULL;
       error = dataset->findAndGetElement(DCM_EncapsulatedDocument, delem);
       if (error.bad() || delem == NULL)
       {
           OFLOG_FATAL(dcm2pdfLogger, "attribute (0042,0011) Encapsulated Document missing.");
           return 1;
       }

       Uint32 len = delem->getLength();
       Uint8 *pdfDocument = NULL;
       error = delem->getUint8Array(pdfDocument);
       if (error.bad() || pdfDocument == NULL || len == 0)
       {
           OFLOG_FATAL(dcm2pdfLogger, "attribute (0042,0011) Encapsulated Document empty or wrong VR.");
           return 1;
       }

       /* strip pad byte at end of file, if there is one. The PDF format expects
        * files to end with %%EOF followed by CR/LF. If the last character of the
        * file is not a CR or LF, we assume it is a pad byte and remove it.
        */
       if (pdfDocument[len-1] != 10 && pdfDocument[len-1] != 13)
       {
           --len;
       }

       FILE *pdffile = fopen(opt_ofname, "wb");
       if (pdffile == NULL)
       {
           OFLOG_FATAL(dcm2pdfLogger, "unable to create file " << opt_ofname);
           return 1;
       }

       if (len != fwrite(pdfDocument, 1, len, pdffile))
       {
           OFLOG_FATAL(dcm2pdfLogger, "write error in file " << opt_ofname);
           fclose(pdffile);
           return 1;
       }

       fclose(pdffile);

       OFLOG_INFO(dcm2pdfLogger, "conversion successful");

       if (opt_execString)
       {
           OFString cmdStr = opt_execString;
           cmdStr = replaceChars(cmdStr, OFString(FILENAME_PLACEHOLDER), opt_ofname);

           // Execute command and return result
           return 0;//system(cmdStr.c_str());
       }

}


class DicomWriter
{
public:
    DicomWriter();
};

#endif // DICOMWRITER_H
