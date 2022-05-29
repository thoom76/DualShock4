#ifndef MAIN_CPP_DUALSHOCK4_H
#define MAIN_CPP_DUALSHOCK4_H

#include <iostream>
#include <hidapi/hidapi.h>

#include "DataPacket/DataPacket.h"
#include "ConnectionType.h"


template <ConnectionType connectionType>
class DualShock4 {
private:
    hid_device *device;
    DataPacket<connectionType> *packet;

public:
    DualShock4(hid_device *device){
        this->device = device;
        packet = new DataPacket<connectionType>();
    };

    /// Receive the data from the DualShock 4 controller.
    void ReceiveInputDataPacket() {
        hid_read(device, (unsigned char*)packet, sizeof(*packet));
    };

    void PrintDataPacket() {
        packet->PrintDataPacket();
    }

    /// Cleanup
    ~DualShock4(){
        hid_close(device);
        delete packet;
    };
};

#endif //MAIN_CPP_DUALSHOCK4_H
