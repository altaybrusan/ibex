

#ifndef DICOMTAGLIST_H
#define DICOMTAGLIST_H
#include <QMap>
#include <QString>
class Dicom{
public:
    static Dicom &GetInstance()
    {
        static Dicom instance;
        return instance;
    }

private:
    QMap<QString,QString> tagsCollection;
    Dicom()
    {
       tagsCollection.insert("0002,0000" , "File Meta Information Group Length");
       tagsCollection.insert("0002,0001" , "File Meta Information Version");
       tagsCollection.insert("0002,0002" , "Media Storage SOP Class UID");
       tagsCollection.insert("0002,0003" , "Media Storage SOP Instance UID");
       tagsCollection.insert("0002,0010" , "Transfer Syntax UID");
       tagsCollection.insert("0002,0012" , "Implementation Class UID");
       tagsCollection.insert("0002,0013" , "Implementation Version Name");
       tagsCollection.insert("0002,0016" , "Source Application Entity Title");
       tagsCollection.insert("0002,0017" , "Sending Application Entity Title");
       tagsCollection.insert("0002,0018" , "Receiving Application Entity Title");
       tagsCollection.insert("0002,0100" , "Private Information Creator UID");
       tagsCollection.insert("0002,0102" , "Private Information");
       tagsCollection.insert("0004,1130" , "File-set ID");
       tagsCollection.insert("0004,1141" , "File-set Descriptor File ID");
       tagsCollection.insert("0004,1142" , "Specific Character Set of File-set Descriptor File");
       tagsCollection.insert("0004,1200" , "Offset of the First Directory Record of the Root Directory Entity");
       tagsCollection.insert("0004,1202" , "Offset of the Last Directory Record of the Root Directory Entity");
       tagsCollection.insert("0004,1212" , "File-set Consistency Flag");
       tagsCollection.insert("0004,1220" , "Directory Record Sequence");
       tagsCollection.insert("0004,1400" , "Offset of the Next Directory Record");
       tagsCollection.insert("0004,1410" , "Record In-use Flag");
       tagsCollection.insert("0004,1420" ,	"Offset of Referenced Lower-Level Directory Entity");
       tagsCollection.insert("0004,1430" ,	"Directory Record Type");
       tagsCollection.insert("0004,1432" ,	"Private Record UID");
       tagsCollection.insert("0004,1500" , "Referenced File ID");
       tagsCollection.insert("0004,1504" , "MRDR Directory Record Offset");//	Retired
       tagsCollection.insert("0004,1510" , "Referenced SOP Class UID in File");
       tagsCollection.insert("0004,1511" , "Referenced SOP Instance UID in File");
       tagsCollection.insert("0004,1512" , "Referenced Transfer Syntax UID in File");
       tagsCollection.insert("0004,151A" , "Referenced Related General SOP Class UID in File");
       tagsCollection.insert("0004,1600" , "Number of References");//	Retired
       tagsCollection.insert("0008,0001" , "Length to End");//	Retired
       tagsCollection.insert("0008,0005" , "Specific Character Set");
       tagsCollection.insert("0008,0006" , "Language Code Sequence");
       tagsCollection.insert("0008,0008" , "Image Type");
       tagsCollection.insert("0008,0010" , "Recognition Code");//	Retired
       tagsCollection.insert("0008,0012" , "Instance Creation Date");
       tagsCollection.insert("0008,0013" , "Instance Creation Time");
       tagsCollection.insert("0008,0014" , "Instance Creator UID");
       tagsCollection.insert("0008,0015" , "Instance Coercion DateTime");
       tagsCollection.insert("0008,0016" , "SOP Class UID");
       tagsCollection.insert("0008,0018" , "SOP Instance UID");
       tagsCollection.insert("0008,001A" , "Related General SOP Class UID");
       tagsCollection.insert("0008,001B" , "Original Specialized SOP Class UID");
       tagsCollection.insert("0008,0020" , "Study Date");
       tagsCollection.insert("0008,0021" , "Series Date");
       tagsCollection.insert("0008,0022" , "Acquisition Date");
       tagsCollection.insert("0008,0023" , "Content Date");
       tagsCollection.insert("0008,0024" , "Overlay Date");//Retired
       tagsCollection.insert("0008,0025" , "Curve Date");	//Retired
       tagsCollection.insert("0008,002A" , "Acquisition DateTime");
       tagsCollection.insert("0008,0030" , "Study Time");
       tagsCollection.insert("0008,0031" , "Series Time");
       tagsCollection.insert("0008,0032" , "Acquisition Time");
       tagsCollection.insert("0008,0033" , "Content Time");
       tagsCollection.insert("0008,0034" , "Overlay Time");//Retired;
       tagsCollection.insert("0008,0035"  , "Curve Time");//Retired;
       tagsCollection.insert("0008,0040"  , "Data Set Type");//Retired;
       tagsCollection.insert("0008,0041"  , "Data Set Subtype");//Retired;
       tagsCollection.insert("0008,0042"  , "Nuclear Medicine Series Type");//Retired;
       tagsCollection.insert("0008,0050"  , "Accession Number");
       tagsCollection.insert("0008,0051"  , "Issuer of Accession Number Sequence");
       tagsCollection.insert("0008,0052"  , "Query/Retrieve Level");
       tagsCollection.insert("0008,0053"  , "Query/Retrieve View");
       tagsCollection.insert("0008,0054"  , "Retrieve AE Title");
       tagsCollection.insert("0008,0055"  , "Station AE Title");
       tagsCollection.insert("0008,0056"  , "Instance Availability");
       tagsCollection.insert("0008,0058"  , "Failed SOP Instance UID List");
       tagsCollection.insert("0008,0060"  , "Modality");
       tagsCollection.insert("0008,0061"  , "Modalities in Study");
       tagsCollection.insert("0008,0062"  , "SOP Classes in Study");
       tagsCollection.insert("0008,0064"  , "Conversion Type");
       tagsCollection.insert("0008,0068"  , "Presentation Intent Type");
       tagsCollection.insert("0008,0070"  , "Manufacturer");
       tagsCollection.insert("0008,0080"  , "Institution Name");
       tagsCollection.insert("0008,0081"  , "Institution Address");
       tagsCollection.insert("0008,0082"  , "Institution Code Sequence");
       tagsCollection.insert("0008,0090"  , "Referring Physician's Name");
       tagsCollection.insert("0008,0092"  , "Referring Physician's Address");
       tagsCollection.insert("0008,0094"  , "Referring Physician's Telephone Numbers");
       tagsCollection.insert("0008,0096"  , "Referring Physician Identification Sequence");
       tagsCollection.insert("0008,009C"  , "Consulting Physician's Name");
       tagsCollection.insert("0008,009D"  , "Consulting Physician Identification Sequence");
       tagsCollection.insert("0008,0100"  , "Code Value");
       tagsCollection.insert("0008,0101"  , "Extended Code Value");
       tagsCollection.insert("0008,0102"  , "Coding Scheme Designator");
       tagsCollection.insert("0008,0103"  , "Coding Scheme Version");
       tagsCollection.insert("0008,0104"  , "Code Meaning");
       tagsCollection.insert("0008,0105"  , "Mapping Resource");
       tagsCollection.insert("0008,0106"  , "Context Group Version");
       tagsCollection.insert("0008,0107"  , "Context Group Local Version");
       tagsCollection.insert("0008,0108"  , "Extended Code Meaning");
       tagsCollection.insert("0008,010B"  , "Context Group Extension Flag");
       tagsCollection.insert("0008,010C"  , "Coding Scheme UID");
       tagsCollection.insert("0008,010D"  , "Context Group Extension Creator UID");
       tagsCollection.insert("0008,010F"  , "Context Identifier");
       tagsCollection.insert("0008,0110"  , "Coding Scheme Identification Sequence");
       tagsCollection.insert("0008,0112"  , "Coding Scheme Registry");
       tagsCollection.insert("0008,0114"  , "Coding Scheme External ID");
       tagsCollection.insert("0008,0115"  , "Coding Scheme Name");
       tagsCollection.insert("0008,0116"  , "Coding Scheme Responsible Organization");
       tagsCollection.insert("0008,0117"  , "Context UID");
       tagsCollection.insert("0008,0118"  , "Mapping Resource UID");
       tagsCollection.insert("0008,0119"  , "Long Code Value");
       tagsCollection.insert("0008,0120"  , "URN Code Value");
       tagsCollection.insert("0008,0121"  , "Equivalent Code Sequence");
       tagsCollection.insert("0008,0122"  , "Mapping Resource Name");
       tagsCollection.insert("0008,0123"  , "Context Group Identification Sequence");
       tagsCollection.insert("0008,0124"  , "Mapping Resource Identification Sequence");
       tagsCollection.insert("0008,0201"  , "Timezone Offset From UTC");
       tagsCollection.insert("0008,0300"  , "Private Data Element Characteristics Sequence");
       tagsCollection.insert("0008,0301"  , "Private Group Reference");
       tagsCollection.insert("0008,0302"  , "Private Creator Reference");
       tagsCollection.insert("0008,0303"  , "Block Identifying Information Status");
       tagsCollection.insert("0008,0304"  , "Nonidentifying Private Elements");
       tagsCollection.insert("0008,0306"  , "Identifying Private Elements");
       tagsCollection.insert("0008,0305"  , "Deidentification Action Sequence");
       tagsCollection.insert("0008,0307"  , "Deidentification Action");
       tagsCollection.insert("0008,1000"  , "Network ID	Retired");
       tagsCollection.insert("0008,1010"  , "Station Name");
       tagsCollection.insert("0008,1030"  , "Study Description");
       tagsCollection.insert("0008,1032"  , "Procedure Code Sequence");
       tagsCollection.insert("0008,103E"  ,	"Series Description");
       tagsCollection.insert("0008,103F"  ,	"Series Description Code Sequence");
       tagsCollection.insert("0008,1040"  ,	"Institutional Department Name");
       tagsCollection.insert("0008,1048"  ,	"Physician(s) of Record");
       tagsCollection.insert("0008,1049"  ,	"Physician(s) of Record Identification Sequence");
       tagsCollection.insert("0008,1050"  ,	"Performing Physician's Name");
       tagsCollection.insert("0008,1052"  ,	"Performing Physician Identification Sequence");
       tagsCollection.insert("0008,1060"  ,	"Name of Physician(s) Reading Study");
       tagsCollection.insert("0008,1062"  ,	"Physician(s) Reading Study Identification Sequence");
       tagsCollection.insert("0008,1070"  ,	"Operators' Name");
       tagsCollection.insert("0008,1072"  ,	"Operator Identification Sequence");
       tagsCollection.insert("0008,1080"  ,	"Admitting Diagnoses Description");
       tagsCollection.insert("0008,1084"  ,	"Admitting Diagnoses Code Sequence");
       tagsCollection.insert("0008,1090"  ,	"Manufacturer's Model Name");
       tagsCollection.insert("0008,1100" ,	"Referenced Results Sequence");	//Retired
       tagsCollection.insert("0008,1110" ,	"Referenced Study Sequence");
       tagsCollection.insert("0008,1111" ,	"Referenced Performed Procedure Step Sequence");
       tagsCollection.insert("0008,1115" ,	"Referenced Series Sequence");
       tagsCollection.insert("0008,1120" ,	"Referenced Patient Sequence");
       tagsCollection.insert("0008,1125" ,	"Referenced Visit Sequence");
       tagsCollection.insert("0008,1130" ,	"Referenced Overlay Sequence");	//Retired
       tagsCollection.insert("0008,1134" ,	"Referenced Stereometric Instance Sequence");
       tagsCollection.insert("0008,113A" ,	"Referenced Waveform Sequence");
       tagsCollection.insert("0008,1140" ,	"Referenced Image Sequence");
       tagsCollection.insert("0008,1145" ,	"Referenced Curve Sequence");	//Retired
       tagsCollection.insert("0008,114A" ,	"Referenced Instance Sequence");
       tagsCollection.insert("0008,114B" ,	"Referenced Real World Value Mapping Instance Sequence");
       tagsCollection.insert("0008,1150" ,	"Referenced SOP Class UID");
       tagsCollection.insert("0008,1155" ,	"Referenced SOP Instance UID");
       tagsCollection.insert("0008,115A" ,	"SOP Classes Supported");
       tagsCollection.insert("0008,1160" ,	"Referenced Frame Number");
       tagsCollection.insert("0008,1161" ,	"Simple Frame List");
       tagsCollection.insert("0008,1162" ,	"Calculated Frame List");
       tagsCollection.insert("0008,1163" ,	"Time Range");
       tagsCollection.insert("0008,1164" ,	"Frame Extraction Sequence");
       tagsCollection.insert("0008,1167" ,	"Multi-frame Source SOP Instance UID");
       tagsCollection.insert("0008,1190" ,	"Retrieve URL");
       tagsCollection.insert("0008,1195" ,	"Transaction UID");
       tagsCollection.insert("0008,1196" ,	"Warning Reason");
       tagsCollection.insert("0008,1197" ,	"Failure Reason");
       tagsCollection.insert("0008,1198" ,	"Failed SOP Sequence");
       tagsCollection.insert("0008,1199" ,	"Referenced SOP Sequence");
       tagsCollection.insert("0008,119A" ,	"Other Failures Sequence");
       tagsCollection.insert("0008,1200" ,	"Studies Containing Other Referenced Instances Sequence");
       tagsCollection.insert("0008,1250" ,	"Related Series Sequence");
       tagsCollection.insert("0008,2110" ,	"Lossy Image Compression"); //(Retired)	Retired
       tagsCollection.insert("0008,2111" ,	"Derivation Description");
       tagsCollection.insert("0008,2112" ,	"Source Image Sequence");
       tagsCollection.insert("0008,2120" ,	"Stage Name");
       tagsCollection.insert("0008,2122" ,	"Stage Number");
       tagsCollection.insert("0008,2124" ,	"Number of Stages");
       tagsCollection.insert("0008,2127" ,	"View Name");
       tagsCollection.insert("0008,2128" ,	"View Number");
       tagsCollection.insert("0008,2129" ,	"Number of Event Timers");
       tagsCollection.insert("0008,212A" ,	"Number of Views in Stage");
       tagsCollection.insert("0008,2130" ,	"Event Elapsed Time(s)");
       tagsCollection.insert("0008,2132" ,	"Event Timer Name(s)");
       tagsCollection.insert("0008,2133" ,	"Event Timer Sequence");
       tagsCollection.insert("0008,2134" ,	"Event Time Offset");
       tagsCollection.insert("0008,2135" ,	"Event Code Sequence");
       tagsCollection.insert("0008,2142" ,	"Start Trim");
       tagsCollection.insert("0008,2143" ,	"Stop Trim");
       tagsCollection.insert("0008,2144" ,	"Recommended Display Frame Rate");
       tagsCollection.insert("0008,2200" ,	"Transducer Position");                                       //Retired
       tagsCollection.insert("0008,2204" ,	"Transducer Orientation");                                    //Retired
       tagsCollection.insert("0008,2208" ,	"Anatomic Structure");                                        //Retired
       tagsCollection.insert("0008,2218" ,	"Anatomic Region Sequence");
       tagsCollection.insert("0008,2220" ,	"Anatomic Region Modifier Sequence");
       tagsCollection.insert("0008,2228" ,	"Primary Anatomic Structure Sequence");
       tagsCollection.insert("0008,2229" ,	"Anatomic Structure, Space or Region Sequence");
       tagsCollection.insert("0008,2230" ,	"Primary Anatomic Structure Modifier Sequence");
       tagsCollection.insert("0008,2240" ,	"Transducer Position Sequence");                              //Retired
       tagsCollection.insert("0008,2242" ,	"Transducer Position Modifier Sequence");                     //Retired
       tagsCollection.insert("0008,2244" ,	"Transducer Orientation Sequence");                           //Retired
       tagsCollection.insert("0008,2246" ,	"Transducer Orientation Modifier Sequence");                  //Retired
       tagsCollection.insert("0008,2251" ,	"Anatomic Structure Space Or Region Code Sequence");          //(Trial)	Retired
       tagsCollection.insert("0008,2253" ,	"Anatomic Portal Of Entrance Code Sequence");                 //(Trial)	Retired
       tagsCollection.insert("0008,2255" ,	"Anatomic Approach Direction Code Sequence");                 //(Trial)	Retired
       tagsCollection.insert("0008,2256" ,	"Anatomic Perspective Description");                          //(Trial)	Retired
       tagsCollection.insert("0008,2257" ,	"Anatomic Perspective Code Sequence");                        //(Trial)	Retired
       tagsCollection.insert("0008,2258" ,	"Anatomic Location Of Examining Instrument Description");     //(Trial)	Retired
       tagsCollection.insert("0008,2259" ,	"Anatomic Location Of Examining Instrument Code Sequence");   //(Trial)	Retired
       tagsCollection.insert("0008,225A" ,	"Anatomic Structure Space Or Region Modifier Code Sequence"); //(Trial)	Retired
       tagsCollection.insert("0008,225C" ,	"On Axis Background Anatomic Structure Code Sequence");       //(Trial)	Retired
       tagsCollection.insert("0008,3001" ,	"Alternate Representation Sequence");
       tagsCollection.insert("0008,3010" ,	"Irradiation Event UID");
       tagsCollection.insert("0008,3011" ,	"Source Irradiation Event Sequence");
       tagsCollection.insert("0008,3012" ,	"Radiopharmaceutical Administration Event UID");
       tagsCollection.insert("0008,4000" ,	"Identifying Comments	Retired");
       tagsCollection.insert("0008,9007" ,	"Frame Type");
       tagsCollection.insert("0008,9092" ,	"Referenced Image Evidence Sequence");
       tagsCollection.insert("0008,9121" ,	"Referenced Raw Data Sequence");
       tagsCollection.insert("0008,9123" ,	"Creator-Version UID");
       tagsCollection.insert("0008,9124" ,	"Derivation Image Sequence");
       tagsCollection.insert("0008,9154" ,	"Source Image Evidence Sequence");
       tagsCollection.insert("0008,9205" ,	"Pixel Presentation");
       tagsCollection.insert("0008,9206" ,	"Volumetric Properties");
       tagsCollection.insert("0008,9207" ,	"Volume Based Calculation Technique");
       tagsCollection.insert("0008,9208" ,	"Complex Image Component");
       tagsCollection.insert("0008,9209" ,	"Acquisition Contrast");
       tagsCollection.insert("0008,9215" ,	"Derivation Code Sequence");
       tagsCollection.insert("0008,9237" ,	"Referenced Presentation State Sequence");
       tagsCollection.insert("0008,9410" ,	"Referenced Other Plane Sequence");
       tagsCollection.insert("0008,9458" ,	"Frame Display Sequence");
       tagsCollection.insert("0008,9459" ,	"Recommended Display Frame Rate in Float");
       tagsCollection.insert("0008,9460" ,	"Skip Frame Range Flag");
       tagsCollection.insert("0010,0010" ,	"Patient's Name");
       tagsCollection.insert("0010,0020" ,	"Patient ID");
       tagsCollection.insert("0010,0021" ,	"Issuer of Patient ID");
       tagsCollection.insert("0010,0022" ,	"Type of Patient ID");
       tagsCollection.insert("0010,0024" ,	"Issuer of Patient ID Qualifiers Sequence");
       tagsCollection.insert("0010,0026" ,	"Source Patient Group Identification Sequence");
       tagsCollection.insert("0010,0027" ,	"Group of Patients Identification Sequence");
       tagsCollection.insert("0010,0028" ,	"Subject Relative Position in Image");
       tagsCollection.insert("0010,0030" ,	"Patient's Birth Date");
       tagsCollection.insert("0010,0032" ,	"Patient's Birth Time");
       tagsCollection.insert("0010,0033" ,	"Patient's Birth Date in Alternative Calendar");
       tagsCollection.insert("0010,0034" ,	"Patient's Death Date in Alternative Calendar");
       tagsCollection.insert("0010,0035" ,	"Patient's Alternative Calendar");
       tagsCollection.insert("0010,0040" ,	"Patient's Sex");
       tagsCollection.insert("0010,0050" ,	"Patient's Insurance Plan Code Sequence");
       tagsCollection.insert("0010,0101" ,	"Patient's Primary Language Code Sequence");
       tagsCollection.insert("0010,0102" ,	"Patient's Primary Language Modifier Code Sequence");
       tagsCollection.insert("0010,0200" ,	"Quality Control Subject");
       tagsCollection.insert("0010,0201" ,	"Quality Control Subject Type Code Sequence");
       tagsCollection.insert("0010,0212" ,	"Strain Description");
       tagsCollection.insert("0010,0213" ,	"Strain Nomenclature");
       tagsCollection.insert("0010,0214" ,	"Strain Stock Number");
       tagsCollection.insert("0010,0215" ,	"Strain Source Registry Code Sequence");
       tagsCollection.insert("0010,0216" ,	"Strain Stock Sequence");
       tagsCollection.insert("0010,0217" ,	"Strain Source");
       tagsCollection.insert("0010,0218" ,	"Strain Additional Information");
       tagsCollection.insert("0010,0219" ,	"Strain Code Sequence");
       tagsCollection.insert("0010,1000" ,	"Other Patient IDs");
       tagsCollection.insert("0010,1001" ,	"Other Patient Names");
       tagsCollection.insert("0010,1002" ,	"Other Patient IDs Sequence");
       tagsCollection.insert("0010,1005" ,	"Patient's Birth Name");
       tagsCollection.insert("0010,1010" ,	"Patient's Age");
       tagsCollection.insert("0010,1020" ,	"Patient's Size");
       tagsCollection.insert("0010,1021" ,	"Patient's Size Code Sequence");
       tagsCollection.insert("0010,1030" ,	"Patient's Weight");
       tagsCollection.insert("0010,1040" ,	"Patient's Address");
       tagsCollection.insert("0010,1050" ,	"Insurance Plan Identification");//	Retired
       tagsCollection.insert("0010,1060" ,	"Patient's Mother's Birth Name");
       tagsCollection.insert("0010,1080" ,	"Military Rank");
       tagsCollection.insert("0010,1081" ,	"Branch of Service");
       tagsCollection.insert("0010,1090" ,	"Medical Record Locator");
       tagsCollection.insert("0010,1100" ,	"Referenced Patient Photo Sequence");
       tagsCollection.insert("0010,2000" ,	"Medical Alerts");
       tagsCollection.insert("0010,2110" ,	"Allergies");
       tagsCollection.insert("0010,2150" ,	"Country of Residence");
       tagsCollection.insert("0010,2152" ,	"Region of Residence");
       tagsCollection.insert("0010,2154" ,	"Patient's Telephone Numbers");
       tagsCollection.insert("0010,2155" ,	"Patient's Telecom Information");
       tagsCollection.insert("0010,2160" ,	"Ethnic Group");
       tagsCollection.insert("0010,2180" ,	"Occupation");
       tagsCollection.insert("0010,21A0" ,	"Smoking Status");
       tagsCollection.insert("0010,21B0" ,	"Additional Patient History");
       tagsCollection.insert("0010,21C0" ,	"Pregnancy Status");
       tagsCollection.insert("0010,21D0" ,	"Last Menstrual Date");
       tagsCollection.insert("0010,21F0" ,	"Patient's Religious Preference");
       tagsCollection.insert("0010,2201" ,	"Patient Species Description");
       tagsCollection.insert("0010,2202" ,	"Patient Species Code Sequence");
       tagsCollection.insert("0010,2203" ,	"Patient's Sex Neutered");
       tagsCollection.insert("0010,2210" ,	"Anatomical Orientation Type");
       tagsCollection.insert("0010,2292" ,	"Patient Breed Description");
       tagsCollection.insert("0010,2293" ,	"Patient Breed Code Sequence");
       tagsCollection.insert("0010,2294" ,	"Breed Registration Sequence");
       tagsCollection.insert("0010,2295" ,	"Breed Registration Number");
       tagsCollection.insert("0010,2296" ,	"Breed Registry Code Sequence");
       tagsCollection.insert("0010,2297" ,	"Responsible Person");
       tagsCollection.insert("0010,2298" ,	"Responsible Person Role");
       tagsCollection.insert("0010,2299" ,	"Responsible Organization");
       tagsCollection.insert("0010,4000" ,	"Patient Comments");
       tagsCollection.insert("0010,9431" ,	"Examined Body Thickness");
       tagsCollection.insert("0012,0010" ,	"Clinical Trial Sponsor Name");
       tagsCollection.insert("0012,0020" ,	"Clinical Trial Protocol ID");
       tagsCollection.insert("0012,0021" ,	"Clinical Trial Protocol Name");
       tagsCollection.insert("0012,0030" ,	"Clinical Trial Site ID");
       tagsCollection.insert("0012,0031" ,	"Clinical Trial Site Name");
       tagsCollection.insert("0012,0040" ,	"Clinical Trial Subject ID");
       tagsCollection.insert("0012,0042" ,	"Clinical Trial Subject Reading ID");
       tagsCollection.insert("0012,0050" ,	"Clinical Trial Time Point ID");
       tagsCollection.insert("0012,0051" ,	"Clinical Trial Time Point Description");
       tagsCollection.insert("0012,0060" ,	"Clinical Trial Coordinating Center Name");
       tagsCollection.insert("0012,0062" ,	"Patient Identity Removed");
       tagsCollection.insert("0012,0063" ,	"De-identification Method");
       tagsCollection.insert("0012,0064" ,	"De-identification Method Code Sequence");
       tagsCollection.insert("0012,0071" ,	"Clinical Trial Series ID");
       tagsCollection.insert("0012,0072" ,	"Clinical Trial Series Description");
       tagsCollection.insert("0012,0081" ,	"Clinical Trial Protocol Ethics Committee Name");
       tagsCollection.insert("0012,0082" ,	"Clinical Trial Protocol Ethics Committee Approval Number");
       tagsCollection.insert("0012,0083" ,	"Consent for Clinical Trial Use Sequence");
       tagsCollection.insert("0012,0084" ,	"Distribution Type");
       tagsCollection.insert("0012,0085" ,	"Consent for Distribution Flag");
       tagsCollection.insert("0014,0023" ,	"CAD File Format");//	Retired
       tagsCollection.insert("0014,0024" ,	"Component Reference System	Retired");
       tagsCollection.insert("0014,0025" ,	"Component Manufacturing Procedure");
       tagsCollection.insert("0014,0028" ,	"Component Manufacturer");
       tagsCollection.insert("0014,0030" ,	"Material Thickness");
       tagsCollection.insert("0014,0032" ,	"Material Pipe Diameter");
       tagsCollection.insert("0014,0034" ,	"Material Isolation Diameter");
       tagsCollection.insert("0014,0042" ,	"Material Grade");
       tagsCollection.insert("0014,0044" ,	"Material Properties Description");
       tagsCollection.insert("0014,0045" ,	"Material Properties File Format");// (Retired)	Retired
       tagsCollection.insert("0014,0046" ,	"Material Notes");
       tagsCollection.insert("0014,0050" ,	"Component Shape");
       tagsCollection.insert("0014,0052" ,	"Curvature Type");
       tagsCollection.insert("0014,0054" ,	"Outer Diameter");
       tagsCollection.insert("0014,0056" ,	"Inner Diameter");
       tagsCollection.insert("0014,0100" ,	"Component Welder IDs");
       tagsCollection.insert("0014,0101" ,	"Secondary Approval Status");
       tagsCollection.insert("0014,0102" ,	"Secondary Review Date");
       tagsCollection.insert("0014,0103" ,	"Secondary Review Time");
       tagsCollection.insert("0014,0104" ,	"Secondary Reviewer Name");
       tagsCollection.insert("0014,0105" ,	"Repair ID");
       tagsCollection.insert("0014,0106" ,	"Multiple Component Approval Sequence");
       tagsCollection.insert("0014,0107" ,	"Other Approval Status");
       tagsCollection.insert("0014,0108" ,	"Other Secondary Approval Status");
       tagsCollection.insert("0014,1010" ,	"Actual Environmental Conditions");
       tagsCollection.insert("0014,1020" ,	"Expiry Date");
       tagsCollection.insert("0014,1040" ,	"Environmental Conditions");
       tagsCollection.insert("0014,2002" ,	"Evaluator Sequence");
       tagsCollection.insert("0014,2004" ,	"Evaluator Number");
       tagsCollection.insert("0014,2006" ,	"Evaluator Name");
       tagsCollection.insert("0014,2008" ,	"Evaluation Attempt");
       tagsCollection.insert("0014,2012" ,	"Indication Sequence");
       tagsCollection.insert("0014,2014" ,	"Indication Number");
       tagsCollection.insert("0014,2016" ,	"Indication Label");
       tagsCollection.insert("0014,2018" ,	"Indication Description");
       tagsCollection.insert("0014,201A" ,	"Indication Type");
       tagsCollection.insert("0014,201C" ,	"Indication Disposition");
       tagsCollection.insert("0014,201E" ,	"Indication ROI Sequence");
       tagsCollection.insert("0014,2030" ,	"Indication Physical Property Sequence");
       tagsCollection.insert("0014,2032" ,	"Property Label");
       tagsCollection.insert("0014,2202" ,	"Coordinate System Number of Axes");
       tagsCollection.insert("0014,2204" ,	"Coordinate System Axes Sequence");
       tagsCollection.insert("0014,2206" ,	"Coordinate System Axis Description");
       tagsCollection.insert("0014,2208" ,	"Coordinate System Data Set Mapping");
       tagsCollection.insert("0014,220A" ,	"Coordinate System Axis Number");
       tagsCollection.insert("0014,220C" ,	"Coordinate System Axis Type");
       tagsCollection.insert("0014,220E" ,	"Coordinate System Axis Units");
       tagsCollection.insert("0014,2210" ,	"Coordinate System Axis Values");
       tagsCollection.insert("0014,2220" ,	"Coordinate System Transform Sequence");
       tagsCollection.insert("0014,2222" ,	"Transform Description");
       tagsCollection.insert("0014,2224" ,	"Transform Number of Axes");
       tagsCollection.insert("0014,2226" ,	"Transform Order of Axes");
       tagsCollection.insert("0014,2228" ,	"Transformed Axis Units");
       tagsCollection.insert("0014,222A" ,	"Coordinate System Transform Rotation and Scale Matrix");
       tagsCollection.insert("0014,222C" ,	"Coordinate System Transform Translation Matrix");
       tagsCollection.insert("0014,3011" ,	"Internal Detector Frame Time");
       tagsCollection.insert("0014,3012" ,	"Number of Frames Integrated");
       tagsCollection.insert("0014,3020" ,	"Detector Temperature Sequence");
       tagsCollection.insert("0014,3022" ,	"Sensor Name");
       tagsCollection.insert("0014,3024" ,	"Horizontal Offset of Sensor");
       tagsCollection.insert("0014,3026" ,	"Vertical Offset of Sensor");
       tagsCollection.insert("0014,3028" ,	"Sensor Temperature");
       tagsCollection.insert("0014,3040" ,	"Dark Current Sequence");
       tagsCollection.insert("0014,3050" , 	"Dark Current Counts");
       tagsCollection.insert("0014,3060" ,	"Gain Correction Reference Sequence");
       tagsCollection.insert("0014,3070" , 	"Air Counts");
       tagsCollection.insert("0014,3071" ,	"KV Used in Gain Calibration");
       tagsCollection.insert("0014,3072" ,	"MA Used in Gain Calibration");
       tagsCollection.insert("0014,3073" ,	"Number of Frames Used for Integration");
       tagsCollection.insert("0014,3074" ,	"Filter Material Used in Gain Calibration");
       tagsCollection.insert("0014,3075" ,	"Filter Thickness Used in Gain Calibration");
       tagsCollection.insert("0014,3076" ,	"Date of Gain Calibration");
       tagsCollection.insert("0014,3077" ,	"Time of Gain Calibration");
       tagsCollection.insert("0014,3080" ,	"Bad Pixel Image");
       tagsCollection.insert("0014,3099" ,	"Calibration Notes");
       tagsCollection.insert("0014,4002" ,	"Pulser Equipment Sequence");
       tagsCollection.insert("0014,4004" ,	"Pulser Type");
       tagsCollection.insert("0014,4006" ,	"Pulser Notes");
       tagsCollection.insert("0014,4008" ,	"Receiver Equipment Sequence");
       tagsCollection.insert("0014,400A" ,	"Amplifier Type");
       tagsCollection.insert("0014,400C" ,	"Receiver Notes");
       tagsCollection.insert("0014,400E" ,	"Pre-Amplifier Equipment Sequence");
       tagsCollection.insert("0014,400F" ,	"Pre-Amplifier Notes");
       tagsCollection.insert("0014,4010" ,	"Transmit Transducer Sequence");
       tagsCollection.insert("0014,4011" ,	"Receive Transducer Sequence");
       tagsCollection.insert("0014,4012" ,	"Number of Elements");
       tagsCollection.insert("0014,4013" ,	"Element Shape");
       tagsCollection.insert("0014,4014" ,	"Element Dimension A");
       tagsCollection.insert("0014,4015" ,	"Element Dimension B");
       tagsCollection.insert("0014,4016" ,	"Element Pitch A");
       tagsCollection.insert("0014,4017" ,	"Measured Beam Dimension A");
       tagsCollection.insert("0014,4018" ,	"Measured Beam Dimension B");
       tagsCollection.insert("0014,4019" ,	"Location of Measured Beam Diameter");
       tagsCollection.insert("0014,401A" ,	"Nominal Frequency");
       tagsCollection.insert("0014,401B" ,	"Measured Center Frequency");
       tagsCollection.insert("0014,401C" ,	"Measured Bandwidth");
       tagsCollection.insert("0014,401D" ,	"Element Pitch B");
       tagsCollection.insert("0014,4020" ,	"Pulser Settings Sequence");
       tagsCollection.insert("0014,4022" ,	"Pulse Width");
       tagsCollection.insert("0014,4024" ,	"Excitation Frequency");
       tagsCollection.insert("0014,4026" ,	"Modulation Type");
       tagsCollection.insert("0014,4028" ,	"Damping");
       tagsCollection.insert("0014,4030" ,	"Receiver Settings Sequence");
       tagsCollection.insert("0014,4031" ,	"Acquired Soundpath Length");
       tagsCollection.insert("0014,4032" ,	"Acquisition Compression Type");
       tagsCollection.insert("0014,4033" ,	"Acquisition Sample Size");
       tagsCollection.insert("0014,4034" ,	"Rectifier Smoothing");
       tagsCollection.insert("0014,4035" ,	"DAC Sequence");
       tagsCollection.insert("0014,4036" ,	"DAC Type");
       tagsCollection.insert("0014,4038" ,	"DAC Gain Points");
       tagsCollection.insert("0014,403A" ,	"DAC Time Points");
       tagsCollection.insert("0014,403C" ,	"DAC Amplitude");
       tagsCollection.insert("0014,4040" ,	"Pre-Amplifier Settings Sequence");
       tagsCollection.insert("0014,4050" ,	"Transmit Transducer Settings Sequence");
       tagsCollection.insert("0014,4051" ,	"Receive Transducer Settings Sequence");
       tagsCollection.insert("0014,4052" ,	"Incident Angle");
       tagsCollection.insert("0014,4054" ,	"Coupling Technique");
       tagsCollection.insert("0014,4056" ,	"Coupling Medium");
       tagsCollection.insert("0014,4057" ,	"Coupling Velocity");
       tagsCollection.insert("0014,4058" ,	"Probe Center Location X");
       tagsCollection.insert("0014,4059" ,	"Probe Center Location Z");
       tagsCollection.insert("0014,405A" ,	"Sound Path Length");
       tagsCollection.insert("0014,405C" ,	"Delay Law Identifier");
       tagsCollection.insert("0014,4060" ,	"Gate Settings Sequence");
       tagsCollection.insert("0014,4062" ,	"Gate Threshold");
       tagsCollection.insert("0014,4064" ,	"Velocity of Sound");
       tagsCollection.insert("0014,4070" ,	"Calibration Settings Sequence");
       tagsCollection.insert("0014,4072" ,	"Calibration Procedure");
       tagsCollection.insert("0014,4074" ,	"Procedure Version");
       tagsCollection.insert("0014,4076" ,	"Procedure Creation Date");
       tagsCollection.insert("0014,4078" ,	"Procedure Expiration Date");
       tagsCollection.insert("0014,407A" ,	"Procedure Last Modified Date");
       tagsCollection.insert("0014,407C" ,	"Calibration Time");
       tagsCollection.insert("0014,407E" ,	"Calibration Date");
       tagsCollection.insert("0014,4080" ,	"Probe Drive Equipment Sequence");
       tagsCollection.insert("0014,4081" ,	"Drive Type");
       tagsCollection.insert("0014,4082" ,	"Probe Drive Notes");
       tagsCollection.insert("0014,4083" ,	"Drive Probe Sequence");
       tagsCollection.insert("0014,4084" ,	"Probe Inductance");
       tagsCollection.insert("0014,4085" ,	"Probe Resistance");
       tagsCollection.insert("0014,4086" ,	"Receive Probe Sequence");
       tagsCollection.insert("0014,4087" ,	"Probe Drive Settings Sequence");
       tagsCollection.insert("0014,4088" ,	"Bridge Resistors");
       tagsCollection.insert("0014,4089" ,	"Probe Orientation Angle");
       tagsCollection.insert("0014,408B" ,	"User Selected Gain Y");
       tagsCollection.insert("0014,408C" ,	"User Selected Phase");
       tagsCollection.insert("0014,408D" ,	"User Selected Offset X");
       tagsCollection.insert("0014,408E" ,	"User Selected Offset Y");
       tagsCollection.insert("0014,4091" ,	"Channel Settings Sequence");
       tagsCollection.insert("0014,4092" ,	"Channel Threshold");
       tagsCollection.insert("0014,409A" ,	"Scanner Settings Sequence");
       tagsCollection.insert("0014,409B" ,	"Scan Procedure");
       tagsCollection.insert("0014,409C" ,	"Translation Rate X");
       tagsCollection.insert("0014,409D" ,	"Translation Rate Y");
       tagsCollection.insert("0014,409F" ,	"Channel Overlap");
       tagsCollection.insert("0014,40A0" ,	"Image Quality Indicator Type");
       tagsCollection.insert("0014,40A1" ,	"Image Quality Indicator Material");
       tagsCollection.insert("0014,40A2" ,	"Image Quality Indicator Size");
       tagsCollection.insert("0014,5002" ,	"LINAC Energy");
       tagsCollection.insert("0014,5004" ,	"LINAC Output");
       tagsCollection.insert("0014,5100" ,	"Active Aperture");
       tagsCollection.insert("0014,5101" ,	"Total Aperture");
       tagsCollection.insert("0014,5102" ,	"Aperture Elevation");
       tagsCollection.insert("0014,5103" ,	"Main Lobe Angle");
       tagsCollection.insert("0014,5104" ,	"Main Roof Angle");
       tagsCollection.insert("0014,5105" ,	"Connector Type");
       tagsCollection.insert("0014,5106" ,	"Wedge Model Number");
       tagsCollection.insert("0014,5107" ,	"Wedge Angle Float");
       tagsCollection.insert("0014,5108" ,	"Wedge Roof Angle");
       tagsCollection.insert("0014,5109" ,	"Wedge Element 1 Position");
       tagsCollection.insert("0014,510A" ,	"Wedge Material Velocity");
       tagsCollection.insert("0014,510B" ,	"Wedge Material");
       tagsCollection.insert("0014,510C" ,	"Wedge Offset Z");
       tagsCollection.insert("0014,510D" ,	"Wedge Origin Offset X");
       tagsCollection.insert("0014,510E" ,	"Wedge Time Delay");
       tagsCollection.insert("0014,510F" , "Wedge Name");
       tagsCollection.insert("0014,5110" , "Wedge Manufacturer Name");
       tagsCollection.insert("0014,5111" , "Wedge Description");
       tagsCollection.insert("0014,5112" , "Nominal Beam Angle");
       tagsCollection.insert("0014,5113" , "Wedge Offset X");
       tagsCollection.insert("0014,5114" , "Wedge Offset Y");
       tagsCollection.insert("0014,5115" , "Wedge Total Length");
       tagsCollection.insert("0014,5116" , "Wedge In Contact Length");
       tagsCollection.insert("0014,5117" , "Wedge Front Gap");
       tagsCollection.insert("0014,5118" , "Wedge Total Height");
       tagsCollection.insert("0014,5119" , "Wedge Front Height");
       tagsCollection.insert("0014,511A" , "Wedge Rear Height");
       tagsCollection.insert("0014,511B" , "Wedge Total Width");
       tagsCollection.insert("0014,511C" , "Wedge In Contact Width");
       tagsCollection.insert("0014,511D" , "Wedge Chamfer Height");
       tagsCollection.insert("0014,511E" , "Wedge Curve");
       tagsCollection.insert("0014,511F" , "Radius Along the Wedge");
       tagsCollection.insert("0018,0010" , "Contrast/Bolus Agent");
       tagsCollection.insert("0018,0012" , "Contrast/Bolus Agent Sequence");
       tagsCollection.insert("0018,0013" , "Contrast/Bolus T1 Relaxivity");
       tagsCollection.insert("0018,0014" , "Contrast/Bolus Administration Route Sequence");
       tagsCollection.insert("0018,0015" , "Body Part Examined");
       tagsCollection.insert("0018,0020" , "Scanning Sequence");
       tagsCollection.insert("0018,0021" , "Sequence Variant");
       tagsCollection.insert("0018,0022" , "Scan Options");
       tagsCollection.insert("0018,0023" , "MR Acquisition Type");
       tagsCollection.insert("0018,0024" , "Sequence Name");
       tagsCollection.insert("0018,0025" , "Angio Flag");
       tagsCollection.insert("0018,0026" , "Intervention Drug Information Sequence");
       tagsCollection.insert("0018,0027" , "Intervention Drug Stop Time");
       tagsCollection.insert("0018,0028" , "Intervention Drug Dose");
       tagsCollection.insert("0018,0029" , "Intervention Drug Code Sequence");
       tagsCollection.insert("0018,002A" , "Additional Drug Sequence");
       tagsCollection.insert("0018,0030" , "Radionuclide");	            //Retired
       tagsCollection.insert("0018,0031" , "Radiopharmaceutical");
       tagsCollection.insert("0018,0032" , "Energy Window Centerline");	//Retired
       tagsCollection.insert("0018,0033" , "Energy Window Total Width");	//Retired
       tagsCollection.insert("0018,0034" , "Intervention Drug Name");
       tagsCollection.insert("0018,0035" , "Intervention Drug Start Time");
       tagsCollection.insert("0018,0036" , "Intervention Sequence");
       tagsCollection.insert("0018,0037" , "Therapy Type");	            //Retired
       tagsCollection.insert("0018,0038" , "Intervention Status");
       tagsCollection.insert("0018,0039" , "Therapy Description");       //Retired
       tagsCollection.insert("0018,003A" , "Intervention Description");
       tagsCollection.insert("0018,0040" , "Cine Rate");
       tagsCollection.insert("0018,0042" , "Initial Cine Run State");
       tagsCollection.insert("0018,0050" , "Slice Thickness");
       tagsCollection.insert("0018,0060" , "KVP");
       tagsCollection.insert("0018,0061" , "");                       	//Retired
       tagsCollection.insert("0018,0070" , "Counts Accumulated");
       tagsCollection.insert("0018,0071" , "Acquisition Termination Condition");
       tagsCollection.insert("0018,0072" , "Effective Duration");
       tagsCollection.insert("0018,0073" , "Acquisition Start Condition");
       tagsCollection.insert("0018,0074" , "Acquisition Start Condition Data");
       tagsCollection.insert("0018,0075" , "Acquisition Termination Condition Data");
       tagsCollection.insert("0018,0080" , "Repetition Time");
       tagsCollection.insert("0018,0081" , "Echo Time");
       tagsCollection.insert("0018,0082" , "Inversion Time");
       tagsCollection.insert("0018,0083" , "Number of Averages");
       tagsCollection.insert("0018,0084" , "Imaging Frequency");
       tagsCollection.insert("0018,0085" , "Imaged Nucleus");
       tagsCollection.insert("0018,0086" , "Echo Number(s)");
       tagsCollection.insert("0018,0087" , "Magnetic Field Strength");
       tagsCollection.insert("0018,0088" , "Spacing Between Slices");
       tagsCollection.insert("0018,0089" , "Number of Phase Encoding Steps");
       tagsCollection.insert("0018,0090" , "Data Collection Diameter");
       tagsCollection.insert("0018,0091" , "Echo Train Length");
       tagsCollection.insert("0018,0093" , "Percent Sampling");
       tagsCollection.insert("0018,0094" , "Percent Phase Field of View");
       tagsCollection.insert("0018,0095" , "Pixel Bandwidth");
       tagsCollection.insert("0018,1000" , "Device Serial Number");
       tagsCollection.insert("0018,1002" , "Device UID");
       tagsCollection.insert("0018,1003" , "Device ID");
       tagsCollection.insert("0018,1004" , "Plate ID");
       tagsCollection.insert("0018,1005" , "Generator ID");
       tagsCollection.insert("0018,1006" , "Grid ID");
       tagsCollection.insert("0018,1007" , "Cassette ID");
       tagsCollection.insert("0018,1008" , "Gantry ID");
       tagsCollection.insert("0018,1010" , "Secondary Capture Device ID");
       tagsCollection.insert("0018,1011" , "Hardcopy Creation Device ID");	//Retired
       tagsCollection.insert("0018,1012" , "Date of Secondary Capture");
       tagsCollection.insert("0018,1014" , "Time of Secondary Capture");
       tagsCollection.insert("0018,1016" , "Secondary Capture Device Manufacturer");
       tagsCollection.insert("0018,1017" , "Hardcopy Device Manufacturer");	//Retired
       tagsCollection.insert("0018,1018" , "Secondary Capture Device Manufacturer's Model Name");
       tagsCollection.insert("0018,1019" , "Secondary Capture Device Software Versions");
       tagsCollection.insert("0018,101A" , "Hardcopy Device Software Version");	//Retired
       tagsCollection.insert("0018,101B" , "Hardcopy Device Manufacturer's Model Name");	//Retired
       tagsCollection.insert("0018,1020" , "Software Version(s)");
       tagsCollection.insert("0018,1022" , "Video Image Format Acquired");
       tagsCollection.insert("0018,1023" , "Digital Image Format Acquired");
       tagsCollection.insert("0018,1030" , "Protocol Name");
       tagsCollection.insert("0018,1040" , "Contrast/Bolus Route");
       tagsCollection.insert("0018,1041" , "Contrast/Bolus Volume");
       tagsCollection.insert("0018,1042" , "Contrast/Bolus Start Time");
       tagsCollection.insert("0018,1043" , "Contrast/Bolus Stop Time");
       tagsCollection.insert("0018,1044" , "Contrast/Bolus Total Dose");
       tagsCollection.insert("0018,1045" , "Syringe Counts");
       tagsCollection.insert("0018,1046" , "Contrast Flow Rate");
       tagsCollection.insert("0018,1047" , "Contrast Flow Duration");
       tagsCollection.insert("0018,1048" , "Contrast/Bolus Ingredient");
       tagsCollection.insert("0018,1049" , "Contrast/Bolus Ingredient Concentration");
       tagsCollection.insert("0018,1050" , "Spatial Resolution");
       tagsCollection.insert("0018,1060" , "Trigger Time");
       tagsCollection.insert("0018,1061" , "Trigger Source or Type");
       tagsCollection.insert("0018,1062" , "Nominal Interval");
       tagsCollection.insert("0018,1063" , "Frame Time");
       tagsCollection.insert("0018,1064" , "Cardiac Framing Type");
       tagsCollection.insert("0018,1065" , "Frame Time Vector");
       tagsCollection.insert("0018,1066" , "Frame Delay");
       tagsCollection.insert("0018,1067" , "Image Trigger Delay");
       tagsCollection.insert("0018,1068" , "Multiplex Group Time Offset");
       tagsCollection.insert("0018,1069" , "Trigger Time Offset");
       tagsCollection.insert("0018,106A" , "Synchronization Trigger");
       tagsCollection.insert("0018,106C" , "Synchronization Channel");
       tagsCollection.insert("0018,106E" , "Trigger Sample Position");
       tagsCollection.insert("0018,1070" , "Radiopharmaceutical Route");
       tagsCollection.insert("0018,1071" , "Radiopharmaceutical Volume");
       tagsCollection.insert("0018,1072" , "Radiopharmaceutical Start Time");
       tagsCollection.insert("0018,1073" , "Radiopharmaceutical Stop Time");
       tagsCollection.insert("0018,1074" , "Radionuclide Total Dose");
       tagsCollection.insert("0018,1075" , "Radionuclide Half Life");
       tagsCollection.insert("0018,1076" , "Radionuclide Positron Fraction");
       tagsCollection.insert("0018,1077" , "Radiopharmaceutical Specific Activity");
       tagsCollection.insert("0018,1078" , "Radiopharmaceutical Start DateTime");
       tagsCollection.insert("0018,1079" , "Radiopharmaceutical Stop DateTime");
       tagsCollection.insert("0018,1080" , "Beat Rejection Flag");
       tagsCollection.insert("0018,1081" , "Low R-R Value");
       tagsCollection.insert("0018,1082" , "High R-R Value");
       tagsCollection.insert("0018,1083" , "Intervals Acquired");
       tagsCollection.insert("0018,1084" , "Intervals Rejected");
       tagsCollection.insert("0018,1085" , "PVC Rejection");
       tagsCollection.insert("0018,1086" , "Skip Beats");
       tagsCollection.insert("0018,1088" , "Heart Rate");
       tagsCollection.insert("0018,1090" , "Cardiac Number of Images");
       tagsCollection.insert("0018,1094" , "Trigger Window");
       tagsCollection.insert("0018,1100" , "Reconstruction Diameter");
       tagsCollection.insert("0018,1110" , "Distance Source to Detector");
       tagsCollection.insert("0018,1111" , "Distance Source to Patient");
       tagsCollection.insert("0018,1114" , "Estimated Radiographic Magnification Factor");
       tagsCollection.insert("0018,1120" , "Gantry/Detector Tilt");
       tagsCollection.insert("0018,1121" , "Gantry/Detector Slew");
       tagsCollection.insert("0018,1130" , "Table Height");
       tagsCollection.insert("0018,1131" , "Table Traverse");
       tagsCollection.insert("0018,1134" , "Table Motion");
       tagsCollection.insert("0018,1135" , "Table Vertical Increment");
       tagsCollection.insert("0018,1136" , "Table Lateral Increment");
       tagsCollection.insert("0018,1137" , "Table Longitudinal Increment");
       tagsCollection.insert("0018,1138" , "Table Angle");
       tagsCollection.insert("0018,113A" , "Table Type");
       tagsCollection.insert("0018,1140" , "Rotation Direction");
       tagsCollection.insert("0018,1141" , "Angular Position"); //Retired
       tagsCollection.insert("0018,1142" , "Radial Position");
       tagsCollection.insert("0018,1143" , "Scan Arc");
       tagsCollection.insert("0018,1144" , "Angular Step");
       tagsCollection.insert("0018,1145" , "Center of Rotation Offset");
       tagsCollection.insert("0018,1146" , "Rotation Offset");	//Retired
       tagsCollection.insert("0018,1147" , "Field of View Shape");
       tagsCollection.insert("0018,1149" , "Field of View Dimension(s)");
       tagsCollection.insert("0018,1150" , "Exposure Time");
       tagsCollection.insert("0018,1151" , "X-Ray Tube Current");
       tagsCollection.insert("0018,1152" , "Exposure");
       tagsCollection.insert("0018,1153" , "Exposure in µAs");
       tagsCollection.insert("0018,1154" , "Average Pulse Width");
       tagsCollection.insert("0018,1155" , "Radiation Setting");
       tagsCollection.insert("0018,1156" , "Rectification Type");
       tagsCollection.insert("0018,115A" , "Radiation Mode");
       tagsCollection.insert("0018,115E" , "Image and Fluoroscopy Area Dose Product");
       tagsCollection.insert("0018,1160" , "Filter Type");
       tagsCollection.insert("0018,1161" , "Type of Filters");
       tagsCollection.insert("0018,1162" , "Intensifier Size");
       tagsCollection.insert("0018,1164" , "Imager Pixel Spacing");
       tagsCollection.insert("0018,1166" , "Grid");
       tagsCollection.insert("0018,1170" , "Generator Power");
       tagsCollection.insert("0018,1180" , "Collimator/grid Name");
       tagsCollection.insert("0018,1181" , "Collimator Type");
       tagsCollection.insert("0018,1182" , "Focal Distance");
       tagsCollection.insert("0018,1183" , "X Focus Center");
       tagsCollection.insert("0018,1184" , "Y Focus Center");
       tagsCollection.insert("0018,1190" , "Focal Spot(s)");
       tagsCollection.insert("0018,1191" , "Anode Target Material");
       tagsCollection.insert("0018,11A0" , "Body Part Thickness");
       tagsCollection.insert("0018,11A2" , "Compression Force");
       tagsCollection.insert("0018,11A4" , "Paddle Description");
       tagsCollection.insert("0018,1200" , "Date of Last Calibration");
       tagsCollection.insert("0018,1201" , "Time of Last Calibration");
       tagsCollection.insert("0018,1202" , "DateTime of Last Calibration");
       tagsCollection.insert("0018,1210" , "Convolution Kernel");
       tagsCollection.insert("0018,1240" , "Upper/Lower Pixel Values");	//Retired
       tagsCollection.insert("0018,1242" , "Actual Frame Duration");
       tagsCollection.insert("0018,1243" , "Count Rate");
       tagsCollection.insert("0018,1244" , "Preferred Playback Sequencing");
       tagsCollection.insert("0018,1250" , "Receive Coil Name");
       tagsCollection.insert("0018,1251" , "Transmit Coil Name");
       tagsCollection.insert("0018,1260" , "Plate Type");
       tagsCollection.insert("0018,1261" , "Phosphor Type");
       tagsCollection.insert("0018,1271" , "Water Equivalent Diameter");
       tagsCollection.insert("0018,1272" , "Water Equivalent Diameter Calculation Method Code Sequence");
       tagsCollection.insert("0018,1300" , "Scan Velocity");
       tagsCollection.insert("0018,1301" , "Whole Body Technique");
       tagsCollection.insert("0018,1302" , "Scan Length");
       tagsCollection.insert("0018,1310" , "Acquisition Matrix");
       tagsCollection.insert("0018,1312" , "In-plane Phase Encoding Direction");
       tagsCollection.insert("0018,1314" , "Flip Angle");
       tagsCollection.insert("0018,1315" , "Variable Flip Angle Flag");
       tagsCollection.insert("0018,1316" , "SAR");
       tagsCollection.insert("0018,1318" , "dB/dt");
       tagsCollection.insert("0018,1320" , "B1rms");
       tagsCollection.insert("0018,1400" , "Acquisition Device Processing Description");
       tagsCollection.insert("0018,1401" , "Acquisition Device Processing Code");
       tagsCollection.insert("0018,1402" , "Cassette Orientation");
       tagsCollection.insert("0018,1403" , "Cassette Size");
       tagsCollection.insert("0018,1404" , "Exposures on Plate");
       tagsCollection.insert("0018,1405" , "Relative X-Ray Exposure");
       tagsCollection.insert("0018,1411" , "Exposure Index");
       tagsCollection.insert("0018,1412" , "Target Exposure Index");
       tagsCollection.insert("0018,1413" , "Deviation Index");
       tagsCollection.insert("0018,1450" , "Column Angulation");
       tagsCollection.insert("0018,1460" , "Tomo Layer Height");
       tagsCollection.insert("0018,1470" , "Tomo Angle");
       tagsCollection.insert("0018,1480" , "Tomo Time");
       tagsCollection.insert("0018,1490" , "Tomo Type");
       tagsCollection.insert("0018,1491" , "Tomo Class");
       tagsCollection.insert("0018,1495" , "Number of Tomosynthesis Source Images");
       tagsCollection.insert("0018,1500" , "Positioner Motion");
       tagsCollection.insert("0018,1508" , "Positioner Type");
       tagsCollection.insert("0018,1510" , "Positioner Primary Angle");
       tagsCollection.insert("0018,1511" , "Positioner Secondary Angle");
       tagsCollection.insert("0018,1520" , "Positioner Primary Angle Increment");
       tagsCollection.insert("0018,1521" , "Positioner Secondary Angle Increment");
       tagsCollection.insert("0018,1530" , "Detector Primary Angle");
       tagsCollection.insert("0018,1531" , "Detector Secondary Angle");
       tagsCollection.insert("0018,1600" , "Shutter Shape");
       tagsCollection.insert("0018,1602" , "Shutter Left Vertical Edge");
       tagsCollection.insert("0018,1604" , "Shutter Right Vertical Edge");
       tagsCollection.insert("0018,1606" , "Shutter Upper Horizontal Edge");
       tagsCollection.insert("0018,1608" , "Shutter Lower Horizontal Edge");
       tagsCollection.insert("0018,1610" , "Center of Circular Shutter");
       tagsCollection.insert("0018,1612" , "Radius of Circular Shutter");
       tagsCollection.insert("0018,1620" , "Vertices of the Polygonal Shutter");
       tagsCollection.insert("0018,1622" , "Shutter Presentation Value");
       tagsCollection.insert("0018,1623" , "Shutter Overlay Group");
       tagsCollection.insert("0018,1624" , "Shutter Presentation Color CIELab Value");
       tagsCollection.insert("0018,1700" , "Collimator Shape");
       tagsCollection.insert("0018,1702" , "Collimator Left Vertical Edge");
       tagsCollection.insert("0018,1704" , "Collimator Right Vertical Edge");
       tagsCollection.insert("0018,1706" , "Collimator Upper Horizontal Edge");
       tagsCollection.insert("0018,1708" , "Collimator Lower Horizontal Edge");
       tagsCollection.insert("0018,1710" , "Center of Circular Collimator");
       tagsCollection.insert("0018,1712" , "Radius of Circular Collimator");
       tagsCollection.insert("0018,1720" , "Vertices of the Polygonal Collimator");
       tagsCollection.insert("0018,1800" , "Acquisition Time Synchronized");
       tagsCollection.insert("0018,1801" , "Time Source");
       tagsCollection.insert("0018,1802" , "Time Distribution Protocol");
       tagsCollection.insert("0018,1803" , "NTP Source Address");
       tagsCollection.insert("0018,2001" , "Page Number Vector");
       tagsCollection.insert("0018,2002" , "Frame Label Vector");
       tagsCollection.insert("0018,2003" , "Frame Primary Angle Vector");
       tagsCollection.insert("0018,2004" , "Frame Secondary Angle Vector");
       tagsCollection.insert("0018,2005" , "Slice Location Vector");
       tagsCollection.insert("0018,2006" , "Display Window Label Vector");
       tagsCollection.insert("0018,2010" , "Nominal Scanned Pixel Spacing");
       tagsCollection.insert("0018,2020" , "Digitizing Device Transport Direction");
       tagsCollection.insert("0018,2030" , "Rotation of Scanned Film");
       tagsCollection.insert("0018,2041" , "Biopsy Target Sequence");
       tagsCollection.insert("0018,2042" , "Target UID");
       tagsCollection.insert("0018,2043" , "Localizing Cursor Position");
       tagsCollection.insert("0018,2044" , "Calculated Target Position");
       tagsCollection.insert("0018,2045" , "Target Label");
       tagsCollection.insert("0018,2046" , "Displayed Z Value");
       tagsCollection.insert("0018,3100" , "IVUS Acquisition");
       tagsCollection.insert("0018,3101" , "IVUS Pullback Rate");
       tagsCollection.insert("0018,3102" , "IVUS Gated Rate");
       tagsCollection.insert("0018,3103" , "IVUS Pullback Start Frame Number");
       tagsCollection.insert("0018,3104" , "IVUS Pullback Stop Frame Number");
       tagsCollection.insert("0018,3105" , "Lesion Number");
       tagsCollection.insert("0018,4000" , "Acquisition Comments");	//Retired
       tagsCollection.insert("0018,5000" , "Output Power");
       tagsCollection.insert("0018,5010" , "Transducer Data");
       tagsCollection.insert("0018,5012" , "Focus Depth");
       tagsCollection.insert("0018,5020" , "Processing Function");
       tagsCollection.insert("0018,5021" , "Postprocessing Function");	//Retired
       tagsCollection.insert("0018,5022" , "Mechanical Index");
       tagsCollection.insert("0018,5024" , "Bone Thermal Index");
       tagsCollection.insert("0018,5026" , "Cranial Thermal Index");
       tagsCollection.insert("0018,5027" , "Soft Tissue Thermal Index");
       tagsCollection.insert("0018,5028" , "Soft Tissue-focus Thermal Index");
       tagsCollection.insert("0018,5029" , "Soft Tissue-surface Thermal Index");
       tagsCollection.insert("0018,5030" , "Dynamic Range");	//Retired
       tagsCollection.insert("0018,5040" , "Total Gain");	//Retired
       tagsCollection.insert("0018,5050" , "Depth of Scan Field");
       tagsCollection.insert("0018,5100" , "Patient Position");
       tagsCollection.insert("0018,5101" , "View Position");
       tagsCollection.insert("0018,5104" , "Projection Eponymous Name Code Sequence");
       tagsCollection.insert("0018,5210" , "Image Transformation Matrix");	//Retired
       tagsCollection.insert("0018,5212" , "Image Translation Vector");	//Retired
       tagsCollection.insert("0018,6000" , "Sensitivity");
       tagsCollection.insert("0018,6011" , "Sequence of Ultrasound Regions");
       tagsCollection.insert("0018,6012" , "Region Spatial Format");
       tagsCollection.insert("0018,6014" , "Region Data Type");
       tagsCollection.insert("0018,6016" , "Region Flags");
       tagsCollection.insert("0018,6018" , "Region Location Min X0");
       tagsCollection.insert("0018,601A" , "Region Location Min Y0");
       tagsCollection.insert("0018,601C" , "Region Location Max X1");
       tagsCollection.insert("0018,601E" , "Region Location Max Y1");
       tagsCollection.insert("0018,6020" , "Reference Pixel X0");
       tagsCollection.insert("0018,6022" , "Reference Pixel Y0");
       tagsCollection.insert("0018,6024" , "Physical Units X Direction");
       tagsCollection.insert("0018,6026" , "Physical Units Y Direction");
       tagsCollection.insert("0018,6028" , "Reference Pixel Physical Value X");
       tagsCollection.insert("0018,602A" , "Reference Pixel Physical Value Y");
       tagsCollection.insert("0018,602C" , "Physical Delta X");
       tagsCollection.insert("0018,602E" , "Physical Delta Y");
       tagsCollection.insert("0018,6030" , "Transducer Frequency");
       tagsCollection.insert("0018,6031" , "Transducer Type");
       tagsCollection.insert("0018,6032" , "Pulse Repetition Frequency");
       tagsCollection.insert("0018,6034" , "Doppler Correction Angle");
       tagsCollection.insert("0018,6036" , "Steering Angle");
       tagsCollection.insert("0018,6038" , "Doppler Sample Volume X Position"); //Retired
       tagsCollection.insert("0018,6039" , "Doppler Sample Volume X Position");
       tagsCollection.insert("0018,603A" , "Doppler Sample Volume Y Position");//Retired
       tagsCollection.insert("0018,603B" , "Doppler Sample Volume Y Position");
       tagsCollection.insert("0018,603C" , "TM-Line Position X0");  //Retired
       tagsCollection.insert("0018,603D" , "TM-Line Position X0");
       tagsCollection.insert("0018,603E" , "TM-Line Position Y0");	//Retired
       tagsCollection.insert("0018,603F" , "TM-Line Position Y0");
       tagsCollection.insert("0018,6040" , "TM-Line Position X1");  //Retired
       tagsCollection.insert("0018,6041" , "TM-Line Position X1");
       tagsCollection.insert("0018,6042" , "TM-Line Position Y1");  //Retired
       tagsCollection.insert("0018,6043" , "TM-Line Position Y1");
       tagsCollection.insert("0018,6044" , "Pixel Component Organization");
       tagsCollection.insert("0018,6046" , "Pixel Component Mask");
       tagsCollection.insert("0018,6048" , "Pixel Component Range Start");
       tagsCollection.insert("0018,604A" , "Pixel Component Range Stop");
       tagsCollection.insert("0018,604C" , "Pixel Component Physical Units");
       tagsCollection.insert("0018,604E" , "Pixel Component Data Type");
       tagsCollection.insert("0018,6050" , "Number of Table Break Points");
       tagsCollection.insert("0018,6052" , "Table of X Break Points");
       tagsCollection.insert("0018,6054" , "Table of Y Break Points");
       tagsCollection.insert("0018,6056" , "Number of Table Entries");
       tagsCollection.insert("0018,6058" , "Table of Pixel Values");
       tagsCollection.insert("0018,605A" , "Table of Parameter Values");
       tagsCollection.insert("0018,6060" , "R Wave Time Vector");
       tagsCollection.insert("0018,7000" , "Detector Conditions Nominal Flag");
       tagsCollection.insert("0018,7001" , "Detector Temperature");
       tagsCollection.insert("0018,7004" , "Detector Type");
       tagsCollection.insert("0018,7005" , "Detector Configuration");
       tagsCollection.insert("0018,7006" , "Detector Description");
       tagsCollection.insert("0018,7008" , "Detector Mode");
       tagsCollection.insert("0018,700A" , "Detector ID");
       tagsCollection.insert("0018,700C" , "Date of Last Detector Calibration");
       tagsCollection.insert("0018,700E" , "Time of Last Detector Calibration");
       tagsCollection.insert("0018,7010" , "Exposures on Detector Since Last Calibration");
       tagsCollection.insert("0018,7011" , "Exposures on Detector Since Manufactured");
       tagsCollection.insert("0018,7012" , "Detector Time Since Last Exposure");
       tagsCollection.insert("0018,7014" , "Detector Active Time");
       tagsCollection.insert("0018,7016" , "Detector Activation Offset From Exposure");
       tagsCollection.insert("0018,701A" , "Detector Binning");
       tagsCollection.insert("0018,7020" , "Detector Element Physical Size");
       tagsCollection.insert("0018,7022" , "Detector Element Spacing");
       tagsCollection.insert("0018,7024" , "Detector Active Shape");
       tagsCollection.insert("0018,7026" , "Detector Active Dimension(s)");
       tagsCollection.insert("0018,7028" , "Detector Active Origin");
       tagsCollection.insert("0018,702A" , "Detector Manufacturer Name");
       tagsCollection.insert("0018,702B" , "Detector Manufacturer's Model Name");
       tagsCollection.insert("0018,7030" , "Field of View Origin");
       tagsCollection.insert("0018,7032" , "Field of View Rotation");
       tagsCollection.insert("0018,7034" , "Field of View Horizontal Flip");
       tagsCollection.insert("0018,7036" , "Pixel Data Area Origin Relative To FOV");
       tagsCollection.insert("0018,7038" , "Pixel Data Area Rotation Angle Relative To FOV");
       tagsCollection.insert("0018,7040" , "Grid Absorbing Material");
       tagsCollection.insert("0018,7041" , "Grid Spacing Material");
       tagsCollection.insert("0018,7042" , "Grid Thickness");
       tagsCollection.insert("0018,7044" , "Grid Pitch");
       tagsCollection.insert("0018,7046" , "Grid Aspect Ratio");
       tagsCollection.insert("0018,7048" , "Grid Period");
       tagsCollection.insert("0018,704C" , "Grid Focal Distance");
       tagsCollection.insert("0018,7050" , "Filter Material");
       tagsCollection.insert("0018,7052" , "Filter Thickness Minimum");
       tagsCollection.insert("0018,7054" , "Filter Thickness Maximum");
       tagsCollection.insert("0018,7056" , "Filter Beam Path Length Minimum");
       tagsCollection.insert("0018,7058" , "Filter Beam Path Length Maximum");
       tagsCollection.insert("0018,7060" , "Exposure Control Mode");
       tagsCollection.insert("0018,7062" , "Exposure Control Mode Description");
       tagsCollection.insert("0018,7064" , "Exposure Status");
       tagsCollection.insert("0018,7065" , "Phototimer Setting");
       tagsCollection.insert("0018,8150" , "Exposure Time in µS");
       tagsCollection.insert("0018,8151" , "X-Ray Tube Current in µA");
       tagsCollection.insert("0018,9004" , "Content Qualification");
       tagsCollection.insert("0018,9005" , "Pulse Sequence Name");
       tagsCollection.insert("0018,9006" , "MR Imaging Modifier Sequence");
       tagsCollection.insert("0018,9008" , "Echo Pulse Sequence");
       tagsCollection.insert("0018,9009" , "Inversion Recovery");
       tagsCollection.insert("0018,9010" , "Flow Compensation");
       tagsCollection.insert("0018,9011" , "Multiple Spin Echo");
       tagsCollection.insert("0018,9012" , "Multi-planar Excitation");
       tagsCollection.insert("0018,9014" , "Phase Contrast");
       tagsCollection.insert("0018,9015" , "Time of Flight Contrast");
       tagsCollection.insert("0018,9016" , "Spoiling");
       tagsCollection.insert("0018,9017" , "Steady State Pulse Sequence");
       tagsCollection.insert("0018,9018" , "Echo Planar Pulse Sequence");
       tagsCollection.insert("0018,9019" , "Tag Angle First Axis");
       tagsCollection.insert("0018,9020" , "Magnetization Transfer");
       tagsCollection.insert("0018,9021" , "T2 Preparation");
       tagsCollection.insert("0018,9022" , "Blood Signal Nulling");
       tagsCollection.insert("0018,9024" , "Saturation Recovery");
       tagsCollection.insert("0018,9025" , "Spectrally Selected Suppression");
       tagsCollection.insert("0018,9026" , "Spectrally Selected Excitation");
       tagsCollection.insert("0018,9027" , "Spatial Pre-saturation");
       tagsCollection.insert("0018,9028" , "Tagging");
       tagsCollection.insert("0018,9029" , "Oversampling Phase");
       tagsCollection.insert("0018,9030" , "Tag Spacing First Dimension");
       tagsCollection.insert("0018,9032" , "Geometry of k-Space Traversal");
       tagsCollection.insert("0018,9033" , "Segmented k-Space Traversal");
       tagsCollection.insert("0018,9034" , "Rectilinear Phase Encode Reordering");
       tagsCollection.insert("0018,9035" , "Tag Thickness");
       tagsCollection.insert("0018,9036" , "Partial Fourier Direction");
       tagsCollection.insert("0018,9037" , "Cardiac Synchronization Technique");
       tagsCollection.insert("0018,9041" , "Receive Coil Manufacturer Name");
       tagsCollection.insert("0018,9042" , "MR Receive Coil Sequence");
       tagsCollection.insert("0018,9043" , "Receive Coil Type");
       tagsCollection.insert("0018,9044" , "Quadrature Receive Coil");
       tagsCollection.insert("0018,9045" , "Multi-Coil Definition Sequence");
       tagsCollection.insert("0018,9046" , "Multi-Coil Configuration");
       tagsCollection.insert("0018,9047" , "Multi-Coil Element Name");
       tagsCollection.insert("0018,9048" , "Multi-Coil Element Used");
       tagsCollection.insert("0018,9049" , "MR Transmit Coil Sequence");
       tagsCollection.insert("0018,9050" , "Transmit Coil Manufacturer Name");
       tagsCollection.insert("0018,9051" , "Transmit Coil Type");
       tagsCollection.insert("0018,9052" , "Spectral Width");
       tagsCollection.insert("0018,9053" , "Chemical Shift Reference");
       tagsCollection.insert("0018,9054" , "Volume Localization Technique");
       tagsCollection.insert("0018,9058" , "MR Acquisition Frequency Encoding Steps");
       tagsCollection.insert("0018,9059" , "De-coupling");
       tagsCollection.insert("0018,9060" , "De-coupled Nucleus");
       tagsCollection.insert("0018,9061" , "De-coupling Frequency");
       tagsCollection.insert("0018,9062" , "De-coupling Method");
       tagsCollection.insert("0018,9063" , "De-coupling Chemical Shift Reference");
       tagsCollection.insert("0018,9064" , "k-space Filtering");
       tagsCollection.insert("0018,9065" , "Time Domain Filtering");
       tagsCollection.insert("0018,9066" , "Number of Zero Fills");
       tagsCollection.insert("0018,9067" , "Baseline Correction");
       tagsCollection.insert("0018,9069" , "Parallel Reduction Factor In-plane");
       tagsCollection.insert("0018,9070" , "Cardiac R-R Interval Specified");
       tagsCollection.insert("0018,9073" , "Acquisition Duration");
       tagsCollection.insert("0018,9074" , "Frame Acquisition DateTime");
       tagsCollection.insert("0018,9075" , "Diffusion Directionality");
       tagsCollection.insert("0018,9076" , "Diffusion Gradient Direction Sequence");
       tagsCollection.insert("0018,9077" , "Parallel Acquisition");
       tagsCollection.insert("0018,9078" , "Parallel Acquisition Technique");
       tagsCollection.insert("0018,9079" , "Inversion Times");
       tagsCollection.insert("0018,9080" , "Metabolite Map Description");
       tagsCollection.insert("0018,9081" , "Partial Fourier");
       tagsCollection.insert("0018,9082" , "Effective Echo Time");
       tagsCollection.insert("0018,9083" , "Metabolite Map Code Sequence");
       tagsCollection.insert("0018,9084" , "Chemical Shift Sequence");
       tagsCollection.insert("0018,9085" , "Cardiac Signal Source");
       tagsCollection.insert("0018,9087" , "Diffusion b-value");
       tagsCollection.insert("0018,9089" , "Diffusion Gradient Orientation");
       tagsCollection.insert("0018,9090" , "Velocity Encoding Direction");
       tagsCollection.insert("0018,9091" , "Velocity Encoding Minimum Value");
       tagsCollection.insert("0018,9092" , "Velocity Encoding Acquisition Sequence");
       tagsCollection.insert("0018,9093" , "Number of k-Space Trajectories");
       tagsCollection.insert("0018,9094" , "Coverage of k-Space");
       tagsCollection.insert("0018,9095" , "Spectroscopy Acquisition Phase Rows");
       tagsCollection.insert("0018,9096" , "Parallel Reduction Factor In-plane"); //Retired
       tagsCollection.insert("0018,9098" , "Transmitter Frequency");
       tagsCollection.insert("0018,9100" , "Resonant Nucleus");
       tagsCollection.insert("0018,9101" , "Frequency Correction");
       tagsCollection.insert("0018,9103" , "MR Spectroscopy FOV/Geometry Sequence");
       tagsCollection.insert("0018,9104" , "Slab Thickness");
       tagsCollection.insert("0018,9105" , "Slab Orientation");
       tagsCollection.insert("0018,9106" , "Mid Slab Position");
       tagsCollection.insert("0018,9107" , "MR Spatial Saturation Sequence");
       tagsCollection.insert("0018,9112" , "MR Timing and Related Parameters Sequence");
       tagsCollection.insert("0018,9114" , "MR Echo Sequence");
       tagsCollection.insert("0018,9115" , "MR Modifier Sequence");
       tagsCollection.insert("0018,9117" , "MR Diffusion Sequence");
       tagsCollection.insert("0018,9118" , "Cardiac Synchronization Sequence");
       tagsCollection.insert("0018,9119" , "MR Averages Sequence");
       tagsCollection.insert("0018,9125" , "MR FOV/Geometry Sequence");
       tagsCollection.insert("0018,9126" , "Volume Localization Sequence");
       tagsCollection.insert("0018,9127" , "Spectroscopy Acquisition Data Columns");
       tagsCollection.insert("0018,9147" , "Diffusion Anisotropy Type");
       tagsCollection.insert("0018,9151" , "Frame Reference DateTime");
       tagsCollection.insert("0018,9152" , "MR Metabolite Map Sequence");
       tagsCollection.insert("0018,9155" , "Parallel Reduction Factor out-of-plane");
       tagsCollection.insert("0018,9159" , "Spectroscopy Acquisition Out-of-plane Phase Steps");
       tagsCollection.insert("0018,9166" , "Bulk Motion Status");//	Retired
       tagsCollection.insert("0018,9168" , "Parallel Reduction Factor Second In-plane");
       tagsCollection.insert("0018,9169" , "Cardiac Beat Rejection Technique");
       tagsCollection.insert("0018,9170" , "Respiratory Motion Compensation Technique");
       tagsCollection.insert("0018,9171" , "Respiratory Signal Source");
       tagsCollection.insert("0018,9172" , "Bulk Motion Compensation Technique");
       tagsCollection.insert("0018,9173" , "Bulk Motion Signal Source");
       tagsCollection.insert("0018,9174" , "Applicable Safety Standard Agency");
       tagsCollection.insert("0018,9175" , "Applicable Safety Standard Description");
       tagsCollection.insert("0018,9176" , "Operating Mode Sequence");
       tagsCollection.insert("0018,9177" , "Operating Mode Type");
       tagsCollection.insert("0018,9178" , "Operating Mode");
       tagsCollection.insert("0018,9179" , "Specific Absorption Rate Definition");
       tagsCollection.insert("0018,9180" , "Gradient Output Type");
       tagsCollection.insert("0018,9181" , "Specific Absorption Rate Value");
       tagsCollection.insert("0018,9182" , "Gradient Output");
       tagsCollection.insert("0018,9183" , "Flow Compensation Direction");
       tagsCollection.insert("0018,9184" , "Tagging Delay");
       tagsCollection.insert("0018,9185" , "Respiratory Motion Compensation Technique Description");
       tagsCollection.insert("0018,9186" , "Respiratory Signal Source ID");
       tagsCollection.insert("0018,9195" , "Chemical Shift Minimum Integration Limit in Hz");//	Retired
       tagsCollection.insert("0018,9196" , "Chemical Shift Maximum Integration Limit in Hz");//	Retired
       tagsCollection.insert("0018,9197" , "MR Velocity Encoding Sequence");
       tagsCollection.insert("0018,9198" , "First Order Phase Correction");
       tagsCollection.insert("0018,9199" , "Water Referenced Phase Correction");
       tagsCollection.insert("0018,9200" , "MR Spectroscopy Acquisition Type");
       tagsCollection.insert("0018,9214" , "Respiratory Cycle Position");
       tagsCollection.insert("0018,9217" , "Velocity Encoding Maximum Value");
       tagsCollection.insert("0018,9218" , "Tag Spacing Second Dimension");
       tagsCollection.insert("0018,9219" , "Tag Angle Second Axis");
       tagsCollection.insert("0018,9220" , "Frame Acquisition Duration");
       tagsCollection.insert("0018,9226" , "MR Image Frame Type Sequence");
       tagsCollection.insert("0018,9227" , "MR Spectroscopy Frame Type Sequence");
       tagsCollection.insert("0018,9231" , "MR Acquisition Phase Encoding Steps in-plane");
       tagsCollection.insert("0018,9232" , "MR Acquisition Phase Encoding Steps out-of-plane");
       tagsCollection.insert("0018,9234" , "Spectroscopy Acquisition Phase Columns");
       tagsCollection.insert("0018,9236" , "Cardiac Cycle Position");
       tagsCollection.insert("0018,9239" , "Specific Absorption Rate Sequence");
       tagsCollection.insert("0018,9240" , "RF Echo Train Length");
       tagsCollection.insert("0018,9241" , "Gradient Echo Train Length");
       tagsCollection.insert("0018,9250" , "Arterial Spin Labeling Contrast");
       tagsCollection.insert("0018,9251" , "MR Arterial Spin Labeling Sequence");
       tagsCollection.insert("0018,9252" , "ASL Technique Description");
       tagsCollection.insert("0018,9253" , "ASL Slab Number");
       tagsCollection.insert("0018,9254" , "ASL Slab Thickness");
       tagsCollection.insert("0018,9255" , "ASL Slab Orientation");
       tagsCollection.insert("0018,9256" , "ASL Mid Slab Position");
       tagsCollection.insert("0018,9257" , "ASL Context");
       tagsCollection.insert("0018,9258" , "ASL Pulse Train Duration");
       tagsCollection.insert("0018,9259" , "ASL Crusher Flag");
       tagsCollection.insert("0018,925A" , "ASL Crusher Flow Limit");
       tagsCollection.insert("0018,925B" , "ASL Crusher Description");
       tagsCollection.insert("0018,925C" , "ASL Bolus Cut-off Flag");
       tagsCollection.insert("0018,925D" , "ASL Bolus Cut-off Timing Sequence");
       tagsCollection.insert("0018,925E" , "ASL Bolus Cut-off Technique");
       tagsCollection.insert("0018,925F" , "ASL Bolus Cut-off Delay Time");
       tagsCollection.insert("0018,9260" , "ASL Slab Sequence");
       tagsCollection.insert("0018,9295" , "Chemical Shift Minimum Integration Limit in ppm");
       tagsCollection.insert("0018,9296" , "Chemical Shift Maximum Integration Limit in ppm");
       tagsCollection.insert("0018,9297" , "Water Reference Acquisition");
       tagsCollection.insert("0018,9298" , "Echo Peak Position");
       tagsCollection.insert("0018,9301" , "CT Acquisition Type Sequence");
       tagsCollection.insert("0018,9302" , "Acquisition Type");
       tagsCollection.insert("0018,9303" , "Tube Angle");
       tagsCollection.insert("0018,9304" , "CT Acquisition Details Sequence");
       tagsCollection.insert("0018,9305" , "Revolution Time");
       tagsCollection.insert("0018,9306" , "Single Collimation Width");
       tagsCollection.insert("0018,9307" , "Total Collimation Width");
       tagsCollection.insert("0018,9308" , "CT Table Dynamics Sequence");
       tagsCollection.insert("0018,9309" , "Table Speed");
       tagsCollection.insert("0018,9310" , "Table Feed per Rotation");
       tagsCollection.insert("0018,9311" , "Spiral Pitch Factor");
       tagsCollection.insert("0018,9312" , "CT Geometry Sequence");
       tagsCollection.insert("0018,9313" , "Data Collection Center (Patient)");
       tagsCollection.insert("0018,9314" , "CT Reconstruction Sequence");
       tagsCollection.insert("0018,9315" , "Reconstruction Algorithm");
       tagsCollection.insert("0018,9316" , "Convolution Kernel Group");
       tagsCollection.insert("0018,9317" , "Reconstruction Field of View");
       tagsCollection.insert("0018,9318" , "Reconstruction Target Center (Patient)");
       tagsCollection.insert("0018,9319" , "Reconstruction Angle");
       tagsCollection.insert("0018,9320" , "Image Filter");
       tagsCollection.insert("0018,9321" , "CT Exposure Sequence");
       tagsCollection.insert("0018,9322" , "Reconstruction Pixel Spacing");
       tagsCollection.insert("0018,9323" , "Exposure Modulation Type");
       tagsCollection.insert("0018,9324" , "Estimated Dose Saving");
       tagsCollection.insert("0018,9325" , "CT X-Ray Details Sequence");
       tagsCollection.insert("0018,9326" , "CT Position Sequence");
       tagsCollection.insert("0018,9327" , "Table Position");
       tagsCollection.insert("0018,9328" , "Exposure Time in ms");
       tagsCollection.insert("0018,9329" , "CT Image Frame Type Sequence");
       tagsCollection.insert("0018,9330" , "X-Ray Tube Current in mA");
       tagsCollection.insert("0018,9332" , "Exposure in mAs");
       tagsCollection.insert("0018,9333" , "Constant Volume Flag");
       tagsCollection.insert("0018,9334" , "Fluoroscopy Flag");
       tagsCollection.insert("0018,9335" , "Distance Source to Data Collection Center");
       tagsCollection.insert("0018,9337" , "Contrast/Bolus Agent Number");
       tagsCollection.insert("0018,9338" , "Contrast/Bolus Ingredient Code Sequence");
       tagsCollection.insert("0018,9340" , "Contrast Administration Profile Sequence");
       tagsCollection.insert("0018,9341" , "Contrast/Bolus Usage Sequence");
       tagsCollection.insert("0018,9342" , "Contrast/Bolus Agent Administered");
       tagsCollection.insert("0018,9343" , "Contrast/Bolus Agent Detected");
       tagsCollection.insert("0018,9344" , "Contrast/Bolus Agent Phase");
       tagsCollection.insert("0018,9345" , "CTDIvol");
       tagsCollection.insert("0018,9346" , "CTDI Phantom Type Code Sequence");
       tagsCollection.insert("0018,9351" , "Calcium Scoring Mass Factor Patient");
       tagsCollection.insert("0018,9352" , "Calcium Scoring Mass Factor Device");
       tagsCollection.insert("0018,9353" , "Energy Weighting Factor");
       tagsCollection.insert("0018,9360" , "CT Additional X-Ray Source Sequence");
       tagsCollection.insert("0018,9401" , "Projection Pixel Calibration Sequence");
       tagsCollection.insert("0018,9402" , "Distance Source to Isocenter");
       tagsCollection.insert("0018,9403" , "Distance Object to Table Top");
       tagsCollection.insert("0018,9404" , "Object Pixel Spacing in Center of Beam");
       tagsCollection.insert("0018,9405" , "Positioner Position Sequence");
       tagsCollection.insert("0018,9406" , "Table Position Sequence");
       tagsCollection.insert("0018,9407" , "Collimator Shape Sequence");
       tagsCollection.insert("0018,9410" , "Planes in Acquisition");
       tagsCollection.insert("0018,9412" , "XA/XRF Frame Characteristics Sequence");
       tagsCollection.insert("0018,9417" , "Frame Acquisition Sequence");
       tagsCollection.insert("0018,9420" , "X-Ray Receptor Type");
       tagsCollection.insert("0018,9423" , "Acquisition Protocol Name");
       tagsCollection.insert("0018,9424" , "Acquisition Protocol Description");
       tagsCollection.insert("0018,9425" , "Contrast/Bolus Ingredient Opaque");
       tagsCollection.insert("0018,9426" , "Distance Receptor Plane to Detector Housing");
       tagsCollection.insert("0018,9427" , "Intensifier Active Shape");
       tagsCollection.insert("0018,9428" , "Intensifier Active Dimension(s)");
       tagsCollection.insert("0018,9429" , "Physical Detector Size");
       tagsCollection.insert("0018,9430" , "Position of Isocenter Projection");
       tagsCollection.insert("0018,9432" , "Field of View Sequence");
       tagsCollection.insert("0018,9433" , "Field of View Description");
       tagsCollection.insert("0018,9434" , "Exposure Control Sensing Regions Sequence");
       tagsCollection.insert("0018,9435" , "Exposure Control Sensing Region Shape");
       tagsCollection.insert("0018,9436" , "Exposure Control Sensing Region Left Vertical Edge");
       tagsCollection.insert("0018,9437" , "Exposure Control Sensing Region Right Vertical Edge");
       tagsCollection.insert("0018,9438" , "Exposure Control Sensing Region Upper Horizontal Edge");
       tagsCollection.insert("0018,9439" , "Exposure Control Sensing Region Lower Horizontal Edge");
       tagsCollection.insert("0018,9440" , "Center of Circular Exposure Control Sensing Region");
       tagsCollection.insert("0018,9441" , "Radius of Circular Exposure Control Sensing Region");
       tagsCollection.insert("0018,9442" , "Vertices of the Polygonal Exposure Control Sensing Region");
       tagsCollection.insert("0018,9445" , "");// Retired
       tagsCollection.insert("0018,9447" , "Column Angulation (Patient)");
       tagsCollection.insert("0018,9449" , "Beam Angle");
       tagsCollection.insert("0018,9451" , "Frame Detector Parameters Sequence");
       tagsCollection.insert("0018,9452" , "Calculated Anatomy Thickness");
       tagsCollection.insert("0018,9455" , "Calibration Sequence");
       tagsCollection.insert("0018,9456" , "Object Thickness Sequence");
       tagsCollection.insert("0018,9457" , "Plane Identification");
       tagsCollection.insert("0018,9461" , "Field of View Dimension(s) in Float");
       tagsCollection.insert("0018,9462" , "Isocenter Reference System Sequence");
       tagsCollection.insert("0018,9463" , "Positioner Isocenter Primary Angle");
       tagsCollection.insert("0018,9464" ,	"Positioner Isocenter Secondary Angle");
       tagsCollection.insert("0018,9465" ,	"Positioner Isocenter Detector Rotation Angle");
       tagsCollection.insert("0018,9466" ,	"Table X Position to Isocenter");
       tagsCollection.insert("0018,9467" ,	"Table Y Position to Isocenter");
       tagsCollection.insert("0018,9468" ,	"Table Z Position to Isocenter");
       tagsCollection.insert("0018,9469" ,	"Table Horizontal Rotation Angle");
       tagsCollection.insert("0018,9470" ,	"Table Head Tilt Angle");
       tagsCollection.insert("0018,9471" ,	"Table Cradle Tilt Angle");
       tagsCollection.insert("0018,9472" ,	"Frame Display Shutter Sequence");
       tagsCollection.insert("0018,9473" ,	"Acquired Image Area Dose Product");
       tagsCollection.insert("0018,9474" ,	"C-arm Positioner Tabletop Relationship");
       tagsCollection.insert("0018,9476" ,	"X-Ray Geometry Sequence");
       tagsCollection.insert("0018,9477" ,	"Irradiation Event Identification Sequence");
       tagsCollection.insert("0018,9504" ,	"X-Ray 3D Frame Type Sequence");
       tagsCollection.insert("0018,9506" ,	"Contributing Sources Sequence");
       tagsCollection.insert("0018,9507" ,	"X-Ray 3D Acquisition Sequence");
       tagsCollection.insert("0018,9508" ,	"Primary Positioner Scan Arc");
       tagsCollection.insert("0018,9509" ,	"Secondary Positioner Scan Arc");
       tagsCollection.insert("0018,9510" ,	"Primary Positioner Scan Start Angle");
       tagsCollection.insert("0018,9511" ,	"Secondary Positioner Scan Start Angle");
       tagsCollection.insert("0018,9514" ,	"Primary Positioner Increment");
       tagsCollection.insert("0018,9515" ,	"Secondary Positioner Increment");
       tagsCollection.insert("0018,9516" ,	"Start Acquisition DateTime");
       tagsCollection.insert("0018,9517" ,	"End Acquisition DateTime");
       tagsCollection.insert("0018,9518" ,	"Primary Positioner Increment Sign");
       tagsCollection.insert("0018,9519" ,	"Secondary Positioner Increment Sign");
       tagsCollection.insert("0018,9524" ,	"Application Name");
       tagsCollection.insert("0018,9525" ,	"Application Version");
       tagsCollection.insert("0018,9526" ,	"Application Manufacturer");
       tagsCollection.insert("0018,9527" ,	"Algorithm Type");
       tagsCollection.insert("0018,9528" ,	"Algorithm Description");
       tagsCollection.insert("0018,9530" ,	"X-Ray 3D Reconstruction Sequence");
       tagsCollection.insert("0018,9531" ,	"Reconstruction Description");
       tagsCollection.insert("0018,9538" ,	"Per Projection Acquisition Sequence");
       tagsCollection.insert("0018,9541" ,	"Detector Position Sequence");
       tagsCollection.insert("0018,9542" ,	"X-Ray Acquisition Dose Sequence");
       tagsCollection.insert("0018,9543" ,	"X-Ray Source Isocenter Primary Angle");
       tagsCollection.insert("0018,9544" ,	"X-Ray Source Isocenter Secondary Angle");
       tagsCollection.insert("0018,9545" ,	"Breast Support Isocenter Primary Angle");
       tagsCollection.insert("0018,9546" ,	"Breast Support Isocenter Secondary Angle");
       tagsCollection.insert("0018,9547" ,	"Breast Support X Position to Isocenter");
       tagsCollection.insert("0018,9548" ,	"Breast Support Y Position to Isocenter");
       tagsCollection.insert("0018,9549" ,	"Breast Support Z Position to Isocenter");
       tagsCollection.insert("0018,9550" ,	"Detector Isocenter Primary Angle");
       tagsCollection.insert("0018,9551" ,	"Detector Isocenter Secondary Angle");
       tagsCollection.insert("0018,9552" ,	"Detector X Position to Isocenter");
       tagsCollection.insert("0018,9553" ,	"Detector Y Position to Isocenter");
       tagsCollection.insert("0018,9554" ,	"Detector Z Position to Isocenter");
       tagsCollection.insert("0018,9555" ,	"X-Ray Grid Sequence");
       tagsCollection.insert("0018,9556" ,	"X-Ray Filter Sequence");
       tagsCollection.insert("0018,9557" ,	"Detector Active Area TLHC Position");
       tagsCollection.insert("0018,9558" ,	"Detector Active Area Orientation");
       tagsCollection.insert("0018,9559" ,	"Positioner Primary Angle Direction");
       tagsCollection.insert("0018,9601" ,	"Diffusion b-matrix Sequence");
       tagsCollection.insert("0018,9602" ,	"Diffusion b-value XX");
       tagsCollection.insert("0018,9603" ,	"Diffusion b-value XY");
       tagsCollection.insert("0018,9604" ,	"Diffusion b-value XZ");
       tagsCollection.insert("0018,9605" ,	"Diffusion b-value YY");
       tagsCollection.insert("0018,9606" ,	"Diffusion b-value YZ");
       tagsCollection.insert("0018,9607" ,	"Diffusion b-value ZZ");
       tagsCollection.insert("0018,9621" ,	"Functional MR Sequence");
       tagsCollection.insert("0018,9622" ,	"Functional Settling Phase Frames Present");
       tagsCollection.insert("0018,9623" ,	"Functional Sync Pulse");
       tagsCollection.insert("0018,9624" ,	"Settling Phase Frame");
       tagsCollection.insert("0018,9701" ,	"Decay Correction DateTime");
       tagsCollection.insert("0018,9715" ,	"Start Density Threshold");
       tagsCollection.insert("0018,9716" ,	"Start Relative Density Difference Threshold");
       tagsCollection.insert("0018,9717" ,	"Start Cardiac Trigger Count Threshold");
       tagsCollection.insert("0018,9718" ,	"Start Respiratory Trigger Count Threshold");
       tagsCollection.insert("0018,9719" ,	"Termination Counts Threshold");
       tagsCollection.insert("0018,9720" ,	"Termination Density Threshold");
       tagsCollection.insert("0018,9721" ,	"Termination Relative Density Threshold");
       tagsCollection.insert("0018,9722" ,	"Termination Time Threshold");
       tagsCollection.insert("0018,9723" ,	"Termination Cardiac Trigger Count Threshold");
       tagsCollection.insert("0018,9724" ,	"Termination Respiratory Trigger Count Threshold");
       tagsCollection.insert("0018,9725" ,	"Detector Geometry");
       tagsCollection.insert("0018,9726" ,	"Transverse Detector Separation");
       tagsCollection.insert("0018,9727" ,	"Axial Detector Dimension");
       tagsCollection.insert("0018,9729" ,	"Radiopharmaceutical Agent Number");
       tagsCollection.insert("0018,9732" ,	"PET Frame Acquisition Sequence");
       tagsCollection.insert("0018,9733" ,	"PET Detector Motion Details Sequence");
       tagsCollection.insert("0018,9734" ,	"PET Table Dynamics Sequence");
       tagsCollection.insert("0018,9735" ,	"PET Position Sequence");
       tagsCollection.insert("0018,9736" ,	"PET Frame Correction Factors Sequence");
       tagsCollection.insert("0018,9737" ,	"Radiopharmaceutical Usage Sequence");
       tagsCollection.insert("0018,9738" ,	"Attenuation Correction Source");
       tagsCollection.insert("0018,9739" ,	"Number of Iterations");
       tagsCollection.insert("0018,9740" ,	"Number of Subsets");
       tagsCollection.insert("0018,9749" ,	"PET Reconstruction Sequence");
       tagsCollection.insert("0018,9751" ,	"PET Frame Type Sequence");
       tagsCollection.insert("0018,9755" ,	"Time of Flight Information Used");
       tagsCollection.insert("0018,9756" ,	"Reconstruction Type");
       tagsCollection.insert("0018,9758" ,	"Decay Corrected");
       tagsCollection.insert("0018,9759" ,	"Attenuation Corrected");
       tagsCollection.insert("0018,9760" ,	"Scatter Corrected");
       tagsCollection.insert("0018,9761" ,	"Dead Time Corrected");
       tagsCollection.insert("0018,9762" ,	"Gantry Motion Corrected");
       tagsCollection.insert("0018,9763" ,	"Patient Motion Corrected");
       tagsCollection.insert("0018,9764" ,	"Count Loss Normalization Corrected");
       tagsCollection.insert("0018,9765" ,	"Randoms Corrected");
       tagsCollection.insert("0018,9766" ,	"Non-uniform Radial Sampling Corrected");
       tagsCollection.insert("0018,9767" ,	"Sensitivity Calibrated");
       tagsCollection.insert("0018,9768" ,	"Detector Normalization Correction");
       tagsCollection.insert("0018,9769" ,	"Iterative Reconstruction Method");
       tagsCollection.insert("0018,9770" ,	"Attenuation Correction Temporal Relationship");
       tagsCollection.insert("0018,9771" ,	"Patient Physiological State Sequence");
       tagsCollection.insert("0018,9772" ,	"Patient Physiological State Code Sequence");
       tagsCollection.insert("0018,9801" ,	"Depth(s) of Focus");
       tagsCollection.insert("0018,9803" ,	"Excluded Intervals Sequence");
       tagsCollection.insert("0018,9804" ,	"Exclusion Start DateTime");
       tagsCollection.insert("0018,9805" ,	"Exclusion Duration");
       tagsCollection.insert("0018,9806" ,	"US Image Description Sequence");
       tagsCollection.insert("0018,9807" ,	"Image Data Type Sequence");
       tagsCollection.insert("0018,9808" ,	"Data Type");
       tagsCollection.insert("0018,9809" ,	"Transducer Scan Pattern Code Sequence");
       tagsCollection.insert("0018,980B" ,	"Aliased Data Type");
       tagsCollection.insert("0018,980C" ,	"Position Measuring Device Used");
       tagsCollection.insert("0018,980D" ,	"Transducer Geometry Code Sequence");
       tagsCollection.insert("0018,980E" ,	"Transducer Beam Steering Code Sequence");
       tagsCollection.insert("0018,980F" ,	"Transducer Application Code Sequence");
       tagsCollection.insert("0018,9810" , 	"Zero Velocity Pixel Value");
       tagsCollection.insert("0018,A001" ,	"Contributing Equipment Sequence");
       tagsCollection.insert("0018,A002" ,	"Contribution DateTime");
       tagsCollection.insert("0018,A003" ,	"Contribution Description");
       tagsCollection.insert("0020,000D" ,	"Study Instance UID");
       tagsCollection.insert("0020,000E" ,	"Series Instance UID");
       tagsCollection.insert("0020,0010" ,	"Study ID");
       tagsCollection.insert("0020,0011" ,	"Series Number");
       tagsCollection.insert("0020,0012" ,	"Acquisition Number");
       tagsCollection.insert("0020,0013" ,	"Instance Number");
       tagsCollection.insert("0020,0014" ,	"Isotope Number	Retired");
       tagsCollection.insert("0020,0015" ,	"Phase Number	Retired");
       tagsCollection.insert("0020,0016" ,	"Interval Number");	//Retired
       tagsCollection.insert("0020,0017" ,	"Time Slot Number");	//Retired
       tagsCollection.insert("0020,0018" ,	"Angle Number");	//Retired
       tagsCollection.insert("0020,0019" ,	"Item Number");
       tagsCollection.insert("0020,0020" ,	"Patient Orientation");
       tagsCollection.insert("0020,0022" ,	"Overlay Number");	//Retired
       tagsCollection.insert("0020,0024" ,	"Curve Number");	//Retired
       tagsCollection.insert("0020,0026" ,	"LUT Number");      //Retired
       tagsCollection.insert("0020,0030" ,	"Image Position");  //Retired
       tagsCollection.insert("0020,0032" ,	"Image Position (Patient)");
       tagsCollection.insert("0020,0035" ,	"Image Orientation");//	Retired
       tagsCollection.insert("0020,0037" ,	"Image Orientation (Patient)");
       tagsCollection.insert("0020,0050" ,	"Location");	//Retired
       tagsCollection.insert("0020,0052" ,	"Frame of Reference UID");
       tagsCollection.insert("0020,0060" ,	"Laterality");
       tagsCollection.insert("0020,0062" ,	"Image Laterality");
       tagsCollection.insert("0020,0070" ,	"Image Geometry Type");	//Retired
       tagsCollection.insert("0020,0080" ,	"Masking Image");	//Retired
       tagsCollection.insert("0020,00AA" ,	"Report Number");	//Retired
       tagsCollection.insert("0020,0100" ,	"Temporal Position Identifier");
       tagsCollection.insert("0020,0105" ,	"Number of Temporal Positions");
       tagsCollection.insert("0020,0110" ,	"Temporal Resolution");
       tagsCollection.insert("0020,0200" ,	"Synchronization Frame of Reference UID");
       tagsCollection.insert("0020,0242" ,	"SOP Instance UID of Concatenation Source");
       tagsCollection.insert("0020,1000" ,	"Series in Study");	//Retired
       tagsCollection.insert("0020,1001" ,	"Acquisitions in Series");	//Retired
       tagsCollection.insert("0020,1002" ,	"Images in Acquisition");
       tagsCollection.insert("0020,1003" ,	"Images in Series");	//Retired
       tagsCollection.insert("0020,1004" ,	"Acquisitions in Study");	//Retired
       tagsCollection.insert("0020,1005" ,	"Images in Study");	//Retired
       tagsCollection.insert("0020,1020" ,	"Reference	Retired");
       tagsCollection.insert("0020,1040" ,	"Position Reference Indicator");
       tagsCollection.insert("0020,1041" ,	"Slice Location");
       tagsCollection.insert("0020,1070" ,	"Other Study Numbers");//	Retired
       tagsCollection.insert("0020,1200" ,	"Number of Patient Related Studies");
       tagsCollection.insert("0020,1202" ,	"Number of Patient Related Series");
       tagsCollection.insert("0020,1204" ,	"Number of Patient Related Instances");
       tagsCollection.insert("0020,1206" ,	"Number of Study Related Series");
       tagsCollection.insert("0020,1208" ,	"Number of Study Related Instances");
       tagsCollection.insert("0020,1209" ,	"Number of Series Related Instances");
       tagsCollection.insert("0020,31xx" ,	"Source Image IDs");  //Retired
       tagsCollection.insert("0020,3401" ,	"Modifying Device ID");	//Retired
       tagsCollection.insert("0020,3402" ,	"Modified Image ID");	//Retired
       tagsCollection.insert("0020,3403" ,	"Modified Image Date");	//Retired
       tagsCollection.insert("0020,3404" ,	"Modifying Device Manufacturer");	//Retired
       tagsCollection.insert("0020,3405" ,	"Modified Image Time");	//Retired
       tagsCollection.insert("0020,3406" ,	"Modified Image Description");	//Retired
       tagsCollection.insert("0020,4000" ,	"Image Comments");
       tagsCollection.insert("0020,5000" ,	"Original Image Identification");	//Retired
       tagsCollection.insert("0020,5002" ,	"Original Image Identification Nomenclature");	//Retired
       tagsCollection.insert("0020,9056" ,	"Stack ID");
       tagsCollection.insert("0020,9057" ,	"In-Stack Position Number");
       tagsCollection.insert("0020,9071" ,	"Frame Anatomy Sequence");
       tagsCollection.insert("0020,9072" ,	"Frame Laterality");
       tagsCollection.insert("0020,9111" ,	"Frame Content Sequence");
       tagsCollection.insert("0020,9113" ,	"Plane Position Sequence");
       tagsCollection.insert("0020,9116" ,	"Plane Orientation Sequence");
       tagsCollection.insert("0020,9128" ,	"Temporal Position Index");
       tagsCollection.insert("0020,9153" ,	"Nominal Cardiac Trigger Delay Time");
       tagsCollection.insert("0020,9154" ,	"Nominal Cardiac Trigger Time Prior To R-Peak");
       tagsCollection.insert("0020,9155" ,	"Actual Cardiac Trigger Time Prior To R-Peak");
       tagsCollection.insert("0020,9156" ,	"Frame Acquisition Number");
       tagsCollection.insert("0020,9157" ,	"Dimension Index Values");
       tagsCollection.insert("0020,9158" ,	"Frame Comments");
       tagsCollection.insert("0020,9161" ,	"Concatenation UID");
       tagsCollection.insert("0020,9162" ,	"In-concatenation Number");
       tagsCollection.insert("0020,9163" ,	"In-concatenation Total Number");
       tagsCollection.insert("0020,9164" ,	"Dimension Organization UID");
       tagsCollection.insert("0020,9165" ,	"Dimension Index Pointer");
       tagsCollection.insert("0020,9167" ,	"Functional Group Pointer");
       tagsCollection.insert("0020,9170" ,	"Unassigned Shared Converted Attributes Sequence");
       tagsCollection.insert("0020,9171" ,	"Unassigned Per-Frame Converted Attributes Sequence");
       tagsCollection.insert("0020,9172" ,	"Conversion Source Attributes Sequence");
       tagsCollection.insert("0020,9213" ,	"Dimension Index Private Creator");
       tagsCollection.insert("0020,9221" ,	"Dimension Organization Sequence");
       tagsCollection.insert("0020,9222" ,	"Dimension Index Sequence");
       tagsCollection.insert("0020,9228" ,	"Concatenation Frame Offset Number");
       tagsCollection.insert("0020,9238" ,	"Functional Group Private Creator");
       tagsCollection.insert("0020,9241" ,	"Nominal Percentage of Cardiac Phase");
       tagsCollection.insert("0020,9245" ,	"Nominal Percentage of Respiratory Phase");
       tagsCollection.insert("0020,9246" ,	"Starting Respiratory Amplitude");
       tagsCollection.insert("0020,9247" ,	"Starting Respiratory Phase");
       tagsCollection.insert("0020,9248" ,	"Ending Respiratory Amplitude");
       tagsCollection.insert("0020,9249" ,	"Ending Respiratory Phase");
       tagsCollection.insert("0020,9250" ,	"Respiratory Trigger Type");
       tagsCollection.insert("0020,9251" ,	"R-R Interval Time Nominal");
       tagsCollection.insert("0020,9252" ,	"Actual Cardiac Trigger Delay Time");
       tagsCollection.insert("0020,9253" ,	"Respiratory Synchronization Sequence");
       tagsCollection.insert("0020,9254" ,	"Respiratory Interval Time");
       tagsCollection.insert("0020,9255" ,	"Nominal Respiratory Trigger Delay Time");
       tagsCollection.insert("0020,9256" ,	"Respiratory Trigger Delay Threshold");
       tagsCollection.insert("0020,9257" ,	"Actual Respiratory Trigger Delay Time");
       tagsCollection.insert("0020,9301" ,	"Image Position (Volume)");
       tagsCollection.insert("0020,9302" ,	"Image Orientation (Volume)");
       tagsCollection.insert("0020,9307" ,	"Ultrasound Acquisition Geometry");
       tagsCollection.insert("0020,9308" ,	"Apex Position");
       tagsCollection.insert("0020,9309" ,	"Volume to Transducer Mapping Matrix");
       tagsCollection.insert("0020,930A" ,	"Volume to Table Mapping Matrix");
       tagsCollection.insert("0020,930B" ,	"Volume to Transducer Relationship");
       tagsCollection.insert("0020,930C" ,	"Patient Frame of Reference Source");
       tagsCollection.insert("0020,930D" ,	"Temporal Position Time Offset");
       tagsCollection.insert("0020,930E" ,	"Plane Position (Volume) Sequence");
       tagsCollection.insert("0020,930F" ,	"Plane Orientation (Volume) Sequence");
       tagsCollection.insert("0020,9310" ,	"Temporal Position Sequence");
       tagsCollection.insert("0020,9311" ,	"Dimension Organization Type");
       tagsCollection.insert("0020,9312" ,	"Volume Frame of Reference UID");
       tagsCollection.insert("0020,9313" ,	"Table Frame of Reference UID");
       tagsCollection.insert("0020,9421" ,	"Dimension Description Label");
       tagsCollection.insert("0020,9450" ,	"Patient Orientation in Frame Sequence");
       tagsCollection.insert("0020,9453" ,	"Frame Label");
       tagsCollection.insert("0020,9518" ,	"Acquisition Index");
       tagsCollection.insert("0020,9529" ,	"Contributing SOP Instances Reference Sequence");
       tagsCollection.insert("0020,9536" ,	"Reconstruction Index");
       tagsCollection.insert("0022,0001" ,	"Light Path Filter Pass-Through Wavelength");
       tagsCollection.insert("0022,0002" ,	"Light Path Filter Pass Band");
       tagsCollection.insert("0022,0003" ,	"Image Path Filter Pass-Through Wavelength");
       tagsCollection.insert("0022,0004" ,	"Image Path Filter Pass Band");
       tagsCollection.insert("0022,0005" ,	"Patient Eye Movement Commanded");
       tagsCollection.insert("0022,0006" ,	"Patient Eye Movement Command Code Sequence");
       tagsCollection.insert("0022,0007" ,	"Spherical Lens Power");
       tagsCollection.insert("0022,0008" ,	"Cylinder Lens Power");
       tagsCollection.insert("0022,0009" ,	"Cylinder Axis");
       tagsCollection.insert("0022,000A" ,	"Emmetropic Magnification");
       tagsCollection.insert("0022,000B" ,	"Intra Ocular Pressure");
       tagsCollection.insert("0022,000C" ,	"Horizontal Field of View");
       tagsCollection.insert("0022,000D" ,	"Pupil Dilated");
       tagsCollection.insert("0022,000E" ,	"Degree of Dilation");
       tagsCollection.insert("0022,0010" ,	"Stereo Baseline Angle");
       tagsCollection.insert("0022,0011" ,	"Stereo Baseline Displacement");
       tagsCollection.insert("0022,0012" ,	"Stereo Horizontal Pixel Offset");
       tagsCollection.insert("0022,0013" ,	"Stereo Vertical Pixel Offset");
       tagsCollection.insert("0022,0014" ,	"Stereo Rotation");
       tagsCollection.insert("0022,0015" ,	"Acquisition Device Type Code Sequence");
       tagsCollection.insert("0022,0016" ,	"Illumination Type Code Sequence");
       tagsCollection.insert("0022,0017" ,	"Light Path Filter Type Stack Code Sequence");
       tagsCollection.insert("0022,0018" ,	"Image Path Filter Type Stack Code Sequence");
       tagsCollection.insert("0022,0019" ,	"Lenses Code Sequence");
       tagsCollection.insert("0022,001A" ,	"Channel Description Code Sequence");
       tagsCollection.insert("0022,001B" ,	"Refractive State Sequence");
       tagsCollection.insert("0022,001C" ,	"Mydriatic Agent Code Sequence");
       tagsCollection.insert("0022,001D" ,	"Relative Image Position Code Sequence");
       tagsCollection.insert("0022,001E" ,	"Camera Angle of View");
       tagsCollection.insert("0022,0020" ,	"Stereo Pairs Sequence");
       tagsCollection.insert("0022,0021" ,	"Left Image Sequence");
       tagsCollection.insert("0022,0022" ,	"Right Image Sequence");
       tagsCollection.insert("0022,0028" ,	"Stereo Pairs Present");
       tagsCollection.insert("0022,0030" ,	"Axial Length of the Eye");
       tagsCollection.insert("0022,0031" ,	"Ophthalmic Frame Location Sequence");
       tagsCollection.insert("0022,0032" ,	"Reference Coordinates");
       tagsCollection.insert("0022,0035" ,	"Depth Spatial Resolution");
       tagsCollection.insert("0022,0036" ,	"Maximum Depth Distortion");
       tagsCollection.insert("0022,0037" ,	"Along-scan Spatial Resolution");
       tagsCollection.insert("0022,0038" ,	"Maximum Along-scan Distortion");
       tagsCollection.insert("0022,0039" ,	"Ophthalmic Image Orientation");
       tagsCollection.insert("0022,0041" ,	"Depth of Transverse Image");
       tagsCollection.insert("0022,0042" ,	"Mydriatic Agent Concentration Units Sequence");
       tagsCollection.insert("0022,0048" ,	"Across-scan Spatial Resolution");
       tagsCollection.insert("0022,0049" ,	"Maximum Across-scan Distortion");
       tagsCollection.insert("0022,004E" ,	"Mydriatic Agent Concentration");
       tagsCollection.insert("0022,0055" ,	"Illumination Wave Length");
       tagsCollection.insert("0022,0056" ,	"Illumination Power");
       tagsCollection.insert("0022,0057" ,	"Illumination Bandwidth");
       tagsCollection.insert("0022,0058" ,	"Mydriatic Agent Sequence");
       tagsCollection.insert("0022,1007" ,	"Ophthalmic Axial Measurements Right Eye Sequence");
       tagsCollection.insert("0022,1008" ,	"Ophthalmic Axial Measurements Left Eye Sequence");
       tagsCollection.insert("0022,1009" ,	"Ophthalmic Axial Measurements Device Type");
       tagsCollection.insert("0022,1010" ,	"Ophthalmic Axial Length Measurements Type");
       tagsCollection.insert("0022,1012" ,	"Ophthalmic Axial Length Sequence");
       tagsCollection.insert("0022,1019" ,	"Ophthalmic Axial Length");
       tagsCollection.insert("0022,1024" ,	"Lens Status Code Sequence");
       tagsCollection.insert("0022,1025" ,	"Vitreous Status Code Sequence");
       tagsCollection.insert("0022,1028" ,	"IOL Formula Code Sequence");
       tagsCollection.insert("0022,1029" ,	"IOL Formula Detail");
       tagsCollection.insert("0022,1033" ,	"Keratometer Index");
       tagsCollection.insert("0022,1035" ,	"Source of Ophthalmic Axial Length Code Sequence");
       tagsCollection.insert("0022,1037" ,	"Target Refraction");
       tagsCollection.insert("0022,1039" ,	"Refractive Procedure Occurred");
       tagsCollection.insert("0022,1040" ,	"Refractive Surgery Type Code Sequence");
       tagsCollection.insert("0022,1044" ,	"Ophthalmic Ultrasound Method Code Sequence");
       tagsCollection.insert("0022,1050" ,	"Ophthalmic Axial Length Measurements Sequence");
       tagsCollection.insert("0022,1053" ,	"IOL Power");
       tagsCollection.insert("0022,1054" ,	"Predicted Refractive Error");
       tagsCollection.insert("0022,1059" ,	"Ophthalmic Axial Length Velocity");
       tagsCollection.insert("0022,1065" ,	"Lens Status Description");
       tagsCollection.insert("0022,1066" ,	"Vitreous Status Description");
       tagsCollection.insert("0022,1090" ,	"IOL Power Sequence");
       tagsCollection.insert("0022,1092" ,	"Lens Constant Sequence");
       tagsCollection.insert("0022,1093" ,	"IOL Manufacturer");
       tagsCollection.insert("0022,1094" ,	"Lens Constant Description");	//Retired
       tagsCollection.insert("0022,1095" ,	"Implant Name");
       tagsCollection.insert("0022,1096" ,	"Keratometry Measurement Type Code Sequence");
       tagsCollection.insert("0022,1097" ,	"Implant Part Number");
       tagsCollection.insert("0022,1100" ,	"Referenced Ophthalmic Axial Measurements Sequence");
       tagsCollection.insert("0022,1101" ,	"Ophthalmic Axial Length Measurements Segment Name Code Sequence");
       tagsCollection.insert("0022,1103" ,	"Refractive Error Before Refractive Surgery Code Sequence");
       tagsCollection.insert("0022,1121" ,	"IOL Power For Exact Emmetropia");
       tagsCollection.insert("0022,1122" ,	"IOL Power For Exact Target Refraction");
       tagsCollection.insert("0022,1125" ,	"Anterior Chamber Depth Definition Code Sequence");
       tagsCollection.insert("0022,1127" ,	"Lens Thickness Sequence");
       tagsCollection.insert("0022,1128" ,	"Anterior Chamber Depth Sequence");
       tagsCollection.insert("0022,1130" ,	"Lens Thickness");
       tagsCollection.insert("0022,1131" ,	"Anterior Chamber Depth");
       tagsCollection.insert("0022,1132" ,	"Source of Lens Thickness Data Code Sequence");
       tagsCollection.insert("0022,1133" ,	"Source of Anterior Chamber Depth Data Code Sequence");
       tagsCollection.insert("0022,1134" ,	"Source of Refractive Measurements Sequence");
       tagsCollection.insert("0022,1135" ,	"Source of Refractive Measurements Code Sequence");
       tagsCollection.insert("0022,1140" ,	"Ophthalmic Axial Length Measurement Modified");
       tagsCollection.insert("0022,1150" ,	"Ophthalmic Axial Length Data Source Code Sequence");
       tagsCollection.insert("0022,1153" ,	"Ophthalmic Axial Length Acquisition Method Code Sequence");	//Retired
       tagsCollection.insert("0022,1155" ,	"Signal to Noise Ratio");
       tagsCollection.insert("0022,1159" ,	"Ophthalmic Axial Length Data Source Description");
       tagsCollection.insert("0022,1210" ,	"Ophthalmic Axial Length Measurements Total Length Sequence");
       tagsCollection.insert("0022,1211" ,	"Ophthalmic Axial Length Measurements Segmental Length Sequence");
       tagsCollection.insert("0022,1212" ,	"Ophthalmic Axial Length Measurements Length Summation Sequence");
       tagsCollection.insert("0022,1220" ,	"Ultrasound Ophthalmic Axial Length Measurements Sequence");
       tagsCollection.insert("0022,1225" ,	"Optical Ophthalmic Axial Length Measurements Sequence");
       tagsCollection.insert("0022,1230" ,	"Ultrasound Selected Ophthalmic Axial Length Sequence");
       tagsCollection.insert("0022,1250" ,	"Ophthalmic Axial Length Selection Method Code Sequence");
       tagsCollection.insert("0022,1255" ,	"Optical Selected Ophthalmic Axial Length Sequence");
       tagsCollection.insert("0022,1257" ,	"Selected Segmental Ophthalmic Axial Length Sequence");
       tagsCollection.insert("0022,1260" ,	"Selected Total Ophthalmic Axial Length Sequence");
       tagsCollection.insert("0022,1262" ,	"Ophthalmic Axial Length Quality Metric Sequence");
       tagsCollection.insert("0022,1265" ,	"Ophthalmic Axial Length Quality Metric Type Code Sequence");	//Retired
       tagsCollection.insert("0022,1273" ,	"Ophthalmic Axial Length Quality Metric Type Description");	//Retired
       tagsCollection.insert("0022,1300" ,	"Intraocular Lens Calculations Right Eye Sequence");
       tagsCollection.insert("0022,1310" ,	"Intraocular Lens Calculations Left Eye Sequence");
       tagsCollection.insert("0022,1330" ,	"Referenced Ophthalmic Axial Length Measurement QC Image Sequence");
       tagsCollection.insert("0022,1415" ,	"Ophthalmic Mapping Device Type");
       tagsCollection.insert("0022,1420" ,	"Acquisition Method Code Sequence");
       tagsCollection.insert("0022,1423" ,	"Acquisition Method Algorithm Sequence");
       tagsCollection.insert("0022,1436" ,	"Ophthalmic Thickness Map Type Code Sequence");
       tagsCollection.insert("0022,1443" ,	"Ophthalmic Thickness Mapping Normals Sequence");
       tagsCollection.insert("0022,1445" ,	"Retinal Thickness Definition Code Sequence");
       tagsCollection.insert("0022,1450" ,	"Pixel Value Mapping to Coded Concept Sequence");
       tagsCollection.insert("0022,1452" ,  "Mapped Pixel Value");
       tagsCollection.insert("0022,1454" ,	"Pixel Value Mapping Explanation");
       tagsCollection.insert("0022,1458" ,	"Ophthalmic Thickness Map Quality Threshold Sequence");
       tagsCollection.insert("0022,1460" ,	"Ophthalmic Thickness Map Threshold Quality Rating");
       tagsCollection.insert("0022,1463" ,	"Anatomic Structure Reference Point");
       tagsCollection.insert("0022,1465" ,	"Registration to Localizer Sequence");
       tagsCollection.insert("0022,1466" ,	"Registered Localizer Units");
       tagsCollection.insert("0022,1467" ,	"Registered Localizer Top Left Hand Corner");
       tagsCollection.insert("0022,1468" ,	"Registered Localizer Bottom Right Hand Corner");
       tagsCollection.insert("0022,1470" ,	"Ophthalmic Thickness Map Quality Rating Sequence");
       tagsCollection.insert("0022,1472" ,	"Relevant OPT Attributes Sequence");
       tagsCollection.insert("0022,1512" ,	"Transformation Method Code Sequence");
       tagsCollection.insert("0022,1513" ,	"Transformation Algorithm Sequence");
       tagsCollection.insert("0022,1515" ,	"Ophthalmic Axial Length Method");
       tagsCollection.insert("0022,1517" ,	"Ophthalmic FOV");
       tagsCollection.insert("0022,1518" ,	"Two Dimensional to Three Dimensional Map Sequence");
       tagsCollection.insert("0022,1525" ,	"Wide Field Ophthalmic Photography Quality Rating Sequence");
       tagsCollection.insert("0022,1526" ,	"Wide Field Ophthalmic Photography Quality Threshold Sequence");
       tagsCollection.insert("0022,1527" ,	"Wide Field Ophthalmic Photography Threshold Quality Rating");
       tagsCollection.insert("0022,1528" ,	"X Coordinates Center Pixel View Angle");
       tagsCollection.insert("0022,1529" ,	"Y Coordinates Center Pixel View Angle");
       tagsCollection.insert("0022,1530" ,	"Number of Map Points");
       tagsCollection.insert("0022,1531" ,	"Two Dimensional to Three Dimensional Map Data");
       tagsCollection.insert("0024,0010" ,	"Visual Field Horizontal Extent");
       tagsCollection.insert("0024,0011" ,	"Visual Field Vertical Extent");
       tagsCollection.insert("0024,0012" ,	"Visual Field Shape");
       tagsCollection.insert("0024,0016" ,	"Screening Test Mode Code Sequence");
       tagsCollection.insert("0024,0018" ,	"Maximum Stimulus Luminance");
       tagsCollection.insert("0024,0020" ,	"Background Luminance");
       tagsCollection.insert("0024,0021" ,	"Stimulus Color Code Sequence");
       tagsCollection.insert("0024,0024" ,	"Background Illumination Color Code Sequence");
       tagsCollection.insert("0024,0025" ,	"Stimulus Area");
       tagsCollection.insert("0024,0028" ,	"Stimulus Presentation Time");
       tagsCollection.insert("0024,0032" ,	"Fixation Sequence");
       tagsCollection.insert("0024,0033" ,	"Fixation Monitoring Code Sequence");
       tagsCollection.insert("0024,0034" ,	"Visual Field Catch Trial Sequence");
       tagsCollection.insert("0024,0035" ,	"Fixation Checked Quantity");
       tagsCollection.insert("0024,0036" ,	"Patient Not Properly Fixated Quantity");
       tagsCollection.insert("0024,0037" ,	"Presented Visual Stimuli Data Flag");
       tagsCollection.insert("0024,0038" ,	"Number of Visual Stimuli");
       tagsCollection.insert("0024,0039" ,	"Excessive Fixation Losses Data Flag");
       tagsCollection.insert("0024,0040" ,	"Excessive Fixation Losses");
       tagsCollection.insert("0024,0042" ,	"Stimuli Retesting Quantity");
       tagsCollection.insert("0024,0044" ,	"Comments on Patient's Performance of Visual Field");
       tagsCollection.insert("0024,0045" ,	"False Negatives Estimate Flag");
       tagsCollection.insert("0024,0046" ,	"False Negatives Estimate");
       tagsCollection.insert("0024,0048" ,	"Negative Catch Trials Quantity");
       tagsCollection.insert("0024,0050" ,	"False Negatives Quantity");
       tagsCollection.insert("0024,0051" ,	"Excessive False Negatives Data Flag");
       tagsCollection.insert("0024,0052" ,	"Excessive False Negatives");
       tagsCollection.insert("0024,0053" ,	"False Positives Estimate Flag");
       tagsCollection.insert("0024,0054" ,	"False Positives Estimate");
       tagsCollection.insert("0024,0055" ,	"Catch Trials Data Flag");
       tagsCollection.insert("0024,0056" ,	"Positive Catch Trials Quantity");
       tagsCollection.insert("0024,0057" ,	"Test Point Normals Data Flag");
       tagsCollection.insert("0024,0058" ,	"Test Point Normals Sequence");
       tagsCollection.insert("0024,0059" ,	"Global Deviation Probability Normals Flag");
       tagsCollection.insert("0024,0060" ,	"False Positives Quantity");
       tagsCollection.insert("0024,0061" ,	"Excessive False Positives Data Flag");
       tagsCollection.insert("0024,0062" ,	"Excessive False Positives");
       tagsCollection.insert("0024,0063" ,	"Visual Field Test Normals Flag");
       tagsCollection.insert("0024,0064" ,	"Results Normals Sequence");
       tagsCollection.insert("0024,0065" ,	"Age Corrected Sensitivity Deviation Algorithm Sequence");
       tagsCollection.insert("0024,0066" ,	"Global Deviation From Normal");
       tagsCollection.insert("0024,0067" ,	"Generalized Defect Sensitivity Deviation Algorithm Sequence");
       tagsCollection.insert("0024,0068" ,	"Localized Deviation From Normal");
       tagsCollection.insert("0024,0069" ,	"Patient Reliability Indicator");
       tagsCollection.insert("0024,0070" ,	"Visual Field Mean Sensitivity");
       tagsCollection.insert("0024,0071" ,	"Global Deviation Probability");
       tagsCollection.insert("0024,0072" ,	"Local Deviation Probability Normals Flag");
       tagsCollection.insert("0024,0073" ,	"Localized Deviation Probability");
       tagsCollection.insert("0024,0074" ,	"Short Term Fluctuation Calculated");
       tagsCollection.insert("0024,0075" ,	"Short Term Fluctuation");
       tagsCollection.insert("0024,0076" ,	"Short Term Fluctuation Probability Calculated");
       tagsCollection.insert("0024,0077" ,	"Short Term Fluctuation Probability");
       tagsCollection.insert("0024,0078" ,	"Corrected Localized Deviation From Normal Calculated");
       tagsCollection.insert("0024,0079" ,	"Corrected Localized Deviation From Normal");
       tagsCollection.insert("0024,0080" ,	"Corrected Localized Deviation From Normal Probability Calculated");
       tagsCollection.insert("0024,0081" ,	"Corrected Localized Deviation From Normal Probability");
       tagsCollection.insert("0024,0083" ,	"Global Deviation Probability Sequence");
       tagsCollection.insert("0024,0085" ,	"Localized Deviation Probability Sequence");
       tagsCollection.insert("0024,0086" ,	"Foveal Sensitivity Measured");
       tagsCollection.insert("0024,0087" ,	"Foveal Sensitivity");
       tagsCollection.insert("0024,0088" ,	"Visual Field Test Duration");
       tagsCollection.insert("0024,0089" ,	"Visual Field Test Point Sequence");
       tagsCollection.insert("0024,0090" ,	"Visual Field Test Point X-Coordinate");
       tagsCollection.insert("0024,0091" ,	"Visual Field Test Point Y-Coordinate");
       tagsCollection.insert("0024,0092" ,	"Age Corrected Sensitivity Deviation Value");
       tagsCollection.insert("0024,0093" ,	"Stimulus Results");
       tagsCollection.insert("0024,0094" ,	"Sensitivity Value");
       tagsCollection.insert("0024,0095" ,	"Retest Stimulus Seen");
       tagsCollection.insert("0024,0096" ,	"Retest Sensitivity Value");
       tagsCollection.insert("0024,0097" ,	"Visual Field Test Point Normals Sequence");
       tagsCollection.insert("0024,0098" ,	"Quantified Defect");
       tagsCollection.insert("0024,0100" ,	"Age Corrected Sensitivity Deviation Probability Value");
       tagsCollection.insert("0024,0102" ,	"Generalized Defect Corrected Sensitivity Deviation Flag");
       tagsCollection.insert("0024,0103" ,	"Generalized Defect Corrected Sensitivity Deviation Value");
       tagsCollection.insert("0024,0104" ,	"Generalized Defect Corrected Sensitivity Deviation Probability Value");
       tagsCollection.insert("0024,0105" ,	"Minimum Sensitivity Value");
       tagsCollection.insert("0024,0106" ,	"Blind Spot Localized");
       tagsCollection.insert("0024,0107" ,	"Blind Spot X-Coordinate");
       tagsCollection.insert("0024,0108" ,	"Blind Spot Y-Coordinate");
       tagsCollection.insert("0024,0110" ,	"Visual Acuity Measurement Sequence");
       tagsCollection.insert("0024,0112" ,	"Refractive Parameters Used on Patient Sequence");
       tagsCollection.insert("0024,0113" ,	"Measurement Laterality");
       tagsCollection.insert("0024,0114" ,	"Ophthalmic Patient Clinical Information Left Eye Sequence");
       tagsCollection.insert("0024,0115" ,	"Ophthalmic Patient Clinical Information Right Eye Sequence");
       tagsCollection.insert("0024,0117" ,	"Foveal Point Normative Data Flag");
       tagsCollection.insert("0024,0118" ,	"Foveal Point Probability Value");
       tagsCollection.insert("0024,0120" ,	"Screening Baseline Measured");
       tagsCollection.insert("0024,0122" ,	"Screening Baseline Measured Sequence");
       tagsCollection.insert("0024,0124" ,	"Screening Baseline Type");
       tagsCollection.insert("0024,0126" ,	"Screening Baseline Value");
       tagsCollection.insert("0024,0202" ,	"Algorithm Source");
       tagsCollection.insert("0024,0306" ,	"Data Set Name");
       tagsCollection.insert("0024,0307" ,	"Data Set Version");
       tagsCollection.insert("0024,0308" ,	"Data Set Source");
       tagsCollection.insert("0024,0309" ,	"Data Set Description");
       tagsCollection.insert("0024,0317" ,	"Visual Field Test Reliability Global Index Sequence");
       tagsCollection.insert("0024,0320" ,	"Visual Field Global Results Index Sequence");
       tagsCollection.insert("0024,0325" ,	"Data Observation Sequence");
       tagsCollection.insert("0024,0338" ,	"Index Normals Flag");
       tagsCollection.insert("0024,0341" ,	"Index Probability");
       tagsCollection.insert("0024,0344" ,	"Index Probability Sequence");
       tagsCollection.insert("0028,0002" ,	"Samples per Pixel");
       tagsCollection.insert("0028,0003" ,	"Samples per Pixel Used");
       tagsCollection.insert("0028,0004" ,	"Photometric Interpretation");
       tagsCollection.insert("0028,0005" ,	"Image Dimensions");	//Retired
       tagsCollection.insert("0028,0006" ,	"Planar Configuration");
       tagsCollection.insert("0028,0008" ,	"Number of Frames");
       tagsCollection.insert("0028,0009" ,	"Frame Increment Pointer");
       tagsCollection.insert("0028,000A" ,	"Frame Dimension Pointer");
       tagsCollection.insert("0028,0010" ,	"Rows");
       tagsCollection.insert("0028,0011" ,	"Columns");
       tagsCollection.insert("0028,0012" ,	"Planes");	//Retired
       tagsCollection.insert("0028,0014" ,	"Ultrasound Color Data Present");
       tagsCollection.insert("0028,0020" ,  "	Retired");
       tagsCollection.insert("0028,0030" ,	"Pixel Spacing");
       tagsCollection.insert("0028,0031" ,	"Zoom Factor");
       tagsCollection.insert("0028,0032" ,	"Zoom Center");
       tagsCollection.insert("0028,0034" ,	"Pixel Aspect Ratio");
       tagsCollection.insert("0028,0040" ,	"Image Format");	//Retired
       tagsCollection.insert("0028,0050" ,	"Manipulated Image");	//Retired
       tagsCollection.insert("0028,0051" ,	"Corrected Image");
       tagsCollection.insert("0028,005F" ,	"Compression Recognition Code");	//Retired
       tagsCollection.insert("0028,0060" ,	"Compression Code");	//Retired
       tagsCollection.insert("0028,0061" ,	"Compression Originator");	//Retired
       tagsCollection.insert("0028,0062" ,	"Compression Label");	//Retired
       tagsCollection.insert("0028,0063" ,	"Compression Description");	//Retired
       tagsCollection.insert("0028,0065" ,	"Compression Sequence");	//Retired
       tagsCollection.insert("0028,0066" ,	"Compression Step Pointers");	//Retired
       tagsCollection.insert("0028,0068" ,	"Repeat Interval");	//Retired
       tagsCollection.insert("0028,0069" ,	"Bits Grouped");	//Retired
       tagsCollection.insert("0028,0070" ,	"Perimeter Table");	//Retired
       tagsCollection.insert("0028,0071" ,  "Perimeter Value");	//Retired
       tagsCollection.insert("0028,0080" ,	"Predictor Rows");	//Retired
       tagsCollection.insert("0028,0081" ,	"Predictor Columns");	//Retired
       tagsCollection.insert("0028,0082" ,	"Predictor Constants");	//Retired
       tagsCollection.insert("0028,0090" ,	"Blocked Pixels");	//Retired
       tagsCollection.insert("0028,0091" ,	"Block Rows");	//Retired
       tagsCollection.insert("0028,0092" ,	"Block Columns");	//Retired
       tagsCollection.insert("0028,0093" ,	"Row Overlap");	//Retired
       tagsCollection.insert("0028,0094" ,	"Column Overlap");	//Retired
       tagsCollection.insert("0028,0100" ,	"Bits Allocated");
       tagsCollection.insert("0028,0101" ,	"Bits Stored");
       tagsCollection.insert("0028,0102" ,	"High Bit");
       tagsCollection.insert("0028,0103" ,	"Pixel Representation");
       tagsCollection.insert("0028,0104" , 	"Smallest Valid Pixel Value");	//Retired
       tagsCollection.insert("0028,0105" , 	"Largest Valid Pixel Value");	//Retired
       tagsCollection.insert("0028,0106" , 	"Smallest Image Pixel Value");
       tagsCollection.insert("0028,0107" , 	"Largest Image Pixel Value");
       tagsCollection.insert("0028,0108" , 	"Smallest Pixel Value in Series");
       tagsCollection.insert("0028,0109" , 	"Largest Pixel Value in Series");
       tagsCollection.insert("0028,0110" , 	"Smallest Image Pixel Value in Plane");	//Retired
       tagsCollection.insert("0028,0111" , 	"Largest Image Pixel Value in Plane");	//Retired
       tagsCollection.insert("0028,0120" , 	"Pixel Padding Value");
       tagsCollection.insert("0028,0121" , 	"Pixel Padding Range Limit");
       tagsCollection.insert("0028,0122" ,	"Float Pixel Padding Value");
       tagsCollection.insert("0028,0123" ,	"Double Float Pixel Padding Value");
       tagsCollection.insert("0028,0124" ,	"Float Pixel Padding Range Limit");
       tagsCollection.insert("0028,0125" ,	"Double Float Pixel Padding Range Limit");
       tagsCollection.insert("0028,0200" ,	"Image Location");	//Retired
       tagsCollection.insert("0028,0300" ,	"Quality Control Image");
       tagsCollection.insert("0028,0301" ,	"Burned In Annotation");
       tagsCollection.insert("0028,0302" ,	"Recognizable Visual Features");
       tagsCollection.insert("0028,0303" ,	"Longitudinal Temporal Information Modified");
       tagsCollection.insert("0028,0304" ,	"Referenced Color Palette Instance UID");
       tagsCollection.insert("0028,0400" ,	"Transform Label");	//Retired
       tagsCollection.insert("0028,0401" ,	"Transform Version Number");	//Retired
       tagsCollection.insert("0028,0402" ,	"Number of Transform Steps");	//Retired
       tagsCollection.insert("0028,0403" ,	"Sequence of Compressed Data");	//Retired
       tagsCollection.insert("0028,0404" ,	"Details of Coefficients");	//Retired
       tagsCollection.insert("0028,04x0" ,	"Rows For Nth Order Coefficients");	//Retired
       tagsCollection.insert("0028,04x1" ,	"Columns For Nth Order Coefficients");	//Retired
       tagsCollection.insert("0028,04x2" ,	"Coefficient Coding");	//Retired
       tagsCollection.insert("0028,04x3" ,	"Coefficient Coding Pointers");	//Retired
       tagsCollection.insert("0028,0700" ,	"DCT Label");	//Retired
       tagsCollection.insert("0028,0701" ,	"Data Block Description");	//Retired
       tagsCollection.insert("0028,0702" ,	"Data Block");	//Retired
       tagsCollection.insert("0028,0710" ,	"Normalization Factor Format");	//Retired
       tagsCollection.insert("0028,0720" ,	"Zonal Map Number Format");	//Retired
       tagsCollection.insert("0028,0721" ,	"Zonal Map Location");	//Retired
       tagsCollection.insert("0028,0722" ,	"Zonal Map Format");	//Retired
       tagsCollection.insert("0028,0730" ,	"Adaptive Map Format"); //Retired
       tagsCollection.insert("0028,0740" ,	"Code Number Format");	//Retired
       tagsCollection.insert("0028,08x0" ,	"Code Label");	//Retired
       tagsCollection.insert("0028,08x2" ,	"Number of Tables");	//Retired
       tagsCollection.insert("0028,08x3" ,	"Code Table Location");	//Retired
       tagsCollection.insert("0028,08x4" ,	"Bits For Code Word"); //Retired
       tagsCollection.insert("0028,08x8" ,	"Image Data Location");//Retired
       tagsCollection.insert("0028,0A02" ,	"Pixel Spacing Calibration Type");
       tagsCollection.insert("0028,0A04" ,	"Pixel Spacing Calibration Description");
       tagsCollection.insert("0028,1040" ,	"Pixel Intensity Relationship");
       tagsCollection.insert("0028,1041" ,	"Pixel Intensity Relationship Sign");
       tagsCollection.insert("0028,1050" ,	"Window Center");
       tagsCollection.insert("0028,1051" ,	"Window Width");
       tagsCollection.insert("0028,1052" ,	"Rescale Intercept");
       tagsCollection.insert("0028,1053" ,	"Rescale Slope");
       tagsCollection.insert("0028,1054" ,	"Rescale Type");
       tagsCollection.insert("0028,1055" ,	"Window Center & Width Explanation");
       tagsCollection.insert("0028,1056" ,	"VOI LUT Function");
       tagsCollection.insert("0028,1080" ,	"Gray Scale");	//Retired
       tagsCollection.insert("0028,1090" ,	"Recommended Viewing Mode");
       tagsCollection.insert("0028,1100" ,  "Gray Lookup Table Descriptor");	//Retired
       tagsCollection.insert("0028,1101" ,  "Red Palette Color Lookup Table Descriptor");
       tagsCollection.insert("0028,1102" ,  "Green Palette Color Lookup Table Descriptor");
       tagsCollection.insert("0028,1103" ,  "Blue Palette Color Lookup Table Descriptor");
       tagsCollection.insert("0028,1104" ,	"Alpha Palette Color Lookup Table Descriptor");
       tagsCollection.insert("0028,1111" ,  "Large Red Palette Color Lookup Table Descriptor");	//Retired
       tagsCollection.insert("0028,1112" ,  "Large Green Palette Color Lookup Table Descriptor");	//Retired
       tagsCollection.insert("0028,1113" ,  "Large Blue Palette Color Lookup Table Descriptor");	//Retired
       tagsCollection.insert("0028,1199" ,	"Palette Color Lookup Table UID");
       tagsCollection.insert("0028,1200" ,  "Gray Lookup Table Data");	//Retired
       tagsCollection.insert("0028,1201" ,	"Red Palette Color Lookup Table Data");
       tagsCollection.insert("0028,1202" ,	"Green Palette Color Lookup Table Data");
       tagsCollection.insert("0028,1203" ,	"Blue Palette Color Lookup Table Data");
       tagsCollection.insert("0028,1204" ,	"Alpha Palette Color Lookup Table Data");
       tagsCollection.insert("0028,1211" ,	"Large Red Palette Color Lookup Table Data");	//Retired
       tagsCollection.insert("0028,1212" ,	"Large Green Palette Color Lookup Table Data");	//Retired
       tagsCollection.insert("0028,1213" ,	"Large Blue Palette Color Lookup Table Data");	//Retired
       tagsCollection.insert("0028,1214" ,	"Large Palette Color Lookup Table UID");	    //Retired
       tagsCollection.insert("0028,1221" ,	"Segmented Red Palette Color Lookup Table Data");
       tagsCollection.insert("0028,1222" ,	"Segmented Green Palette Color Lookup Table Data");
       tagsCollection.insert("0028,1223" ,	"Segmented Blue Palette Color Lookup Table Data");
       tagsCollection.insert("0028,1224" ,	"Segmented Alpha Palette Color Lookup Table Data");
       tagsCollection.insert("0028,1300" ,	"Breast Implant Present");
       tagsCollection.insert("0028,1350" ,	"Partial View");
       tagsCollection.insert("0028,1351" ,	"Partial View Description");
       tagsCollection.insert("0028,1352" ,	"Partial View Code Sequence");
       tagsCollection.insert("0028,135A" ,	"Spatial Locations Preserved");
       tagsCollection.insert("0028,1401" ,	"Data Frame Assignment Sequence");
       tagsCollection.insert("0028,1402" ,	"Data Path Assignment");
       tagsCollection.insert("0028,1403" ,	"Bits Mapped to Color Lookup Table");
       tagsCollection.insert("0028,1404" ,	"Blending LUT 1 Sequence");
       tagsCollection.insert("0028,1405" ,	"Blending LUT 1 Transfer Function");
       tagsCollection.insert("0028,1406" ,	"Blending Weight Constant");
       tagsCollection.insert("0028,1407" ,	"Blending Lookup Table Descriptor");
       tagsCollection.insert("0028,1408" ,	"Blending Lookup Table Data");
       tagsCollection.insert("0028,140B" ,	"Enhanced Palette Color Lookup Table Sequence");
       tagsCollection.insert("0028,140C" ,	"Blending LUT 2 Sequence");
       tagsCollection.insert("0028,140D" ,	"Blending LUT 2 Transfer Function");
       tagsCollection.insert("0028,140E" ,	"Data Path ID");
       tagsCollection.insert("0028,140F" ,	"RGB LUT Transfer Function");
       tagsCollection.insert("0028,1410" ,	"Alpha LUT Transfer Function");
       tagsCollection.insert("0028,2000" ,	"ICC Profile");
       tagsCollection.insert("0028,2002" ,	"Color Space");
       tagsCollection.insert("0028,2110" ,	"Lossy Image Compression");
       tagsCollection.insert("0028,2112" ,	"Lossy Image Compression Ratio");
       tagsCollection.insert("0028,2114" ,	"Lossy Image Compression Method");
       tagsCollection.insert("0028,3000" ,	"Modality LUT Sequence");
       tagsCollection.insert("0028,3002" ,  "LUT Descriptor");
       tagsCollection.insert("0028,3003" ,	"LUT Explanation");
       tagsCollection.insert("0028,3004" ,	"Modality LUT Type");
       tagsCollection.insert("0028,3006" ,  "LUT Data");
       tagsCollection.insert("0028,3010" ,	"VOI LUT Sequence");
       tagsCollection.insert("0028,3110" ,	"Softcopy VOI LUT Sequence");
       tagsCollection.insert("0028,4000" ,	"Image Presentation Comments");	//Retired
       tagsCollection.insert("0028,5000" ,	"Bi-Plane Acquisition Sequence");	//Retired
       tagsCollection.insert("0028,6010" ,	"Representative Frame Number");
       tagsCollection.insert("0028,6020" ,	"Frame Numbers of Interest (FOI)");
       tagsCollection.insert("0028,6022" ,	"Frame of Interest Description");
       tagsCollection.insert("0028,6023" ,	"Frame of Interest Type");
       tagsCollection.insert("0028,6030" ,	"Mask Pointer(s)");	//Retired
       tagsCollection.insert("0028,6040" ,	"R Wave Pointer");
       tagsCollection.insert("0028,6100" ,	"Mask Subtraction Sequence");
       tagsCollection.insert("0028,6101" ,	"Mask Operation");
       tagsCollection.insert("0028,6102" ,	"Applicable Frame Range");
       tagsCollection.insert("0028,6110" ,	"Mask Frame Numbers");
       tagsCollection.insert("0028,6112" ,	"Contrast Frame Averaging");
       tagsCollection.insert("0028,6114" ,	"Mask Sub-pixel Shift");
       tagsCollection.insert("0028,6120" ,	"TID Offset");
       tagsCollection.insert("0028,6190" ,	"Mask Operation Explanation");
       tagsCollection.insert("0028,7000" ,	"Equipment Administrator Sequence");
       tagsCollection.insert("0028,7001" ,	"Number of Display Subsystems");
       tagsCollection.insert("0028,7002" ,	"Current Configuration ID");
       tagsCollection.insert("0028,7003" ,	"Display Subsystem ID");
       tagsCollection.insert("0028,7004" ,	"Display Subsystem Name");
       tagsCollection.insert("0028,7005" ,	"Display Subsystem Description");
       tagsCollection.insert("0028,7006" ,	"System Status");
       tagsCollection.insert("0028,7007" ,	"System Status Comment");
       tagsCollection.insert("0028,7008" ,	"Target Luminance Characteristics Sequence");
       tagsCollection.insert("0028,7009" ,	"Luminance Characteristics ID");
       tagsCollection.insert("0028,700A" ,	"Display Subsystem Configuration Sequence");
       tagsCollection.insert("0028,700B" ,	"Configuration ID");
       tagsCollection.insert("0028,700C" ,	"Configuration Name");
       tagsCollection.insert("0028,700D" ,	"Configuration Description");
       tagsCollection.insert("0028,700E" ,	"Referenced Target Luminance Characteristics ID");
       tagsCollection.insert("0028,700F" ,	"QA Results Sequence");
       tagsCollection.insert("0028,7010" ,	"Display Subsystem QA Results Sequence");
       tagsCollection.insert("0028,7011" ,	"Configuration QA Results Sequence");
       tagsCollection.insert("0028,7012" ,	"Measurement Equipment Sequence");
       tagsCollection.insert("0028,7013" ,	"Measurement Functions");
       tagsCollection.insert("0028,7014" ,	"Measurement Equipment Type");
       tagsCollection.insert("0028,7015" ,	"Visual Evaluation Result Sequence");
       tagsCollection.insert("0028,7016" ,	"Display Calibration Result Sequence");
       tagsCollection.insert("0028,7017" ,	"DDL Value");
       tagsCollection.insert("0028,7018" ,	"CIExy White Point");
       tagsCollection.insert("0028,7019" ,	"Display Function Type");
       tagsCollection.insert("0028,701A" ,	"Gamma Value");
       tagsCollection.insert("0028,701B" ,	"Number of Luminance Points");
       tagsCollection.insert("0028,701C" ,	"Luminance Response Sequence");
       tagsCollection.insert("0028,701D" ,	"Target Minimum Luminance");
       tagsCollection.insert("0028,701E" ,	"Target Maximum Luminance");
       tagsCollection.insert("0028,701F" ,	"Luminance Value");
       tagsCollection.insert("0028,7020" ,	"Luminance Response Description");
       tagsCollection.insert("0028,7021" ,	"White Point Flag");
       tagsCollection.insert("0028,7022" ,	"Display Device Type Code Sequence");
       tagsCollection.insert("0028,7023" ,	"Display Subsystem Sequence");
       tagsCollection.insert("0028,7024" ,	"Luminance Result Sequence");
       tagsCollection.insert("0028,7025" ,	"Ambient Light Value Source");
       tagsCollection.insert("0028,7026" ,	"Measured Characteristics");
       tagsCollection.insert("0028,7027" ,	"Luminance Uniformity Result Sequence");
       tagsCollection.insert("0028,7028" ,	"Visual Evaluation Test Sequence");
       tagsCollection.insert("0028,7029" ,	"Test Result");
       tagsCollection.insert("0028,702A" ,	"Test Result Comment");
       tagsCollection.insert("0028,702B" ,	"Test Image Validation");
       tagsCollection.insert("0028,702C" ,	"Test Pattern Code Sequence");
       tagsCollection.insert("0028,702D" ,	"Measurement Pattern Code Sequence");
       tagsCollection.insert("0028,702E" ,	"Visual Evaluation Method Code Sequence");
       tagsCollection.insert("0028,7FE0" ,	"Pixel Data Provider URL");
       tagsCollection.insert("0028,9001" ,	"Data Point Rows");
       tagsCollection.insert("0028,9002" ,	"Data Point Columns");
       tagsCollection.insert("0028,9003" ,	"Signal Domain Columns");
       tagsCollection.insert("0028,9099" ,	"Largest Monochrome Pixel Value");	//Retired
       tagsCollection.insert("0028,9108" ,	"Data Representation");
       tagsCollection.insert("0028,9110" ,	"Pixel Measures Sequence");
       tagsCollection.insert("0028,9132" ,	"Frame VOI LUT Sequence");
       tagsCollection.insert("0028,9145" ,	"Pixel Value Transformation Sequence");
       tagsCollection.insert("0028,9235" ,	"Signal Domain Rows");
       tagsCollection.insert("0028,9411" ,	"Display Filter Percentage");
       tagsCollection.insert("0028,9415" ,	"Frame Pixel Shift Sequence");
       tagsCollection.insert("0028,9416" ,	"Subtraction Item ID");
       tagsCollection.insert("0028,9422" ,	"Pixel Intensity Relationship LUT Sequence");
       tagsCollection.insert("0028,9443" ,	"Frame Pixel Data Properties Sequence");
       tagsCollection.insert("0028,9444" ,	"Geometrical Properties");
       tagsCollection.insert("0028,9445" ,	"Geometric Maximum Distortion");
       tagsCollection.insert("0028,9446" ,	"Image Processing Applied");
       tagsCollection.insert("0028,9454" ,	"Mask Selection Mode");
       tagsCollection.insert("0028,9474" ,	"LUT Function");
       tagsCollection.insert("0028,9478" ,	"Mask Visibility Percentage");
       tagsCollection.insert("0028,9501" ,	"Pixel Shift Sequence");
       tagsCollection.insert("0028,9502" ,	"Region Pixel Shift Sequence");
       tagsCollection.insert("0028,9503" ,	"Vertices of the Region");
       tagsCollection.insert("0028,9505" ,	"Multi-frame Presentation Sequence");
       tagsCollection.insert("0028,9506" ,	"Pixel Shift Frame Range");
       tagsCollection.insert("0028,9507" ,	"LUT Frame Range");
       tagsCollection.insert("0028,9520" ,	"Image to Equipment Mapping Matrix");
       tagsCollection.insert("0028,9537" ,	"Equipment Coordinate System Identification");
       tagsCollection.insert("0032,000A" ,	"Study Status ID"); //Retired
       tagsCollection.insert("0032,000C" ,	"Study Priority ID");	//Retired
       tagsCollection.insert("0032,0012" ,	"Study ID Issuer");	//Retired
       tagsCollection.insert("0032,0032" ,	"Study Verified Date");	//Retired
       tagsCollection.insert("0032,0033" ,	"Study Verified Time");	//Retired
       tagsCollection.insert("0032,0034" ,	"Study Read Date");	//Retired
       tagsCollection.insert("0032,0035" ,	"Study Read Time");	//Retired
       tagsCollection.insert("0032,1000" ,	"Scheduled Study Start Date");	//Retired
       tagsCollection.insert("0032,1001" ,	"Scheduled Study Start Time");	//Retired
       tagsCollection.insert("0032,1010" ,	"Scheduled Study Stop Date");	//Retired
       tagsCollection.insert("0032,1011" ,	"Scheduled Study Stop Time");	//Retired
       tagsCollection.insert("0032,1020" ,	"Scheduled Study Location");	//Retired
       tagsCollection.insert("0032,1021" ,	"Scheduled Study Location AE Title");	//Retired
       tagsCollection.insert("0032,1030" ,	"Reason for Study");	//Retired
       tagsCollection.insert("0032,1031" ,	"Requesting Physician Identification Sequence");
       tagsCollection.insert("0032,1032" ,	"Requesting Physician");
       tagsCollection.insert("0032,1033" ,	"Requesting Service");
       tagsCollection.insert("0032,1034" ,	"Requesting Service Code Sequence");
       tagsCollection.insert("0032,1040" ,	"Study Arrival Date");	//Retired
       tagsCollection.insert("0032,1041" ,	"Study Arrival Time");	//Retired
       tagsCollection.insert("0032,1050" ,	"Study Completion Date");	//Retired
       tagsCollection.insert("0032,1051" ,	"Study Completion Time");	//Retired
       tagsCollection.insert("0032,1055" ,	"Study Component Status ID");	//Retired
       tagsCollection.insert("0032,1060" ,	"Requested Procedure Description");
       tagsCollection.insert("0032,1064" ,	"Requested Procedure Code Sequence");
       tagsCollection.insert("0032,1070" ,	"Requested Contrast Agent");
       tagsCollection.insert("0032,4000" ,	"Study Comments");	//Retired
       tagsCollection.insert("0038,0004" ,	"Referenced Patient Alias Sequence");
       tagsCollection.insert("0038,0008" ,	"Visit Status ID");
       tagsCollection.insert("0038,0010" ,	"Admission ID");
       tagsCollection.insert("0038,0011" ,	"Issuer of Admission ID");	//Retired
       tagsCollection.insert("0038,0014" ,	"Issuer of Admission ID Sequence");
       tagsCollection.insert("0038,0016" ,	"Route of Admissions");
       tagsCollection.insert("0038,001A" ,	"Scheduled Admission Date");	//Retired
       tagsCollection.insert("0038,001B" ,	"Scheduled Admission Time");	//Retired
       tagsCollection.insert("0038,001C" ,	"Scheduled Discharge Date");	//Retired
       tagsCollection.insert("0038,001D" ,	"Scheduled Discharge Time");	//Retired
       tagsCollection.insert("0038,001E" ,	"Scheduled Patient Institution Residence");	//Retired
       tagsCollection.insert("0038,0020" ,	"Admitting Date");
       tagsCollection.insert("0038,0021" ,	"Admitting Time");
       tagsCollection.insert("0038,0030" ,	"Discharge Date");	//Retired
       tagsCollection.insert("0038,0032" ,	"Discharge Time");	//Retired
       tagsCollection.insert("0038,0040" ,	"Discharge Diagnosis Description");	//Retired
       tagsCollection.insert("0038,0044" ,	"Discharge Diagnosis Code Sequence");	//Retired
       tagsCollection.insert("0038,0050" ,	"Special Needs");
       tagsCollection.insert("0038,0060" ,	"Service Episode ID");
       tagsCollection.insert("0038,0061" ,	"Issuer of Service Episode ID");	//Retired
       tagsCollection.insert("0038,0062" ,	"Service Episode Description");
       tagsCollection.insert("0038,0064" ,	"Issuer of Service Episode ID Sequence");
       tagsCollection.insert("0038,0100" ,	"Pertinent Documents Sequence");
       tagsCollection.insert("0038,0101" ,	"Pertinent Resources Sequence");
       tagsCollection.insert("0038,0102" ,	"Resource Description");
       tagsCollection.insert("0038,0300" ,	"Current Patient Location");
       tagsCollection.insert("0038,0400" ,	"Patient's Institution Residence");
       tagsCollection.insert("0038,0500" ,	"Patient State");
       tagsCollection.insert("0038,0502" ,	"Patient Clinical Trial Participation Sequence");
       tagsCollection.insert("0038,4000" ,	"Visit Comments");
       tagsCollection.insert("003A,0004" ,	"Waveform Originality");
       tagsCollection.insert("003A,0005" ,	"Number of Waveform Channels");
       tagsCollection.insert("003A,0010" ,	"Number of Waveform Samples");
       tagsCollection.insert("003A,001A" ,	"Sampling Frequency");
       tagsCollection.insert("003A,0020" ,	"Multiplex Group Label");
       tagsCollection.insert("003A,0200" ,	"Channel Definition Sequence");
       tagsCollection.insert("003A,0202" ,	"Waveform Channel Number");
       tagsCollection.insert("003A,0203" ,	"Channel Label");
       tagsCollection.insert("003A,0205" ,	"Channel Status");
       tagsCollection.insert("003A,0208" ,	"Channel Source Sequence");
       tagsCollection.insert("003A,0209" ,	"Channel Source Modifiers Sequence");
       tagsCollection.insert("003A,020A" ,	"Source Waveform Sequence");
       tagsCollection.insert("003A,020C" ,	"Channel Derivation Description");
       tagsCollection.insert("003A,0210" ,	"Channel Sensitivity");
       tagsCollection.insert("003A,0211" ,	"Channel Sensitivity Units Sequence");
       tagsCollection.insert("003A,0212" ,	"Channel Sensitivity Correction Factor");
       tagsCollection.insert("003A,0213" ,	"Channel Baseline");
       tagsCollection.insert("003A,0214" ,	"Channel Time Skew");
       tagsCollection.insert("003A,0215" ,	"Channel Sample Skew");
       tagsCollection.insert("003A,0218" ,	"Channel Offset");
       tagsCollection.insert("003A,021A" ,	"Waveform Bits Stored");
       tagsCollection.insert("003A,0220" ,	"Filter Low Frequency");
       tagsCollection.insert("003A,0221" ,	"Filter High Frequency");
       tagsCollection.insert("003A,0222" ,	"Notch Filter Frequency");
       tagsCollection.insert("003A,0223" ,	"Notch Filter Bandwidth");
       tagsCollection.insert("003A,0230" ,	"Waveform Data Display Scale");
       tagsCollection.insert("003A,0231" ,	"Waveform Display Background CIELab Value");
       tagsCollection.insert("003A,0240" ,	"Waveform Presentation Group Sequence");
       tagsCollection.insert("003A,0241" ,	"Presentation Group Number");
       tagsCollection.insert("003A,0242" ,	"Channel Display Sequence");
       tagsCollection.insert("003A,0244" ,	"Channel Recommended Display CIELab Value");
       tagsCollection.insert("003A,0245" ,	"Channel Position");
       tagsCollection.insert("003A,0246" ,	"Display Shading Flag");
       tagsCollection.insert("003A,0247" ,	"Fractional Channel Display Scale");
       tagsCollection.insert("003A,0248" ,	"Absolute Channel Display Scale");
       tagsCollection.insert("003A,0300" ,	"Multiplexed Audio Channels Description Code Sequence");
       tagsCollection.insert("003A,0301" ,	"Channel Identification Code");
       tagsCollection.insert("003A,0302" ,	"Channel Mode");
       tagsCollection.insert("0040,0001" ,	"Scheduled Station AE Title");
       tagsCollection.insert("0040,0002" ,	"Scheduled Procedure Step Start Date");
       tagsCollection.insert("0040,0003" ,	"Scheduled Procedure Step Start Time");
       tagsCollection.insert("0040,0004" ,	"Scheduled Procedure Step End Date");
       tagsCollection.insert("0040,0005" ,	"Scheduled Procedure Step End Time");
       tagsCollection.insert("0040,0006" ,	"Scheduled Performing Physician's Name");
       tagsCollection.insert("0040,0007" ,	"Scheduled Procedure Step Description");
       tagsCollection.insert("0040,0008" ,	"Scheduled Protocol Code Sequence");
       tagsCollection.insert("0040,0009" ,	"Scheduled Procedure Step ID");
       tagsCollection.insert("0040,000A" ,	"Stage Code Sequence");
       tagsCollection.insert("0040,000B" ,	"Scheduled Performing Physician Identification Sequence");
       tagsCollection.insert("0040,0010" ,	"Scheduled Station Name");
       tagsCollection.insert("0040,0011" ,	"Scheduled Procedure Step Location");
       tagsCollection.insert("0040,0012" ,	"Pre-Medication");
       tagsCollection.insert("0040,0020" ,	"Scheduled Procedure Step Status");
       tagsCollection.insert("0040,0026" ,	"Order Placer Identifier Sequence");
       tagsCollection.insert("0040,0027" ,	"Order Filler Identifier Sequence");
       tagsCollection.insert("0040,0031" ,	"Local Namespace Entity ID");
       tagsCollection.insert("0040,0032" ,	"Universal Entity ID");
       tagsCollection.insert("0040,0033" ,	"Universal Entity ID Type");
       tagsCollection.insert("0040,0035" ,	"Identifier Type Code");
       tagsCollection.insert("0040,0036" ,	"Assigning Facility Sequence");
       tagsCollection.insert("0040,0039" ,	"Assigning Jurisdiction Code Sequence");
       tagsCollection.insert("0040,003A" ,	"Assigning Agency or Department Code Sequence");
       tagsCollection.insert("0040,0100" ,	"Scheduled Procedure Step Sequence");
       tagsCollection.insert("0040,0220" ,	"Referenced Non-Image Composite SOP Instance Sequence");
       tagsCollection.insert("0040,0241" ,	"Performed Station AE Title");
       tagsCollection.insert("0040,0242" ,	"Performed Station Name");
       tagsCollection.insert("0040,0243" ,	"Performed Location");
       tagsCollection.insert("0040,0244" ,	"Performed Procedure Step Start Date");
       tagsCollection.insert("0040,0245" ,	"Performed Procedure Step Start Time");
       tagsCollection.insert("0040,0250" ,	"Performed Procedure Step End Date");
       tagsCollection.insert("0040,0251" ,	"Performed Procedure Step End Time");
       tagsCollection.insert("0040,0252" ,	"Performed Procedure Step Status");
       tagsCollection.insert("0040,0253" ,	"Performed Procedure Step ID");
       tagsCollection.insert("0040,0254" ,	"Performed Procedure Step Description");
       tagsCollection.insert("0040,0255" ,	"Performed Procedure Type Description");
       tagsCollection.insert("0040,0260" ,	"Performed Protocol Code Sequence");
       tagsCollection.insert("0040,0261" ,	"Performed Protocol Type");
       tagsCollection.insert("0040,0270" ,	"Scheduled Step Attributes Sequence");
       tagsCollection.insert("0040,0275" ,	"Request Attributes Sequence");
       tagsCollection.insert("0040,0280" ,	"Comments on the Performed Procedure Step");
       tagsCollection.insert("0040,0281" ,	"Performed Procedure Step Discontinuation Reason Code Sequence");
       tagsCollection.insert("0040,0293" ,	"Quantity Sequence");
       tagsCollection.insert("0040,0294" ,	"Quantity");
       tagsCollection.insert("0040,0295" ,	"Measuring Units Sequence");
       tagsCollection.insert("0040,0296" ,	"Billing Item Sequence");
       tagsCollection.insert("0040,0300" ,	"Total Time of Fluoroscopy");
       tagsCollection.insert("0040,0301" ,	"Total Number of Exposures");
       tagsCollection.insert("0040,0302" ,	"Entrance Dose");
       tagsCollection.insert("0040,0303" ,	"Exposed Area");
       tagsCollection.insert("0040,0306" ,	"Distance Source to Entrance");
       tagsCollection.insert("0040,0307" ,	"Distance Source to Support");	//Retired
       tagsCollection.insert("0040,030E" ,	"Exposure Dose Sequence");
       tagsCollection.insert("0040,0310" ,	"Comments on Radiation Dose");
       tagsCollection.insert("0040,0312" ,	"X-Ray Output");
       tagsCollection.insert("0040,0314" ,	"Half Value Layer");
       tagsCollection.insert("0040,0316" ,	"Organ Dose");
       tagsCollection.insert("0040,0318" ,	"Organ Exposed");
       tagsCollection.insert("0040,0320" ,	"Billing Procedure Step Sequence");
       tagsCollection.insert("0040,0321" ,	"Film Consumption Sequence");
       tagsCollection.insert("0040,0324" ,	"Billing Supplies and Devices Sequence");
       tagsCollection.insert("0040,0330" ,	"Referenced Procedure Step Sequence");	//Retired
       tagsCollection.insert("0040,0340" ,	"Performed Series Sequence");
       tagsCollection.insert("0040,0400" ,	"Comments on the Scheduled Procedure Step");
       tagsCollection.insert("0040,0440" ,	"Protocol Context Sequence");
       tagsCollection.insert("0040,0441" ,	"Content Item Modifier Sequence");
       tagsCollection.insert("0040,0500" ,	"Scheduled Specimen Sequence");
       tagsCollection.insert("0040,050A" ,	"Specimen Accession Number");	//Retired
       tagsCollection.insert("0040,0512" ,	"Container Identifier");
       tagsCollection.insert("0040,0513" ,	"Issuer of the Container Identifier Sequence");
       tagsCollection.insert("0040,0515" ,	"Alternate Container Identifier Sequence");
       tagsCollection.insert("0040,0518" ,	"Container Type Code Sequence");
       tagsCollection.insert("0040,051A" ,	"Container Description");
       tagsCollection.insert("0040,0520" ,	"Container Component Sequence");
       tagsCollection.insert("0040,0550" ,	"Specimen Sequence"); //Retired
       tagsCollection.insert("0040,0551" ,	"Specimen Identifier");
       tagsCollection.insert("0040,0552" ,	"Specimen Description Sequence"); //(Trial)	Retired
       tagsCollection.insert("0040,0553" ,	"Specimen Description"); //(Trial)	Retired
       tagsCollection.insert("0040,0554" ,	"Specimen UID");
       tagsCollection.insert("0040,0555" ,	"Acquisition Context Sequence");
       tagsCollection.insert("0040,0556" ,	"Acquisition Context Description");
       tagsCollection.insert("0040,059A" ,	"Specimen Type Code Sequence");
       tagsCollection.insert("0040,0560" ,	"Specimen Description Sequence");
       tagsCollection.insert("0040,0562" ,	"Issuer of the Specimen Identifier Sequence");
       tagsCollection.insert("0040,0600" ,	"Specimen Short Description");
       tagsCollection.insert("0040,0602" ,	"Specimen Detailed Description");
       tagsCollection.insert("0040,0610" ,	"Specimen Preparation Sequence");
       tagsCollection.insert("0040,0612" ,	"Specimen Preparation Step Content Item Sequence");
       tagsCollection.insert("0040,0620" ,	"Specimen Localization Content Item Sequence");
       tagsCollection.insert("0040,06FA" ,	"Slide Identifier	Retired");
       tagsCollection.insert("0040,071A" ,	"Image Center Point Coordinates Sequence");
       tagsCollection.insert("0040,072A" ,	"X Offset in Slide Coordinate System");
       tagsCollection.insert("0040,073A" ,	"Y Offset in Slide Coordinate System");
       tagsCollection.insert("0040,074A" ,	"Z Offset in Slide Coordinate System");
       tagsCollection.insert("0040,08D8" ,	"Pixel Spacing Sequence	Retired");
       tagsCollection.insert("0040,08DA" ,	"Coordinate System Axis Code Sequence");	//Retired
       tagsCollection.insert("0040,08EA" ,	"Measurement Units Code Sequence");
       tagsCollection.insert("0040,09F8" ,	"Vital Stain Code Sequence"); //(Trial)	Retired
       tagsCollection.insert("0040,1001" ,	"Requested Procedure ID");
       tagsCollection.insert("0040,1002" ,	"Reason for the Requested Procedure");
       tagsCollection.insert("0040,1003" ,	"Requested Procedure Priority");
       tagsCollection.insert("0040,1004" ,	"Patient Transport Arrangements");
       tagsCollection.insert("0040,1005" ,	"Requested Procedure Location");
       tagsCollection.insert("0040,1006" ,	"Placer Order Number / Procedure");	//Retired
       tagsCollection.insert("0040,1007" ,	"Filler Order Number / Procedure");	//Retired
       tagsCollection.insert("0040,1008" ,	"Confidentiality Code");
       tagsCollection.insert("0040,1009" ,	"Reporting Priority");
       tagsCollection.insert("0040,100A" ,	"Reason for Requested Procedure Code Sequence");
       tagsCollection.insert("0040,1010" ,	"Names of Intended Recipients of Results");
       tagsCollection.insert("0040,1011" ,	"Intended Recipients of Results Identification Sequence");
       tagsCollection.insert("0040,1012" ,	"Reason For Performed Procedure Code Sequence");
       tagsCollection.insert("0040,1060" ,	"Requested Procedure Description"); //(Trial)	Retired
       tagsCollection.insert("0040,1101" ,	"Person Identification Code Sequence");
       tagsCollection.insert("0040,1102" ,	"Person's Address");
       tagsCollection.insert("0040,1103" ,	"Person's Telephone Numbers");
       tagsCollection.insert("0040,1104" ,	"Person's Telecom Information");
       tagsCollection.insert("0040,1400" ,	"Requested Procedure Comments");
       tagsCollection.insert("0040,2001" ,	"Reason for the Imaging Service Request");	//Retired
       tagsCollection.insert("0040,2004" ,	"Issue Date of Imaging Service Request");
       tagsCollection.insert("0040,2005" ,	"Issue Time of Imaging Service Request");
       tagsCollection.insert("0040,2006" ,	"Placer Order Number / Imaging Service Request"); //(Retired)	Retired
       tagsCollection.insert("0040,2007" ,	"Filler Order Number / Imaging Service Request"); //(Retired)	Retired
       tagsCollection.insert("0040,2008" ,	"Order Entered By");
       tagsCollection.insert("0040,2009" ,	"Order Enterer's Location");
       tagsCollection.insert("0040,2010" ,	"Order Callback Phone Number");
       tagsCollection.insert("0040,2011" ,	"Order Callback Telecom Information");
       tagsCollection.insert("0040,2016" ,	"Placer Order Number / Imaging Service Request");
       tagsCollection.insert("0040,2017" ,	"Filler Order Number / Imaging Service Request");
       tagsCollection.insert("0040,2400" ,	"Imaging Service Request Comments");
       tagsCollection.insert("0040,3001" ,	"Confidentiality Constraint on Patient Data Description");
       tagsCollection.insert("0040,4001" ,	"General Purpose Scheduled Procedure Step Status"); //Retired
       tagsCollection.insert("0040,4002" ,	"General Purpose Performed Procedure Step Status");	//Retired
       tagsCollection.insert("0040,4003" ,	"General Purpose Scheduled Procedure Step Priority");	//Retired
       tagsCollection.insert("0040,4004" ,	"Scheduled Processing Applications Code Sequence");	//Retired
       tagsCollection.insert("0040,4005" ,	"Scheduled Procedure Step Start DateTime");
       tagsCollection.insert("0040,4006" ,	"Multiple Copies Flag");	//Retired
       tagsCollection.insert("0040,4007" ,	"Performed Processing Applications Code Sequence");
       tagsCollection.insert("0040,4009" ,	"Human Performer Code Sequence");
       tagsCollection.insert("0040,4010" ,	"Scheduled Procedure Step Modification DateTime");
       tagsCollection.insert("0040,4011" ,	"Expected Completion DateTime");
       tagsCollection.insert("0040,4015" ,	"Resulting General Purpose Performed Procedure Steps Sequence");	//Retired
       tagsCollection.insert("0040,4016" ,	"Referenced General Purpose Scheduled Procedure Step Sequence");	//Retired
       tagsCollection.insert("0040,4018" ,	"Scheduled Workitem Code Sequence");
       tagsCollection.insert("0040,4019" ,	"Performed Workitem Code Sequence");
       tagsCollection.insert("0040,4020" ,	"Input Availability Flag");
       tagsCollection.insert("0040,4021" ,	"Input Information Sequence");
       tagsCollection.insert("0040,4022" ,	"Relevant Information Sequence");	//Retired
       tagsCollection.insert("0040,4023" ,	"Referenced General Purpose Scheduled Procedure Step Transaction UID");	//Retired
       tagsCollection.insert("0040,4025" ,	"Scheduled Station Name Code Sequence");
       tagsCollection.insert("0040,4026" ,	"Scheduled Station Class Code Sequence");
       tagsCollection.insert("0040,4027" ,	"Scheduled Station Geographic Location Code Sequence");
       tagsCollection.insert("0040,4028" ,	"Performed Station Name Code Sequence");
       tagsCollection.insert("0040,4029" ,	"Performed Station Class Code Sequence");
       tagsCollection.insert("0040,4030" ,	"Performed Station Geographic Location Code Sequence");
       tagsCollection.insert("0040,4031" ,	"Requested Subsequent Workitem Code Sequence");	//Retired
       tagsCollection.insert("0040,4032" ,	"Non-DICOM Output Code Sequence");	//Retired
       tagsCollection.insert("0040,4033" ,	"Output Information Sequence");
       tagsCollection.insert("0040,4034" ,	"Scheduled Human Performers Sequence");
       tagsCollection.insert("0040,4035" ,	"Actual Human Performers Sequence");
       tagsCollection.insert("0040,4036" ,	"Human Performer's Organization");
       tagsCollection.insert("0040,4037" ,	"Human Performer's Name");
       tagsCollection.insert("0040,4040" ,	"Raw Data Handling");
       tagsCollection.insert("0040,4041" ,	"Input Readiness State");
       tagsCollection.insert("0040,4050" ,	"Performed Procedure Step Start DateTime");
       tagsCollection.insert("0040,4051" ,	"Performed Procedure Step End DateTime");
       tagsCollection.insert("0040,4052" ,	"Procedure Step Cancellation DateTime");
       tagsCollection.insert("0040,4070" ,	"Output Destination Sequence");
       tagsCollection.insert("0040,4071" ,	"DICOM Storage Sequence");
       tagsCollection.insert("0040,4072" ,	"STOW-RS Storage Sequence");
       tagsCollection.insert("0040,4073" ,	"Storage URL");
       tagsCollection.insert("0040,4074" ,	"XDS Storage Sequence");
       tagsCollection.insert("0040,8302" ,	"Entrance Dose in mGy");
       tagsCollection.insert("0040,9092" ,	"Parametric Map Frame Type Sequence");
       tagsCollection.insert("0040,9094" ,	"Referenced Image Real World Value Mapping Sequence");
       tagsCollection.insert("0040,9096" ,	"Real World Value Mapping Sequence");
       tagsCollection.insert("0040,9098" ,	"Pixel Value Mapping Code Sequence");
       tagsCollection.insert("0040,9210" ,	"LUT Label");
       tagsCollection.insert("0040,9211" ,   "Real World Value Last Value Mapped");
       tagsCollection.insert("0040,9212" ,	"Real World Value LUT Data");
       tagsCollection.insert("0040,9213" ,	"Double Float Real World Value Last Value Mapped");
       tagsCollection.insert("0040,9214" ,	"Double Float Real World Value First Value Mapped");
       tagsCollection.insert("0040,9216" , 	"Real World Value First Value Mapped");
       tagsCollection.insert("0040,9220" ,	"Quantity Definition Sequence");
       tagsCollection.insert("0040,9224" ,	"Real World Value Intercept");
       tagsCollection.insert("0040,9225" ,	"Real World Value Slope");
       tagsCollection.insert("0040,A007" ,	"Findings Flag (Trial)");	//Retired
       tagsCollection.insert("0040,A010" ,	"Relationship Type");
       tagsCollection.insert("0040,A020" ,	"Findings Sequence"); //(Trial)	Retired
       tagsCollection.insert("0040,A021" ,	"Findings Group UID"); //(Trial)	Retired
       tagsCollection.insert("0040,A022" ,	"Referenced Findings Group UID"); //(Trial)	Retired
       tagsCollection.insert("0040,A023" ,	"Findings Group Recording Date"); //(Trial)	Retired
       tagsCollection.insert("0040,A024" ,	"Findings Group Recording Time"); //(Trial)	Retired
       tagsCollection.insert("0040,A026" ,	"Findings Source Category Code Sequence"); //(Trial)	Retired
       tagsCollection.insert("0040,A027" ,	"Verifying Organization");
       tagsCollection.insert("0040,A028" ,	"Documenting Organization Identifier Code Sequence"); //(Trial)	Retired
       tagsCollection.insert("0040,A030" ,	"Verification DateTime");
       tagsCollection.insert("0040,A032" ,	"Observation DateTime");
       tagsCollection.insert("0040,A040" ,	"Value Type");
       tagsCollection.insert("0040,A043" ,	"Concept Name Code Sequence");
       tagsCollection.insert("0040,A047" ,	"Measurement Precision Description"); //(Trial)	Retired
       tagsCollection.insert("0040,A050" ,	"Continuity Of Content");
       tagsCollection.insert("0040,A057" ,	"Urgency or Priority Alerts"); //(Trial)	Retired
       tagsCollection.insert("0040,A060" ,	"Sequencing Indicator"); //(Trial)	Retired
       tagsCollection.insert("0040,A066" ,	"Document Identifier Code Sequence"); //(Trial)	Retired
       tagsCollection.insert("0040,A067" ,	"Document Author"); //(Trial)	Retired
       tagsCollection.insert("0040,A068" ,	"Document Author Identifier Code Sequence"); //(Trial)	Retired
       tagsCollection.insert("0040,A070" ,	"Identifier Code Sequence"); //(Trial)	Retired
       tagsCollection.insert("0040,A073" ,	"Verifying Observer Sequence");
       tagsCollection.insert("0040,A074" ,	"Object Binary Identifier"); //(Trial)	Retired
       tagsCollection.insert("0040,A075" ,	"Verifying Observer Name");
       tagsCollection.insert("0040,A076" ,	"Documenting Observer Identifier Code Sequence");// (Trial)	Retired
       tagsCollection.insert("0040,A078" ,	"Author Observer Sequence");
       tagsCollection.insert("0040,A07A" ,	"Participant Sequence");
       tagsCollection.insert("0040,A07C" ,	"Custodial Organization Sequence");
       tagsCollection.insert("0040,A080" ,	"Participation Type");
       tagsCollection.insert("0040,A082" ,	"Participation DateTime");
       tagsCollection.insert("0040,A084" ,	"Observer Type");
       tagsCollection.insert("0040,A085" ,	"Procedure Identifier Code Sequence"); //(Trial)	Retired
       tagsCollection.insert("0040,A088" ,	"Verifying Observer Identification Code Sequence");
       tagsCollection.insert("0040,A089" ,	"Object Directory Binary Identifier"); //(Trial)	Retired
       tagsCollection.insert("0040,A090" ,	"Equivalent CDA Document Sequence");	//Retired
       tagsCollection.insert("0040,A0B0" ,	"Referenced Waveform Channels");
       tagsCollection.insert("0040,A110" ,	"Date of Document or Verbal Transaction"); //(Trial)	Retired
       tagsCollection.insert("0040,A112" ,	"Time of Document Creation or Verbal Transaction"); //(Trial)	Retired
       tagsCollection.insert("0040,A120" ,	"DateTime");
       tagsCollection.insert("0040,A121" ,	"Date");
       tagsCollection.insert("0040,A122" ,	"Time");
       tagsCollection.insert("0040,A123" ,	"Person Name");
       tagsCollection.insert("0040,A124" ,	"UID");
       tagsCollection.insert("0040,A125" ,	"Report Status ID"); //(Trial)	Retired
       tagsCollection.insert("0040,A130" ,	"Temporal Range Type");
       tagsCollection.insert("0040,A132" ,	"Referenced Sample Positions");
       tagsCollection.insert("0040,A136" ,	"Referenced Frame Numbers");
       tagsCollection.insert("0040,A138" ,	"Referenced Time Offsets");
       tagsCollection.insert("0040,A13A" ,	"Referenced DateTime");
       tagsCollection.insert("0040,A160" ,	"Text Value");
       tagsCollection.insert("0040,A161" ,	"Floating Point Value");
       tagsCollection.insert("0040,A162" ,	"Rational Numerator Value");
       tagsCollection.insert("0040,A163" ,	"Rational Denominator Value");
       tagsCollection.insert("0040,A167" ,	"Observation Category Code Sequence"); //(Trial)	Retired
       tagsCollection.insert("0040,A168" ,	"Concept Code Sequence");
       tagsCollection.insert("0040,A16A" ,	"Bibliographic Citation"); //(Trial)	Retired
       tagsCollection.insert("0040,A170" ,	"Purpose of Reference Code Sequence";
       tagsCollection.insert("0040,A171" ,	"Observation UID");
       tagsCollection.insert("0040,A172" ,	"Referenced Observation UID"); //(Trial)	Retired
       tagsCollection.insert("0040,A173" ,	"Referenced Observation Class"); //(Trial)	Retired
       tagsCollection.insert("0040,A174" ,	"Referenced Object Observation Class"); //(Trial)	Retired
       tagsCollection.insert("0040,A180" ,	"Annotation Group Number");
       tagsCollection.insert("0040,A192" ,	"Observation Date"); //(Trial)	Retired
       tagsCollection.insert("0040,A193" ,	"Observation Time"); //(Trial)	Retired
       tagsCollection.insert("0040,A194" ,	"Measurement Automation"); //(Trial)	Retired
       tagsCollection.insert("0040,A195" ,	"Modifier Code Sequence");
       tagsCollection.insert("0040,A224" ,	"Identification Description"); //(Trial)	Retired
       tagsCollection.insert("0040,A290" ,	"Coordinates Set Geometric Type"); //(Trial)	Retired
       tagsCollection.insert("0040,A296" ,	"Algorithm Code Sequence"); //(Trial)	Retired
       tagsCollection.insert("0040,A297" ,	"Algorithm Description"); //(Trial)	Retired
       tagsCollection.insert("0040,A29A" ,	"Pixel Coordinates Set"); //(Trial)	Retired
       tagsCollection.insert("0040,A300" ,	"Measured Value Sequence");
       tagsCollection.insert("0040,A301" ,	"Numeric Value Qualifier Code Sequence");
       tagsCollection.insert("0040,A307" ,	"Current Observer"); //(Trial)	Retired
       tagsCollection.insert("0040,A30A" ,	"Numeric Value");
       tagsCollection.insert("0040,A313" ,	"Referenced Accession Sequence"); //(Trial)	Retired
       tagsCollection.insert("0040,A33A" ,	"Report Status Comment"); //(Trial)	Retired
       tagsCollection.insert("0040,A340" ,	"Procedure Context Sequence"); //(Trial)	Retired
       tagsCollection.insert("0040,A352" ,	"Verbal Source"); //(Trial)	Retired
       tagsCollection.insert("0040,A353" ,	"Address"); //(Trial)	Retired
       tagsCollection.insert("0040,A354" ,	"Telephone Number"); //(Trial)	Retired
       tagsCollection.insert("0040,A358" ,	"Verbal Source Identifier Code Sequence"); //(Trial)	Retired
       tagsCollection.insert("0040,A360" ,	"Predecessor Documents Sequence");
       tagsCollection.insert("0040,A370" ,	"Referenced Request Sequence");
       tagsCollection.insert("0040,A372" ,	"Performed Procedure Code Sequence");
       tagsCollection.insert("0040,A375" ,	"Current Requested Procedure Evidence Sequence");
       tagsCollection.insert("0040,A380" ,	"Report Detail Sequence"); //(Trial)	Retired
       tagsCollection.insert("0040,A385" ,	"Pertinent Other Evidence Sequence");
       tagsCollection.insert("0040,A390" ,	"HL7 Structured Document Reference Sequence");
       tagsCollection.insert("0040,A402" ,	"Observation Subject UID");//(Trial)	Retired
       tagsCollection.insert("0040,A403" ,	"Observation Subject Class" //(Trial)	Retired
       tagsCollection.insert("0040,A404" ,	"Observation Subject Type Code Sequence" //(Trial)	Retired
       tagsCollection.insert("0040,A491" ,	"Completion Flag");
       tagsCollection.insert("0040,A492" ,	"Completion Flag Description");
       tagsCollection.insert("0040,A493" ,	"Verification Flag");
       tagsCollection.insert("0040,A494" ,	"Archive Requested");
       tagsCollection.insert("0040,A496" ,	"Preliminary Flag");
       tagsCollection.insert("0040,A504" ,	"Content Template Sequence");
       tagsCollection.insert("0040,A525" ,	"Identical Documents Sequence");
       tagsCollection.insert("0040,A600" ,	"Observation Subject Context Flag");//(Trial)	Retired
       tagsCollection.insert("0040,A601" ,	"Observer Context Flag");//(Trial)	Retired
       tagsCollection.insert("0040,A603" ,	"Procedure Context Flag");//(Trial)	Retired
       tagsCollection.insert("0040,A730" ,	"Content Sequence");
       tagsCollection.insert("0040,A731" ,	"Relationship Sequence"); //(Trial)	Retired
       tagsCollection.insert("0040,A732" ,	"Relationship Type Code Sequence" //(Trial)	Retired
       tagsCollection.insert("0040,A744" ,	"Language Code Sequence");// (Trial)	Retired
       tagsCollection.insert("0040,A992" ,	"Uniform Resource Locator"); //(Trial)	Retired
       tagsCollection.insert("0040,B020" ,	"Waveform Annotation Sequence");
       tagsCollection.insert("0040,DB00" ,	"Template Identifier");
       tagsCollection.insert("0040,DB06" ,	"Template Version");	//Retired
       tagsCollection.insert("0040,DB07" ,	"Template Local Version");	//Retired
       tagsCollection.insert("0040,DB0B" ,	"Template Extension Flag");	//Retired
       tagsCollection.insert("0040,DB0C" ,	"Template Extension Organization UID");	//Retired
       tagsCollection.insert("0040,DB0D" ,	"Template Extension Creator UID");	//Retired
       tagsCollection.insert("0040,DB73" ,	"Referenced Content Item Identifier");
       tagsCollection.insert("0040,E001" ,	"HL7 Instance Identifier");
       tagsCollection.insert("0040,E004" ,	"HL7 Document Effective Time");
       tagsCollection.insert("0040,E006" ,	"HL7 Document Type Code Sequence");
       tagsCollection.insert("0040,E008" ,	"Document Class Code Sequence");
       tagsCollection.insert("0040,E010" ,	"Retrieve URI");
       tagsCollection.insert("0040,E011" ,	"Retrieve Location UID");
       tagsCollection.insert("0040,E020" ,	"Type of Instances");
       tagsCollection.insert("0040,E021" ,	"DICOM Retrieval Sequence");
       tagsCollection.insert("0040,E022" ,	"DICOM Media Retrieval Sequence");
       tagsCollection.insert("0040,E023" ,	"WADO Retrieval Sequence");
       tagsCollection.insert("0040,E024" ,	"XDS Retrieval Sequence");
       tagsCollection.insert("0040,E025" ,	"WADO-RS Retrieval Sequence");
       tagsCollection.insert("0040,E030" ,	"Repository Unique ID");
       tagsCollection.insert("0040,E031" ,	"Home Community ID");
       tagsCollection.insert("0042,0010" ,	"Document Title");
       tagsCollection.insert("0042,0011" ,	"Encapsulated Document");
       tagsCollection.insert("0042,0012" ,	"MIME Type of Encapsulated Document");
       tagsCollection.insert("0042,0013" ,	"Source Instance Sequence");
       tagsCollection.insert("0042,0014" ,	"List of MIME Types");
       tagsCollection.insert("0044,0001" ,	"Product Package Identifier");
       tagsCollection.insert("0044,0002" ,	"Substance Administration Approval");
       tagsCollection.insert("0044,0003" ,	"Approval Status Further Description");
       tagsCollection.insert("0044,0004" ,	"Approval Status DateTime");
       tagsCollection.insert("0044,0007" ,	"Product Type Code Sequence");
       tagsCollection.insert("0044,0008" ,	"Product Name");
       tagsCollection.insert("0044,0009" ,	"Product Description");
       tagsCollection.insert("0044,000A" ,	"Product Lot Identifier");
       tagsCollection.insert("0044,000B" ,	"Product Expiration DateTime");
       tagsCollection.insert("0044,0010" ,	"Substance Administration DateTime");
       tagsCollection.insert("0044,0011" ,	"Substance Administration Notes");
       tagsCollection.insert("0044,0012" ,	"Substance Administration Device ID");
       tagsCollection.insert("0044,0013" ,	"Product Parameter Sequence");
       tagsCollection.insert("0044,0019" ,	"Substance Administration Parameter Sequence");
       tagsCollection.insert("0046,0012" ,	"Lens Description");
       tagsCollection.insert("0046,0014" ,	"Right Lens Sequence");
       tagsCollection.insert("0046,0015" ,	"Left Lens Sequence");
       tagsCollection.insert("0046,0016" ,	"Unspecified Laterality Lens Sequence");
       tagsCollection.insert("0046,0018" ,	"Cylinder Sequence");
       tagsCollection.insert("0046,0028" ,	"Prism Sequence");
       tagsCollection.insert("0046,0030" ,	"Horizontal Prism Power");
       tagsCollection.insert("0046,0032" ,	"Horizontal Prism Base");
       tagsCollection.insert("0046,0034" ,	"Vertical Prism Power");
       tagsCollection.insert("0046,0036" ,	"Vertical Prism Base");
       tagsCollection.insert("0046,0038" ,	"Lens Segment Type");
       tagsCollection.insert("0046,0040" ,	"Optical Transmittance");
       tagsCollection.insert("0046,0042" ,	"Channel Width");
       tagsCollection.insert("0046,0044" ,	"Pupil Size");
       tagsCollection.insert("0046,0046" ,	"Corneal Size");
       tagsCollection.insert("0046,0050" ,	"Autorefraction Right Eye Sequence");
       tagsCollection.insert("0046,0052" ,	"Autorefraction Left Eye Sequence");
       tagsCollection.insert("0046,0060" ,	"Distance Pupillary Distance");
       tagsCollection.insert("0046,0062" ,	"Near Pupillary Distance");
       tagsCollection.insert("0046,0063" ,	"Intermediate Pupillary Distance");
       tagsCollection.insert("0046,0064" ,	"Other Pupillary Distance");
       tagsCollection.insert("0046,0070" ,	"Keratometry Right Eye Sequence");
       tagsCollection.insert("0046,0071" ,	"Keratometry Left Eye Sequence");
       tagsCollection.insert("0046,0074" ,	"Steep Keratometric Axis Sequence");
       tagsCollection.insert("0046,0075" ,	"Radius of Curvature");
       tagsCollection.insert("0046,0076" ,	"Keratometric Power");
       tagsCollection.insert("0046,0077" ,	"Keratometric Axis");
       tagsCollection.insert("0046,0080" ,	"Flat Keratometric Axis Sequence");
       tagsCollection.insert("0046,0092" ,	"Background Color");
       tagsCollection.insert("0046,0094" ,	"Optotype");
       tagsCollection.insert("0046,0095" ,	"Optotype Presentation");
       tagsCollection.insert("0046,0097" ,	"Subjective Refraction Right Eye Sequence");
       tagsCollection.insert("0046,0098" ,	"Subjective Refraction Left Eye Sequence");
       tagsCollection.insert("0046,0100" ,	"Add Near Sequence");
       tagsCollection.insert("0046,0101" ,	"Add Intermediate Sequence");
       tagsCollection.insert("0046,0102" ,	"Add Other Sequence");
       tagsCollection.insert("0046,0104" ,	"Add Power");
       tagsCollection.insert("0046,0106" ,	"Viewing Distance");
       tagsCollection.insert("0046,0121" ,	"Visual Acuity Type Code Sequence");
       tagsCollection.insert("0046,0122" ,	"Visual Acuity Right Eye Sequence");
       tagsCollection.insert("0046,0123" ,	"Visual Acuity Left Eye Sequence");
       tagsCollection.insert("0046,0124" ,	"Visual Acuity Both Eyes Open Sequence");
       tagsCollection.insert("0046,0125" ,	"Viewing Distance Type");
       tagsCollection.insert("0046,0135" ,	"Visual Acuity Modifiers");
       tagsCollection.insert("0046,0137" ,	"Decimal Visual Acuity");
       tagsCollection.insert("0046,0139" ,	"Optotype Detailed Definition");
       tagsCollection.insert("0046,0145" ,	"Referenced Refractive Measurements Sequence");
       tagsCollection.insert("0046,0146" ,	"Sphere Power");
       tagsCollection.insert("0046,0147" ,	"Cylinder Power");
       tagsCollection.insert("0046,0201" ,	"Corneal Topography Surface");
       tagsCollection.insert("0046,0202" ,	"Corneal Vertex Location");
       tagsCollection.insert("0046,0203" ,	"Pupil Centroid X-Coordinate");
       tagsCollection.insert("0046,0204" ,	"Pupil Centroid Y-Coordinate");
       tagsCollection.insert("0046,0205" ,	"Equivalent Pupil Radius");
       tagsCollection.insert("0046,0207" ,	"Corneal Topography Map Type Code Sequence");
       tagsCollection.insert("0046,0208" ,	"Vertices of the Outline of Pupil");
       tagsCollection.insert("0046,0210" ,	"Corneal Topography Mapping Normals Sequence");
       tagsCollection.insert("0046,0211" ,	"Maximum Corneal Curvature Sequence");
       tagsCollection.insert("0046,0212" ,	"Maximum Corneal Curvature");
       tagsCollection.insert("0046,0213" ,	"Maximum Corneal Curvature Location");
       tagsCollection.insert("0046,0215" ,	"Minimum Keratometric Sequence");
       tagsCollection.insert("0046,0218" ,	"Simulated Keratometric Cylinder Sequence");
       tagsCollection.insert("0046,0220" ,	"Average Corneal Power");
       tagsCollection.insert("0046,0224" ,	"Corneal I-S Value");
       tagsCollection.insert("0046,0227" ,	"Analyzed Area");
       tagsCollection.insert("0046,0230" ,	"Surface Regularity Index");
       tagsCollection.insert("0046,0232" ,	"Surface Asymmetry Index");
       tagsCollection.insert("0046,0234" ,	"Corneal Eccentricity Index");
       tagsCollection.insert("0046,0236" ,	"Keratoconus Prediction Index");
       tagsCollection.insert("0046,0238" ,	"Decimal Potential Visual Acuity");
       tagsCollection.insert("0046,0242" ,	"Corneal Topography Map Quality Evaluation");
       tagsCollection.insert("0046,0244" ,	"Source Image Corneal Processed Data Sequence");
       tagsCollection.insert("0046,0247" ,	"Corneal Point Location");
       tagsCollection.insert("0046,0248" ,	"Corneal Point Estimated");
       tagsCollection.insert("0046,0249" ,	"Axial Power");
       tagsCollection.insert("0046,0250" ,	"Tangential Power");
       tagsCollection.insert("0046,0251" ,	"Refractive Power");
       tagsCollection.insert("0046,0252" ,	"Relative Elevation");
       tagsCollection.insert("0046,0253" ,	"Corneal Wavefront");
       tagsCollection.insert("0048,0001" ,	"Imaged Volume Width");
       tagsCollection.insert("0048,0002" ,	"Imaged Volume Height");
       tagsCollection.insert("0048,0003" ,	"Imaged Volume Depth");
       tagsCollection.insert("0048,0006" ,	"Total Pixel Matrix Columns");
       tagsCollection.insert("0048,0007" ,	"Total Pixel Matrix Rows");
       tagsCollection.insert("0048,0008" ,	"Total Pixel Matrix Origin Sequence");
       tagsCollection.insert("0048,0010" ,	"Specimen Label in Image");
       tagsCollection.insert("0048,0011" ,	"Focus Method");
       tagsCollection.insert("0048,0012" ,	"Extended Depth of Field");
       tagsCollection.insert("0048,0013" ,	"Number of Focal Planes");
       tagsCollection.insert("0048,0014" ,	"Distance Between Focal Planes");
       tagsCollection.insert("0048,0015" ,	"Recommended Absent Pixel CIELab Value");
       tagsCollection.insert("0048,0100" ,	"Illuminator Type Code Sequence");
       tagsCollection.insert("0048,0102" ,	"Image Orientation (Slide)");
       tagsCollection.insert("0048,0105" ,	"Optical Path Sequence");
       tagsCollection.insert("0048,0106" ,	"Optical Path Identifier");
       tagsCollection.insert("0048,0107" ,	"Optical Path Description");
       tagsCollection.insert("0048,0108" ,	"Illumination Color Code Sequence");
       tagsCollection.insert("0048,0110" ,	"Specimen Reference Sequence");
       tagsCollection.insert("0048,0111" ,	"Condenser Lens Power");
       tagsCollection.insert("0048,0112" ,	"Objective Lens Power");
       tagsCollection.insert("0048,0113" ,	"Objective Lens Numerical Aperture");
       tagsCollection.insert("0048,0120" ,	"Palette Color Lookup Table Sequence");
       tagsCollection.insert("0048,0200" ,	"Referenced Image Navigation Sequence");
       tagsCollection.insert("0048,0201" ,	"Top Left Hand Corner of Localizer Area");
       tagsCollection.insert("0048,0202" ,	"Bottom Right Hand Corner of Localizer Area");
       tagsCollection.insert("0048,0207" ,	"Optical Path Identification Sequence");
       tagsCollection.insert("0048,021A" ,	"Plane Position (Slide) Sequence");
       tagsCollection.insert("0048,021E" ,	"Column Position In Total Image Pixel Matrix");
       tagsCollection.insert("0048,021F" ,	"Row Position In Total Image Pixel Matrix");
       tagsCollection.insert("0048,0301" ,	"Pixel Origin Interpretation");
       tagsCollection.insert("0050,0004" ,	"Calibration Image");
       tagsCollection.insert("0050,0010" ,	"Device Sequence");
       tagsCollection.insert("0050,0012" ,	"Container Component Type Code Sequence");
       tagsCollection.insert("0050,0013" ,	"Container Component Thickness");
       tagsCollection.insert("0050,0014" ,	"Device Length");
       tagsCollection.insert("0050,0015" ,	"Container Component Width");
       tagsCollection.insert("0050,0016" ,	"Device Diameter");
       tagsCollection.insert("0050,0017" ,	"Device Diameter Units");
       tagsCollection.insert("0050,0018" ,	"Device Volume");
       tagsCollection.insert("0050,0019" ,	"Inter-Marker Distance");
       tagsCollection.insert("0050,001A" ,	"Container Component Material");
       tagsCollection.insert("0050,001B" ,	"Container Component ID");
       tagsCollection.insert("0050,001C" ,	"Container Component Length");
       tagsCollection.insert("0050,001D" ,	"Container Component Diameter");
       tagsCollection.insert("0050,001E" ,	"Container Component Description");
       tagsCollection.insert("0050,0020" ,	"Device Description");
       tagsCollection.insert("0052,0001" ,	"Contrast/Bolus Ingredient Percent by Volume");
       tagsCollection.insert("0052,0002" ,	"OCT Focal Distance");
       tagsCollection.insert("0052,0003" ,	"Beam Spot Size");
       tagsCollection.insert("0052,0004" ,	"Effective Refractive Index");
       tagsCollection.insert("0052,0006" ,	"OCT Acquisition Domain");
       tagsCollection.insert("0052,0007" ,	"OCT Optical Center Wavelength");
       tagsCollection.insert("0052,0008" ,	"Axial Resolution");
       tagsCollection.insert("0052,0009" ,	"Ranging Depth");
       tagsCollection.insert("0052,0011" ,	"A-line Rate");
       tagsCollection.insert("0052,0012" ,	"A-lines Per Frame");
       tagsCollection.insert("0052,0013" ,	"Catheter Rotational Rate");
       tagsCollection.insert("0052,0014" ,	"A-line Pixel Spacing");
       tagsCollection.insert("0052,0016" ,	"Mode of Percutaneous Access Sequence");
       tagsCollection.insert("0052,0025" ,	"Intravascular OCT Frame Type Sequence");
       tagsCollection.insert("0052,0026" ,	"OCT Z Offset Applied");
       tagsCollection.insert("0052,0027" ,	"Intravascular Frame Content Sequence");
       tagsCollection.insert("0052,0028" ,	"Intravascular Longitudinal Distance");
       tagsCollection.insert("0052,0029" ,	"Intravascular OCT Frame Content Sequence");
       tagsCollection.insert("0052,0030" ,	"OCT Z Offset Correction");
       tagsCollection.insert("0052,0031" ,	"Catheter Direction of Rotation");
       tagsCollection.insert("0052,0033" ,	"Seam Line Location");
       tagsCollection.insert("0052,0034" ,	"First A-line Location");
       tagsCollection.insert("0052,0036" ,	"Seam Line Index");
       tagsCollection.insert("0052,0038" ,	"Number of Padded A-lines");
       tagsCollection.insert("0052,0039" ,	"Interpolation Type");
       tagsCollection.insert("0052,003A" ,	"Refractive Index Applied");
       tagsCollection.insert("0054,0010" ,	"Energy Window Vector");
       tagsCollection.insert("0054,0011" ,	"Number of Energy Windows");
       tagsCollection.insert("0054,0012" ,	"Energy Window Information Sequence");
       tagsCollection.insert("0054,0013" ,	"Energy Window Range Sequence");
       tagsCollection.insert("0054,0014" ,	"Energy Window Lower Limit");
       tagsCollection.insert("0054,0015" ,	"Energy Window Upper Limit");
       tagsCollection.insert("0054,0016" ,	"Radiopharmaceutical Information Sequence");
       tagsCollection.insert("0054,0017" ,	"Residual Syringe Counts");
       tagsCollection.insert("0054,0018" ,	"Energy Window Name");
       tagsCollection.insert("0054,0020" ,	"Detector Vector");
       tagsCollection.insert("0054,0021" ,	"Number of Detectors");
       tagsCollection.insert("0054,0022" ,	"Detector Information Sequence");
       tagsCollection.insert("0054,0030" ,	"Phase Vector");
       tagsCollection.insert("0054,0031" ,	"Number of Phases");
       tagsCollection.insert("0054,0032" ,	"Phase Information Sequence");
       tagsCollection.insert("0054,0033" ,	"Number of Frames in Phase");
       tagsCollection.insert("0054,0036" ,	"Phase Delay");
       tagsCollection.insert("0054,0038" ,	"Pause Between Frames");
       tagsCollection.insert("0054,0039" ,	"Phase Description");
       tagsCollection.insert("0054,0050" ,	"Rotation Vector");
       tagsCollection.insert("0054,0051" ,	"Number of Rotations");
       tagsCollection.insert("0054,0052" ,	"Rotation Information Sequence");
       tagsCollection.insert("0054,0053" ,	"Number of Frames in Rotation");
       tagsCollection.insert("0054,0060" ,	"R-R Interval Vector");
       tagsCollection.insert("0054,0061" ,	"Number of R-R Intervals");
       tagsCollection.insert("0054,0062" ,	"Gated Information Sequence");
       tagsCollection.insert("0054,0063" ,	"Data Information Sequence");
       tagsCollection.insert("0054,0070" ,	"Time Slot Vector");
       tagsCollection.insert("0054,0071" ,	"Number of Time Slots");
       tagsCollection.insert("0054,0072" ,	"Time Slot Information Sequence");
       tagsCollection.insert("0054,0073" ,	"Time Slot Time");
       tagsCollection.insert("0054,0080" ,	"Slice Vector");
       tagsCollection.insert("0054,0081" ,	"Number of Slices");
       tagsCollection.insert("0054,0090" ,	"Angular View Vector");
       tagsCollection.insert("0054,0100" ,	"Time Slice Vector");
       tagsCollection.insert("0054,0101" ,	"Number of Time Slices");
       tagsCollection.insert("0054,0200" ,	"Start Angle");
       tagsCollection.insert("0054,0202" ,	"Type of Detector Motion");
       tagsCollection.insert("0054,0210" ,	"Trigger Vector");
       tagsCollection.insert("0054,0211" ,	"Number of Triggers in Phase");
       tagsCollection.insert("0054,0220" ,	"View Code Sequence");
       tagsCollection.insert("0054,0222" ,	"View Modifier Code Sequence");
       tagsCollection.insert("0054,0300" ,	"Radionuclide Code Sequence");
       tagsCollection.insert("0054,0302" ,	"Administration Route Code Sequence");
       tagsCollection.insert("0054,0304" ,	"Radiopharmaceutical Code Sequence");
       tagsCollection.insert("0054,0306" ,	"Calibration Data Sequence");
       tagsCollection.insert("0054,0308" ,	"Energy Window Number");
       tagsCollection.insert("0054,0400" ,	"Image ID");
       tagsCollection.insert("0054,0410" ,	"Patient Orientation Code Sequence");
       tagsCollection.insert("0054,0412" ,	"Patient Orientation Modifier Code Sequence");
       tagsCollection.insert("0054,0414" ,	"Patient Gantry Relationship Code Sequence");
       tagsCollection.insert("0054,0500" ,	"Slice Progression Direction");
       tagsCollection.insert("0054,0501" ,	"Scan Progression Direction");
       tagsCollection.insert("0054,1000" ,	"Series Type");
       tagsCollection.insert("0054,1001" ,	"Units");
       tagsCollection.insert("0054,1002" ,	"Counts Source");
       tagsCollection.insert("0054,1004" ,	"Reprojection Method");
       tagsCollection.insert("0054,1006" ,	"SUV Type");
       tagsCollection.insert("0054,1100" ,	"Randoms Correction Method");
       tagsCollection.insert("0054,1101" ,	"Attenuation Correction Method");
       tagsCollection.insert("0054,1102" ,	"Decay Correction");
       tagsCollection.insert("0054,1103" ,	"Reconstruction Method");
       tagsCollection.insert("0054,1104" ,	"Detector Lines of Response Used");
       tagsCollection.insert("0054,1105" ,	"Scatter Correction Method");
       tagsCollection.insert("0054,1200" ,	"Axial Acceptance");
       tagsCollection.insert("0054,1201" ,	"Axial Mash");
       tagsCollection.insert("0054,1202" ,	"Transverse Mash");
       tagsCollection.insert("0054,1203" ,	"Detector Element Size");
       tagsCollection.insert("0054,1210" ,	"Coincidence Window Width");
       tagsCollection.insert("0054,1220" ,	"Secondary Counts Type");
       tagsCollection.insert("0054,1300" ,	"Frame Reference Time");
       tagsCollection.insert("0054,1310" ,	"Primary (Prompts) Counts Accumulated");
       tagsCollection.insert("0054,1311" ,	"Secondary Counts Accumulated");
       tagsCollection.insert("0054,1320" ,	"Slice Sensitivity Factor");
       tagsCollection.insert("0054,1321" ,	"Decay Factor");
       tagsCollection.insert("0054,1322" ,	"Dose Calibration Factor");
       tagsCollection.insert("0054,1323" ,	"Scatter Fraction Factor");
       tagsCollection.insert("0054,1324" ,	"Dead Time Factor");
       tagsCollection.insert("0054,1330" ,	"Image Index");
       tagsCollection.insert("0054,1400" ,	"Counts Included");	//Retired
       tagsCollection.insert("0054,1401" ,	"Dead Time Correction Flag");	//Retired
       tagsCollection.insert("0060,3000" ,	"Histogram Sequence");
       tagsCollection.insert("0060,3002" ,	"Histogram Number of Bins");
       tagsCollection.insert("0060,3004" ,   "Histogram First Bin Value");
       tagsCollection.insert("0060,3006" , 	"Histogram Last Bin Value");
       tagsCollection.insert("0060,3008" ,	"Histogram Bin Width");
       tagsCollection.insert("0060,3010" ,	"Histogram Explanation");
       tagsCollection.insert("0060,3020" ,	"Histogram Data");
       tagsCollection.insert("0062,0001" ,	"Segmentation Type");
       tagsCollection.insert("0062,0002" ,	"Segment Sequence");
       tagsCollection.insert("0062,0003" ,	"Segmented Property Category Code Sequence");
       tagsCollection.insert("0062,0004" ,	"Segment Number");
       tagsCollection.insert("0062,0005" ,	"Segment Label");
       tagsCollection.insert("0062,0006" ,	"Segment Description");
       tagsCollection.insert("0062,0008" ,	"Segment Algorithm Type");
       tagsCollection.insert("0062,0009" ,	"Segment Algorithm Name");
       tagsCollection.insert("0062,000A" ,	"Segment Identification Sequence");
       tagsCollection.insert("0062,000B" ,	"Referenced Segment Number");
       tagsCollection.insert("0062,000C" ,	"Recommended Display Grayscale Value");
       tagsCollection.insert("0062,000D" ,	"Recommended Display CIELab Value");
       tagsCollection.insert("0062,000E" ,	"Maximum Fractional Value");
       tagsCollection.insert("0062,000F" ,	"Segmented Property Type Code Sequence");
       tagsCollection.insert("0062,0010" ,	"Segmentation Fractional Type");
       tagsCollection.insert("0062,0011" ,	"Segmented Property Type Modifier Code Sequence");
       tagsCollection.insert("0062,0012" ,	"Used Segments Sequence");
       tagsCollection.insert("0062,0020" ,	"Tracking ID");
       tagsCollection.insert("0062,0021" ,	"Tracking UID");
       tagsCollection.insert("0064,0002" ,	"Deformable Registration Sequence");
       tagsCollection.insert("0064,0003" ,	"Source Frame of Reference UID");
       tagsCollection.insert("0064,0005" ,	"Deformable Registration Grid Sequence");
       tagsCollection.insert("0064,0007" ,	"Grid Dimensions");
       tagsCollection.insert("0064,0008" ,	"Grid Resolution");
       tagsCollection.insert("0064,0009" ,	"Vector Grid Data");
       tagsCollection.insert("0064,000F" ,	"Pre Deformation Matrix Registration Sequence");
       tagsCollection.insert("0064,0010" ,	"Post Deformation Matrix Registration Sequence");
       tagsCollection.insert("0066,0001" ,	"Number of Surfaces");
       tagsCollection.insert("0066,0002" ,	"Surface Sequence");
       tagsCollection.insert("0066,0003" ,	"Surface Number");
       tagsCollection.insert("0066,0004" ,	"Surface Comments");
       tagsCollection.insert("0066,0009" ,	"Surface Processing");
       tagsCollection.insert("0066,000A" ,	"Surface Processing Ratio");
       tagsCollection.insert("0066,000B" ,	"Surface Processing Description");
       tagsCollection.insert("0066,000C" ,	"Recommended Presentation Opacity");
       tagsCollection.insert("0066,000D" ,	"Recommended Presentation Type");
       tagsCollection.insert("0066,000E" ,	"Finite Volume");
       tagsCollection.insert("0066,0010" ,	"Manifold");
       tagsCollection.insert("0066,0011" ,	"Surface Points Sequence");
       tagsCollection.insert("0066,0012" ,	"Surface Points Normals Sequence");
       tagsCollection.insert("0066,0013" ,	"Surface Mesh Primitives Sequence");
       tagsCollection.insert("0066,0015" ,	"Number of Surface Points");
       tagsCollection.insert("0066,0016" ,	"Point Coordinates Data");
       tagsCollection.insert("0066,0017" ,	"Point Position Accuracy");
       tagsCollection.insert("0066,0018" ,	"Mean Point Distance");
       tagsCollection.insert("0066,0019" ,	"Maximum Point Distance");
       tagsCollection.insert("0066,001A" ,	"Points Bounding Box Coordinates");
       tagsCollection.insert("0066,001B" ,	"Axis of Rotation");
       tagsCollection.insert("0066,001C" ,	"Center of Rotation");
       tagsCollection.insert("0066,001E" ,	"Number of Vectors");
       tagsCollection.insert("0066,001F" ,	"Vector Dimensionality");
       tagsCollection.insert("0066,0020" ,	"Vector Accuracy");
       tagsCollection.insert("0066,0021" ,	"Vector Coordinate Data");
       tagsCollection.insert("0066,0023" ,	"Triangle Point Index List");	//Retired
       tagsCollection.insert("0066,0024" ,	"Edge Point Index List");	    //Retired
       tagsCollection.insert("0066,0025" ,	"Vertex Point Index List");     //Retired
       tagsCollection.insert("0066,0026" ,	"Triangle Strip Sequence");
       tagsCollection.insert("0066,0027" ,	"Triangle Fan Sequence");
       tagsCollection.insert("0066,0028" ,	"Line Sequence");
       tagsCollection.insert("0066,0029" ,	"Primitive Point Index List");	//Retired
       tagsCollection.insert("0066,002A" ,	"Surface Count");
       tagsCollection.insert("0066,002B" ,	"Referenced Surface Sequence");
       tagsCollection.insert("0066,002C" ,	"Referenced Surface Number");
       tagsCollection.insert("0066,002D" ,	"Segment Surface Generation Algorithm Identification Sequence");
       tagsCollection.insert("0066,002E" ,	"Segment Surface Source Instance Sequence");
       tagsCollection.insert("0066,002F" ,	"Algorithm Family Code Sequence");
       tagsCollection.insert("0066,0030" ,	"Algorithm Name Code Sequence");
       tagsCollection.insert("0066,0031" ,	"Algorithm Version");
       tagsCollection.insert("0066,0032" ,	"Algorithm Parameters");
       tagsCollection.insert("0066,0034" ,	"Facet Sequence");
       tagsCollection.insert("0066,0035" ,	"Surface Processing Algorithm Identification Sequence");
       tagsCollection.insert("0066,0036" ,	"Algorithm Name");
       tagsCollection.insert("0066,0037" ,	"Recommended Point Radius");
       tagsCollection.insert("0066,0038" ,	"Recommended Line Thickness");
       tagsCollection.insert("0066,0040" ,	"Long Primitive Point Index List");
       tagsCollection.insert("0066,0041" ,	"Long Triangle Point Index List");
       tagsCollection.insert("0066,0042" ,	"Long Edge Point Index List");
       tagsCollection.insert("0066,0043" ,	"Long Vertex Point Index List");
       tagsCollection.insert("0066,0101" ,	"Track Set Sequence");
       tagsCollection.insert("0066,0102" ,	"Track Sequence");
       tagsCollection.insert("0066,0103" ,	"Recommended Display CIELab Value List");
       tagsCollection.insert("0066,0104" ,	"Tracking Algorithm Identification Sequence");
       tagsCollection.insert("0066,0105" ,	"Track Set Number");
       tagsCollection.insert("0066,0106" ,	"Track Set Label");
       tagsCollection.insert("0066,0107" ,	"Track Set Description");
       tagsCollection.insert("0066,0108" ,	"Track Set Anatomical Type Code Sequence");
       tagsCollection.insert("0066,0121" ,	"Measurements Sequence");
       tagsCollection.insert("0066,0124" ,	"Track Set Statistics Sequence");
       tagsCollection.insert("0066,0125" ,	"Floating Point Values");
       tagsCollection.insert("0066,0129" ,	"Track Point Index List");
       tagsCollection.insert("0066,0130" ,	"Track Statistics Sequence");
       tagsCollection.insert("0066,0132" ,	"Measurement Values Sequence");
       tagsCollection.insert("0066,0133" ,	"Diffusion Acquisition Code Sequence");
       tagsCollection.insert("0066,0134" ,	"Diffusion Model Code Sequence");
       tagsCollection.insert("0068,6210" ,	"Implant Size");
       tagsCollection.insert("0068,6221" ,	"Implant Template Version");
       tagsCollection.insert("0068,6222" ,	"Replaced Implant Template Sequence");
       tagsCollection.insert("0068,6223" ,	"Implant Type");
       tagsCollection.insert("0068,6224" ,	"Derivation Implant Template Sequence");
       tagsCollection.insert("0068,6225" ,	"Original Implant Template Sequence");
       tagsCollection.insert("0068,6226" ,	"Effective DateTime");
       tagsCollection.insert("0068,6230" ,	"Implant Target Anatomy Sequence");
       tagsCollection.insert("0068,6260" ,	"Information From Manufacturer Sequence");
       tagsCollection.insert("0068,6265" ,	"Notification From Manufacturer Sequence");
       tagsCollection.insert("0068,6270" ,	"Information Issue DateTime");
       tagsCollection.insert("0068,6280" ,	"Information Summary");
       tagsCollection.insert("0068,62A0" ,	"Implant Regulatory Disapproval Code Sequence");
       tagsCollection.insert("0068,62A5" ,	"Overall Template Spatial Tolerance");
       tagsCollection.insert("0068,62C0" ,	"HPGL Document Sequence");
       tagsCollection.insert("0068,62D0" ,	"HPGL Document ID");
       tagsCollection.insert("0068,62D5" ,	"HPGL Document Label");
       tagsCollection.insert("0068,62E0" ,	"View Orientation Code Sequence");
       tagsCollection.insert("0068,62F0" ,	"View Orientation Modifier");
       tagsCollection.insert("0068,62F2" ,	"HPGL Document Scaling");
       tagsCollection.insert("0068,6300" ,	"HPGL Document");
       tagsCollection.insert("0068,6310" ,	"HPGL Contour Pen Number");
       tagsCollection.insert("0068,6320" ,	"HPGL Pen Sequence");
       tagsCollection.insert("0068,6330" ,	"HPGL Pen Number");
       tagsCollection.insert("0068,6340" ,	"HPGL Pen Label");
       tagsCollection.insert("0068,6345" ,	"HPGL Pen Description");
       tagsCollection.insert("0068,6346" ,	"Recommended Rotation Point");
       tagsCollection.insert("0068,6347" ,	"Bounding Rectangle");
       tagsCollection.insert("0068,6350" ,	"Implant Template 3D Model Surface Number");
       tagsCollection.insert("0068,6360" ,	"Surface Model Description Sequence");
       tagsCollection.insert("0068,6380" ,	"Surface Model Label");
       tagsCollection.insert("0068,6390" ,	"Surface Model Scaling Factor");
       tagsCollection.insert("0068,63A0" ,	"Materials Code Sequence");
       tagsCollection.insert("0068,63A4" ,	"Coating Materials Code Sequence");
       tagsCollection.insert("0068,63A8" ,	"Implant Type Code Sequence");
       tagsCollection.insert("0068,63AC" ,	"Fixation Method Code Sequence");
       tagsCollection.insert("0068,63B0" ,	"Mating Feature Sets Sequence");
       tagsCollection.insert("0068,63C0" ,	"Mating Feature Set ID");
       tagsCollection.insert("0068,63D0" ,	"Mating Feature Set Label");
       tagsCollection.insert("0068,63E0" ,	"Mating Feature Sequence");
       tagsCollection.insert("0068,63F0" ,	"Mating Feature ID");
       tagsCollection.insert("0068,6400" ,	"Mating Feature Degree of Freedom Sequence");
       tagsCollection.insert("0068,6410" ,	"Degree of Freedom ID");
       tagsCollection.insert("0068,6420" ,	"Degree of Freedom Type");
       tagsCollection.insert("0068,6430" ,	"2D Mating Feature Coordinates Sequence");
       tagsCollection.insert("0068,6440" ,	"Referenced HPGL Document ID");
       tagsCollection.insert("0068,6450" ,	"2D Mating Point");
       tagsCollection.insert("0068,6460" ,	"2D Mating Axes");
       tagsCollection.insert("0068,6470" ,	"2D Degree of Freedom Sequence");
       tagsCollection.insert("0068,6490" ,	"3D Degree of Freedom Axis");
       tagsCollection.insert("0068,64A0" ,	"Range of Freedom");
       tagsCollection.insert("0068,64C0" ,	"3D Mating Point");
       tagsCollection.insert("0068,64D0" ,	"3D Mating Axes");
       tagsCollection.insert("0068,64F0" ,	"2D Degree of Freedom Axis");
       tagsCollection.insert("0068,6500" ,	"Planning Landmark Point Sequence");
       tagsCollection.insert("0068,6510" ,	"Planning Landmark Line Sequence");
       tagsCollection.insert("0068,6520" ,	"Planning Landmark Plane Sequence");
       tagsCollection.insert("0068,6530" ,	"Planning Landmark ID");
       tagsCollection.insert("0068,6540" ,	"Planning Landmark Description");
       tagsCollection.insert("0068,6545" ,	"Planning Landmark Identification Code Sequence");
       tagsCollection.insert("0068,6550" ,	"2D Point Coordinates Sequence");
       tagsCollection.insert("0068,6560" ,	"2D Point Coordinates");
       tagsCollection.insert("0068,6590" ,	"3D Point Coordinates");
       tagsCollection.insert("0068,65A0" ,	"2D Line Coordinates Sequence");
       tagsCollection.insert("0068,65B0" ,	"2D Line Coordinates");
       tagsCollection.insert("0068,65D0" ,	"3D Line Coordinates");
       tagsCollection.insert("0068,65E0" ,	"2D Plane Coordinates Sequence");
       tagsCollection.insert("0068,65F0" ,	"2D Plane Intersection");
       tagsCollection.insert("0068,6610" ,	"3D Plane Origin");
       tagsCollection.insert("0068,6620" ,	"3D Plane Normal");
       tagsCollection.insert("0070,0001" ,	"Graphic Annotation Sequence");
       tagsCollection.insert("0070,0002" ,	"Graphic Layer");
       tagsCollection.insert("0070,0003" ,	"Bounding Box Annotation Units");
       tagsCollection.insert("0070,0004" ,	"Anchor Point Annotation Units");
       tagsCollection.insert("0070,0005" ,	"Graphic Annotation Units");
       tagsCollection.insert("0070,0006" ,	"Unformatted Text Value");
       tagsCollection.insert("0070,0008" ,	"Text Object Sequence");
       tagsCollection.insert("0070,0009" ,	"Graphic Object Sequence");
       tagsCollection.insert("0070,0010" ,	"Bounding Box Top Left Hand Corner");
       tagsCollection.insert("0070,0011" ,	"Bounding Box Bottom Right Hand Corner");
       tagsCollection.insert("0070,0012" ,	"Bounding Box Text Horizontal Justification");
       tagsCollection.insert("0070,0014" ,	"Anchor Point");
       tagsCollection.insert("0070,0015" ,	"Anchor Point Visibility");
       tagsCollection.insert("0070,0020" ,	"Graphic Dimensions");
       tagsCollection.insert("0070,0021" ,	"Number of Graphic Points");
       tagsCollection.insert("0070,0022" ,	"Graphic Data");
       tagsCollection.insert("0070,0023" ,	"Graphic Type");
       tagsCollection.insert("0070,0024" ,	"Graphic Filled");
       tagsCollection.insert("0070,0040" ,	"Image Rotation"); //(Retired)	Retired
       tagsCollection.insert("0070,0041" ,	"Image Horizontal Flip");
       tagsCollection.insert("0070,0042" ,	"Image Rotation");
       tagsCollection.insert("0070,0050" ,	"Displayed Area Top Left Hand Corner"); //(Trial)	Retired
       tagsCollection.insert("0070,0051" ,	"Displayed Area Bottom Right Hand Corner"); //(Trial)	Retired
       tagsCollection.insert("0070,0052" ,	"Displayed Area Top Left Hand Corner");
       tagsCollection.insert("0070,0053" ,	"Displayed Area Bottom Right Hand Corner");
       tagsCollection.insert("0070,005A" ,	"Displayed Area Selection Sequence");
       tagsCollection.insert("0070,0060" ,	"Graphic Layer Sequence");
       tagsCollection.insert("0070,0062" ,	"Graphic Layer Order");
       tagsCollection.insert("0070,0066" ,	"Graphic Layer Recommended Display Grayscale Value");
       tagsCollection.insert("0070,0067" ,	"Graphic Layer Recommended Display RGB Value");	//Retired
       tagsCollection.insert("0070,0068" ,	"Graphic Layer Description");
       tagsCollection.insert("0070,0080" ,	"Content Label");
       tagsCollection.insert("0070,0081" ,	"Content Description");
       tagsCollection.insert("0070,0082" ,	"Presentation Creation Date");
       tagsCollection.insert("0070,0083" ,	"Presentation Creation Time");
       tagsCollection.insert("0070,0084" ,	"Content Creator's Name");
       tagsCollection.insert("0070,0086" ,	"Content Creator's Identification Code Sequence");
       tagsCollection.insert("0070,0087" ,	"Alternate Content Description Sequence");
       tagsCollection.insert("0070,0100" ,	"Presentation Size Mode");
       tagsCollection.insert("0070,0101" ,	"Presentation Pixel Spacing");
       tagsCollection.insert("0070,0102" ,	"Presentation Pixel Aspect Ratio");
       tagsCollection.insert("0070,0103" ,	"Presentation Pixel Magnification Ratio");
       tagsCollection.insert("0070,0207" ,	"Graphic Group Label");
       tagsCollection.insert("0070,0208" ,	"Graphic Group Description");
       tagsCollection.insert("0070,0209" ,	"Compound Graphic Sequence");
       tagsCollection.insert("0070,0226" ,	"Compound Graphic Instance ID");
       tagsCollection.insert("0070,0227" ,	"Font Name");
       tagsCollection.insert("0070,0228" ,	"Font Name Type");
       tagsCollection.insert("0070,0229" ,	"CSS Font Name");
       tagsCollection.insert("0070,0230" ,	"Rotation Angle");
       tagsCollection.insert("0070,0231" ,	"Text Style Sequence");
       tagsCollection.insert("0070,0232" ,	"Line Style Sequence");
       tagsCollection.insert("0070,0233" ,	"Fill Style Sequence");
       tagsCollection.insert("0070,0234" ,	"Graphic Group Sequence");
       tagsCollection.insert("0070,0241" ,	"Text Color CIELab Value");
       tagsCollection.insert("0070,0242" ,	"Horizontal Alignment");
       tagsCollection.insert("0070,0243" ,	"Vertical Alignment");
       tagsCollection.insert("0070,0244" ,	"Shadow Style");
       tagsCollection.insert("0070,0245" ,	"Shadow Offset X");
       tagsCollection.insert("0070,0246" ,	"Shadow Offset Y");
       tagsCollection.insert("0070,0247" ,	"Shadow Color CIELab Value");
       tagsCollection.insert("0070,0248" ,	"Underlined");
       tagsCollection.insert("0070,0249" ,	"Bold");
       tagsCollection.insert("0070,0250" ,	"Italic");
       tagsCollection.insert("0070,0251" ,	"Pattern On Color CIELab Value");
       tagsCollection.insert("0070,0252" ,	"Pattern Off Color CIELab Value");
       tagsCollection.insert("0070,0253" ,	"Line Thickness");
       tagsCollection.insert("0070,0254" ,	"Line Dashing Style");
       tagsCollection.insert("0070,0255" ,	"Line Pattern");
       tagsCollection.insert("0070,0256" ,	"Fill Pattern");
       tagsCollection.insert("0070,0257" ,	"Fill Mode");
       tagsCollection.insert("0070,0258" ,	"Shadow Opacity");
       tagsCollection.insert("0070,0261" ,	"Gap Length");
       tagsCollection.insert("0070,0262" ,	"Diameter of Visibility");
       tagsCollection.insert("0070,0273" ,	"Rotation Point");
       tagsCollection.insert("0070,0274" ,	"Tick Alignment");
       tagsCollection.insert("0070,0278" ,	"Show Tick Label");
       tagsCollection.insert("0070,0279" ,	"Tick Label Alignment");
       tagsCollection.insert("0070,0282" ,	"Compound Graphic Units");
       tagsCollection.insert("0070,0284" ,	"Pattern On Opacity");
       tagsCollection.insert("0070,0285" ,	"Pattern Off Opacity");
       tagsCollection.insert("0070,0287" ,	"Major Ticks Sequence");
       tagsCollection.insert("0070,0288" ,	"Tick Position");
       tagsCollection.insert("0070,0289" ,	"Tick Label");
       tagsCollection.insert("0070,0294" ,	"Compound Graphic Type");
       tagsCollection.insert("0070,0295" ,	"Graphic Group ID");
       tagsCollection.insert("0070,0306" ,	"Shape Type");
       tagsCollection.insert("0070,0308" ,	"Registration Sequence");
       tagsCollection.insert("0070,0309" ,	"Matrix Registration Sequence");
       tagsCollection.insert("0070,030A" ,	"Matrix Sequence");
       tagsCollection.insert("0070,030B" ,	"Frame of Reference to Displayed Coordinate System Transformation Matrix");
       tagsCollection.insert("0070,030C" ,	"Frame of Reference Transformation Matrix Type");
       tagsCollection.insert("0070,030D" ,	"Registration Type Code Sequence");
       tagsCollection.insert("0070,030F" ,	"Fiducial Description");
       tagsCollection.insert("0070,0310" ,	"Fiducial Identifier");
       tagsCollection.insert("0070,0311" ,	"Fiducial Identifier Code Sequence");
       tagsCollection.insert("0070,0312" ,	"Contour Uncertainty Radius");
       tagsCollection.insert("0070,0314" ,	"Used Fiducials Sequence");
       tagsCollection.insert("0070,0318" ,	"Graphic Coordinates Data Sequence");
       tagsCollection.insert("0070,031A" ,	"Fiducial UID");
       tagsCollection.insert("0070,031C" ,	"Fiducial Set Sequence");
       tagsCollection.insert("0070,031E" ,	"Fiducial Sequence");
       tagsCollection.insert("0070,0401" ,	"Graphic Layer Recommended Display CIELab Value");
       tagsCollection.insert("0070,0402" ,	"Blending Sequence");
       tagsCollection.insert("0070,0403" ,	"Relative Opacity");
       tagsCollection.insert("0070,0404" ,	"Referenced Spatial Registration Sequence");
       tagsCollection.insert("0070,0405" ,	"Blending Position");
       tagsCollection.insert("0070,1101" ,	"Presentation Display Collection UID");
       tagsCollection.insert("0070,1102" ,	"Presentation Sequence Collection UID");
       tagsCollection.insert("0070,1103" ,	"Presentation Sequence Position Index");
       tagsCollection.insert("0070,1104" ,	"Rendered Image Reference Sequence");
       tagsCollection.insert("0070,1201" ,	"Volumetric Presentation State Input Sequence");
       tagsCollection.insert("0070,1202" ,	"Presentation Input Type");
       tagsCollection.insert("0070,1203" ,	"Input Sequence Position Index");
       tagsCollection.insert("0070,1204" ,	"Crop");
       tagsCollection.insert("0070,1205" ,	"Cropping Specification Index");
       tagsCollection.insert("0070,1206" ,	"Compositing Method");
       tagsCollection.insert("0070,1207" ,	"Volumetric Presentation Input Number");
       tagsCollection.insert("0070,1208" ,	"Image Volume Geometry");
       tagsCollection.insert("0070,1301" ,	"Volume Cropping Sequence");
       tagsCollection.insert("0070,1302" ,	"Volume Cropping Method");
       tagsCollection.insert("0070,1303" ,	"Bounding Box Crop");
       tagsCollection.insert("0070,1304" ,	"Oblique Cropping Plane Sequence");
       tagsCollection.insert("0070,1305" ,	"Plane");
       tagsCollection.insert("0070,1306" ,	"Plane Normal");
       tagsCollection.insert("0070,1309" ,	"Cropping Specification Number");
       tagsCollection.insert("0070,1501" ,	"Multi-Planar Reconstruction Style");
       tagsCollection.insert("0070,1502" ,	"MPR Thickness Type");
       tagsCollection.insert("0070,1503" ,	"MPR Slab Thickness");
       tagsCollection.insert("0070,1505" ,	"MPR Top Left Hand Corner");
       tagsCollection.insert("0070,1507" ,	"MPR View Width Direction");
       tagsCollection.insert("0070,1508" ,	"MPR View Width");
       tagsCollection.insert("0070,150C" ,	"Number of Volumetric Curve Points");
       tagsCollection.insert("0070,150D" ,	"Volumetric Curve Points");
       tagsCollection.insert("0070,1511" ,	"MPR View Height Direction");
       tagsCollection.insert("0070,1512" ,	"MPR View Height");
       tagsCollection.insert("0070,1801" ,	"Presentation State Classification Component Sequence");
       tagsCollection.insert("0070,1802" ,	"Component Type");
       tagsCollection.insert("0070,1803" ,	"Component Input Sequence");
       tagsCollection.insert("0070,1804" ,	"Volumetric Presentation Input Index");
       tagsCollection.insert("0070,1805" ,	"Presentation State Compositor Component Sequence");
       tagsCollection.insert("0070,1806" ,	"Weighting Transfer Function Sequence");
       tagsCollection.insert("0070,1807" ,	"Weighting Lookup Table Descriptor");
       tagsCollection.insert("0070,1808" ,	"Weighting Lookup Table Data");
       tagsCollection.insert("0070,1901" ,	"Volumetric Annotation Sequence");
       tagsCollection.insert("0070,1903" ,	"Referenced Structured Context Sequence");
       tagsCollection.insert("0070,1904" ,	"Referenced Content Item");
       tagsCollection.insert("0070,1905" ,	"Volumetric Presentation Input Annotation Sequence");
       tagsCollection.insert("0070,1907" ,	"Annotation Clipping");
       tagsCollection.insert("0070,1A01" ,	"Presentation Animation Style");
       tagsCollection.insert("0070,1A03" ,	"Recommended Animation Rate");
       tagsCollection.insert("0070,1A04" ,	"Animation Curve Sequence");
       tagsCollection.insert("0070,1A05" ,	"Animation Step Size");
       tagsCollection.insert("0072,0002" ,	"Hanging Protocol Name");
       tagsCollection.insert("0072,0004" ,	"Hanging Protocol Description");
       tagsCollection.insert("0072,0006" ,	"Hanging Protocol Level");
       tagsCollection.insert("0072,0008" ,	"Hanging Protocol Creator");
       tagsCollection.insert("0072,000A" ,	"Hanging Protocol Creation DateTime");
       tagsCollection.insert("0072,000C" ,	"Hanging Protocol Definition Sequence");
       tagsCollection.insert("0072,000E" ,	"Hanging Protocol User Identification Code Sequence");
       tagsCollection.insert("0072,0010" ,	"Hanging Protocol User Group Name");
       tagsCollection.insert("0072,0012" ,	"Source Hanging Protocol Sequence");
       tagsCollection.insert("0072,0014" ,	"Number of Priors Referenced");
       tagsCollection.insert("0072,0020" ,	"Image Sets Sequence");
       tagsCollection.insert("0072,0022" ,	"Image Set Selector Sequence");
       tagsCollection.insert("0072,0024" ,	"Image Set Selector Usage Flag");
       tagsCollection.insert("0072,0026" ,	"Selector Attribute");
       tagsCollection.insert("0072,0028" ,	"Selector Value Number");
       tagsCollection.insert("0072,0030" ,	"Time Based Image Sets Sequence");
       tagsCollection.insert("0072,0032" ,	"Image Set Number");
       tagsCollection.insert("0072,0034" ,	"Image Set Selector Category");
       tagsCollection.insert("0072,0038" ,	"Relative Time");
       tagsCollection.insert("0072,003A" ,	"Relative Time Units");
       tagsCollection.insert("0072,003C" ,	"Abstract Prior Value");
       tagsCollection.insert("0072,003E" ,	"Abstract Prior Code Sequence");
       tagsCollection.insert("0072,0040" ,	"Image Set Label");
       tagsCollection.insert("0072,0050" ,	"Selector Attribute VR");
       tagsCollection.insert("0072,0052" ,	"Selector Sequence Pointer");
       tagsCollection.insert("0072,0054" ,	"Selector Sequence Pointer Private Creator");
       tagsCollection.insert("0072,0056" ,	"Selector Attribute Private Creator");
       tagsCollection.insert("0072,005E" ,	"Selector AE Value");
       tagsCollection.insert("0072,005F" ,	"Selector AS Value");
       tagsCollection.insert("0072,0060" ,	"Selector AT Value");
       tagsCollection.insert("0072,0061" ,	"Selector DA Value");
       tagsCollection.insert("0072,0062" ,	"Selector CS Value");
       tagsCollection.insert("0072,0063" ,	"Selector DT Value");
       tagsCollection.insert("0072,0064" ,	"Selector IS Value");
       tagsCollection.insert("0072,0065" ,	"Selector OB Value");
       tagsCollection.insert("0072,0066" ,	"Selector LO Value");
       tagsCollection.insert("0072,0067" ,	"Selector OF Value");
       tagsCollection.insert("0072,0068" ,	"Selector LT Value");
       tagsCollection.insert("0072,0069" ,	"Selector OW Value");
       tagsCollection.insert("0072,006A" ,	"Selector PN Value");
       tagsCollection.insert("0072,006B" ,	"Selector TM Value");
       tagsCollection.insert("0072,006C" ,	"Selector SH Value");
       tagsCollection.insert("0072,006D" ,	"Selector UN Value");
       tagsCollection.insert("0072,006E" ,	"Selector ST Value");
       tagsCollection.insert("0072,006F" ,	"Selector UC Value");
       tagsCollection.insert("0072,0070" ,	"Selector UT Value");
       tagsCollection.insert("0072,0071" ,	"Selector UR Value");
       tagsCollection.insert("0072,0072" ,	"Selector DS Value");
       tagsCollection.insert("0072,0073" ,	"Selector OD Value");
       tagsCollection.insert("0072,0074" ,	"Selector FD Value");
       tagsCollection.insert("0072,0075" ,	"Selector OL Value");
       tagsCollection.insert("0072,0076" ,	"Selector FL Value");
       tagsCollection.insert("0072,0078" ,	"Selector UL Value");
       tagsCollection.insert("0072,007A" ,	"Selector US Value");
       tagsCollection.insert("0072,007C" ,	"Selector SL Value");
       tagsCollection.insert("0072,007E" ,	"Selector SS Value");
       tagsCollection.insert("0072,007F" ,	"Selector UI Value");
       tagsCollection.insert("0072,0080" ,	"Selector Code Sequence Value");
       tagsCollection.insert("0072,0100" ,	"Number of Screens");
       tagsCollection.insert("0072,0102" ,	"Nominal Screen Definition Sequence");
       tagsCollection.insert("0072,0104" ,	"Number of Vertical Pixels");
       tagsCollection.insert("0072,0106" ,	"Number of Horizontal Pixels");
       tagsCollection.insert("0072,0108" ,	"Display Environment Spatial Position");
       tagsCollection.insert("0072,010A" ,	"Screen Minimum Grayscale Bit Depth");
       tagsCollection.insert("0072,010C" ,	"Screen Minimum Color Bit Depth");
       tagsCollection.insert("0072,010E" ,	"Application Maximum Repaint Time");
       tagsCollection.insert("0072,0200" ,	"Display Sets Sequence");
       tagsCollection.insert("0072,0202" ,	"Display Set Number");
       tagsCollection.insert("0072,0203" ,	"Display Set Label");
       tagsCollection.insert("0072,0204" ,	"Display Set Presentation Group");
       tagsCollection.insert("0072,0206" ,	"Display Set Presentation Group Description");
       tagsCollection.insert("0072,0208" ,	"Partial Data Display Handling");
       tagsCollection.insert("0072,0210" ,	"Synchronized Scrolling Sequence");
       tagsCollection.insert("0072,0212" ,	"Display Set Scrolling Group");
       tagsCollection.insert("0072,0214" ,	"Navigation Indicator Sequence");
       tagsCollection.insert("0072,0216" ,	"Navigation Display Set");
       tagsCollection.insert("0072,0218" ,	"Reference Display Sets");
       tagsCollection.insert("0072,0300" ,	"Image Boxes Sequence");
       tagsCollection.insert("0072,0302" ,	"Image Box Number");
       tagsCollection.insert("0072,0304" ,	"Image Box Layout Type");
       tagsCollection.insert("0072,0306" ,	"Image Box Tile Horizontal Dimension");
       tagsCollection.insert("0072,0308" ,	"Image Box Tile Vertical Dimension");
       tagsCollection.insert("0072,0310" ,	"Image Box Scroll Direction");
       tagsCollection.insert("0072,0312" ,	"Image Box Small Scroll Type");
       tagsCollection.insert("0072,0314" ,	"Image Box Small Scroll Amount");
       tagsCollection.insert("0072,0316" ,	"Image Box Large Scroll Type");
       tagsCollection.insert("0072,0318" ,	"Image Box Large Scroll Amount");
       tagsCollection.insert("0072,0320" ,	"Image Box Overlap Priority");
       tagsCollection.insert("0072,0330" ,	"Cine Relative to Real-Time");
       tagsCollection.insert("0072,0400" ,	"Filter Operations Sequence");
       tagsCollection.insert("0072,0402" ,	"Filter-by Category");
       tagsCollection.insert("0072,0404" ,	"Filter-by Attribute Presence");
       tagsCollection.insert("0072,0406" ,	"Filter-by Operator");
       tagsCollection.insert("0072,0420" ,	"Structured Display Background CIELab Value");
       tagsCollection.insert("0072,0421" ,	"Empty Image Box CIELab Value");
       tagsCollection.insert("0072,0422" ,	"Structured Display Image Box Sequence");
       tagsCollection.insert("0072,0424" ,	"Structured Display Text Box Sequence");
       tagsCollection.insert("0072,0427" ,	"Referenced First Frame Sequence");
       tagsCollection.insert("0072,0430" ,	"Image Box Synchronization Sequence");
       tagsCollection.insert("0072,0432" ,	"Synchronized Image Box List");
       tagsCollection.insert("0072,0434" ,	"Type of Synchronization");
       tagsCollection.insert("0072,0500" ,	"Blending Operation Type");
       tagsCollection.insert("0072,0510" ,	"Reformatting Operation Type");
       tagsCollection.insert("0072,0512" ,	"Reformatting Thickness");
       tagsCollection.insert("0072,0514" ,	"Reformatting Interval");
       tagsCollection.insert("0072,0516" ,	"Reformatting Operation Initial View Direction");
       tagsCollection.insert("0072,0520" ,	"3D Rendering Type");
       tagsCollection.insert("0072,0600" ,	"Sorting Operations Sequence");
       tagsCollection.insert("0072,0602" ,	"Sort-by Category");
       tagsCollection.insert("0072,0604" ,	"Sorting Direction");
       tagsCollection.insert("0072,0700" ,	"Display Set Patient Orientation");
       tagsCollection.insert("0072,0702" ,	"VOI Type");
       tagsCollection.insert("0072,0704" ,	"Pseudo-Color Type");
       tagsCollection.insert("0072,0705" ,	"Pseudo-Color Palette Instance Reference Sequence");
       tagsCollection.insert("0072,0706" ,	"Show Grayscale Inverted");
       tagsCollection.insert("0072,0710" ,	"Show Image True Size Flag");
       tagsCollection.insert("0072,0712" ,	"Show Graphic Annotation Flag");
       tagsCollection.insert("0072,0714" ,	"Show Patient Demographics Flag");
       tagsCollection.insert("0072,0716" ,	"Show Acquisition Techniques Flag");
       tagsCollection.insert("0072,0717" ,	"Display Set Horizontal Justification");
       tagsCollection.insert("0072,0718" ,	"Display Set Vertical Justification");
       tagsCollection.insert("0074,0120" ,	"Continuation Start Meterset");
       tagsCollection.insert("0074,0121" ,	"Continuation End Meterset");
       tagsCollection.insert("0074,1000" ,	"Procedure Step State");
       tagsCollection.insert("0074,1002" ,	"Procedure Step Progress Information Sequence");
       tagsCollection.insert("0074,1004" ,	"Procedure Step Progress");
       tagsCollection.insert("0074,1006" ,	"Procedure Step Progress Description");
       tagsCollection.insert("0074,1008" ,	"Procedure Step Communications URI Sequence");
       tagsCollection.insert("0074,100A" ,	"Contact URI");
       tagsCollection.insert("0074,100C" ,	"Contact Display Name");
       tagsCollection.insert("0074,100E" ,	"Procedure Step Discontinuation Reason Code Sequence");
       tagsCollection.insert("0074,1020" ,	"Beam Task Sequence");
       tagsCollection.insert("0074,1022" ,	"Beam Task Type");
       tagsCollection.insert("0074,1024" ,	"Beam Order Index"); //(Trial)	Retired
       tagsCollection.insert("0074,1025" ,	"Autosequence Flag");
       tagsCollection.insert("0074,1026" ,	"Table Top Vertical Adjusted Position");
       tagsCollection.insert("0074,1027" ,	"Table Top Longitudinal Adjusted Position");
       tagsCollection.insert("0074,1028" ,	"Table Top Lateral Adjusted Position");
       tagsCollection.insert("0074,102A" ,	"Patient Support Adjusted Angle");
       tagsCollection.insert("0074,102B" ,	"Table Top Eccentric Adjusted Angle");
       tagsCollection.insert("0074,102C" ,	"Table Top Pitch Adjusted Angle");
       tagsCollection.insert("0074,102D" ,	"Table Top Roll Adjusted Angle");
       tagsCollection.insert("0074,1030" ,	"Delivery Verification Image Sequence");
       tagsCollection.insert("0074,1032" ,	"Verification Image Timing");
       tagsCollection.insert("0074,1034" ,	"Double Exposure Flag");
       tagsCollection.insert("0074,1036" ,	"Double Exposure Ordering");
       tagsCollection.insert("0074,1038" ,	"Double Exposure Meterset");// (Trial)	Retired
       tagsCollection.insert("0074,103A" ,	"Double Exposure Field Delta");// (Trial)	Retired
       tagsCollection.insert("0074,1040" ,	"Related Reference RT Image Sequence");
       tagsCollection.insert("0074,1042" ,	"General Machine Verification Sequence");
       tagsCollection.insert("0074,1044" ,	"Conventional Machine Verification Sequence");
       tagsCollection.insert("0074,1046" ,	"Ion Machine Verification Sequence");
       tagsCollection.insert("0074,1048" ,	"Failed Attributes Sequence");
       tagsCollection.insert("0074,104A" ,	"Overridden Attributes Sequence");
       tagsCollection.insert("0074,104C" ,	"Conventional Control Point Verification Sequence");
       tagsCollection.insert("0074,104E" ,	"Ion Control Point Verification Sequence");
       tagsCollection.insert("0074,1050" ,	"Attribute Occurrence Sequence");
       tagsCollection.insert("0074,1052" ,	"Attribute Occurrence Pointer");
       tagsCollection.insert("0074,1054" ,	"Attribute Item Selector");
       tagsCollection.insert("0074,1056" ,	"Attribute Occurrence Private Creator");
       tagsCollection.insert("0074,1057" ,	"Selector Sequence Pointer Items");
       tagsCollection.insert("0074,1200" ,	"Scheduled Procedure Step Priority");
       tagsCollection.insert("0074,1202" ,	"Worklist Label");
       tagsCollection.insert("0074,1204" ,	"Procedure Step Label");
       tagsCollection.insert("0074,1210" ,	"Scheduled Processing Parameters Sequence");
       tagsCollection.insert("0074,1212" ,	"Performed Processing Parameters Sequence");
       tagsCollection.insert("0074,1216" ,	"Unified Procedure Step Performed Procedure Sequence");
       tagsCollection.insert("0074,1220" ,	"Related Procedure Step Sequence");	//Retired
       tagsCollection.insert("0074,1222" ,	"Procedure Step Relationship Type");	//Retired
       tagsCollection.insert("0074,1224" ,	"Replaced Procedure Step Sequence");
       tagsCollection.insert("0074,1230" ,	"Deletion Lock");
       tagsCollection.insert("0074,1234" ,	"Receiving AE");
       tagsCollection.insert("0074,1236" ,	"Requesting AE");
       tagsCollection.insert("0074,1238" ,	"Reason for Cancellation");
       tagsCollection.insert("0074,1242" ,	"SCP Status");
       tagsCollection.insert("0074,1244" ,	"Subscription List Status");
       tagsCollection.insert("0074,1246" ,	"Unified Procedure Step List Status");
       tagsCollection.insert("0074,1324" ,	"Beam Order Index");
       tagsCollection.insert("0074,1338" ,	"Double Exposure Meterset");
       tagsCollection.insert("0074,133A" ,	"Double Exposure Field Delta");
       tagsCollection.insert("0074,1401" ,	"Brachy Task Sequence");
       tagsCollection.insert("0074,1402" ,	"Continuation Start Total Reference Air Kerma");
       tagsCollection.insert("0074,1403" ,	"Continuation End Total Reference Air Kerma");
       tagsCollection.insert("0074,1404" ,	"Continuation Pulse Number");
       tagsCollection.insert("0074,1405" ,	"Channel Delivery Order Sequence");
       tagsCollection.insert("0074,1406" ,	"Referenced Channel Number");
       tagsCollection.insert("0074,1407" ,	"Start Cumulative Time Weight");
       tagsCollection.insert("0074,1408" ,	"End Cumulative Time Weight");
       tagsCollection.insert("0074,1409" ,	"Omitted Channel Sequence");
       tagsCollection.insert("0074,140A" ,	"Reason for Channel Omission");
       tagsCollection.insert("0074,140B" ,	"Reason for Channel Omission Description");
       tagsCollection.insert("0074,140C" ,	"Channel Delivery Order Index");
       tagsCollection.insert("0074,140D" ,	"Channel Delivery Continuation Sequence");
       tagsCollection.insert("0074,140E" ,	"Omitted Application Setup Sequence");
       tagsCollection.insert("0076,0001" ,	"Implant Assembly Template Name");
       tagsCollection.insert("0076,0003" ,	"Implant Assembly Template Issuer");
       tagsCollection.insert("0076,0006" ,	"Implant Assembly Template Version");
       tagsCollection.insert("0076,0008" ,	"Replaced Implant Assembly Template Sequence");
       tagsCollection.insert("0076,000A" ,	"Implant Assembly Template Type");
       tagsCollection.insert("0076,000C" ,	"Original Implant Assembly Template Sequence");
       tagsCollection.insert("0076,000E" ,	"Derivation Implant Assembly Template Sequence");
       tagsCollection.insert("0076,0010" ,	"Implant Assembly Template Target Anatomy Sequence");
       tagsCollection.insert("0076,0020" ,	"Procedure Type Code Sequence");
       tagsCollection.insert("0076,0030" ,	"Surgical Technique");
       tagsCollection.insert("0076,0032" ,	"Component Types Sequence");
       tagsCollection.insert("0076,0034" ,	"Component Type Code Sequence");
       tagsCollection.insert("0076,0036" ,	"Exclusive Component Type");
       tagsCollection.insert("0076,0038" ,	"Mandatory Component Type");
       tagsCollection.insert("0076,0040" ,	"Component Sequence");
       tagsCollection.insert("0076,0055" ,	"Component ID");
       tagsCollection.insert("0076,0060" ,	"Component Assembly Sequence");
       tagsCollection.insert("0076,0070" ,	"Component 1 Referenced ID");
       tagsCollection.insert("0076,0080" ,	"Component 1 Referenced Mating Feature Set ID");
       tagsCollection.insert("0076,0090" ,	"Component 1 Referenced Mating Feature ID");
       tagsCollection.insert("0076,00A0" ,	"Component 2 Referenced ID");
       tagsCollection.insert("0076,00B0" ,	"Component 2 Referenced Mating Feature Set ID");
       tagsCollection.insert("0076,00C0" ,	"Component 2 Referenced Mating Feature ID");
       tagsCollection.insert("0078,0001" ,	"Implant Template Group Name");
       tagsCollection.insert("0078,0010" ,	"Implant Template Group Description");
       tagsCollection.insert("0078,0020" ,	"Implant Template Group Issuer");
       tagsCollection.insert("0078,0024" ,	"Implant Template Group Version");
       tagsCollection.insert("0078,0026" ,	"Replaced Implant Template Group Sequence");
       tagsCollection.insert("0078,0028" ,	"Implant Template Group Target Anatomy Sequence");
       tagsCollection.insert("0078,002A" ,	"Implant Template Group Members Sequence");
       tagsCollection.insert("0078,002E" ,	"Implant Template Group Member ID");
       tagsCollection.insert("0078,0050" ,	"3D Implant Template Group Member Matching Point");
       tagsCollection.insert("0078,0060" ,	"3D Implant Template Group Member Matching Axes");
       tagsCollection.insert("0078,0070" ,	"Implant Template Group Member Matching 2D Coordinates Sequence");
       tagsCollection.insert("0078,0090" ,	"2D Implant Template Group Member Matching Point");
       tagsCollection.insert("0078,00A0" ,	"2D Implant Template Group Member Matching Axes");
       tagsCollection.insert("0078,00B0" ,	"Implant Template Group Variation Dimension Sequence");
       tagsCollection.insert("0078,00B2" ,	"Implant Template Group Variation Dimension Name");
       tagsCollection.insert("0078,00B4" ,	"Implant Template Group Variation Dimension Rank Sequence");
       tagsCollection.insert("0078,00B6" ,	"Referenced Implant Template Group Member ID");
       tagsCollection.insert("0078,00B8" ,	"Implant Template Group Variation Dimension Rank");
       tagsCollection.insert("0080,0001" ,	"Surface Scan Acquisition Type Code Sequence");
       tagsCollection.insert("0080,0002" ,	"Surface Scan Mode Code Sequence");
       tagsCollection.insert("0080,0003" ,	"Registration Method Code Sequence");
       tagsCollection.insert("0080,0004" ,	"Shot Duration Time");
       tagsCollection.insert("0080,0005" ,	"Shot Offset Time");
       tagsCollection.insert("0080,0006" ,	"Surface Point Presentation Value Data");
       tagsCollection.insert("0080,0007" ,	"Surface Point Color CIELab Value Data");
       tagsCollection.insert("0080,0008" ,	"UV Mapping Sequence");
       tagsCollection.insert("0080,0009" ,	"Texture Label");
       tagsCollection.insert("0080,0010" ,	"U Value Data");
       tagsCollection.insert("0080,0011" ,	"V Value Data");
       tagsCollection.insert("0080,0012" ,	"Referenced Texture Sequence");
       tagsCollection.insert("0080,0013" ,	"Referenced Surface Data Sequence");
       tagsCollection.insert("0082,0001" ,	"Assessment Summary");
       tagsCollection.insert("0082,0003" ,	"Assessment Summary Description");
       tagsCollection.insert("0082,0004" ,	"Assessed SOP Instance Sequence");
       tagsCollection.insert("0082,0005" ,	"Referenced Comparison SOP Instance Sequence");
       tagsCollection.insert("0082,0006" ,  "Number of Assessment Observations");
       tagsCollection.insert("0082,0007" ,  "Assessment Observations Sequence");
       tagsCollection.insert("0082,0008" ,  "Observation Significance");
       tagsCollection.insert("0082,000A" ,  "Observation Description");
       tagsCollection.insert("0082,000C" ,  "Structured Constraint Observation Sequence");
       tagsCollection.insert("0082,0010" ,  "Assessed Attribute Value Sequence");
       tagsCollection.insert("0082,0016" ,  "Assessment Set ID");
       tagsCollection.insert("0082,0017" ,  "Assessment Requester Sequence");
       tagsCollection.insert("0082,0018" ,  "Selector Attribute Name");
       tagsCollection.insert("0082,0019" ,  "Selector Attribute Keyword");
       tagsCollection.insert("0082,0021" ,  "Assessment Type Code Sequence");
       tagsCollection.insert("0082,0022" ,  "Observation Basis Code Sequence");
       tagsCollection.insert("0082,0023" ,  "Assessment Label");
       tagsCollection.insert("0082,0032" ,  "Constraint Type");
       tagsCollection.insert("0082,0033" ,  "Specification Selection Guidance");
       tagsCollection.insert("0082,0034" ,  "Constraint Value Sequence");
       tagsCollection.insert("0082,0035" ,  "Recommended Default Value Sequence");
       tagsCollection.insert("0082,0036" ,  "Constraint Violation Significance");
       tagsCollection.insert("0082,0037" ,  "Constraint Violation Condition");
       tagsCollection.insert("0088,0130" ,  "Storage Media File-set ID");
       tagsCollection.insert("0088,0140" ,  "Storage Media File-set UID");
       tagsCollection.insert("0088,0200" ,  "Icon Image Sequence");
       tagsCollection.insert("0088,0904" ,  "Topic Title");	//Retired
       tagsCollection.insert("0088,0906" ,  "Topic Subject");	//Retired
       tagsCollection.insert("0088,0910" ,  "Topic Author");	//Retired
       tagsCollection.insert("0088,0912" ,  "Topic Keywords");	//Retired
       tagsCollection.insert("0100,0410" ,  "SOP Instance Status");
       tagsCollection.insert("0100,0420" ,  "SOP Authorization DateTime");
       tagsCollection.insert("0100,0424" ,  "SOP Authorization Comment");
       tagsCollection.insert("0100,0426" ,  "Authorization Equipment Certification Number");
       tagsCollection.insert("0400,0005" ,  "MAC ID Number");
       tagsCollection.insert("0400,0010" ,  "MAC Calculation Transfer Syntax UID");
       tagsCollection.insert("0400,0015" ,  "MAC Algorithm");
       tagsCollection.insert("0400,0020" ,  "Data Elements Signed");
       tagsCollection.insert("0400,0100" ,  "Digital Signature UID");
       tagsCollection.insert("0400,0105" ,  "Digital Signature DateTime");
       tagsCollection.insert("0400,0110" ,  "Certificate Type");
       tagsCollection.insert("0400,0115" ,  "Certificate of Signer");
       tagsCollection.insert("0400,0120" ,  "Signature");
       tagsCollection.insert("0400,0305" ,  "Certified Timestamp Type");
       tagsCollection.insert("0400,0310" ,  "Certified Timestamp");
       tagsCollection.insert("0400,0315" ,  "");	//Retired
       tagsCollection.insert("0400,0401" ,  "Digital Signature Purpose Code Sequence");
       tagsCollection.insert("0400,0402" ,  "Referenced Digital Signature Sequence");
       tagsCollection.insert("0400,0403" ,  "Referenced SOP Instance MAC Sequence");
       tagsCollection.insert("0400,0404" ,  "MAC");
       tagsCollection.insert("0400,0500" ,  "Encrypted Attributes Sequence");
       tagsCollection.insert("0400,0510" ,  "Encrypted Content Transfer Syntax UID");
       tagsCollection.insert("0400,0520" ,  "Encrypted Content");
       tagsCollection.insert("0400,0550" ,  "Modified Attributes Sequence");
       tagsCollection.insert("0400,0561" ,  "Original Attributes Sequence");
       tagsCollection.insert("0400,0562" ,  "Attribute Modification DateTime");
       tagsCollection.insert("0400,0563" ,  "Modifying System");
       tagsCollection.insert("0400,0564" ,  "Source of Previous Values");
       tagsCollection.insert("0400,0565" ,  "Reason for the Attribute Modification");
       tagsCollection.insert("1000,xxx0" ,  "Escape Triplet");	//Retired
       tagsCollection.insert("1000,xxx1" ,  "Run Length Triplet");	//Retired
       tagsCollection.insert("1000,xxx2" ,  "Huffman Table Size");	//Retired
       tagsCollection.insert("1000,xxx3" ,  "Huffman Table Triplet");	//Retired
       tagsCollection.insert("1000,xxx4" ,  "Shift Table Size");	//Retired
       tagsCollection.insert("1000,xxx5" ,  "Shift Table Triplet");	//Retired
       tagsCollection.insert("1010,xxxx" ,  "Zonal Map");	//Retired
       tagsCollection.insert("2000,0010" ,  "Number of Copies");
       tagsCollection.insert("2000,001E" ,  "Printer Configuration Sequence");
       tagsCollection.insert("2000,0020" ,  "Print Priority");
       tagsCollection.insert("2000,0030" ,  "Medium Type");
       tagsCollection.insert("2000,0040" ,  "Film Destination");
       tagsCollection.insert("2000,0050" ,  "Film Session Label");
       tagsCollection.insert("2000,0060" ,  "Memory Allocation");
       tagsCollection.insert("2000,0061" ,  "Maximum Memory Allocation");
       tagsCollection.insert("2000,0062" ,  "Color Image Printing Flag");	//Retired
       tagsCollection.insert("2000,0063" ,  "Collation Flag");	//Retired
       tagsCollection.insert("2000,0065" ,  "Annotation Flag");	//Retired
       tagsCollection.insert("2000,0067" ,  "Image Overlay Flag");	//Retired
       tagsCollection.insert("2000,0069" ,  "Presentation LUT Flag");	//Retired
       tagsCollection.insert("2000,006A" ,  "Image Box Presentation LUT Flag");	//Retired
       tagsCollection.insert("2000,00A0" ,  "Memory Bit Depth");
       tagsCollection.insert("2000,00A1" ,  "Printing Bit Depth");
       tagsCollection.insert("2000,00A2" ,  "Media Installed Sequence");
       tagsCollection.insert("2000,00A4" ,  "Other Media Available Sequence");
       tagsCollection.insert("2000,00A8" ,  "Supported Image Display Formats Sequence");
       tagsCollection.insert("2000,0500" ,  "Referenced Film Box Sequence");
       tagsCollection.insert("2000,0510" ,  "Referenced Stored Print Sequence"); //Retired");
       tagsCollection.insert("2010,0010" ,  "Image Display Format");
       tagsCollection.insert("2010,0030" ,  "Annotation Display Format ID");
       tagsCollection.insert("2010,0040" ,  "Film Orientation");
       tagsCollection.insert("2010,0050" ,  "Film Size ID");
       tagsCollection.insert("2010,0052" ,  "Printer Resolution ID");
       tagsCollection.insert("2010,0054" ,  "Default Printer Resolution ID");
       tagsCollection.insert("2010,0060" ,  "Magnification Type");
       tagsCollection.insert("2010,0080" ,  "Smoothing Type");
       tagsCollection.insert("2010,00A6" ,  "Default Magnification Type");
       tagsCollection.insert("2010,00A7" ,  "Other Magnification Types Available");
       tagsCollection.insert("2010,00A8" ,  "Default Smoothing Type");
       tagsCollection.insert("2010,00A9" ,  "Other Smoothing Types Available");
       tagsCollection.insert("2010,0100" ,  "Border Density");
       tagsCollection.insert("2010,0110" ,  "Empty Image Density");
       tagsCollection.insert("2010,0120" ,  "Min Density");
       tagsCollection.insert("2010,0130" ,  "Max Density");
       tagsCollection.insert("2010,0140" ,  "Trim");
       tagsCollection.insert("2010,0150" ,  "Configuration Information");
       tagsCollection.insert("2010,0152" ,  "Configuration Information Description");
       tagsCollection.insert("2010,0154" ,  "Maximum Collated Films");
       tagsCollection.insert("2010,015E" ,  "Illumination");
       tagsCollection.insert("2010,0160" ,  "Reflected Ambient Light");
       tagsCollection.insert("2010,0376" ,  "Printer Pixel Spacing");
       tagsCollection.insert("2010,0500" ,  "Referenced Film Session Sequence");
       tagsCollection.insert("2010,0510" ,  "Referenced Image Box Sequence");
       tagsCollection.insert("2010,0520" ,  "Referenced Basic Annotation Box Sequence");
       tagsCollection.insert("2020,0010" ,  "Image Box Position");
       tagsCollection.insert("2020,0020" ,  "Polarity");
       tagsCollection.insert("2020,0030" ,  "Requested Image Size");
       tagsCollection.insert("2020,0040" ,  "Requested Decimate/Crop Behavior");
       tagsCollection.insert("2020,0050" ,  "Requested Resolution ID");
       tagsCollection.insert("2020,00A0" ,  "Requested Image Size Flag");
       tagsCollection.insert("2020,00A2" ,  "Decimate/Crop Result");
       tagsCollection.insert("2020,0110" ,  "Basic Grayscale Image Sequence");
       tagsCollection.insert("2020,0111" ,  "Basic Color Image Sequence");
       tagsCollection.insert("2020,0130" ,  "Referenced Image Overlay Box Sequence");	//Retired
       tagsCollection.insert("2020,0140" ,  "Referenced VOI LUT Box Sequence");	//Retired
       tagsCollection.insert("2030,0010" ,  "Annotation Position");
       tagsCollection.insert("2030,0020" ,  "Text String");
       tagsCollection.insert("2040,0010" ,  "Referenced Overlay Plane Sequence");	//Retired
       tagsCollection.insert("2040,0011" ,  "Referenced Overlay Plane Groups");	//Retired
       tagsCollection.insert("2040,0020" ,  "Overlay Pixel Data Sequence");	//Retired
       tagsCollection.insert("2040,0060" ,  "Overlay Magnification Type");	//Retired
       tagsCollection.insert("2040,0070" ,  "Overlay Smoothing Type");//Retired
       tagsCollection.insert("2040,0072" ,  "Overlay or Image Magnification");	//Retired
       tagsCollection.insert("2040,0074" ,  "Magnify to Number of Columns");	//Retired
       tagsCollection.insert("2040,0080" ,  "Overlay Foreground Density");	//Retired
       tagsCollection.insert("2040,0082" ,  "Overlay Background Density");	//Retired
       tagsCollection.insert("2040,0090" ,  "Overlay Mode");	//Retired
       tagsCollection.insert("2040,0100" ,  "Threshold Density");	//Retired
       tagsCollection.insert("2040,0500" ,  "Referenced Image Box Sequence");//(Retired)	Retired
       tagsCollection.insert("2050,0010" ,  "Presentation LUT Sequence");
       tagsCollection.insert("2050,0020" ,  "Presentation LUT Shape");
       tagsCollection.insert("2050,0500" ,  "Referenced Presentation LUT Sequence");
       tagsCollection.insert("2100,0010" ,  "Print Job ID");	//Retired
       tagsCollection.insert("2100,0020" ,  "Execution Status");
       tagsCollection.insert("2100,0030" ,  "Execution Status Info");
       tagsCollection.insert("2100,0040" ,  "Creation Date");
       tagsCollection.insert("2100,0050" ,  "Creation Time");
       tagsCollection.insert("2100,0070" ,  "Originator");
       tagsCollection.insert("2100,0140" ,  "Destination AE");
       tagsCollection.insert("2100,0160" ,  "Owner ID");
       tagsCollection.insert("2100,0170" ,  "Number of Films");
       tagsCollection.insert("2100,0500" ,  "Referenced Print Job Sequence (Pull Stored Print)");	//Retired
       tagsCollection.insert("2110,0010" ,  "Printer Status");
       tagsCollection.insert("2110,0020" ,  "Printer Status Info");
       tagsCollection.insert("2110,0030" ,  "Printer Name");
       tagsCollection.insert("2110,0099" ,  "Print Queue ID");	//Retired
       tagsCollection.insert("2120,0010" ,  "Queue Status");	//Retired
       tagsCollection.insert("2120,0050" ,  "Print Job Description Sequence");	//Retired
       tagsCollection.insert("2120,0070" ,  "Referenced Print Job Sequence");	//Retired
       tagsCollection.insert("2130,0010" ,  "Print Management Capabilities Sequence");	//Retired
       tagsCollection.insert("2130,0015" ,  "Printer Characteristics Sequence");	//Retired
       tagsCollection.insert("2130,0030" ,  "Film Box Content Sequence");//Retired
       tagsCollection.insert("2130,0040" ,  "Image Box Content Sequence");	//Retired
       tagsCollection.insert("2130,0050" ,  "Annotation Content Sequence");	//Retired
       tagsCollection.insert("2130,0060" ,  "Image Overlay Box Content Sequence");	//Retired
       tagsCollection.insert("2130,0080" ,  "Presentation LUT Content Sequence");	//Retired
       tagsCollection.insert("2130,00A0" ,  "Proposed Study Sequence");	//Retired
       tagsCollection.insert("2130,00C0" ,  "Original Image Sequence");	//Retired
       tagsCollection.insert("2200,0001" ,  "Label Using Information Extracted From Instances");
       tagsCollection.insert("2200,0002" ,  "Label Text");
       tagsCollection.insert("2200,0003" ,  "Label Style Selection");
       tagsCollection.insert("2200,0004" ,  "Media Disposition");
       tagsCollection.insert("2200,0005" ,  "Barcode Value");
       tagsCollection.insert("2200,0006" ,  "Barcode Symbology");
       tagsCollection.insert("2200,0007" ,  "Allow Media Splitting");
       tagsCollection.insert("2200,0008" ,  "Include Non-DICOM Objects");
       tagsCollection.insert("2200,0009" ,  "Include Display Application");
       tagsCollection.insert("2200,000A" ,  "Preserve Composite Instances After Media Creation");
       tagsCollection.insert("2200,000B" ,  "Total Number of Pieces of Media Created");
       tagsCollection.insert("2200,000C" ,  "Requested Media Application Profile");
       tagsCollection.insert("2200,000D" ,  "Referenced Storage Media Sequence");
       tagsCollection.insert("2200,000E" ,  "Failure Attributes");
       tagsCollection.insert("2200,000F" ,  "Allow Lossy Compression");
       tagsCollection.insert("2200,0020" ,  "Request Priority");
       tagsCollection.insert("3002,0002" ,  "RT Image Label");
       tagsCollection.insert("3002,0003" ,  "RT Image Name");
       tagsCollection.insert("3002,0004" ,  "RT Image Description");
       tagsCollection.insert("3002,000A" ,  "Reported Values Origin");
       tagsCollection.insert("3002,000C" ,  "RT Image Plane");
       tagsCollection.insert("3002,000D" ,  "X-Ray Image Receptor Translation");
       tagsCollection.insert("3002,000E" ,  "X-Ray Image Receptor Angle");
       tagsCollection.insert("3002,0010" ,  "RT Image Orientation");
       tagsCollection.insert("3002,0011" ,  "Image Plane Pixel Spacing");
       tagsCollection.insert("3002,0012" ,  "RT Image Position");
       tagsCollection.insert("3002,0020" ,  "Radiation Machine Name");
       tagsCollection.insert("3002,0022" ,  "Radiation Machine SAD");
       tagsCollection.insert("3002,0024" ,  "Radiation Machine SSD");
       tagsCollection.insert("3002,0026" ,  "RT Image SID");
       tagsCollection.insert("3002,0028" ,  "Source to Reference Object Distance");
       tagsCollection.insert("3002,0029" ,  "Fraction Number");
       tagsCollection.insert("3002,0030" ,  "Exposure Sequence");
       tagsCollection.insert("3002,0032" ,  "Meterset Exposure");
       tagsCollection.insert("3002,0034" ,  "Diaphragm Position");
       tagsCollection.insert("3002,0040" ,  "Fluence Map Sequence
       tagsCollection.insert("3002,0041" ,  "Fluence Data Source");
       tagsCollection.insert("3002,0042" ,  "Fluence Data Scale");
       tagsCollection.insert("3002,0050" ,  "Primary Fluence Mode Sequence");
       tagsCollection.insert("3002,0051" ,  "Fluence Mode");
       tagsCollection.insert("3002,0052" ,  "Fluence Mode ID");
       tagsCollection.insert("3004,0001" ,  "DVH Type");
       tagsCollection.insert("3004,0002" ,  "Dose Units");
       tagsCollection.insert("3004,0004" ,  "Dose Type");
       tagsCollection.insert("3004,0005" ,  "Spatial Transform of Dose");
       tagsCollection.insert("3004,0006" ,  "Dose Comment");
       tagsCollection.insert("3004,0008" ,  "Normalization Point");
       tagsCollection.insert("3004,000A" ,  "Dose Summation Type");
       tagsCollection.insert("3004,000C" ,  "Grid Frame Offset Vector");
       tagsCollection.insert("3004,000E" ,  "Dose Grid Scaling");
       tagsCollection.insert("3004,0010" ,  "RT Dose ROI Sequence");
       tagsCollection.insert("3004,0012" ,  "Dose Value");
       tagsCollection.insert("3004,0014" ,  "Tissue Heterogeneity Correction");
       tagsCollection.insert("3004,0040" ,  "DVH Normalization Point");
       tagsCollection.insert("3004,0042" ,  "DVH Normalization Dose Value");
       tagsCollection.insert("3004,0050" ,  "DVH Sequence");
       tagsCollection.insert("3004,0052" ,  "DVH Dose Scaling");
       tagsCollection.insert("3004,0054" ,  "DVH Volume Units");
       tagsCollection.insert("3004,0056" ,  "DVH Number of Bins");
       tagsCollection.insert("3004,0058" ,  "DVH Data");
       tagsCollection.insert("3004,0060" ,  "DVH Referenced ROI Sequence");
       tagsCollection.insert("3004,0062" ,  "DVH ROI Contribution Type");
       tagsCollection.insert("3004,0070" ,  "DVH Minimum Dose");
       tagsCollection.insert("3004,0072" ,  "DVH Maximum Dose");
       tagsCollection.insert("3004,0074" ,  "DVH Mean Dose");
       tagsCollection.insert("3006,0002" ,  "Structure Set Label");
       tagsCollection.insert("3006,0004" ,  "Structure Set Name");
       tagsCollection.insert("3006,0006" ,  "Structure Set Description");
       tagsCollection.insert("3006,0008" ,  "Structure Set Date");
       tagsCollection.insert("3006,0009" ,  "Structure Set Time");
       tagsCollection.insert("3006,0010" ,  "Referenced Frame of Reference Sequence");
       tagsCollection.insert("3006,0012" ,  "RT Referenced Study Sequence");
       tagsCollection.insert("3006,0014" ,  "RT Referenced Series Sequence");
       tagsCollection.insert("3006,0016" ,  "Contour Image Sequence");
       tagsCollection.insert("3006,0018" ,  "Predecessor Structure Set Sequence");
       tagsCollection.insert("3006,0020" ,  "Structure Set ROI Sequence");
       tagsCollection.insert("3006,0022" ,  "ROI Number");
       tagsCollection.insert("3006,0024" ,  "Referenced Frame of Reference UID");
       tagsCollection.insert("3006,0026" ,  "ROI Name");
       tagsCollection.insert("3006,0028" ,  "ROI Description");
       tagsCollection.insert("3006,002A" ,  "ROI Display Color");
       tagsCollection.insert("3006,002C" ,  "ROI Volume");
       tagsCollection.insert("3006,0030" ,  "RT Related ROI Sequence");
       tagsCollection.insert("3006,0033" ,  "RT ROI Relationship");
       tagsCollection.insert("3006,0036" ,  "ROI Generation Algorithm");
       tagsCollection.insert("3006,0038" ,  "ROI Generation Description");
       tagsCollection.insert("3006,0039" ,  "ROI Contour Sequence");
       tagsCollection.insert("3006,0040" ,  "Contour Sequence");
       tagsCollection.insert("3006,0042" ,  "Contour Geometric Type");
       tagsCollection.insert("3006,0044" ,  "Contour Slab Thickness");
       tagsCollection.insert("3006,0045" ,  "Contour Offset Vector");
       tagsCollection.insert("3006,0046" ,  "Number of Contour Points");
       tagsCollection.insert("3006,0048" ,  "Contour Number");
       tagsCollection.insert("3006,0049" ,  "Attached Contours");
       tagsCollection.insert("3006,0050" ,  "Contour Data");
       tagsCollection.insert("3006,0080" ,  "RT ROI Observations Sequence");
       tagsCollection.insert("3006,0082" ,  "Observation Number");
       tagsCollection.insert("3006,0084" ,  "Referenced ROI Number");
       tagsCollection.insert("3006,0085" ,  "ROI Observation Label");
       tagsCollection.insert("3006,0086" ,  "RT ROI Identification Code Sequence");
       tagsCollection.insert("3006,0088" ,  "ROI Observation Description");
       tagsCollection.insert("3006,00A0" ,  "Related RT ROI Observations Sequence");
       tagsCollection.insert("3006,00A4" ,  "RT ROI Interpreted Type");
       tagsCollection.insert("3006,00A6" ,  "ROI Interpreter");
       tagsCollection.insert("3006,00B0" ,  "ROI Physical Properties Sequence");
       tagsCollection.insert("3006,00B2" ,  "ROI Physical Property");
       tagsCollection.insert("3006,00B4" ,  "ROI Physical Property Value");
       tagsCollection.insert("3006,00B6" ,  "ROI Elemental Composition Sequence");
       tagsCollection.insert("3006,00B7" ,  "ROI Elemental Composition Atomic Number");
       tagsCollection.insert("3006,00B8" ,  "ROI Elemental Composition Atomic Mass Fraction");
       tagsCollection.insert("3006,00B9" ,  "Additional RT ROI Identification Code Sequence");
       tagsCollection.insert("3006,00C0" ,  "Frame of Reference Relationship Sequence");	//Retired
       tagsCollection.insert("3006,00C2" ,  "Related Frame of Reference UID");	//Retired
       tagsCollection.insert("3006,00C4" ,  "Frame of Reference Transformation Type");//Retired
       tagsCollection.insert("3006,00C6" ,  "Frame of Reference Transformation Matrix");
       tagsCollection.insert("3006,00C8" ,  "Frame of Reference Transformation Comment");
       tagsCollection.insert("3008,0010" ,  "Measured Dose Reference Sequence");
       tagsCollection.insert("3008,0012" ,  "Measured Dose Description");
       tagsCollection.insert("3008,0014" ,  "Measured Dose Type");
       tagsCollection.insert("3008,0016" ,  "Measured Dose Value");
       tagsCollection.insert("3008,0020" ,  "Treatment Session Beam Sequence");
       tagsCollection.insert("3008,0021" ,  "Treatment Session Ion Beam Sequence");
       tagsCollection.insert("3008,0022" ,  "Current Fraction Number");
       tagsCollection.insert("3008,0024" ,  "Treatment Control Point Date");
       tagsCollection.insert("3008,0025" ,  "Treatment Control Point Time");
       tagsCollection.insert("3008,002A" ,  "Treatment Termination Status");
       tagsCollection.insert("3008,002B" ,  "Treatment Termination Code");
       tagsCollection.insert("3008,002C" ,  "Treatment Verification Status");
       tagsCollection.insert("3008,0030" ,  "Referenced Treatment Record Sequence");
       tagsCollection.insert("3008,0032" ,  "Specified Primary Meterset");
       tagsCollection.insert("3008,0033" ,  "Specified Secondary Meterset");
       tagsCollection.insert("3008,0036" ,  "Delivered Primary Meterset");
       tagsCollection.insert("3008,0037" ,  "Delivered Secondary Meterset");
       tagsCollection.insert("3008,003A" ,  "Specified Treatment Time");
       tagsCollection.insert("3008,003B" ,  "Delivered Treatment Time");
       tagsCollection.insert("3008,0040" ,  "Control Point Delivery Sequence");
       tagsCollection.insert("3008,0041" ,  "Ion Control Point Delivery Sequence");
       tagsCollection.insert("3008,0042" ,  "Specified Meterset");
       tagsCollection.insert("3008,0044" ,  "Delivered Meterset");
       tagsCollection.insert("3008,0045" ,  "Meterset Rate Set");
       tagsCollection.insert("3008,0046" ,  "Meterset Rate Delivered");
       tagsCollection.insert("3008,0047" ,  "Scan Spot Metersets Delivered");
       tagsCollection.insert("3008,0048" ,  "Dose Rate Delivered");
       tagsCollection.insert("3008,0050" ,  "Treatment Summary Calculated Dose Reference Sequence");
       tagsCollection.insert("3008,0052" ,  "Cumulative Dose to Dose Reference");
       tagsCollection.insert("3008,0054" ,  "First Treatment Date");
       tagsCollection.insert("3008,0056" ,  "Most Recent Treatment Date");
       tagsCollection.insert("3008,005A" ,  "Number of Fractions Delivered");
       tagsCollection.insert("3008,0060" ,  "Override Sequence");
       tagsCollection.insert("3008,0061" ,  "Parameter Sequence Pointer");
       tagsCollection.insert("3008,0062" ,  "Override Parameter Pointer");
       tagsCollection.insert("3008,0063" ,  "Parameter Item Index");
       tagsCollection.insert("3008,0064" ,  "Measured Dose Reference Number");
       tagsCollection.insert("3008,0065" ,  "Parameter Pointer");
       tagsCollection.insert("3008,0066" ,  "Override Reason");
       tagsCollection.insert("3008,0068" ,  "Corrected Parameter Sequence");
       tagsCollection.insert("3008,006A" ,  "Correction Value");
       tagsCollection.insert("3008,0070" ,  "Calculated Dose Reference Sequence");
       tagsCollection.insert("3008,0072" ,  "Calculated Dose Reference Number");
       tagsCollection.insert("3008,0074" ,  "Calculated Dose Reference Description");
       tagsCollection.insert("3008,0076" ,  "Calculated Dose Reference Dose Value");
       tagsCollection.insert("3008,0078" ,  "Start Meterset");
       tagsCollection.insert("3008,007A" ,  "End Meterset");
       tagsCollection.insert("3008,0080" ,  "Referenced Measured Dose Reference Sequence");
       tagsCollection.insert("3008,0082" ,  "Referenced Measured Dose Reference Number");
       tagsCollection.insert("3008,0090" ,  "Referenced Calculated Dose Reference Sequence");
       tagsCollection.insert("3008,0092" ,  "Referenced Calculated Dose Reference Number");
       tagsCollection.insert("3008,00A0" ,  "Beam Limiting Device Leaf Pairs Sequence");
       tagsCollection.insert("3008,00B0" ,  "Recorded Wedge Sequence");
       tagsCollection.insert("3008,00C0" ,  "Recorded Compensator Sequence");
       tagsCollection.insert("3008,00D0" ,  "Recorded Block Sequence");
       tagsCollection.insert("3008,00E0" ,  "Treatment Summary Measured Dose Reference Sequence");
       tagsCollection.insert("3008,00F0" ,  "Recorded Snout Sequence");
       tagsCollection.insert("3008,00F2" ,  "Recorded Range Shifter Sequence");
       tagsCollection.insert("3008,00F4" ,  "Recorded Lateral Spreading Device Sequence");
       tagsCollection.insert("3008,00F6" ,  "Recorded Range Modulator Sequence");
       tagsCollection.insert("3008,0100" ,  "Recorded Source Sequence");
       tagsCollection.insert("3008,0105" ,  "Source Serial Number");
       tagsCollection.insert("3008,0110" ,  "Treatment Session Application Setup Sequence");
       tagsCollection.insert("3008,0116" ,  "Application Setup Check");
       tagsCollection.insert("3008,0120" ,  "Recorded Brachy Accessory Device Sequence");
       tagsCollection.insert("3008,0122" ,  "Referenced Brachy Accessory Device Number");
       tagsCollection.insert("3008,0130" ,  "Recorded Channel Sequence");
       tagsCollection.insert("3008,0132" ,  "Specified Channel Total Time");
       tagsCollection.insert("3008,0134" ,  "Delivered Channel Total Time");
       tagsCollection.insert("3008,0136" ,  "Specified Number of Pulses");
       tagsCollection.insert("3008,0138" ,  "Delivered Number of Pulses");
       tagsCollection.insert("3008,013A" ,  "Specified Pulse Repetition Interval");
       tagsCollection.insert("3008,013C" ,  "Delivered Pulse Repetition Interval");
       tagsCollection.insert("3008,0140" ,  "Recorded Source Applicator Sequence");
       tagsCollection.insert("3008,0142" ,  "Referenced Source Applicator Number");
       tagsCollection.insert("3008,0150" ,  "Recorded Channel Shield Sequence");
       tagsCollection.insert("3008,0152" ,  "Referenced Channel Shield Number");
       tagsCollection.insert("3008,0160" ,  "Brachy Control Point Delivered Sequence");
       tagsCollection.insert("3008,0162" ,  "Safe Position Exit Date");
       tagsCollection.insert("3008,0164" ,  "Safe Position Exit Time");
       tagsCollection.insert("3008,0166" ,  "Safe Position Return Date");
       tagsCollection.insert("3008,0168" ,  "Safe Position Return Time");
       tagsCollection.insert("3008,0171" ,  "Pulse Specific Brachy Control Point Delivered Sequence");
       tagsCollection.insert("3008,0172" ,  "Pulse Number");
       tagsCollection.insert("3008,0173" ,  "Brachy Pulse Control Point Delivered Sequence");
       tagsCollection.insert("3008,0200" ,  "Current Treatment Status");
       tagsCollection.insert("3008,0202" ,  "Treatment Status Comment");
       tagsCollection.insert("3008,0220" ,  "Fraction Group Summary Sequence");
       tagsCollection.insert("3008,0223" ,  "Referenced Fraction Number");
       tagsCollection.insert("3008,0224" ,  "Fraction Group Type");
       tagsCollection.insert("3008,0230" ,  "Beam Stopper Position");
       tagsCollection.insert("3008,0240" ,  "Fraction Status Summary Sequence");
       tagsCollection.insert("3008,0250" ,  "Treatment Date");
       tagsCollection.insert("3008,0251" ,  "Treatment Time");
       tagsCollection.insert("300A,0002" ,  "RT Plan Label");
       tagsCollection.insert("300A,0003" ,  "RT Plan Name");
       tagsCollection.insert("300A,0004" ,  "RT Plan Description");
       tagsCollection.insert("300A,0006" ,  "RT Plan Date");
       tagsCollection.insert("300A,0007" ,  "RT Plan Time");
       tagsCollection.insert("300A,0009" ,  "Treatment Protocols");
       tagsCollection.insert("300A,000A" ,  "Plan Intent");
       tagsCollection.insert("300A,000B" ,  "Treatment Sites");
       tagsCollection.insert("300A,000C" ,  "RT Plan Geometry");
       tagsCollection.insert("300A,000E" ,  "Prescription Description");
       tagsCollection.insert("300A,0010" ,  "Dose Reference Sequence");
       tagsCollection.insert("300A,0012" ,  "Dose Reference Number");
       tagsCollection.insert("300A,0013" ,  "Dose Reference UID");
       tagsCollection.insert("300A,0014" ,  "Dose Reference Structure Type");
       tagsCollection.insert("300A,0015" ,  "Nominal Beam Energy Unit");
       tagsCollection.insert("300A,0016" ,  "Dose Reference Description");
       tagsCollection.insert("300A,0018" ,  "Dose Reference Point Coordinates");
       tagsCollection.insert("300A,001A" ,  "Nominal Prior Dose");
       tagsCollection.insert("300A,0020" ,  "Dose Reference Type");
       tagsCollection.insert("300A,0021" ,  "Constraint Weight");
       tagsCollection.insert("300A,0022" ,  "Delivery Warning Dose");
       tagsCollection.insert("300A,0023" ,  "Delivery Maximum Dose");
       tagsCollection.insert("300A,0025" ,  "Target Minimum Dose");
       tagsCollection.insert("300A,0026" ,  "Target Prescription Dose");
       tagsCollection.insert("300A,0027" ,  "Target Maximum Dose");
       tagsCollection.insert("300A,0028" ,  "Target Underdose Volume Fraction");
       tagsCollection.insert("300A,002A" ,  "Organ at Risk Full-volume Dose");
       tagsCollection.insert("300A,002B" ,  "Organ at Risk Limit Dose");
       tagsCollection.insert("300A,002C" ,  "Organ at Risk Maximum Dose");
       tagsCollection.insert("300A,002D" ,  "Organ at Risk Overdose Volume Fraction");
       tagsCollection.insert("300A,0040" ,  "Tolerance Table Sequence");
       tagsCollection.insert("300A,0042" ,  "Tolerance Table Number");
       tagsCollection.insert("300A,0043" ,  "Tolerance Table Label");
       tagsCollection.insert("300A,0044" ,  "Gantry Angle Tolerance");
       tagsCollection.insert("300A,0046" ,  "Beam Limiting Device Angle Tolerance");
       tagsCollection.insert("300A,0048" ,  "Beam Limiting Device Tolerance Sequence");
       tagsCollection.insert("300A,004A" ,  "Beam Limiting Device Position Tolerance");
       tagsCollection.insert("300A,004B" ,  "Snout Position Tolerance");
       tagsCollection.insert("300A,004C" ,  "Patient Support Angle Tolerance");
       tagsCollection.insert("300A,004E" ,  "Table Top Eccentric Angle Tolerance");
       tagsCollection.insert("300A,004F" ,  "Table Top Pitch Angle Tolerance");
       tagsCollection.insert("300A,0050" ,  "Table Top Roll Angle Tolerance");
       tagsCollection.insert("300A,0051" ,  "Table Top Vertical Position Tolerance");
       tagsCollection.insert("300A,0052" ,  "Table Top Longitudinal Position Tolerance");
       tagsCollection.insert("300A,0053" ,  "Table Top Lateral Position Tolerance");
       tagsCollection.insert("300A,0055" ,  "RT Plan Relationship");
       tagsCollection.insert("300A,0070" ,  "Fraction Group Sequence");
       tagsCollection.insert("300A,0071" ,  "Fraction Group Number");
       tagsCollection.insert("300A,0072" ,  "Fraction Group Description");
       tagsCollection.insert("300A,0078" ,  "Number of Fractions Planned");
       tagsCollection.insert("300A,0079" ,  "Number of Fraction Pattern Digits Per Day");
       tagsCollection.insert("300A,007A" ,  "Repeat Fraction Cycle Length");
       tagsCollection.insert("300A,007B" ,  "Fraction Pattern");
       tagsCollection.insert("300A,0080" ,  "Number of Beams");
       tagsCollection.insert("300A,0082" ,  "Beam Dose Specification Point");
       tagsCollection.insert("300A,0084" ,  "Beam Dose");
       tagsCollection.insert("300A,0086" ,  "Beam Meterset
       tagsCollection.insert("300A,0088" ,  "Beam Dose Point Depth");	//Retired
       tagsCollection.insert("300A,0089" ,  "Beam Dose Point Equivalent Depth");	//Retired
       tagsCollection.insert("300A,008A" ,  "Beam Dose Point SSD");	//Retired
       tagsCollection.insert("300A,008B" ,  "Beam Dose Meaning");
       tagsCollection.insert("300A,008C" ,  "Beam Dose Verification Control Point Sequence");
       tagsCollection.insert("300A,008D" ,  "Average Beam Dose Point Depth");
       tagsCollection.insert("300A,008E" ,  "Average Beam Dose Point Equivalent Depth");
       tagsCollection.insert("300A,008F" ,  "Average Beam Dose Point SSD");
       tagsCollection.insert("300A,0090" ,  "Beam Dose Type");
       tagsCollection.insert("300A,0091" ,  "Alternate Beam Dose");
       tagsCollection.insert("300A,0092" ,  "Alternate Beam Dose Type");
       tagsCollection.insert("300A,00A0" ,  "Number of Brachy Application Setups");
       tagsCollection.insert("300A,00A2" ,  "Brachy Application Setup Dose Specification Point");
       tagsCollection.insert("300A,00A4" ,  "Brachy Application Setup Dose");
       tagsCollection.insert("300A,00B0" ,  "Beam Sequence");
       tagsCollection.insert("300A,00B2" ,  "Treatment Machine Name");
       tagsCollection.insert("300A,00B3" ,  "Primary Dosimeter Unit");
       tagsCollection.insert("300A,00B4" ,  "Source-Axis Distance");
       tagsCollection.insert("300A,00B6" ,  "Beam Limiting Device Sequence");
       tagsCollection.insert("300A,00B8" ,  "RT Beam Limiting Device Type");
       tagsCollection.insert("300A,00BA" ,  "Source to Beam Limiting Device Distance");
       tagsCollection.insert("300A,00BB" ,  "Isocenter to Beam Limiting Device Distance");
       tagsCollection.insert("300A,00BC" ,  "Number of Leaf/Jaw Pairs");
       tagsCollection.insert("300A,00BE" ,  "Leaf Position Boundaries");
       tagsCollection.insert("300A,00C0" ,  "Beam Number");
       tagsCollection.insert("300A,00C2" ,  "Beam Name");
       tagsCollection.insert("300A,00C3" ,  "Beam Description");
       tagsCollection.insert("300A,00C4" ,  "Beam Type");
       tagsCollection.insert("300A,00C5" ,  "Beam Delivery Duration Limit");
       tagsCollection.insert("300A,00C6" ,  "Radiation Type");
       tagsCollection.insert("300A,00C7" ,  "High-Dose Technique Type");
       tagsCollection.insert("300A,00C8" ,  "Reference Image Number");
       tagsCollection.insert("300A,00CA" ,  "Planned Verification Image Sequence");
       tagsCollection.insert("300A,00CC" ,  "Imaging Device-Specific Acquisition Parameters");
       tagsCollection.insert("300A,00CE" ,  "Treatment Delivery Type");
       tagsCollection.insert("300A,00D0" ,  "Number of Wedges");
       tagsCollection.insert("300A,00D1" ,  "Wedge Sequence");
       tagsCollection.insert("300A,00D2" ,  "Wedge Number");
       tagsCollection.insert("300A,00D3" ,  "Wedge Type");
       tagsCollection.insert("300A,00D4" ,  "Wedge ID");
       tagsCollection.insert("300A,00D5" ,  "Wedge Angle");
       tagsCollection.insert("300A,00D6" ,  "Wedge Factor");
       tagsCollection.insert("300A,00D7" ,  "Total Wedge Tray Water-Equivalent Thickness");
       tagsCollection.insert("300A,00D8" ,  "Wedge Orientation");
       tagsCollection.insert("300A,00D9" ,  "Isocenter to Wedge Tray Distance");
       tagsCollection.insert("300A,00DA" ,  "Source to Wedge Tray Distance");
       tagsCollection.insert("300A,00DB" ,  "Wedge Thin Edge Position");
       tagsCollection.insert("300A,00DC" ,  "Bolus ID");
       tagsCollection.insert("300A,00DD" ,  "Bolus Description");
       tagsCollection.insert("300A,00DE" ,  "Effective Wedge Angle");
       tagsCollection.insert("300A,00E0" ,  "Number of Compensators");
       tagsCollection.insert("300A,00E1" ,  "Material ID");
       tagsCollection.insert("300A,00E2" ,  "Total Compensator Tray Factor");
       tagsCollection.insert("300A,00E3" ,  "Compensator Sequence");
       tagsCollection.insert("300A,00E4" ,  "Compensator Number");
       tagsCollection.insert("300A,00E5" ,  "Compensator ID");
       tagsCollection.insert("300A,00E6" ,  "Source to Compensator Tray Distance");
       tagsCollection.insert("300A,00E7" ,  "Compensator Rows");
       tagsCollection.insert("300A,00E8" ,  "Compensator Columns");
       tagsCollection.insert("300A,00E9" ,  "Compensator Pixel Spacing");
       tagsCollection.insert("300A,00EA" ,  "Compensator Position");
       tagsCollection.insert("300A,00EB" ,  "Compensator Transmission Data");
       tagsCollection.insert("300A,00EC" ,  "Compensator Thickness Data");
       tagsCollection.insert("300A,00ED" ,  "Number of Boli");
       tagsCollection.insert("300A,00EE" ,  "Compensator Type");
       tagsCollection.insert("300A,00EF" ,  "Compensator Tray ID");
       tagsCollection.insert("300A,00F0" ,  "Number of Blocks");
       tagsCollection.insert("300A,00F2" ,  "Total Block Tray Factor");
       tagsCollection.insert("300A,00F3" ,  "Total Block Tray Water-Equivalent Thickness");
       tagsCollection.insert("300A,00F4" ,  "Block Sequence");
       tagsCollection.insert("300A,00F5" ,  "Block Tray ID");
       tagsCollection.insert("300A,00F6" ,  "Source to Block Tray Distance");
       tagsCollection.insert("300A,00F7" ,  "Isocenter to Block Tray Distance");
       tagsCollection.insert("300A,00F8" ,  "Block Type");
       tagsCollection.insert("300A,00F9" ,  "Accessory Code");
       tagsCollection.insert("300A,00FA" ,  "Block Divergence");
       tagsCollection.insert("300A,00FB" ,  "Block Mounting Position");
       tagsCollection.insert("300A,00FC" ,  "Block Number");
       tagsCollection.insert("300A,00FE" ,  "Block Name");
       tagsCollection.insert("300A,0100" ,  "Block Thickness");
       tagsCollection.insert("300A,0102" ,  "Block Transmission");
       tagsCollection.insert("300A,0104" ,  "Block Number of Points");
       tagsCollection.insert("300A,0106" ,  "Block Data");
       tagsCollection.insert("300A,0107" ,  "Applicator Sequence");
       tagsCollection.insert("300A,0108" ,  "Applicator ID");
       tagsCollection.insert("300A,0109" ,  "Applicator Type");
       tagsCollection.insert("300A,010A" ,  "Applicator Description");
       tagsCollection.insert("300A,010C" ,  "Cumulative Dose Reference Coefficient");
       tagsCollection.insert("300A,010E" ,  "Final Cumulative Meterset Weight");
       tagsCollection.insert("300A,0110" ,  "Number of Control Points");
       tagsCollection.insert("300A,0111" ,  "Control Point Sequence");
       tagsCollection.insert("300A,0112" ,  "Control Point Index");
       tagsCollection.insert("300A,0114" ,  "Nominal Beam Energy");
       tagsCollection.insert("300A,0115" ,  "Dose Rate Set");
       tagsCollection.insert("300A,0116" ,  "Wedge Position Sequence");
       tagsCollection.insert("300A,0118" ,  "Wedge Position");
       tagsCollection.insert("300A,011A" ,  "Beam Limiting Device Position Sequence");
       tagsCollection.insert("300A,011C" ,  "Leaf/Jaw Positions");
       tagsCollection.insert("300A,011E" ,  "Gantry Angle");
       tagsCollection.insert("300A,011F" ,  "Gantry Rotation Direction");
       tagsCollection.insert("300A,0120" ,  "Beam Limiting Device Angle");
       tagsCollection.insert("300A,0121" ,  "Beam Limiting Device Rotation Direction");
       tagsCollection.insert("300A,0122" ,  "Patient Support Angle");
       tagsCollection.insert("300A,0123" ,  "Patient Support Rotation Direction");
       tagsCollection.insert("300A,0124" ,  "Table Top Eccentric Axis Distance");
       tagsCollection.insert("300A,0125" ,  "Table Top Eccentric Angle");
       tagsCollection.insert("300A,0126" ,  "Table Top Eccentric Rotation Direction");
       tagsCollection.insert("300A,0128" ,  "Table Top Vertical Position");
       tagsCollection.insert("300A,0129" ,  "Table Top Longitudinal Position");
       tagsCollection.insert("300A,012A" ,  "Table Top Lateral Position");
       tagsCollection.insert("300A,012C" ,  "Isocenter Position");
       tagsCollection.insert("300A,012E" ,  "Surface Entry Point");
       tagsCollection.insert("300A,0130" ,  "Source to Surface Distance");
       tagsCollection.insert("300A,0131" ,  "Average Beam Dose Point Source to External Contour Distance");
       tagsCollection.insert("300A,0132" ,  "Source to External Contour Distance");
       tagsCollection.insert("300A,0133" ,  "External Contour Entry Point");
       tagsCollection.insert("300A,0134" ,  "Cumulative Meterset Weight");
       tagsCollection.insert("300A,0140" ,  "Table Top Pitch Angle");
       tagsCollection.insert("300A,0142" ,  "Table Top Pitch Rotation Direction");
       tagsCollection.insert("300A,0144" ,  "Table Top Roll Angle");
       tagsCollection.insert("300A,0146" ,  "Table Top Roll Rotation Direction");
       tagsCollection.insert("300A,0148" ,  "Head Fixation Angle");
       tagsCollection.insert("300A,014A" ,  "Gantry Pitch Angle");
       tagsCollection.insert("300A,014C" ,  "Gantry Pitch Rotation Direction");
       tagsCollection.insert("300A,014E" ,  "Gantry Pitch Angle Tolerance");
       tagsCollection.insert("300A,0150" ,  "Fixation Eye");
       tagsCollection.insert("300A,0151" ,  "Chair Head Frame Position");
       tagsCollection.insert("300A,0152" ,  "Head Fixation Angle Tolerance");
       tagsCollection.insert("300A,0153" ,  "Chair Head Frame Position Tolerance");
       tagsCollection.insert("300A,0154" ,  "Fixation Light Azimuthal Angle Tolerance");
       tagsCollection.insert("300A,0155" ,  "Fixation Light Polar Angle Tolerance");
       tagsCollection.insert("300A,0180" ,  "Patient Setup Sequence");
       tagsCollection.insert("300A,0182" ,  "Patient Setup Number");
       tagsCollection.insert("300A,0183" ,  "Patient Setup Label");
       tagsCollection.insert("300A,0184" ,  "Patient Additional Position");
       tagsCollection.insert("300A,0190" ,  "Fixation Device Sequence");
       tagsCollection.insert("300A,0192" ,  "Fixation Device Type");
       tagsCollection.insert("300A,0194" ,  "Fixation Device Label");
       tagsCollection.insert("300A,0196" ,  "Fixation Device Description");
       tagsCollection.insert("300A,0198" ,  "Fixation Device Position");
       tagsCollection.insert("300A,0199" ,  "Fixation Device Pitch Angle");
       tagsCollection.insert("300A,019A" ,  "Fixation Device Roll Angle");
       tagsCollection.insert("300A,01A0" ,  "Shielding Device Sequence");
       tagsCollection.insert("300A,01A2" ,  "Shielding Device Type");
       tagsCollection.insert("300A,01A4" ,  "Shielding Device Label");
       tagsCollection.insert("300A,01A6" ,  "Shielding Device Description");
       tagsCollection.insert("300A,01A8" ,  "Shielding Device Position");
       tagsCollection.insert("300A,01B0" ,  "Setup Technique");
       tagsCollection.insert("300A,01B2" ,  "Setup Technique Description");
       tagsCollection.insert("300A,01B4" ,  "Setup Device Sequence");
       tagsCollection.insert("300A,01B6" ,  "Setup Device Type");
       tagsCollection.insert("300A,01B8" ,  "Setup Device Label");
       tagsCollection.insert("300A,01BA" ,  "Setup Device Description");
       tagsCollection.insert("300A,01BC" ,  "Setup Device Parameter");
       tagsCollection.insert("300A,01D0" ,  "Setup Reference Description");
       tagsCollection.insert("300A,01D2" ,  "Table Top Vertical Setup Displacement");
       tagsCollection.insert("300A,01D4" ,  "Table Top Longitudinal Setup Displacement");
       tagsCollection.insert("300A,01D6" ,  "Table Top Lateral Setup Displacement");
       tagsCollection.insert("300A,0200" ,  "Brachy Treatment Technique");
       tagsCollection.insert("300A,0202" ,  "Brachy Treatment Type");
       tagsCollection.insert("300A,0206" ,  "Treatment Machine Sequence");
       tagsCollection.insert("300A,0210" ,  "Source Sequence");
       tagsCollection.insert("300A,0212" ,  "Source Number");
       tagsCollection.insert("300A,0214" ,  "Source Type");
       tagsCollection.insert("300A,0216" ,  "Source Manufacturer");
       tagsCollection.insert("300A,0218" ,  "Active Source Diameter");
       tagsCollection.insert("300A,021A" ,  "Active Source Length");
       tagsCollection.insert("300A,021B" ,  "Source Model ID");
       tagsCollection.insert("300A,021C" ,  "Source Description");
       tagsCollection.insert("300A,0222" ,  "Source Encapsulation Nominal Thickness");
       tagsCollection.insert("300A,0224" ,  "Source Encapsulation Nominal Transmission");
       tagsCollection.insert("300A,0226" ,  "Source Isotope Name");
       tagsCollection.insert("300A,0228" ,  "Source Isotope Half Life");
       tagsCollection.insert("300A,0229" ,  "Source Strength Units");
       tagsCollection.insert("300A,022A" ,  "Reference Air Kerma Rate");
       tagsCollection.insert("300A,022B" ,  "Source Strength");
       tagsCollection.insert("300A,022C" ,  "Source Strength Reference Date");
       tagsCollection.insert("300A,022E" ,  "Source Strength Reference Time");
       tagsCollection.insert("300A,0230" ,  "Application Setup Sequence");
       tagsCollection.insert("300A,0232" ,  "Application Setup Type");
       tagsCollection.insert("300A,0234" ,  "Application Setup Number");
       tagsCollection.insert("300A,0236" ,  "Application Setup Name");
       tagsCollection.insert("300A,0238" ,  "Application Setup Manufacturer");
       tagsCollection.insert("300A,0240" ,  "Template Number");
       tagsCollection.insert("300A,0242" ,  "Template Type");
       tagsCollection.insert("300A,0244" ,  "Template Name");
       tagsCollection.insert("300A,0250" ,  "Total Reference Air Kerma");
       tagsCollection.insert("300A,0260" ,  "Brachy Accessory Device Sequence");
       tagsCollection.insert("300A,0262" ,  "Brachy Accessory Device Number");
       tagsCollection.insert("300A,0263" ,  "Brachy Accessory Device ID");
       tagsCollection.insert("300A,0264" ,  "Brachy Accessory Device Type");
       tagsCollection.insert("300A,0266" ,  "Brachy Accessory Device Name");
       tagsCollection.insert("300A,026A" ,  "Brachy Accessory Device Nominal Thickness");
       tagsCollection.insert("300A,026C" ,  "Brachy Accessory Device Nominal Transmission");
       tagsCollection.insert("300A,0280" ,  "Channel Sequence");
       tagsCollection.insert("300A,0282" ,  "Channel Number");
       tagsCollection.insert("300A,0284" ,  "Channel Length");
       tagsCollection.insert("300A,0286" ,  "Channel Total Time");
       tagsCollection.insert("300A,0288" ,  "Source Movement Type");
       tagsCollection.insert("300A,028A" ,  "Number of Pulses");
       tagsCollection.insert("300A,028C" ,  "Pulse Repetition Interval");
       tagsCollection.insert("300A,0290" ,  "Source Applicator Number");
       tagsCollection.insert("300A,0291" ,  "Source Applicator ID");
       tagsCollection.insert("300A,0292" ,  "Source Applicator Type");
       tagsCollection.insert("300A,0294" ,  "Source Applicator Name");
       tagsCollection.insert("300A,0296" ,  "Source Applicator Length");
       tagsCollection.insert("300A,0298" ,  "Source Applicator Manufacturer");
       tagsCollection.insert("300A,029C" ,  "Source Applicator Wall Nominal Thickness");
       tagsCollection.insert("300A,029E" ,  "Source Applicator Wall Nominal Transmission");
       tagsCollection.insert("300A,02A0" ,  "Source Applicator Step Size");
       tagsCollection.insert("300A,02A2" ,  "Transfer Tube Number");
       tagsCollection.insert("300A,02A4" ,  "Transfer Tube Length");
       tagsCollection.insert("300A,02B0" ,  "Channel Shield Sequence");
       tagsCollection.insert("300A,02B2" ,  "Channel Shield Number");
       tagsCollection.insert("300A,02B3" ,  "Channel Shield ID");
       tagsCollection.insert("300A,02B4" ,  "Channel Shield Name");
       tagsCollection.insert("300A,02B8" ,  "Channel Shield Nominal Thickness");
       tagsCollection.insert("300A,02BA" ,  "Channel Shield Nominal Transmission");
       tagsCollection.insert("300A,02C8" ,  "Final Cumulative Time Weight");
       tagsCollection.insert("300A,02D0" ,  "Brachy Control Point Sequence");
       tagsCollection.insert("300A,02D2" ,  "Control Point Relative Position");
       tagsCollection.insert("300A,02D4" ,  "Control Point 3D Position");
       tagsCollection.insert("300A,02D6" ,  "Cumulative Time Weight");
       tagsCollection.insert("300A,02E0" ,  "Compensator Divergence");
       tagsCollection.insert("300A,02E1" ,  "Compensator Mounting Position");
       tagsCollection.insert("300A,02E2" ,  "Source to Compensator Distance");
       tagsCollection.insert("300A,02E3" ,  "Total Compensator Tray Water-Equivalent Thickness");
       tagsCollection.insert("300A,02E4" ,  "Isocenter to Compensator Tray Distance");
       tagsCollection.insert("300A,02E5" ,  "Compensator Column Offset");
       tagsCollection.insert("300A,02E6" ,  "Isocenter to Compensator Distances");
       tagsCollection.insert("300A,02E7" ,  "Compensator Relative Stopping Power Ratio");
       tagsCollection.insert("300A,02E8" ,  "Compensator Milling Tool Diameter");
       tagsCollection.insert("300A,02EA" ,  "Ion Range Compensator Sequence");
       tagsCollection.insert("300A,02EB" ,  "Compensator Description");
       tagsCollection.insert("300A,0302" ,  "Radiation Mass Number");
       tagsCollection.insert("300A,0304" ,  "Radiation Atomic Number");
       tagsCollection.insert("300A,0306" ,  "Radiation Charge State");
       tagsCollection.insert("300A,0308" ,  "Scan Mode");
       tagsCollection.insert("300A,0309" ,  "Modulated Scan Mode Type");
       tagsCollection.insert("300A,030A" ,  "Virtual Source-Axis Distances");
       tagsCollection.insert("300A,030C" ,  "Snout Sequence");
       tagsCollection.insert("300A,030D" ,  "Snout Position");
       tagsCollection.insert("300A,030F" ,  "Snout ID");
       tagsCollection.insert("300A,0312" ,  "Number of Range Shifters");
       tagsCollection.insert("300A,0314" ,  "Range Shifter Sequence");
       tagsCollection.insert("300A,0316" ,  "Range Shifter Number");
       tagsCollection.insert("300A,0318" ,  "Range Shifter ID");
       tagsCollection.insert("300A,0320" ,  "Range Shifter Type");
       tagsCollection.insert("300A,0322" ,  "Range Shifter Description");
       tagsCollection.insert("300A,0330" ,  "Number of Lateral Spreading Devices");
       tagsCollection.insert("300A,0332" ,  "Lateral Spreading Device Sequence");
       tagsCollection.insert("300A,0334" ,  "Lateral Spreading Device Number");
       tagsCollection.insert("300A,0336" ,  "Lateral Spreading Device ID");
       tagsCollection.insert("300A,0338" ,  "Lateral Spreading Device Type");
       tagsCollection.insert("300A,033A" ,  "Lateral Spreading Device Description");
       tagsCollection.insert("300A,033C" ,  "Lateral Spreading Device Water Equivalent Thickness");
       tagsCollection.insert("300A,0340" ,  "Number of Range Modulators");
       tagsCollection.insert("300A,0342" ,  "Range Modulator Sequence");
       tagsCollection.insert("300A,0344" ,  "Range Modulator Number");
       tagsCollection.insert("300A,0346" ,  "Range Modulator ID");
       tagsCollection.insert("300A,0348" ,  "Range Modulator Type");
       tagsCollection.insert("300A,034A" ,  "Range Modulator Description");
       tagsCollection.insert("300A,034C" ,  "Beam Current Modulation ID");
       tagsCollection.insert("300A,0350" ,  "Patient Support Type");
       tagsCollection.insert("300A,0352" ,  "Patient Support ID");
       tagsCollection.insert("300A,0354" ,  "Patient Support Accessory Code");
       tagsCollection.insert("300A,0355" ,  "Tray Accessory Code");
       tagsCollection.insert("300A,0356" ,  "Fixation Light Azimuthal Angle");
       tagsCollection.insert("300A,0358" ,  "Fixation Light Polar Angle");
       tagsCollection.insert("300A,035A" ,  "Meterset Rate");
       tagsCollection.insert("300A,0360" ,  "Range Shifter Settings Sequence");
       tagsCollection.insert("300A,0362" ,  "Range Shifter Setting");
       tagsCollection.insert("300A,0364" ,  "Isocenter to Range Shifter Distance");
       tagsCollection.insert("300A,0366" ,  "Range Shifter Water Equivalent Thickness");
       tagsCollection.insert("300A,0370" ,  "Lateral Spreading Device Settings Sequence");
       tagsCollection.insert("300A,0372" ,  "Lateral Spreading Device Setting");
       tagsCollection.insert("300A,0374" ,  "Isocenter to Lateral Spreading Device Distance");
       tagsCollection.insert("300A,0380" ,  "Range Modulator Settings Sequence");
       tagsCollection.insert("300A,0382" ,  "Range Modulator Gating Start Value");
       tagsCollection.insert("300A,0384" ,  "Range Modulator Gating Stop Value");
       tagsCollection.insert("300A,0386" ,  "Range Modulator Gating Start Water Equivalent Thickness");
       tagsCollection.insert("300A,0388" ,  "Range Modulator Gating Stop Water Equivalent Thickness");
       tagsCollection.insert("300A,038A" ,  "Isocenter to Range Modulator Distance");
       tagsCollection.insert("300A,0390" ,  "Scan Spot Tune ID");
       tagsCollection.insert("300A,0391" ,  "Scan Spot Prescribed Indices");
       tagsCollection.insert("300A,0392" ,  "Number of Scan Spot Positions");
       tagsCollection.insert("300A,0393" ,  "Scan Spot Reordered");
       tagsCollection.insert("300A,0394" ,  "Scan Spot Position Map");
       tagsCollection.insert("300A,0395" ,  "Scan Spot Reordering Allowed");
       tagsCollection.insert("300A,0396" ,  "Scan Spot Meterset Weights");
       tagsCollection.insert("300A,0398" ,  "Scanning Spot Size");
       tagsCollection.insert("300A,039A" ,  "Number of Paintings");
       tagsCollection.insert("300A,03A0" ,  "Ion Tolerance Table Sequence");
       tagsCollection.insert("300A,03A2" ,  "Ion Beam Sequence");
       tagsCollection.insert("300A,03A4" ,  "Ion Beam Limiting Device Sequence");
       tagsCollection.insert("300A,03A6" ,  "Ion Block Sequence");
       tagsCollection.insert("300A,03A8" ,  "Ion Control Point Sequence");
       tagsCollection.insert("300A,03AA" ,  "Ion Wedge Sequence");
       tagsCollection.insert("300A,03AC" ,  "Ion Wedge Position Sequence");
       tagsCollection.insert("300A,0401" ,  "Referenced Setup Image Sequence");
       tagsCollection.insert("300A,0402" ,  "Setup Image Comment");
       tagsCollection.insert("300A,0410" ,  "Motion Synchronization Sequence");
       tagsCollection.insert("300A,0412" ,  "Control Point Orientation");
       tagsCollection.insert("300A,0420" ,  "General Accessory Sequence");
       tagsCollection.insert("300A,0421" ,  "General Accessory ID");
       tagsCollection.insert("300A,0422" ,  "General Accessory Description");
       tagsCollection.insert("300A,0423" ,  "General Accessory Type");
       tagsCollection.insert("300A,0424" ,  "General Accessory Number");
       tagsCollection.insert("300A,0425" ,  "Source to General Accessory Distance");
       tagsCollection.insert("300A,0431" ,  "Applicator Geometry Sequence");
       tagsCollection.insert("300A,0432" ,  "Applicator Aperture Shape");
       tagsCollection.insert("300A,0433" ,  "Applicator Opening");
       tagsCollection.insert("300A,0434" ,  "Applicator Opening X");
       tagsCollection.insert("300A,0435" ,  "Applicator Opening Y");
       tagsCollection.insert("300A,0436" ,  "Source to Applicator Mounting Position Distance");
       tagsCollection.insert("300A,0440" ,  "Number of Block Slab Items");
       tagsCollection.insert("300A,0441" ,  "Block Slab Sequence");
       tagsCollection.insert("300A,0442" ,  "Block Slab Thickness");
       tagsCollection.insert("300A,0443" ,  "Block Slab Number");
       tagsCollection.insert("300A,0450" ,  "Device Motion Control Sequence");
       tagsCollection.insert("300A,0451" ,  "Device Motion Execution Mode");
       tagsCollection.insert("300A,0452" ,  "Device Motion Observation Mode");
       tagsCollection.insert("300A,0453" ,  "Device Motion Parameter Code Sequence");
       tagsCollection.insert("300A,0501" ,  "Distal Depth Fraction");
       tagsCollection.insert("300A,0502" ,  "Distal Depth");
       tagsCollection.insert("300A,0503" ,  "Nominal Range Modulation Fractions");
       tagsCollection.insert("300A,0504" ,  "Nominal Range Modulated Region Depths");
       tagsCollection.insert("300A,0505" ,  "Depth Dose Parameters Sequence");
       tagsCollection.insert("300A,0506" ,  "Delivered Depth Dose Parameters Sequence");
       tagsCollection.insert("300A,0507" ,  "Delivered Distal Depth Fraction");
       tagsCollection.insert("300A,0508" ,  "Delivered Distal Depth");
       tagsCollection.insert("300A,0509" ,  "Delivered Nominal Range Modulation Fractions");
       tagsCollection.insert("300A,0510" ,  "Delivered Nominal Range Modulated Region Depths");
       tagsCollection.insert("300A,0511" ,  "Delivered Reference Dose Definition");
       tagsCollection.insert("300A,0512" ,  "Reference Dose Definition");
       tagsCollection.insert("300C,0002" ,  "Referenced RT Plan Sequence");
       tagsCollection.insert("300C,0004" ,  "Referenced Beam Sequence");
       tagsCollection.insert("300C,0006" ,  "Referenced Beam Number");
       tagsCollection.insert("300C,0007" ,  "Referenced Reference Image Number");
       tagsCollection.insert("300C,0008" ,  "Start Cumulative Meterset Weight");
       tagsCollection.insert("300C,0009" ,  "End Cumulative Meterset Weight");
       tagsCollection.insert("300C,000A" ,  "Referenced Brachy Application Setup Sequence");
       tagsCollection.insert("300C,000C" ,  "Referenced Brachy Application Setup Number");
       tagsCollection.insert("300C,000E" ,  "Referenced Source Number");
       tagsCollection.insert("300C,0020" ,  "Referenced Fraction Group Sequence");
       tagsCollection.insert("300C,0022" ,  "Referenced Fraction Group Number");
       tagsCollection.insert("300C,0040" ,  "Referenced Verification Image Sequence");
       tagsCollection.insert("300C,0042" ,  "Referenced Reference Image Sequence");
       tagsCollection.insert("300C,0050" ,  "Referenced Dose Reference Sequence");
       tagsCollection.insert("300C,0051" ,  "Referenced Dose Reference Number");
       tagsCollection.insert("300C,0055" ,  "Brachy Referenced Dose Reference Sequence");
       tagsCollection.insert("300C,0060" ,  "Referenced Structure Set Sequence");
       tagsCollection.insert("300C,006A" ,  "Referenced Patient Setup Number");
       tagsCollection.insert("300C,0080" ,  "Referenced Dose Sequence");
       tagsCollection.insert("300C,00A0" ,  "Referenced Tolerance Table Number");
       tagsCollection.insert("300C,00B0" ,  "Referenced Bolus Sequence");
       tagsCollection.insert("300C,00C0" ,  "Referenced Wedge Number");
       tagsCollection.insert("300C,00D0" ,  "Referenced Compensator Number");
       tagsCollection.insert("300C,00E0" ,  "Referenced Block Number");
       tagsCollection.insert("300C,00F0" ,  "Referenced Control Point Index");
       tagsCollection.insert("300C,00F2" ,  "Referenced Control Point Sequence");
       tagsCollection.insert("300C,00F4" ,  "Referenced Start Control Point Index");
       tagsCollection.insert("300C,00F6" ,  "Referenced Stop Control Point Index");
       tagsCollection.insert("300C,0100" ,  "Referenced Range Shifter Number");
       tagsCollection.insert("300C,0102" ,  "Referenced Lateral Spreading Device Number");
       tagsCollection.insert("300C,0104" ,  "Referenced Range Modulator Number");
       tagsCollection.insert("300C,0111" ,  "Omitted Beam Task Sequence");
       tagsCollection.insert("300C,0112" ,  "Reason for Omission");
       tagsCollection.insert("300C,0113" ,  "Reason for Omission Description");
       tagsCollection.insert("300E,0002" ,  "Approval Status");
       tagsCollection.insert("300E,0004" ,  "Review Date");
       tagsCollection.insert("300E,0005" ,  "Review Time");
       tagsCollection.insert("300E,0008" ,  "Reviewer Name");
       tagsCollection.insert("4000,0010" ,  "Arbitrary");	//Retired
       tagsCollection.insert("4000,4000" ,  "Text Comments");	//Retired
       tagsCollection.insert("4008,0040" ,  "Results ID");	//Retired
       tagsCollection.insert("4008,0042" ,  "Results ID Issuer");//Retired
       tagsCollection.insert("4008,0050" ,  "Referenced Interpretation Sequence");	//Retired
       tagsCollection.insert("4008,00FF" ,  "Report Production Status"); //(Trial)	Retired
       tagsCollection.insert("4008,0100" ,  "Interpretation Recorded Date");//Retired
       tagsCollection.insert("4008,0101" ,  "Interpretation Recorded Time");	//Retired
       tagsCollection.insert("4008,0102" ,  "Interpretation Recorder");	//Retired
       tagsCollection.insert("4008,0103" ,  "Reference to Recorded Sound");	//Retired
       tagsCollection.insert("4008,0108" ,  "Interpretation Transcription Date")//Retired
       tagsCollection.insert("4008,0109" ,  "Interpretation Transcription Time");	//Retired
       tagsCollection.insert("4008,010A" ,  "Interpretation Transcriber");	//Retired
       tagsCollection.insert("4008,010B" ,  "Interpretation Text");	//Retired
       tagsCollection.insert("4008,010C" ,  "Interpretation Author");	//Retired
       tagsCollection.insert("4008,0111" ,  "Interpretation Approver Sequence");//Retired
       tagsCollection.insert("4008,0112" ,  "Interpretation Approval Date");	//Retired
       tagsCollection.insert("4008,0113" ,  "Interpretation Approval Time");	//Retired
       tagsCollection.insert("4008,0114" ,  "Physician Approving Interpretation");//Retired
       tagsCollection.insert("4008,0115" ,  "Interpretation Diagnosis Description");	//Retired
       tagsCollection.insert("4008,0117" ,  "Interpretation Diagnosis Code Sequence");//Retired
       tagsCollection.insert("4008,0118" ,  "Results Distribution List Sequence");//Retired
       tagsCollection.insert("4008,0119" ,  "Distribution Name");//Retired
       tagsCollection.insert("4008,011A" ,  "Distribution Address");//Retired
       tagsCollection.insert("4008,0200" ,  "Interpretation ID");	//Retired
       tagsCollection.insert("4008,0202" ,  "Interpretation ID Issuer");	//Retired
       tagsCollection.insert("4008,0210" ,  "Interpretation Type ID");	//Retired
       tagsCollection.insert("4008,0212" ,  "Interpretation Status ID");	//Retired
       tagsCollection.insert("4008,0300" ,  "Impressions");//Retired
       tagsCollection.insert("4008,4000" ,  "Results Comments");//Retired
       tagsCollection.insert("4010,0001" ,  "Low Energy Detectors");
       tagsCollection.insert("4010,0002" ,  "High Energy Detectors");
       tagsCollection.insert("4010,0004" ,  "Detector Geometry Sequence");
       tagsCollection.insert("4010,1001" ,  "Threat ROI Voxel Sequence");
       tagsCollection.insert("4010,1004" ,  "Threat ROI Base");
       tagsCollection.insert("4010,1005" ,  "Threat ROI Extents");
       tagsCollection.insert("4010,1006" ,  "Threat ROI Bitmap");
       tagsCollection.insert("4010,1007" ,  "Route Segment ID");
       tagsCollection.insert("4010,1008" ,  "Gantry Type");
       tagsCollection.insert("4010,1009" ,  "OOI Owner Type");
       tagsCollection.insert("4010,100A" ,  "Route Segment Sequence");
       tagsCollection.insert("4010,1010" ,  "Potential Threat Object ID");
       tagsCollection.insert("4010,1011" ,  "Threat Sequence");
       tagsCollection.insert("4010,1012" ,  "Threat Category");
       tagsCollection.insert("4010,1013" ,  "Threat Category Description");
       tagsCollection.insert("4010,1014" ,  "ATD Ability Assessment");
       tagsCollection.insert("4010,1015" ,  "ATD Assessment Flag");
       tagsCollection.insert("4010,1016" ,  "ATD Assessment Probability");
       tagsCollection.insert("4010,1017" ,  "Mass");
       tagsCollection.insert("4010,1018" ,  "Density");
       tagsCollection.insert("4010,1019" ,  "Z Effective");
       tagsCollection.insert("4010,101A" ,  "Boarding Pass ID");
       tagsCollection.insert("4010,101B" ,  "Center of Mass");
       tagsCollection.insert("4010,101C" ,  "Center of PTO");
       tagsCollection.insert("4010,101D" ,  "Bounding Polygon");
       tagsCollection.insert("4010,101E" ,  "Route Segment Start Location ID");
       tagsCollection.insert("4010,101F" ,  "Route Segment End Location ID");
       tagsCollection.insert("4010,1020" ,  "Route Segment Location ID Type");
       tagsCollection.insert("4010,1021" ,  "Abort Reason");
       tagsCollection.insert("4010,1023" ,  "Volume of PTO");
       tagsCollection.insert("4010,1024" ,  "Abort Flag");
       tagsCollection.insert("4010,1025" ,  "Route Segment Start Time");
       tagsCollection.insert("4010,1026" ,  "Route Segment End Time");
       tagsCollection.insert("4010,1027" ,  "TDR Type");
       tagsCollection.insert("4010,1028" ,  "International Route Segment");
       tagsCollection.insert("4010,1029" ,  "Threat Detection Algorithm and Version");
       tagsCollection.insert("4010,102A" ,  "Assigned Location");
       tagsCollection.insert("4010,102B" ,  "Alarm Decision Time");
       tagsCollection.insert("4010,1031" ,  "Alarm Decision");
       tagsCollection.insert("4010,1033" ,  "Number of Total Objects");
       tagsCollection.insert("4010,1034" ,  "Number of Alarm Objects");
       tagsCollection.insert("4010,1037" ,  "PTO Representation Sequence");
       tagsCollection.insert("4010,1038" ,  "ATD Assessment Sequence");
       tagsCollection.insert("4010,1039" ,  "TIP Type");
       tagsCollection.insert("4010,103A" ,  "Version");
       tagsCollection.insert("4010,1041" ,  "OOI Owner Creation Time");
       tagsCollection.insert("4010,1042" ,  "OOI Type");
       tagsCollection.insert("4010,1043" ,  "OOI Size");
       tagsCollection.insert("4010,1044" ,  "Acquisition Status");
       tagsCollection.insert("4010,1045" ,  "Basis Materials Code Sequence");
       tagsCollection.insert("4010,1046" ,  "Phantom Type");
       tagsCollection.insert("4010,1047" ,  "OOI Owner Sequence");
       tagsCollection.insert("4010,1048" ,  "Scan Type");
       tagsCollection.insert("4010,1051" ,  "Itinerary ID");
       tagsCollection.insert("4010,1052" ,  "Itinerary ID Type");
       tagsCollection.insert("4010,1053" ,  "Itinerary ID Assigning Authority");
       tagsCollection.insert("4010,1054" ,  "Route ID");
       tagsCollection.insert("4010,1055" ,  "Route ID Assigning Authority");
       tagsCollection.insert("4010,1056" ,  "Inbound Arrival Type");
       tagsCollection.insert("4010,1058" ,  "Carrier ID");
       tagsCollection.insert("4010,1059" ,  "Carrier ID Assigning Authority");
       tagsCollection.insert("4010,1060" ,  "Source Orientation");
       tagsCollection.insert("4010,1061" ,  "Source Position");
       tagsCollection.insert("4010,1062" ,  "Belt Height");
       tagsCollection.insert("4010,1064" ,  "Algorithm Routing Code Sequence");
       tagsCollection.insert("4010,1067" ,  "Transport Classification");
       tagsCollection.insert("4010,1068" ,  "OOI Type Descriptor");
       tagsCollection.insert("4010,1069" ,  "Total Processing Time");
       tagsCollection.insert("4010,106C" ,  "Detector Calibration Data");
       tagsCollection.insert("4010,106D" ,  "Additional Screening Performed");
       tagsCollection.insert("4010,106E" ,  "Additional Inspection Selection Criteria");
       tagsCollection.insert("4010,106F" ,  "Additional Inspection Method Sequence");
       tagsCollection.insert("4010,1070" ,  "AIT Device Type");
       tagsCollection.insert("4010,1071" ,  "QR Measurements Sequence");
       tagsCollection.insert("4010,1072" ,  "Target Material Sequence");
       tagsCollection.insert("4010,1073" ,  "SNR Threshold");
       tagsCollection.insert("4010,1075" ,  "Image Scale Representation");
       tagsCollection.insert("4010,1076" ,  "Referenced PTO Sequence");
       tagsCollection.insert("4010,1077" ,  "Referenced TDR Instance Sequence");
       tagsCollection.insert("4010,1078" ,  "PTO Location Description");
       tagsCollection.insert("4010,1079" ,  "Anomaly Locator Indicator Sequence");
       tagsCollection.insert("4010,107A" ,  "Anomaly Locator Indicator");
       tagsCollection.insert("4010,107B" ,  "PTO Region Sequence");
       tagsCollection.insert("4010,107C" ,  "Inspection Selection Criteria");
       tagsCollection.insert("4010,107D" ,  "Secondary Inspection Method Sequence");
       tagsCollection.insert("4010,107E" ,  "PRCS to RCS Orientation");
       tagsCollection.insert("4FFE,0001" ,  "MAC Parameters Sequence");
       tagsCollection.insert("50xx,0005" ,  "Curve Dimensions");	//Retired
       tagsCollection.insert("50xx,0010" ,  "Number of Points");	//Retired
       tagsCollection.insert("50xx,0020" ,  "Type of Data");	//Retired
       tagsCollection.insert("50xx,0022" ,  "Curve Description");	//Retired
       tagsCollection.insert("50xx,0030" ,  "Axis Units");	//Retired
       tagsCollection.insert("50xx,0040" ,  "Axis Labels");//Retired
       tagsCollection.insert("50xx,0103" ,  "Data Value Representation");	//Retired
       tagsCollection.insert("50xx,0104" ,  "Minimum Coordinate Value");	//Retired
       tagsCollection.insert("50xx,0105" ,  "Maximum Coordinate Value");	//Retired
       tagsCollection.insert("50xx,0106" ,  "Curve Range");	//Retired
       tagsCollection.insert("50xx,0110" ,  "Curve Data Descriptor");	//Retired
       tagsCollection.insert("50xx,0112" ,  "Coordinate Start Value");	//Retired
       tagsCollection.insert("50xx,0114" ,  "Coordinate Step Value");	//Retired
       tagsCollection.insert("50xx,1001" ,  "Curve Activation Layer");//Retired
       tagsCollection.insert("50xx,2000" ,  "Audio Type	Retired");
       tagsCollection.insert("50xx,2002" ,  "Audio Sample Format");//Retired
       tagsCollection.insert("50xx,2004" ,  "Number of Channels");	//Retired
       tagsCollection.insert("50xx,2006" ,  "Number of Samples");	//Retired
       tagsCollection.insert("50xx,2008" ,  "Sample Rate");	//Retired
       tagsCollection.insert("50xx,200A" ,  "Total Time");	//Retired
       tagsCollection.insert("50xx,200C" ,  "Audio Sample Data");//Retired
       tagsCollection.insert("50xx,200E" ,  "Audio Comments");	//Retired
       tagsCollection.insert("50xx,2500" ,  "Curve Label");	//Retired
       tagsCollection.insert("50xx,2600" ,  "Curve Referenced Overlay Sequence");	//Retired
       tagsCollection.insert("50xx,2610" ,  "Curve Referenced Overlay Group");	//Retired
       tagsCollection.insert("50xx,3000" ,  "Curve Data");//Retired
       tagsCollection.insert("5200,9229" ,  "Shared Functional Groups Sequence");
       tagsCollection.insert("5200,9230" ,  "Per-frame Functional Groups Sequence");
       tagsCollection.insert("5400,0100" ,  "Waveform Sequence");
       tagsCollection.insert("5400,0110" ,  "Channel Minimum Value");
       tagsCollection.insert("5400,0112" ,  "Channel Maximum Value");
       tagsCollection.insert("5400,1004" ,  "Waveform Bits Allocated");
       tagsCollection.insert("5400,1006" ,  "Waveform Sample Interpretation");
       tagsCollection.insert("5400,100A" ,  "Waveform Padding Value");
       tagsCollection.insert("5400,1010" ,  "Waveform Data");
       tagsCollection.insert("5600,0010" ,  "First Order Phase Correction Angle");
       tagsCollection.insert("5600,0020" ,  "Spectroscopy Data");
       tagsCollection.insert("60xx,0010" ,  "Overlay Rows");
       tagsCollection.insert("60xx,0011" ,  "Overlay Columns");
       tagsCollection.insert("60xx,0012" ,  "Overlay Planes");	//Retired
       tagsCollection.insert("60xx,0015" ,  "Number of Frames in Overlay");
       tagsCollection.insert("60xx,0022" ,  "Overlay Description");
       tagsCollection.insert("60xx,0040" ,  "Overlay Type");
       tagsCollection.insert("60xx,0045" ,  "Overlay Subtype");
       tagsCollection.insert("60xx,0050" ,  "Overlay Origin");
       tagsCollection.insert("60xx,0051" ,  "Image Frame Origin");
       tagsCollection.insert("60xx,0052" ,  "Overlay Plane Origin");	Retired
       tagsCollection.insert("60xx,0060" ,  "Overlay Compression Code");	Retired
       tagsCollection.insert("60xx,0061" ,  "Overlay Compression Originator");	Retired
       tagsCollection.insert("60xx,0062" ,  "Overlay Compression Label");	Retired
       tagsCollection.insert("60xx,0063" ,  "Overlay Compression Description");	Retired
       tagsCollection.insert("60xx,0066" ,  "Overlay Compression Step Pointers");	Retired
       tagsCollection.insert("60xx,0068" ,  "Overlay Repeat Interval");	//Retired
       tagsCollection.insert("60xx,0069" ,  "Overlay Bits Grouped");	//Retired
       tagsCollection.insert("60xx,0100" ,  "Overlay Bits Allocated");
       tagsCollection.insert("60xx,0102" ,  "Overlay Bit Position");
       tagsCollection.insert("60xx,0110" ,  "Overlay Format");//Retired
       tagsCollection.insert("60xx,0200" ,  "Overlay Location");	//Retired
       tagsCollection.insert("60xx,0800" ,  "Overlay Code Label");	//Retired
       tagsCollection.insert("60xx,0802" ,  "Overlay Number of Tables");//	Retired
       tagsCollection.insert("60xx,0803" ,  "Overlay Code Table Location");//Retired
       tagsCollection.insert("60xx,0804" ,  "Overlay Bits For Code Word");	//Retired
       tagsCollection.insert("60xx,1001" ,  "Overlay Activation Layer");
       tagsCollection.insert("60xx,1100" ,  "Overlay Descriptor - Gray");	//Retired
       tagsCollection.insert("60xx,1101" ,  "Overlay Descriptor - Red");	//Retired
       tagsCollection.insert("60xx,1102" ,  "Overlay Descriptor - Green");	//Retired
       tagsCollection.insert("60xx,1103" ,  "Overlay Descriptor - Blue")	//Retired
       tagsCollection.insert("60xx,1200" ,  "Overlays - Gray");	//Retired
       tagsCollection.insert("60xx,1201" ,  "Overlays - Red");	//Retired
       tagsCollection.insert("60xx,1202" ,  "Overlays - Green");	//Retired
       tagsCollection.insert("60xx,1203" ,  "Overlays - Blue");	//Retired
       tagsCollection.insert("60xx,1301" ,  "ROI Area");
       tagsCollection.insert("60xx,1302" ,  "ROI Mean");
       tagsCollection.insert("60xx,1303" ,  "ROI Standard Deviation");
       tagsCollection.insert("60xx,1500" ,  "Overlay Label");
       tagsCollection.insert("60xx,3000" ,  "Overlay Data");
       tagsCollection.insert("60xx,4000" ,  "Overlay Comments");	//Retired
       tagsCollection.insert("7FE0,0008" ,  "Float Pixel Data");
       tagsCollection.insert("7FE0,0009" ,  "Double Float Pixel Data");
       tagsCollection.insert("7FE0,0010" ,  "Pixel Data");
       tagsCollection.insert("7FE0,0020" ,  "Coefficients SDVN");	//Retired
       tagsCollection.insert("7FE0,0030" ,  "Coefficients SDHN");	//Retired
       tagsCollection.insert("7FE0,0040" ,  "Coefficients SDDN");	//Retired
       tagsCollection.insert("7Fxx,0010" ,  "Variable Pixel Data");	//Retired
       tagsCollection.insert("7Fxx,0011" ,  "Variable Next Data Group");	//Retired
       tagsCollection.insert("7Fxx,0020" ,  "Variable Coefficients SDVN");	//Retired
       tagsCollection.insert("7Fxx,0030" ,  "Variable Coefficients SDHN");	//Retired
       tagsCollection.insert("7Fxx,0040" ,  "Variable Coefficients SDDN");	//Retired
       tagsCollection.insert("FFFA,FFFA" ,  "Digital Signatures Sequence");
       tagsCollection.insert("FFFC,FFFC" ,  "Data Set Trailing Padding");
       tagsCollection.insert("FFFE,E000" ,  "Item");
       tagsCollection.insert("FFFE,E00D" ,  "Item Delimitation Item");
       tagsCollection.insert("FFFE,E0DD" ,  "Sequence Delimitation Item");
    }
}
QMap<QString,QString> DICOM_TAGS;





#endif // DICOMTAGLIST_H
