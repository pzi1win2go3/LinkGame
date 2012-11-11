#ifndef TIME_BAR_H
#define TIME_BAR_H

#define DECREASE 0.05               // value decreases every frame
#define INCREASE 1                  // reward when a link is done

class TimeBar
{
public:
    TimeBar(double maxTime);        // constructor

    void passBy();                  // time passes by, called every frame

    void bingo();                   // make time increase, called when a link is done

    double getValue();              // API to private value

private:
    double maxValue;                // max and initialized time

    double value;                   // current time value
};

#endif