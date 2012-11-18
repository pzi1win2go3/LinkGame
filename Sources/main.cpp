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
            // 游戏欢迎页面要响应的事件
        } else if (engine->getStatus() == InGame) {
            // 游戏进行页面要响应的事件
        } else if (engine->getStatus() == InFinish) {
            // 游戏结束页面要响应的事件
        } else {
            printf("Something Went Wrong!\n");
            return 0;
        }
    }

    return 0;
}