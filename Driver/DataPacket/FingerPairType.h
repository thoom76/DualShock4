#ifndef MAIN_CPP_FINGERPAIRTYPE_H
#define MAIN_CPP_FINGERPAIRTYPE_H

#include "../../Definitions.h"
#include "FingerType.h"

struct FingerPair{
    unsigned int packetCounter : BYTE;
    Finger       finger1;
    Finger       finger2;
} __attribute__((packed));

#endif //MAIN_CPP_FINGERPAIRTYPE_H
