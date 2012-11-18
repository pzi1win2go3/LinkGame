#ifndef LINK_GAME_H
#define LINK_GAME_H

#include "Board.h"
#include "../Headers/ComboBar.h"
#include "Point.h"
#include "TimeBar.h"
class LinkGame
{
private:
    enum status_t {
        InGame,
        InWelcome,
        InFinish
    } gameStatus;

    Board *board;

    TimeBar *timeBar;

    ComboBar *comboBar;

    int score;

    void init();            // 初始化游戏
public:

    LinkGame();             // 构造函数

    void startGame();       // 开始游戏

    void draw();            // 画图

    int getScore();         // 设置得分

    void setScore(int s);   // 得分

    void reset();           // 重置游戏环境

    void finish();          // 进入游戏结束页

    int getStatus();
};

#endif