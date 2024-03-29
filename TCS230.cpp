#include "TCS230.h"

tcs::tcs(int S0, int S1, int S2, int S3, int ss_data) : S0(S0), S1(S1), S2(S2), S3(S3), ss_data(ss_data)
{
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(ss_data, INPUT);
}


void tcs :: Frequency_Scaling(int mode)
{
    if (mode == 0)                  // Stall Mode, Frequencies are some constant values as the sensor is a Permenant Enable Sensor
    {
        digitalWrite(S0, LOW);
        digitalWrite(S1, LOW);
    }
    if (mode == 1)                  // Output Frequency --> 2%
    {
        digitalWrite(S0, LOW);
        digitalWrite(S1, HIGH);
    }
    if (mode == 2)                  // Output Frequency --> 20%   
    {
        digitalWrite(S0, HIGH);
        digitalWrite(S1, LOW);
    }
    if (mode == 3)                  // Output Frequency --> 100%
    {
        digitalWrite(S0, HIGH);
        digitalWrite(S1, HIGH);
    }
}
int tcs::get_Red_Freq()
{
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);

    int red = pulseIn(ss_data, LOW);
    red = map(red, 25, 72, 255, 0);
    return (red);
}
int tcs::get_Green_Freq()
{
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);

    int green = pulseIn(ss_data, LOW);
    green = map(green, 30, 90, 255, 0);
    return (green);
}
int tcs::get_Blue_Freq()
{
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);

    int blue = pulseIn(ss_data, LOW);
    blue = map(blue, 25, 70, 255, 0);
    return (blue);
}
