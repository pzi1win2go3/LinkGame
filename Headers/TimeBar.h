#ifndef TIME_BAR_H
#define TIME_BAR_H

// globla viarables for conveniently modifying
double TIME_DECREASE = 0.05;        // value decreases every frame
double TIME_INCREASE = 1;           // reward when a link is done
double TIME_MAXVALUE = 60;          // initialized time value


class TimeBar
{
public:
    TimeBar();                      // constructor

    void init();                    // called when a new game starts

    void passBy();                  // time passes by, called every frame

    void bingo();                   // make time increase, called when a link is done

    double getValue();              // API to private value

private:
    double maxValue;                // max and initialized time

    double value;                   // current time value
};

#endif