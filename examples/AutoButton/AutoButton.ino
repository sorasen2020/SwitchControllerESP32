/*
Copyright (c) 2023 sorasen2020
released under the MIT license
https://opensource.org/licenses/mit-license.php
*/

#ifndef ARDUINO_USB_MODE
#error This sketch should be used when USB is in OTG mode
void setup(){}
void loop(){}
#else
#include "SwitchControllerESP32.h"
#include "Arduino.h"
#endif /* ARDUINO_USB_MODE */

void setup() {
  switchcontrolleresp32_init();
  USB.begin();
  switchcontrolleresp32_reset();
}

void loop() {
  pushButton(Button::A, 100, 1);
}
