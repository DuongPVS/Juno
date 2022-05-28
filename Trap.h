#pragma once
#include "Item.h"

class Trap : public Item 
{
public:
    Trap(int x, int y);
    bool Collide(Directions dir) override;
    char* getPath() override;

private:
    char* IMAGE_PATH = "./img/Trap.bmp";
};