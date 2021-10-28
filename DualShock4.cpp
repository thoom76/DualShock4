#include "DualShock4.h"

void DualShock4::Init(const char *filePath) {
    deviceInput = open(filePath, O_RDWR | O_NONBLOCK);

    if (deviceInput <= 0) {
        printf("Failed to open hidraw deviceInput\n");
        exit(-1);
    }

    packet = new DataPacket;
}

DualShock4::DualShock4() {
    const char* hidrawDevicePath = "/dev/";
    const char* hidrawClassesPath = "/sys/class/hidraw/";
    const char* hidrawUeventSubPath = "/device/uevent";

    std::string hidrawDevice = "hidraw";

    for (const auto & entry : std::filesystem::directory_iterator(hidrawClassesPath)){
        std::string hidrawUeventPath = entry.path().string().append(hidrawUeventSubPath);

        std::ifstream ueventFile(hidrawUeventPath, std::ifstream::in);

        if (!ueventFile.good()){
            std::cout << "Failed to open hidraw uevent deviceInput: " + hidrawUeventPath + '\n';
            exit(-1);
        }

        std::string driverName;

        std::getline(ueventFile, driverName);

        std::cout << driverName << '\n';

        if(driverName != "DRIVER=sony") {
            continue;
        }

        hidrawDevice += hidrawUeventPath[hidrawUeventPath.rfind(hidrawDevice) + hidrawDevice.length()];
        Init(std::string(hidrawDevicePath).append(hidrawDevice).c_str());
    }

    std::cout << "Did not find a connected controller!\n";
}

DualShock4::DualShock4(const char *filePath) {
    Init(filePath);
}

DataPacket *DualShock4::ReceiveInputDataPacket() {
    read(deviceInput, packet, sizeof(*packet));
    return packet;
}

void DualShock4::PrintVariables() {
    // Clear the screen before printing.
    std::cout << "\033[2J\033[1;1H";
    // The variables of the controller.
    std::cout << "ReportID:\t\t" << packet->reportID << '\n'
              << "LeftStick_X:\t\t" << packet->leftStick_X << '\n'
              << "LeftStick_Y:\t\t" << packet->leftStick_Y << '\n'
              << "RightStick_X:\t\t" << packet->rightStick_X << '\n'
              << "RightStick_Y:\t\t" << packet->rightStick_Y << '\n'
              << "arrowPad:\t\t" << packet->arrowPad << '\n'
              << "square:\t\t\t" << packet->square << '\n'
              << "cross:\t\t\t" << packet->cross << '\n'
              << "circle:\t\t\t" << packet->circle << '\n'
              << "triangle:\t\t" << packet->triangle << '\n'
              << "l1:\t\t\t" << packet->l1 << '\n'
              << "r1:\t\t\t" << packet->r1 << '\n'
              << "l2:\t\t\t" << packet->l2 << '\n'
              << "r2:\t\t\t" << packet->r2 << '\n'
              << "share:\t\t\t" << packet->share << '\n'
              << "option:\t\t\t" << packet->option << '\n'
              << "l3:\t\t\t" << packet->l3 << '\n'
              << "r3:\t\t\t" << packet->r3 << '\n'
              << "psButton:\t\t" << packet->psButton << '\n'
              << "trackpad:\t\t" << packet->trackpad << '\n'
              << "counter:\t\t" << packet->counter << '\n'
              << "leftTrigger:\t\t" << packet->leftTrigger << '\n'
              << "rightTrigger:\t\t" << packet->rightTrigger << '\n'
              << "timestamp:\t\t" << packet->timestamp << '\n'
              << "battery:\t\t" << packet->battery << '\n'
              << "acceleration_X:\t\t" << packet->acceleration_X << '\n'
              << "acceleration_Y:\t\t" << packet->acceleration_Y << '\n'
              << "acceleration_Z:\t\t" << packet->acceleration_Z << '\n'
              << "gyroscopeRoll:\t\t" << packet->gyroscopeRoll << '\n'
              << "gyroscopeYaw:\t\t" << packet->gyroscopeYaw << '\n'
              << "gyroscopePitch:\t\t" << packet->gyroscopePitch << '\n'
              << "charging:\t\t" << packet->charging << '\n'
              << "usb:\t\t\t" << packet->usb << '\n'
              << "mic:\t\t\t" << packet->mic << '\n'
              << "phone:\t\t\t" << packet->phone << '\n'
              << "__unknown__:\t\t" << packet->__unknown__ << '\n'
              << "trackpadPackets:\t" << packet->trackpadPackets << '\n'
              << "Packet 1:\n" <<
              "  Packet counter: " << packet->fingerPairData1.packetCounter << '\n' <<
              "    Finger 1:\n" <<
              "      *FingerId: " << packet->fingerPairData1.finger1.fingerId << '\n' <<
              "      *Active: " << !packet->fingerPairData1.finger1.fingerActive << '\n' <<
              "      *Coordinates: (" << packet->fingerPairData1.finger1.fingerCoordinates1 << ',' << packet->fingerPairData1.finger1.fingerCoordinates2 << ")\n" <<
              "    Finger 2:\n" <<
              "      *FingerId: " << packet->fingerPairData1.finger2.fingerId << '\n' <<
              "      *Active: " << !packet->fingerPairData1.finger2.fingerActive << '\n' <<
              "      *Coordinates: (" << packet->fingerPairData1.finger2.fingerCoordinates1 << ',' << packet->fingerPairData1.finger2.fingerCoordinates2 << ")\n";
}

DualShock4::~DualShock4() {
    delete packet;
}
