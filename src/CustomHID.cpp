/*
Copyright (c) 2023 sorasen2020
released under the MIT license
https://opensource.org/licenses/mit-license.php
*/

#include "CustomHID.h"

CustomHID_::CustomHID_()
{
}

bool CustomHID_::SendReport(const void *data, int len)
{
  return (USBHID::SendReport(0, data, len));
}

CustomHID_ &CustomHID()
{
  static CustomHID_ obj;
  return obj;
}