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

    void init();            // ��ʼ����Ϸ
public:
	int welcomeGraph;

    LinkGame();             // ���캯��

    void startGame();       // ��ʼ��Ϸ

    void draw();            // ��ͼ

    int getScore();         // ���õ÷�

    void setScore(int s);   // �÷�

    void reset();           // ������Ϸ����

    void finish();          // ������Ϸ����ҳ

    int getStatus();

    void timerEvent();      // ÿһ֡��Ҫ��������

    Board * getBoard();

	void aboutUs();

	bool timeIsUp();

	void menu();

	void quit();
};

#endif