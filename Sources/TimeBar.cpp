#include "../Headers/TimeBar.h"

TimeBar::TimeBar(double maxTime)
{
    maxValue = value = maxTime;
}

void TimeBar::passBy()
{
    if (value - DECREASE < 0)
        value = 0;
    else
        value -= DECREASE;
}

void TimeBar::bingo()
{
    if (value + INCREASE > maxValue)
        value = maxValue;
    else
        value += INCREASE;
}

double TimeBar::getValue()
{
    return value;
}