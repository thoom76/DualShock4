#ifndef MAIN_CPP_DUALSHOCK4_H
#define MAIN_CPP_DUALSHOCK4_H

#include <iostream>
#include <filesystem>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <bitset>
#include <fstream>
#include <chrono>
#include <thread>
#include "DataPacket/DataPacket.h"


class DualShock4 {
private:
    int deviceInput;
    DataPacket *packet;

private:
    void Init(const char *filePath);

public:
    DualShock4();
    DualShock4(const char *filePath);;

    /// Receive the data from the DualShock 4 controller.
    DataPacket* ReceiveInputDataPacket();

    /// Print the received data packet in a readable format.
    void PrintVariables();

    /// Cleanup
    ~DualShock4();
};

#endif //MAIN_CPP_DUALSHOCK4_H
