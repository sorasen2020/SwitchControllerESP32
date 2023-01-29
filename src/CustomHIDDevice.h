#pragma once

#include "USBHID.h"

class CustomHIDDevice_: public USBHIDDevice {
  private:
    USBHID hid;
  public:
    CustomHIDDevice_(void);
    void begin(void);
    bool SendReport(const void *data, int len);
    uint16_t _onGetDescriptor(uint8_t* buffer);
};

CustomHIDDevice_ &CustomHIDDevice();
