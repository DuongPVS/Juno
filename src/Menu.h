#pragma once
#include "loadIMG.h"

class Menu 
{
public:
    Menu();
    ~Menu();
    int chooseMap();
    bool loadMainMenu();
    int loadMenu();

    void render();
    int getMapID();
private:
    Img* img;
    int mapID = -1;
    bool isPlayMusic = 1;
};