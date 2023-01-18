/*
Copyright (c) 2023 sorasen2020
released under the MIT license
https://opensource.org/licenses/mit-license.php
*/

#pragma once
#include "USBHID.h"
#include "CustomHID.h"

class CustomHIDDevice_: public USBHIDDevice {
public:
  CustomHIDDevice_(void);
  void  begin(void);
  uint16_t _onGetDescriptor(uint8_t* buffer);
};

CustomHIDDevice_ &CustomHIDDevice();
