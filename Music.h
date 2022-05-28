#pragma once
#include "Function.h"

class Mus 
{
public:
    Mus();
    ~Mus();
    bool initMixer();
    bool loadMus();
    bool loadWav();
    void playMus();
    void stopMus();
    void continuePlayMus();
    void playTouch();
    void playOuch();
    void freeMus();
    void freeWav();
    bool getIsPlayMusic();
    void playdaphom();
    void playtingting();
    void playvachamthung();
    void playxien();
    bool loadEnd();
    void playEnd();
    void stop();
private:
    bool isPlayMusic;
    Mix_Music *gMusic, *end;
    Mix_Chunk *gTouch, *gOuch;
    Mix_Chunk *daphom, *tingting, *vachamthung, *xien;
};