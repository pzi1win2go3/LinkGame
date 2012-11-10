#include 'ComboBar.h'

ComboBar::ComboBar()
{
    maxValue = MAXVALUE;
    highestValue = 1;
    value = 1;
}

ComboBar::init()
{
    maxValue = MAXVALUE;
    highestValue = 1;
    value = 1;
}

ComboBar::getValue()
{
    return value;
}

ComboBar::getMaxValue()
{
    return maxValue;
}

ComboBar::getHighestValue()
{
    return highestValue;
}

ComboBar::fallDown(double down)
{
    if (value - down >= 1)
        value -= down;
    
    else
        value = 1;
}

ComboBar::bingo()
{
    score += value;

    if (value + INCREASE <= maxValue)
        value += INCREASE;
    else
        value = maxValue;

    if (value > highestValue)
        highestValue = value;
}