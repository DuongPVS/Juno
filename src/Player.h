#pragma once
#include "Directions.h"
#include "Function.h"
#include "Music.h"
#define WALKING_FRAMES 44

class Game;

class Player 
{
public:
    Player(int x, int y, Game* game_);
    ~Player();
    bool canMove(Directions dir);
    void movePlayer(int x, int y);
    void animate();
    void loadTexture();
    void setupClips();
    void switchClip(Directions dir, bool isStanding);
    void draw(int mapWidth, int mapHeight);
    void setCountStep(int step);
    int getCountStep();

private:
    int xTab, yTab;
    int countStep;
    int deltaX = 0, deltaY = 0;
    const int PLAYER_SIZE = 32;
    const int PLAYER_SPEED = 2;
    SDL_Surface* sprite;
    SDL_Rect playerClips[WALKING_FRAMES];
    SDL_Rect currentClip;
    const char* path = "./img/Player1.bmp";

    Game* selfGame_;
    Mus* touch;
};