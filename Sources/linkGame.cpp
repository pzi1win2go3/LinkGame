#include "../Headers/LinkGame.h"

LinkGame::LinkGame()
{
    init();
}

void LinkGame::aboutUs() {
    gameStatus = InAboutUs;
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
    return (timeBar->getValue < 1.0E-6);
}

void LinkGame::draw() {
    if (engine->getStatus() == InWelcome)
    {
        int aboutUsCr = getColor(0, 0, 255);
        int startGameCr = getColor(0, 255, 0);
        DrawBox(aboutUsLeftTopX, aboutUsLeftTopY, aboutUsRightBottomX, aboutUsRightBottomY,
                aboutUsCr, TRUE);
        DrawBox(startGameLeftTopX, startGameLeftTopY, startGameRightBottomX, startGameRightBottomY,
                startGameCr, TRUE);
    }
    if (engine->getStatus() == InAboutUs)
    {
        int welcomeCr = getColor(255, 0, 0);
        DrawBox(welcomeLeftTopX, welcomeLeftTopY, welcomeRightBottomX, welcomeRightBottomY,
                welcomeCr, TRUE);
    }
    if (engine->getStatus() == InGame)
    {
        int finishCr = getColor(0, 0, 255);
        int boardCr = getColor(255, 255, 255);
        DrawBox(finishLeftTopX, finishLeftTopY, finishRightBottomX, finishRightBottomY,
                finishCr, TRUE);
        DrawBox(boardLeftTopX, boardLeftTopY, boardRightBottomX, boardRightBottomY,
                boardCr, TRUE);
    }
    if (engine->getStatus() == InFinish)
    {
        int restartCr = getColor(0, 255, 255);
        int exitCr = getColor(255, 255, 0);
        DrawBox(restartLeftTopX, restartLeftTopY, restartRightBottomX, restartRightBottomY,
                restartCr, TRUE);
        DrawBox(exitLeftTopX, exitLeftTopY, exitRightBottomX, exitRightBottomY,
                exitCr, TRUE);
    }
}

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

Board* LinkGame::getBoard()
{
	return board;
}