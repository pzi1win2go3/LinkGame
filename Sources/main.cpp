#include "../Headers/LinkGame.h"
#include <stdio.h>

int score = 0;

enum {InGame, InWelcome, InFinish};

int main()
{
    LinkGame *engine = new LinkGame;

    while (1) {
        engine->draw();

        if (engine->getStatus() == InWelcome) {

        } else if (engine->getStatus() == InGame) {

        } else if (engine->getStatus() == InFinish) {

        } else {
            printf("Something Went Wrong!\n");
            return 0;
        }
    }

    return 0;
}