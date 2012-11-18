#include "TimeBar.h"

TimeBar::TimeBar()
{
    maxValue = value = TIME_MAXVALUE;
}

void TimeBar::init()
{
    maxValue = value = TIME_MAXVALUE;
}

void TimeBar::passBy()
{
    double down = TIME_DECREASE;

    if (value - down < 0)
        value = 0;
    else
        value -= down;
}

void TimeBar::bingo()
{
    double up = TIME_INCREASE;

    if (value + up > maxValue)
        value = maxValue;
    else
        value += up;
}

double TimeBar::getValue()
{
    return value;
}