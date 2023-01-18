/*
Copyright (c) 2023 sorasen2020
released under the MIT license
https://opensource.org/licenses/mit-license.php
*/

#pragma once

#include "USB.h"
#include "USBHID.h"

class CustomHID_: public USBHID {
public:
  CustomHID_(void);
  bool SendReport(const void *data, int len);
};

CustomHID_ &CustomHID();
