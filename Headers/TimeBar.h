#ifndef TIME_BAR_H
#define TIME_BAR_H

// globla viarables for conveniently modifying
#define TIME_DECREASE 0.05         // value decreases every frame
#define TIME_INCREASE 1            // reward when a link is done
#define TIME_MAXVALUE 60           // initialized time value


class TimeBar
{
public:
    TimeBar();                      // constructor

    void init();                    // called when a new game starts

    void passBy();                  // time passes by, called every frame

    void bingo();                   // make time increase, called when a link is done

    double getValue();              // API to private value

    double toBonus();               // 剩余的时间能够兑换为多少分数

private:
    double maxValue;                // max and initialized time

    double value;                   // current time value
};

#endif