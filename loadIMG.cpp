#include "loadIMG.h"

Img::Img() {}

Img::~Img() {
    SDL_FreeSurface( gMain );
    SDL_FreeSurface( gMusic );
    SDL_FreeSurface( gMute );
    SDL_FreeSurface( gSkip );
    SDL_FreeSurface( gResume );
    SDL_FreeSurface( gNewGame );
    SDL_FreeSurface( gExit );
    SDL_FreeSurface( gChapterSelect );
    SDL_FreeSurface( gPNGSurface );
	SDL_FreeSurface( gMenu );
	SDL_FreeSurface( gline );
	SDL_FreeSurface( gboldLine );
    SDL_FreeSurface( chapter1 );
    SDL_FreeSurface( chapter2 );
    SDL_FreeSurface( chapter3 );
    SDL_FreeSurface( chapter4 );
    SDL_FreeSurface( chapter5 );
    SDL_FreeSurface( chapter6 );
    SDL_FreeSurface( chapter7 );
    SDL_FreeSurface( chapter8 );
    SDL_FreeSurface( chapter9 );
	SDL_FreeSurface( chapter10 );
}

SDL_Surface* Img::loadSurface( std::string path ) {
    //The final optimized image
    SDL_Surface* optimizedSurface = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface, Sample::screen->format, 0 );
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return optimizedSurface;
}

bool Img::loadgPNGSurface() {
    gPNGSurface = loadSurface("./img/background.png");
	if( gPNGSurface == NULL )
	{
		printf( "Failed to load press texture!\n" );
		return false;
	}
    return true;
}

bool Img::loadgMainMenu() {
    bool success = true;
    gNewGame = loadSurface("./img/MainMenu/newGame.jpg");
	if( gNewGame == NULL )
	{
		printf( "Failed to load up texture!\n" );
		success = false;
	}

    gExit = loadSurface("./img/MainMenu/exit.jpg");
	if( gExit == NULL )
	{
		printf( "Failed to load up texture!\n" );
		success = false;
	}

    gChapterSelect = loadSurface("./img/MainMenu/chapterSelect.jpg");
	if( gChapterSelect == NULL )
	{
		printf( "Failed to load up texture!\n" );
		success = false;
	}
    return success;
}

bool Img::loadgMenu() {
    bool success = true;
    gMenu = loadSurface("./img/Menu/menu.png");
	if( gMenu == NULL )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
    gline = loadSurface("./img/Menu/line.png");
	if( gline == NULL )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
    gboldLine = loadSurface("./img/Menu/boldLine.png");
	if( gboldLine == NULL )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
    gMain = loadSurface("./img/Menu/MAIN.png");
	if( gMain == NULL )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
    gMusic = loadSurface("./img/Menu/MUSIC.png");
	if( gMusic == NULL )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
    gMute = loadSurface("./img/Menu/Mute.png");
	if( gMute == NULL )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
    gSkip = loadSurface("./img/Menu/SKIP.png");
	if( gSkip == NULL )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
    gResume = loadSurface("./img/Menu/RESUME.png");
	if( gResume == NULL )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
    return success;
}

bool Img::loadgChapterSelect() {
    bool success = true;
    chapter1 = loadSurface("./img/ChapterSelect/1.png");
	if( chapter1 == NULL )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
    chapter2 = loadSurface("./img/ChapterSelect/2.png");
	if( chapter2 == NULL )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
    chapter3 = loadSurface("./img/ChapterSelect/3.png");
	if( chapter3 == NULL )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
    chapter4 = loadSurface("./img/ChapterSelect/4.png");
	if( chapter4 == NULL )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
    chapter5 = loadSurface("./img/ChapterSelect/5.png");
	if( chapter5 == NULL )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
    chapter6 = loadSurface("./img/ChapterSelect/6.png");
	if( chapter6 == NULL )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
    chapter7 = loadSurface("./img/ChapterSelect/7.png");
	if( chapter7 == NULL )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
    chapter8 = loadSurface("./img/ChapterSelect/8.png");
	if( chapter8 == NULL )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
    chapter9 = loadSurface("./img/ChapterSelect/9.png");
    if( chapter9 == NULL )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
    chapter10 = loadSurface("./img/ChapterSelect/10.png");
    if( chapter10 == NULL )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
    return success;
}

void Img::getgPNGSurface() {
    //Apply the current image
    SDL_BlitSurface( gPNGSurface, NULL, Sample::screen, NULL);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getgMenu() {
    //Apply the current image
    SDL_BlitSurface( gMenu, NULL, Sample::screen, NULL);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getgline(SDL_Rect d) {
    //Apply the current image
    SDL_BlitScaled( gline, NULL, Sample::screen, &d);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getgboldLine(SDL_Rect d) {
    //Apply the current image
    SDL_BlitScaled( gboldLine, NULL, Sample::screen, &d);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getgNewGame() {
    //Apply the current image
    SDL_BlitScaled( gNewGame, NULL, Sample::screen, NULL);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getgExit() {
    //Apply the current image
    SDL_BlitScaled( gExit, NULL, Sample::screen, NULL);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getgChapterSelect() {
    //Apply the current image
    SDL_BlitScaled( gChapterSelect, NULL, Sample::screen, NULL);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getgMain(SDL_Rect d) {
    //Apply the current image
    SDL_BlitScaled( gMain, NULL, Sample::screen, &d);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getgMusic(SDL_Rect d) {
    //Apply the current image
    SDL_BlitScaled( gMusic, NULL, Sample::screen, &d);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getgMute(SDL_Rect d) {
    //Apply the current image
    SDL_BlitScaled( gMute, NULL, Sample::screen, &d);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getgSkip(SDL_Rect d) {
    //Apply the current image
    SDL_BlitScaled( gSkip, NULL, Sample::screen, &d);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getgResume(SDL_Rect d) {
    //Apply the current image
    SDL_BlitScaled( gResume, NULL, Sample::screen, &d);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getChapter1() {
    SDL_Rect d;
    d = {0, 0, 1280, 720};
    //Apply the current image
    SDL_BlitScaled( chapter1, NULL, Sample::screen, &d);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getChapter2() {
    SDL_Rect d;
    d = {0, 0, 1280, 720};
    //Apply the current image
    SDL_BlitScaled( chapter2, NULL, Sample::screen, &d);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getChapter3() {
    SDL_Rect d;
    d = {0, 0, 1280, 720};
    //Apply the current image
    SDL_BlitScaled( chapter3, NULL, Sample::screen, &d);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getChapter4() {
    SDL_Rect d;
    d = {0, 0, 1280, 720};
    //Apply the current image
    SDL_BlitScaled( chapter4, NULL, Sample::screen, &d);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getChapter5() {
    SDL_Rect d;
    d = {0, 0, 1280, 720};
    //Apply the current image
    SDL_BlitScaled( chapter5, NULL, Sample::screen, &d);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getChapter6() {
    SDL_Rect d;
    d = {0, 0, 1280, 720};
    //Apply the current image
    SDL_BlitScaled( chapter6, NULL, Sample::screen, &d);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getChapter7() {
    SDL_Rect d;
    d = {0, 0, 1280, 720};
    //Apply the current image
    SDL_BlitScaled( chapter7, NULL, Sample::screen, &d);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getChapter8() {
    SDL_Rect d;
    d = {0, 0, 1280, 720};
    //Apply the current image
    SDL_BlitScaled( chapter8, NULL, Sample::screen, &d);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getChapter9() {
    SDL_Rect d;
    d = {0, 0, 1280, 720};
    //Apply the current image
    SDL_BlitScaled( chapter9, NULL, Sample::screen, &d);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

void Img::getChapter10() {
    SDL_Rect d;
    d = {0, 0, 1280, 720};
    //Apply the current image
    SDL_BlitScaled( chapter10, NULL, Sample::screen, &d);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}

bool Img::loadEnd() {
    end = loadSurface("./img/win.png");
	if( end == NULL )
	{
		printf( "Failed to load press texture!\n" );
		return false;
	}
    return true;
}

void Img::getEnd() {
    SDL_Rect d;
    d = {0, 0, 1280, 720};
    //Apply the current image
    SDL_BlitScaled( end, NULL, Sample::screen, &d);
    
    //Update the surface
    SDL_UpdateWindowSurface( Sample::window );
}