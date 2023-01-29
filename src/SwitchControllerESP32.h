#pragma one

#include "Arduino.h"
#include "math.h"
#include "NintendoSwitchControllESP32.h"

enum class LS : uint16_t
{
  LS_CENTER     = 0x0000,
  LS_UP         = 0x0001,
  LS_UP_RIGHT   = 0x0002,
  LS_RIGHT      = 0x0003,
  LS_DOWN_RIGHT = 0x0004,
  LS_DOWN       = 0x0005,
  LS_DOWN_LEFT  = 0x0006,
  LS_LEFT       = 0x0007,
  LS_UP_LEFT    = 0x0008
};

enum class RS : uint16_t
{
  RS_CENTER     = 0x0000,
  RS_UP         = 0x0001,
  RS_UP_RIGHT   = 0x0002,
  RS_RIGHT      = 0x0003,
  RS_DOWN_RIGHT = 0x0004,
  RS_DOWN       = 0x0005,
  RS_DOWN_LEFT  = 0x0006,
  RS_LEFT       = 0x0007,
  RS_UP_LEFT    = 0x0008
};

static uint16_t _button_pushing_msec;

void switchcontrolleresp32_init(void);
void switchcontrolleresp32_init(uint16_t button_pushing_msec);
void switchcontrolleresp32_reset(void);
void pushButton(Button button, int delay_after_pushing_msec, int loop_num);
void pushButton2(Button button, int pushing_time_msec, int delay_after_pushing_msec, int loop_num);
void pushHatButton(Hat button, int delay_after_pushing_msec, int loop_num);
void pushHatButtonContinuous(Hat button, int pushing_time_msec);
void tiltJoystick(int lx_per, int ly_per, int rx_per, int ry_per, int tilt_time_msec, int delay_after_tilt_msec);
void sendReportOnly(USB_JoystickReport_Input_t t_joystickInputData);

void UseLStick(LS Lstick, int tilt_time_msec, int delay_after_tilt_msec);
void UseRStick(RS Rstick, int tilt_time_msec, int delay_after_tilt_msec);
void TiltLeftStick(int direction_deg, double power, int holdtime, int delaytime);
