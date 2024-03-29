#include "TCS230.h"
tcs mySensor(4,5,6,7,8);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  mySensor.Frequency_Scaling(1);
  int Red_F = mySensor.get_Red_Freq();
  Serial.print("R = ");
  Serial.println(Red_F);
  int Blue_F = mySensor.get_Blue_Freq();
  Serial.print("R = ");
  Serial.println(Blue_F);
  int Green_F = mySensor.get_Green_Freq();
  Serial.print("R = ");
  Serial.println(Green_F);
}
