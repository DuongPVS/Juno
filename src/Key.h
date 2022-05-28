#pragma once
#include "Item.h"

class Key : public Item 
{
public:
    Key(int x, int y);
    bool Collide(Directions dir) override;
    char* getPath() override;

private:
    char* IMAGE_PATH = "./img/Key.bmp";
};