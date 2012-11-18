#ifndef LINK_GAME_H
#define LINK_GAME_H

#include "Board.h"
#include "ComboBar.h"
#include "Point.h"
#include "TimeBar.h"

// 欢迎界面开始游戏按钮
extern int startGameLeftTopX, startGameLeftTopY, startGameRightBottomX, startGameRightBottomY;
// 欢迎界面关于我们按钮
extern int aboutUsLeftTopX, aboutUsLeftTopY, aboutUsRightBottomX, aboutUsRightBottomY;
// 关于我们界面返回欢迎界面的按钮
extern int welcomeLeftTopX, welcomeLeftTopY, welcomeRightBottomX, welcomeRightBottomY;
// 游戏界面退出游戏按钮
extern int finishLeftTopX, finishLeftTopY, finishRightBottomX, finishRightBottomY;
// 游戏界面board的范围
extern int boardLeftTopX, boardLeftTopY, boardRightBottomX, boardRightBottomY;
// 结束界面退出游戏按钮
extern int exitLeftTopX, exitLeftTopY, exitRightBottomX, exitRightBottomY;
// 结束界面重新开始按钮
extern int restartLeftTopX, restartLeftTopY, restartRightBottomX, restartRightBottomY;

class LinkGame
{
private:
    enum status_t {
        InGame,
        InWelcome,
        InFinish,
		InAboutUs
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

    void timerEvent();      // 每一帧都要做的事情

    Board * getBoard();

	void aboutUs();

	bool timeIsUp();
};

#endif