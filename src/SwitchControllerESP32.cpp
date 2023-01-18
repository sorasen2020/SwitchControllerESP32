/*
Copyright (c) 2023 sorasen2020
released under the MIT license
https://opensource.org/licenses/mit-license.php
*/
#include "SwitchControllerESP32.h"

SwitchControllerESP32_::SwitchControllerESP32_()
{
  memset(&_joystickInputData, 0, sizeof(USB_JoystickReport_Input_t));
}

void SwitchControllerESP32_::begin()
{
  CustomHIDDevice().begin();
  USB.PID(0x0092);
  USB.VID(0x0f0d);
  USB.begin();
  while(!CustomHID().ready());
  setStickTiltRatio(0,0,0,0);
  releaseHatButton();
}

bool SwitchControllerESP32_::sendReport()
{
  return CustomHID().SendReport(&_joystickInputData, sizeof(USB_JoystickReport_Input_t));
}

void SwitchControllerESP32_::pressButton(Button button_num)
{
  _joystickInputData.Button |= (uint16_t)button_num;
  sendReport();
}

void SwitchControllerESP32_::releaseButton(Button button_num)
{
  _joystickInputData.Button &= ((uint16_t)button_num ^ 0xffff);
  sendReport();
}

void SwitchControllerESP32_::pressHatButton(Hat hat)
{
  _joystickInputData.Hat = (uint8_t)hat;
  sendReport();
}

void SwitchControllerESP32_::releaseHatButton()
{
  _joystickInputData.Hat = (uint8_t)Hat::CENTER;
  sendReport();
}

void SwitchControllerESP32_::sendReportOnly(USB_JoystickReport_Input_t t_joystickInputData)
{
  _joystickInputData.Button = t_joystickInputData.Button;
  _joystickInputData.Hat = t_joystickInputData.Hat;
  _joystickInputData.LX = t_joystickInputData.LX;
  _joystickInputData.LY = t_joystickInputData.LY;
  _joystickInputData.RX = t_joystickInputData.RX;
  _joystickInputData.RY = t_joystickInputData.RY;
  _joystickInputData.Dummy = t_joystickInputData.Dummy;
  sendReport();
}

void SwitchControllerESP32_::setStickTiltRatio(int16_t lx_per, int16_t ly_per,
                                          int16_t rx_per, int16_t ry_per)
{
  _joystickInputData.LX = (uint8_t)(lx_per * 0xFF / 200 + 0x80);
  _joystickInputData.LY = (uint8_t)(ly_per * 0xFF / 200 + 0x80);
  _joystickInputData.RX = (uint8_t)(rx_per * 0xFF / 200 + 0x80);
  _joystickInputData.RY = (uint8_t)(ry_per * 0xFF / 200 + 0x80);
  sendReport();
}

SwitchControllerESP32_ &SwitchController()
{
  static SwitchControllerESP32_ obj;
  return obj;
}
