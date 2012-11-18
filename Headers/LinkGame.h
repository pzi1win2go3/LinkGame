#ifndef LINK_GAME_H
#define LINK_GAME_H

#include "ComboBar.h"
#include "Point.h"
#include "TimeBar.h"
#include "size.h"
#include "Board.h"
#define MAXPIC 8

class LinkGame
{
private:
    enum status_t {
        InGame,
        InWelcome,
        InFinish,
		InAboutUs
    } gameStatus;

	ComboBar *comboBar;

    Board *board;

    TimeBar *timeBar;

    int score;

	int pics[MAXPIC];

    void init();            // 初始化游戏
public:
	int welcomeGraph;

    LinkGame();             // 构造函数

    void startGame();       // 开始游戏

    void draw();            // 画图

    int getScore();         // 设置得分

    void setScore(int s);   // 得分

    void reset();           // 重置游戏环境

    void finish();          // 进入游戏结束页

    int getStatus();

    void timerEvent();      // 每一帧都要做的事情

    Board * getBoard();

	void aboutUs();

	bool timeIsUp();

	void menu();

	void quit();
};

#endif