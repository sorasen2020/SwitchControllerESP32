#include "NintendoSwitchControllESP32.h"

NintendoSwitchControllESP32_::NintendoSwitchControllESP32_(void)
{
  memset(&_joystickInputData, 0, sizeof(USB_JoystickReport_Input_t));
}

void NintendoSwitchControllESP32_::begin(void)
{
  CustomHIDDevice().begin();
  USB.PID(0x0092);
  USB.VID(0x0f0d);
}

bool NintendoSwitchControllESP32_::sendReport(void)
{
  return CustomHIDDevice().SendReport(&_joystickInputData, sizeof(USB_JoystickReport_Input_t));
}

void NintendoSwitchControllESP32_::pressButton(Button button_num)
{
  _joystickInputData.Button |= (uint16_t)button_num;
  sendReport();
}

void NintendoSwitchControllESP32_::releaseButton(Button button_num)
{
  _joystickInputData.Button &= ((uint16_t)button_num ^ 0xffff);
  sendReport();
}

void NintendoSwitchControllESP32_::pressHatButton(Hat hat)
{
  _joystickInputData.Hat = (uint8_t)hat;
  sendReport();
}

void NintendoSwitchControllESP32_::releaseHatButton(void)
{
  _joystickInputData.Hat = (uint8_t)Hat::CENTER;
  sendReport();
}

void NintendoSwitchControllESP32_::sendReportOnly(USB_JoystickReport_Input_t t_joystickInputData)
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

void NintendoSwitchControllESP32_::setStickTiltRatio(int16_t lx_per, int16_t ly_per,
                                                     int16_t rx_per, int16_t ry_per)
{
  _joystickInputData.LX = (uint8_t)(lx_per * 0xFF / 200 + 0x80);
  _joystickInputData.LY = (uint8_t)(ly_per * 0xFF / 200 + 0x80);
  _joystickInputData.RX = (uint8_t)(rx_per * 0xFF / 200 + 0x80);
  _joystickInputData.RY = (uint8_t)(ry_per * 0xFF / 200 + 0x80);
  sendReport();
}

NintendoSwitchControllESP32_ &SwitchController(void)
{
  static NintendoSwitchControllESP32_ obj;
  return obj;
}
