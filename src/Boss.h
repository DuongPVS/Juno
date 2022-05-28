#pragma once
#include "Item.h"

class Boss : public Item 
{
public:
    Boss(int x, int y);
    bool Collide(Directions dir) override;
    char* getPath() override;

private:
    char* IMAGE_PATH = "./img/Boss.bmp";
};