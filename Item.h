#pragma once
#include "Function.h"
#include "Directions.h"

class Item 
{
public:
    Item(int x, int y);
    ~Item();
    void loadSprite(char* path);
    virtual char* getPath() = 0;
    SDL_Surface* getSprite();
    SDL_Texture* loadTexture( std::string path );
    virtual bool Collide(Directions dir) = 0;
    bool getIsOnEndPoint();
    void setIsOnEndPoint(const bool value);
    int getXPosition();
    int getYPosition();
    char getType();

    int xPosition, yPosition;
    bool isOnEndPoint;
    char type;

private:
    SDL_Surface* sprite;
    char* IMAGE_PATH;
};