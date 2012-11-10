#ifndef COMBOBAR_H
#define COMBOBAR_H

#define INCREASE 5                          // value increase when a link is down
#define MAXVALUE 100

extern score;

class ComboBar
{
public:
    ComboBar();                             // constructor

    init();                                 // called when a new game starts
    
    getValue();                             // API to private value

    getMaxValue();                          // API to private max value

    getHighestValue();                      // API to private highest value

    fallDown(double down = 0.1);            // decrease value, called every frame

    bingo();                                // make bar jump up and update your score, called when a link is down

private:
    double maxValue;                        // max value you can reach, initialized as 100

    double highestValue;                    // the highest value you reach

    double value;                           // current value, initialized as 1, and you score add by this value when a link is done
};

#endif