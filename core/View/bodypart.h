#ifndef BODYPART_H
#define BODYPART_H

#include<QObject>
#include<QMetaEnum>

namespace iBEX
{
    Q_NAMESPACE

    enum class BodyPart {
        HEAD, THORAX, ABDOMEN, PELVIS, FERMUR,
        KNEE, TIBIA,  ANKEL,   FOOT,   HAND,
        FINGER, WRIST,ELBOW,   SCAPULA,SHOULDER
    };

    Q_ENUM_NS(BodyPart);
}

#endif // BODYPART_H
