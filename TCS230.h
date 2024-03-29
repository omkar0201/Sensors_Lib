#ifndef TCS230.h
#define TCS230_h

#include "arduino.h"

class tcs
{
private:
    int S0, S1, S2, S3, ss_data;

public:
    tcs(int S0, int S1, int S2, int S3, int ss_data);
    void Frequency_Scaling(int mode);
    int get_Red_Freq();
    int get_Blue_Freq();
    int get_Green_Freq();
};

#endif