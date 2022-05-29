#include "Music.h"

Mus::Mus() {
    if (!initMixer())
        printf("can't init Mixer!");
}
Mus::~Mus() {}

bool Mus::initMixer() {
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
	{
		printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
		return false;
	}
    return true;
}

bool Mus::loadMus() {
    bool success = true;
    gMusic = Mix_LoadMUS("./mus/soundtrack.wav");
    if (gMusic == NULL) {
        printf( "Failed to load soundtrack sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		return false;
    }
	return success;
}

bool Mus::loadEnd() {
    bool success = true;
    end = Mix_LoadMUS("./mus/end.wav");
    if (end == NULL) {
        printf( "Failed to load soundtrack sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		return false;
    }
	return success;
}

void Mus::playEnd() {
    if( Mix_PlayingMusic() == 0 )
	{
		//Play the music
		Mix_PlayMusic( end, -1 );
	}
}

void Mus::stop() {
    Mix_HaltMusic();
}

bool Mus::loadWav() {
    bool success = true;
    gTouch = Mix_LoadWAV("./mus/touch.wav");
    if (gTouch == NULL) {
        printf( "Failed to load touch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
    }
    gOuch = Mix_LoadWAV("./mus/ouch.wav");
    if (gOuch == NULL) {
        printf( "Failed to load touch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
    }
    daphom = Mix_LoadWAV("./mus/daphom.wav");
    if (daphom == NULL) {
        printf( "Failed to load touch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
    }
    tingting = Mix_LoadWAV("./mus/tingting.wav");
    if (tingting == NULL) {
        printf( "Failed to load touch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
    }
    vachamthung = Mix_LoadWAV("./mus/vachamthung.wav");
    if (vachamthung == NULL) {
        printf( "Failed to load touch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
    }
    xien = Mix_LoadWAV("./mus/xien.wav");
    if (xien == NULL) {
        printf( "Failed to load touch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
    }

	return success;
}

void Mus::playMus() {
    if( Mix_PlayingMusic() == 0 )
	{
		//Play the music
		Mix_PlayMusic( gMusic, -1 );
	}
    isPlayMusic = true;
}

void Mus::stopMus() {
    Mix_PauseMusic();
    isPlayMusic = false;
}

void Mus::continuePlayMus() {
    if( Mix_PausedMusic() == 1 )
    {
        //Resume the music
        Mix_ResumeMusic();
    }
    isPlayMusic = true;
}

void Mus::playTouch() {
    Mix_PlayChannel( -1, gTouch, 0 );
}

void Mus::playOuch() {
    Mix_PlayChannel( -1, gOuch, 0 );
}

void Mus::playdaphom() {
    Mix_PlayChannel( -1, daphom, 0 );
}

void Mus::playtingting() {
    Mix_PlayChannel( -1, tingting, 0 );
}

void Mus::playvachamthung() {
    Mix_PlayChannel( -1, vachamthung, 0 );
}

void Mus::playxien() {
    Mix_PlayChannel( -1, xien, 0 );
}

void Mus::freeMus() {
    Mix_FreeMusic(gMusic);
}

void Mus::freeWav() {
   Mix_FreeChunk(gTouch);
   Mix_FreeChunk(gOuch);
   Mix_FreeChunk(daphom);
   Mix_FreeChunk(gOuch);
   Mix_FreeChunk(vachamthung);
   Mix_FreeChunk(xien);
}

bool Mus::getIsPlayMusic() {
    return isPlayMusic;
}

