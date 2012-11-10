#ifndef COMBOBAR_H
#define COMBOBAR_H

#define INCREASE 5                          // value increase when a link is down
#define MAXVALUE 100

extern score;

class ComboBar
{
public:
    ComboBar();                                     // constructor

    void init();                                    // called when a new game starts
    
    double getValue();                              // API to private value

    double getMaxValue();                           // API to private max value

    double getHighestValue();                       // API to private highest value

    void fallDown(double down = 0.1);               // decrease value, called every frame

    void bingo();                                   // make bar jump up and update your score, called when a link is down

private:
    double maxValue;                                // max value you can reach, initialized as 100

    double highestValue;                            // the highest value you reach

    double value;                                   // current value, initialized as 1, and you score add by this value when a link is done
};

#endif