#include "../Headers/ComboBar.h"

ComboBar::ComboBar()
{
    maxValue = COMBO_MAXVALUE;
    value = highestValue = 1;
}

void ComboBar::init()
{
    maxValue = COMBO_MAXVALUE;
    value = highestValue = 1;
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

void ComboBar::fallDown()
{
    double down = COMBO_DECREASE;

    if (value - down >= 1)
        value -= down;
    else
        value = 1;
}

void ComboBar::bingo()
{
    double up = COMBO_INCREASE;

    int score = engine->getScore() + (int)value;
    engine->setScore(score);

    if (value + up <= maxValue)
        value += up;
    else
        value = maxValue;

    if (value > highestValue)
        highestValue = value;
}