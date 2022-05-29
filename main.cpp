#include "Driver/DualShock4.h"
#include "Driver/DataPacket/DataPacket.h"
#include "Driver/DualShock4Connector.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"


int main() {
    const Connection* connection = DualShock4Connector::GetConnectedDualShock4Device();

    if (connection->connectionType == BLUETOOTH){
        auto controller = DualShock4<BLUETOOTH>(connection->hidDevice);
        for (unsigned long long i = 0;;i++) {
            controller.ReceiveInputDataPacket();
            if(i%20 == 0){
                controller.PrintDataPacket();
            }
        }
    } else if (connection->connectionType == USB){
        auto controller = DualShock4<USB>(connection->hidDevice);
        for (unsigned long long i = 0;;i++) {
            controller.ReceiveInputDataPacket();
            if(i%20 == 0){
                controller.PrintDataPacket();
            }
        }
    }
}

#pragma clang diagnostic pop