#ifndef MAIN_CPP_DATAPACKET_H
#define MAIN_CPP_DATAPACKET_H

#include "Definitions.h"
#include "ZeroType.h"
#include "FingerPairType.h"


// http://eleccelerator.com/wiki/index.php?title=DualShock_4#HID_INPUT
struct DataPacket {
#if BLUETOOTH
    ZERO<BYTE*2> __0__                  ;                                                                                         // 1 ~ 2
#endif
    unsigned int reportID               : BYTE;                                                                                   // 3
    unsigned int leftStick_X            : BYTE;   // (0 = left)                                                                   // 4
    unsigned int leftStick_Y            : BYTE;   // (0 = up)                                                                     // 5
    unsigned int rightStick_X           : BYTE;   // (0 = left)                                                                   // 6
    unsigned int rightStick_Y           : BYTE;   // (0 = up)                                                                     // 7
    unsigned int arrowPad               : 4;      // (has format, 0x08 is released, 0=N, 1=NE, 2=E, 3=SE, 4=S, 5=SW, 6=W, 7=NW)   // 8
    bool         square                 : 1,
                 cross                  : 1,
                 circle                 : 1,
                 triangle               : 1,
                 l1                     : 1,                                                                                      // 9
                 r1                     : 1,
                 l2                     : 1,
                 r2                     : 1,
                 share                  : 1,
                 option                 : 1,
                 l3                     : 1,
                 r3                     : 1,
                 psButton               : 1,                                                                                      // 10
                 trackpad               : 1;
    unsigned int counter                : 6;
    unsigned int leftTrigger            : BYTE;   // (0 = released, 0xFF = fully pressed)                                         // 11
    unsigned int rightTrigger           : BYTE;   // (0 = released, 0xFF = fully pressed)                                         // 12
    unsigned int timestamp              : BYTE*2;                                                                                 // 13 ~ 14
    unsigned int battery                : BYTE;   // 0x00 - 0xFF                                                                  // 15
    signed int   acceleration_X         : BYTE*2;                                                                                 // 16 ~ 17
    signed int   acceleration_Y         : BYTE*2;                                                                                 // 18 ~ 19
    signed int   acceleration_Z         : BYTE*2;                                                                                 // 20 ~ 21
    signed int   gyroscopeRoll          : BYTE*2;                                                                                 // 22 ~ 23
    signed int   gyroscopeYaw           : BYTE*2;                                                                                 // 24 ~ 25
    signed int   gyroscopePitch         : BYTE*2; // Not sure                                                                     // 26 ~ 27
    ZERO<BYTE*5> __1__                  ;                                                                                         // 28 ~ 32
    unsigned int charging               : 4;      // Not sure                                                                     // 33 ~ 34
    bool         usb                    : 1,
                 mic                    : 1,
                 phone                  : 1,
                 __unknown__            : 1;      // Not sure
    ZERO<BYTE*2> __2__                  ;                                                                                         // 34 ~ 35
    unsigned int trackpadPackets        : BYTE;   // number of trackpad packets (0x00 to 0x04)                                    // 36
    FingerPair   fingerPairData1        ;                                                                                         // 37 ~ 45
    FingerPair   fingerPairData2        ;                                                                                         // 47 ~ 54
    FingerPair   fingerPairData3        ;                                                                                         // 57 ~ 63
    FingerPair   fingerPairData4        ;                                                                                         // 67 ~ 72
    ZERO<BYTE*2> __3__                  ;                                                                                         // 73 ~ 74
    uint32_t     CRC                    : BYTE*4; // TODO: CRC-32 of the first 75 bytes                                           // 75 ~ 78
} __attribute__((packed));

#endif //MAIN_CPP_DATAPACKET_H
