#ifndef BODYPART_H
#define BODYPART_H

#include<QObject>
#include<QMetaEnum>

namespace iBEX
{

    Q_NAMESPACE

    /**
     Ref:
     Digital Imaging and Communications in Medicine (DICOM)
     Supplement 32: Digital X-Ray Supplement
     (0018,0015) Body Part Examined
     {
        SKULL, CSPINE, TSPINE, LSPINE,
        SSPINE, COCCYX, CHEST, CLAVICLE,
        BREAST, ABDOMEN, PELVIS, HIP,
        SHOULDER, ELBOW, KNEE, ANKLE,
        HAND, FOOT, EXTREMITY, HEAD,
        HEART, NECK, LEG, ARM, JAW
     }
    */
    enum class BODY_PART {
        HEAD, THORAX, ABDOMEN, PELVIS, FERMUR,
        KNEE, TIBIA,  ANKEL,   FOOT,   HAND,
        FINGER, WRIST,ELBOW,   SCAPULA,SHOULDER
    };
    /* Patient's Sex	(0010,0040) **/
    enum class GENDER
    {
        M,F,O
    };

    /**
     Radiographic view associated with Patient Position (0018,5100).
     For humans:
      Defined Terms:
      AP   Anterior/Posterior
      PA   Posterior/Anterior
      LL   Left Lateral
      RL   Right Lateral
      RLD  Right Lateral Decubitus
      LLD  Left Lateral Decubitus
      RLO  Right Lateral Oblique
      LLO  Left Lateral Oblique
*/
    enum class PATIENT_POSISTION
    {
        AP,PA,LL,RL,RLD,LLD,RLO,LLO
    };

    /*
     *  SCHEDULED,
        INPROGRESS,
        SUSPENDED,
        COMPLETED,
        DISCONTINUED
     */
   enum class STUDY_STATUS
   {
       SCHEDULED,INPROGRESS,SUSPENDED,COMPLETED,DISCONTINUED
   };

    Q_ENUM_NS(BODY_PART);
    Q_ENUM_NS(GENDER);
    Q_ENUM_NS(PATIENT_POSISTION);
    Q_ENUM_NS(STUDY_STATUS);
}

#endif // BODYPART_H
