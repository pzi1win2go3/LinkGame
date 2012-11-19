#include "../Headers/LinkGame.h"

LinkGame::LinkGame()
{
    init();
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

void LinkGame::draw() {}

void LinkGame::reset() {
    delete board;
    delete timeBar;
    delete comboBar;

    init();
}

void LinkGame::finish() {
    gameStatus = InFinish;
}

void LinkGame::init() {
    gameStatus = InWelcome;
    board = new Board(18, 15, 8);
    timeBar = new TimeBar();
    comboBar = new ComboBar();
    score = 0;
}

int LinkGame::getStatus() {
    return gameStatus;
}

void timerEvent() {
    timeBar->passBy();
}