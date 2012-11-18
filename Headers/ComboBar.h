#ifndef COMBOBAR_H
#define COMBOBAR_H

#include "LinkGame.h"

extern LinkGame *engine;

// globla viarables for conveniently modifying
#define COMBO_DECREASE 0.1                // value decrease every frame
#define COMBO_INCREASE 5				  // value increase when a link is down
#define COMBO_MAXVALUE 100                // the max value that you can reach

class ComboBar
{
public:
    ComboBar();                             // constructor

    void init();                            // called when a new game starts
    
    double getValue();                      // API to private value

    double getMaxValue();                   // API to private max value

    double getHighestValue();               // API to private highest value

    void fallDown();                        // decrease value, called every frame

    void bingo();                           // make bar jump up and update your score, called when a link is down

private:
    double maxValue;                        // the max value you can reach, initialized as MAXVALUE

    double highestValue;                    // the highest value you reach

    double value;                           // current value, initialized as 1, and you score add by this value when a link is done
};

#endif