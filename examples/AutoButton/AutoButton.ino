#ifndef ARDUINO_USB_MODE
#error This sketch should be used when USB is in OTG mode
void setup(){}
void loop(){}
#else
#include "SwitchControllerESP32.h"
#endif /* ARDUINO_USB_MODE */

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  SwitchController().begin();
}

void loop() {
  Serial.println("Button Pressed");
  SwitchController().pressButton(Button::A);
  delay(100);
  SwitchController().releaseButton(Button::A);
  delay(100);
}
