#ifndef MAIN_CPP_DATAPACKET_H
#define MAIN_CPP_DATAPACKET_H

#include <iostream>
#include <cstdint>
#include "../../Definitions.h"
#include "ZeroType.h"
#include "FingerPairType.h"
#include "../ConnectionType.h"


template <ConnectionType connectionType, typename PRE_BYTES = ZERO_BYTES<connectionType == BLUETOOTH ? 2 : 0>>
struct DataPacket {
    PRE_BYTES     __PRE_BYTES__          ;
    unsigned int  reportID               : BYTE;                                                                                   // 3
    unsigned int  leftStick_X            : BYTE;   // (0 = left)                                                                   // 4
    unsigned int  leftStick_Y            : BYTE;   // (0 = up)                                                                     // 5
    unsigned int  rightStick_X           : BYTE;   // (0 = left)                                                                   // 6
    unsigned int  rightStick_Y           : BYTE;   // (0 = up)                                                                     // 7
    unsigned int  arrowPad               : 4;      // (has format, 0x08 is released, 0=N, 1=NE, 2=E, 3=SE, 4=S, 5=SW, 6=W, 7=NW)   // 8
    bool          square                 : 1,
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
    unsigned int  counter                : 6;
    unsigned int  leftTrigger            : BYTE;   // (0 = released, 0xFF = fully pressed)                                         // 11
    unsigned int  rightTrigger           : BYTE;   // (0 = released, 0xFF = fully pressed)                                         // 12
    unsigned int  timestamp              : BYTE*2;                                                                                 // 13 ~ 14
    unsigned int  battery                : BYTE;   // 0x00 - 0xFF                                                                  // 15
    signed int    acceleration_X         : BYTE*2;                                                                                 // 16 ~ 17
    signed int    acceleration_Y         : BYTE*2;                                                                                 // 18 ~ 19
    signed int    acceleration_Z         : BYTE*2;                                                                                 // 20 ~ 21
    signed int    gyroscopeRoll          : BYTE*2;                                                                                 // 22 ~ 23
    signed int    gyroscopeYaw           : BYTE*2;                                                                                 // 24 ~ 25
    signed int    gyroscopePitch         : BYTE*2; // Not sure                                                                     // 26 ~ 27
    ZERO_BYTES<5> __1__                  ;                                                                                         // 28 ~ 32
    unsigned int  charging               : 4;      // Not sure                                                                     // 33 ~ 34
    bool          usb                    : 1,
                  mic                    : 1,
                  phone                  : 1,
                  __unknown__            : 1;      // Not sure
    ZERO_BYTES<2> __2__                  ;                                                                                         // 34 ~ 35
    unsigned int  trackpadPackets        : BYTE;   // number of trackpad packets (0x00 to 0x04)                                    // 36
    FingerPair    fingerPairData1        ;                                                                                         // 37 ~ 45
    FingerPair    fingerPairData2        ;                                                                                         // 47 ~ 54
    FingerPair    fingerPairData3        ;                                                                                         // 57 ~ 63
    FingerPair    fingerPairData4        ;                                                                                         // 67 ~ 72
    ZERO_BYTES<2> __3__                  ;                                                                                         // 73 ~ 74
    uint32_t      CRC                    : BYTE*4; // TODO: CRC-32 of the first 75 bytes                                           // 75 ~ 78

    void PrintDataPacket() {
        // Clear the screen before printing.
        std::cout << "\033[2J\033[1;1H";
        // The variables of the controller.
        std::cout << "ReportID:\t\t" << reportID << '\n'
                  << "LeftStick_X:\t\t" << leftStick_X << '\n'
                  << "LeftStick_Y:\t\t" << leftStick_Y << '\n'
                  << "RightStick_X:\t\t" << rightStick_X << '\n'
                  << "RightStick_Y:\t\t" << rightStick_Y << '\n'
                  << "arrowPad:\t\t" << arrowPad << '\n'
                  << "square:\t\t\t" << square << '\n'
                  << "cross:\t\t\t" << cross << '\n'
                  << "circle:\t\t\t" << circle << '\n'
                  << "triangle:\t\t" << triangle << '\n'
                  << "l1:\t\t\t" << l1 << '\n'
                  << "r1:\t\t\t" << r1 << '\n'
                  << "l2:\t\t\t" << l2 << '\n'
                  << "r2:\t\t\t" << r2 << '\n'
                  << "share:\t\t\t" << share << '\n'
                  << "option:\t\t\t" << option << '\n'
                  << "l3:\t\t\t" << l3 << '\n'
                  << "r3:\t\t\t" << r3 << '\n'
                  << "psButton:\t\t" << psButton << '\n'
                  << "trackpad:\t\t" << trackpad << '\n'
                  << "counter:\t\t" << counter << '\n'
                  << "leftTrigger:\t\t" << leftTrigger << '\n'
                  << "rightTrigger:\t\t" << rightTrigger << '\n'
                  << "timestamp:\t\t" << timestamp << '\n'
                  << "battery:\t\t" << battery << '\n'
                  << "acceleration_X:\t\t" << acceleration_X << '\n'
                  << "acceleration_Y:\t\t" << acceleration_Y << '\n'
                  << "acceleration_Z:\t\t" << acceleration_Z << '\n'
                  << "gyroscopeRoll:\t\t" << gyroscopeRoll << '\n'
                  << "gyroscopeYaw:\t\t" << gyroscopeYaw << '\n'
                  << "gyroscopePitch:\t\t" << gyroscopePitch << '\n'
                  << "charging:\t\t" << charging << '\n'
                  << "usb:\t\t\t" << usb << '\n'
                  << "mic:\t\t\t" << mic << '\n'
                  << "phone:\t\t\t" << phone << '\n'
                  << "__unknown__:\t\t" << __unknown__ << '\n'
                  << "trackpadPackets:\t" << trackpadPackets << '\n'
                  << "Packet 1:\n" <<
                  "  Packet counter: " << fingerPairData1.packetCounter << '\n' <<
                  "    Finger 1:\n" <<
                  "      *FingerId: " << fingerPairData1.finger1.fingerId << '\n' <<
                  "      *Active: " << !fingerPairData1.finger1.fingerActive << '\n' <<
                  "      *Coordinates: (" << fingerPairData1.finger1.fingerCoordinates1 << ',' << fingerPairData1.finger1.fingerCoordinates2 << ")\n" <<
                  "    Finger 2:\n" <<
                  "      *FingerId: " << fingerPairData1.finger2.fingerId << '\n' <<
                  "      *Active: " << !fingerPairData1.finger2.fingerActive << '\n' <<
                  "      *Coordinates: (" << fingerPairData1.finger2.fingerCoordinates1 << ',' << fingerPairData1.finger2.fingerCoordinates2 << ")\n";
    }
} __attribute__((packed));


#endif //MAIN_CPP_DATAPACKET_H
