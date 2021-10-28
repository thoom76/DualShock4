#include "DualShock4.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

// Need to know if the device is
// connected via USB or Bluetooth.
#define BLUETOOTH false

int main() {
    DualShock4 ps4controller = DualShock4();

    for (unsigned long long i = 0;;i++) {
        ps4controller.ReceiveInputDataPacket();
        if(i%2000000 == 0){
            ps4controller.PrintVariables();
        }
    }
}
#pragma clang diagnostic pop