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

    Q_ENUM_NS(BODY_PART);
    Q_ENUM_NS(GENDER);
}

#endif // BODYPART_H
