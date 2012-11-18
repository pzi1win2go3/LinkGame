#include "LinkGame.h"
#include "DxLib.h"
#include "stdio.h"

LinkGame::LinkGame()
{
    init();
	char filename[10] = {};

	for (int i = 0; i < 8; i++) {
		sprintf(filename, "%d.png", i);
		pics[i] = LoadGraph(filename);
	}
}

void LinkGame::startGame() {
    gameStatus = InGame;
}

int LinkGame::getScore() {
    return score;
}

void LinkGame::setScore(int s) {
    score = s;
}

bool LinkGame::timeIsUp() {
    return (timeBar->getValue() < 1.0E-6);
}

void LinkGame::draw() {
	int MouseX, MouseY;
	GetMousePoint(&MouseX, &MouseY);
	
	ClearDrawScreen();
	
	if (gameStatus == InWelcome) {
		LoadGraphScreen(0, 0, "welcome.png", true);
	} else if (gameStatus == InGame) {
		LoadGraphScreen(0, 0, "game.png", true);
		
		for (int i = 1; i <= board->getHeight(); i++) {
			for (int j = 1; j <= board->getLength(); j++) {
				DrawGraph(Point(i, j).toX(), Point(i, j).toY(), pics[board->getVal(Point(i, j))], true);
			}
		}
	} else if (gameStatus == InAboutUs) {
		LoadGraphScreen(0, 0, "about.png", true);
	} else if (gameStatus == InFinish) {
		LoadGraphScreen(0, 0, "win.png", true);	
	}

	DrawFormatString(0, 0, GetColor(255, 255, 255), "(%d, %d) ON %d", MouseX, MouseY, gameStatus);

	ScreenFlip();
}

void LinkGame::reset() {
    delete board;
    delete timeBar;
    // delete comboBar;

    init();
}

void LinkGame::finish() {
    gameStatus = InFinish;
}

void LinkGame::init() {
    gameStatus = InWelcome;
    board = new Board(7, 10, 8);
    timeBar = new TimeBar();
    // comboBar = new ComboBar();
    score = 0;
}

int LinkGame::getStatus() {
    return gameStatus;
}

void LinkGame::timerEvent() {
    timeBar->passBy();
}

Board *LinkGame::getBoard() {
    return board;
}

void LinkGame::aboutUs() {
	gameStatus = InAboutUs;
}

void LinkGame::menu() {
	gameStatus = InWelcome;

	reset();
}

void LinkGame::quit() {
	delete board;
	delete timeBar;
}