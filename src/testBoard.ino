/* Author: Liam Lawrence
 * Date: 5.28.17
 * Main file for the test board
 */

#include <SoftwareSerial.h>

void setup() {
 bluetoothInit();
 stepperMotorInit();
}

void loop() {
  delay(1000);
}
