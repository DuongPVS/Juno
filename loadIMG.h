#pragma once
#include "Sample.h"

class Img 
{
public:
    Img();
    ~Img();
    SDL_Surface* loadSurface( std::string path );
    bool loadgPNGSurface();
    bool loadgMainMenu();
    bool loadgMenu();
    bool loadgChapterSelect();

    void getgPNGSurface();
    void getgMenu();
    void getgline(SDL_Rect d);
    void getgboldLine(SDL_Rect d);
    void getgNewGame();
    void getgExit();
    void getgChapterSelect();
    void getgMain(SDL_Rect d);
    void getgMusic(SDL_Rect d);
    void getgMute(SDL_Rect d);
    void getgSkip(SDL_Rect d);
    void getgResume(SDL_Rect d);
    void getChapter1();
    void getChapter2();
    void getChapter3();
    void getChapter4();
    void getChapter5();
    void getChapter6();
    void getChapter7();
    void getChapter8();
    void getChapter9();
    void getChapter10();
    void getEnd();
    bool loadEnd();
private:
    SDL_Surface *gPNGSurface, *gMenu, *gline, *gboldLine, *gNewGame, *gExit, *gChapterSelect, *end;
    SDL_Surface *gMain, *gMusic, *gMute, *gSkip, *gResume;
    SDL_Surface *chapter1, *chapter2, *chapter3, *chapter4, *chapter5, *chapter6, *chapter7, *chapter8, *chapter9, *chapter10;
};