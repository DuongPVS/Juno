#pragma once
#include "Item.h"

class Map;

class Demon : public Item
{
public:
    Demon(int x, int y, Map* map);
    bool Collide(Directions dir) override;
    char* getPath() override;

private:
    char* IMAGE_PATH = "./img/Demon.bmp";
    Map* selfMap_;
};