#include "../Headers/ComboBar.h"

ComboBar::ComboBar()
{
    maxValue = MAXVALUE;
    highestValue = 1;
    value = 1;
}

void ComboBar::init()
{
    maxValue = MAXVALUE;
    highestValue = 1;
    value = 1;
}

double ComboBar::getValue()
{
    return value;
}

double ComboBar::getMaxValue()
{
    return maxValue;
}

double ComboBar::getHighestValue()
{
    return highestValue;
}

void ComboBar::fallDown(double down)
{
    if (value - down >= 1)
        value -= down;
    
    else
        value = 1;
}

void ComboBar::bingo()
{
    score += value;

    if (value + INCREASE <= maxValue)
        value += INCREASE;
    else
        value = maxValue;

    if (value > highestValue)
        highestValue = value;
}