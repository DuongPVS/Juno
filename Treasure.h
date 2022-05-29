#pragma once
#include "Item.h"

class Treasure : public Item 
{
public:
    Treasure(int x, int y);
    bool Collide(Directions dir) override;
    char* getPath() override;

private:
    char* IMAGE_PATH = "./img/Treasure.bmp";
};