#ifndef MAIN_CPP_DUALSHOCK4CONNECTOR_H
#define MAIN_CPP_DUALSHOCK4CONNECTOR_H

#include <stdexcept>
#include <hidapi/hidapi.h>

#include "ConnectionType.h"
#include "../Definitions.h"

struct Connection{
    ConnectionType connectionType;
    hid_device *hidDevice;

    Connection(const ConnectionType connectionType, hid_device *hidDevice){
        this->connectionType = connectionType;
        this->hidDevice = hidDevice;
    }
};

class DualShock4Connector{
private:
    static constexpr const ConnectionType GetConnectionType(hid_device_info *deviceInfo){
        return deviceInfo->interface_number == -1 ? BLUETOOTH : USB;
    }

public:
    static const Connection* GetConnectedDualShock4Device(){
        if(hid_init()){
            throw std::runtime_error("Failed to initialize the HID API\n");
        }

        // The vendor and product ID for a DualShock4 device.
        auto devices = hid_enumerate(DUALSHOCK_VENDOR_ID, DUALSHOCK_PRODUCT_ID);
        if(!devices){
            throw std::runtime_error("No DualShock4 controller found!\n");
        }

        auto connection_type = GetConnectionType(devices);
        auto device = hid_open(
            devices->vendor_id,
            devices->product_id,
            devices->serial_number
        );

        return new Connection(connection_type, device);
    }
};

#endif //MAIN_CPP_DUALSHOCK4CONNECTOR_H
