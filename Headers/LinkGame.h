#ifndef LINK_GAME_H
#define LINK_GAME_H

class LinkGame
{
private:
    bool isInGame;
    bool isInWelcome;
    bool isFinish;
public:
    LinkGame();

    void start();
};

#endif