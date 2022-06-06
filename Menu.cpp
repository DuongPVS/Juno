#include "Menu.h"

Menu::Menu() {
    img = new Img();
	img->loadgMenu();
	img->loadgMainMenu();
	img->loadgChapterSelect();
}
Menu::~Menu() { delete img; }

int Menu::chooseMap() {
	SDL_Event e;
	bool exit = false;
	int currentChoose = 1;
	while( !exit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
				return -1;
            else if  (e.type == SDL_KEYDOWN) 
                switch (e.key.keysym.sym) {
                    case SDLK_RIGHT:
                        currentChoose = (currentChoose < 10 ? currentChoose + 1 : 1);
                        break;
                    case SDLK_LEFT:
                        currentChoose = (currentChoose > 1 ? currentChoose - 1 : 10);
                        break;
                    case SDLK_RETURN:
                        return currentChoose;
                }
		}
		switch (currentChoose) {
			case 1:
                img->getChapter1();
				break;
			case 2:
                img->getChapter2();
				break;
			case 3:
                img->getChapter3();
				break;
			case 4:
                img->getChapter4();
				break;
			case 5:
                img->getChapter5();
				break;
			case 6:
                img->getChapter6();
				break;
			case 7:
                img->getChapter7();
				break;
			case 8:
                img->getChapter8();
				break;
			case 9:
                img->getChapter9();
				break;
			case 10:
                img->getChapter10();
				break;
		}
		render();
	}
}

void Menu::render() {
	//updates everything on texture
	SDL_UpdateTexture(Sample::scrtex, NULL, Sample::screen->pixels, Sample::screen->pitch);

	//connects the new texture with renderer
	SDL_RenderCopy(Sample::renderer, Sample::scrtex, NULL, NULL);
	
	//renders
	SDL_RenderPresent(Sample::renderer);
}

bool Menu::loadMainMenu() {
	SDL_Event e;
	bool exit = false;
	int currentChoose = 1;
	while( !exit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
				return false;
            else if  (e.type == SDL_KEYDOWN) 
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        currentChoose = (currentChoose > 1 ? currentChoose - 1 : 3);
                        break;
                    case SDLK_DOWN:
                        currentChoose = (currentChoose < 3 ? currentChoose + 1 : 1);
                        break;
                    case SDLK_RETURN:
                        switch (currentChoose) {
                            case 1:
                                mapID = 1;
                                break;
                            case 2:
                                mapID = chooseMap();
								if (mapID == -1)
									return false;
                                break;
                            case 3:
                                return false;
                        }
                        exit = true;
                        break;
                }
		}
	
		switch (currentChoose) {
			case 1:
                img->getgNewGame();
				break;
			case 2:
                img->getgChapterSelect();
				break;
			case 3:
                img->getgExit();
				break;
		}
		render();
	}
	return true;
}

int Menu::loadMenu() {
    img->getgMenu();
	SDL_Rect s1, s2, s3, s4, s5;
	s1 = {590, 168, 100, 17};
	s2 = {585, 243, 110, 17};
	s3 = {610, 317, 60, 17};
	s4 = {615, 355, 50, 17};
	s5 = {585, 433, 110, 17};

	img->getgResume(s1);
	img->getgSkip(s2);
	img->getgMusic(s3);
	img->getgMute(s4);
	img->getgMain(s5);

	SDL_Rect d1, d2, d3, d4;
	d1 = {457, 150, 366, 54};
	d2 = {457, 225, 366, 54};
	d3 = {457, 300, 366, 54};
    d4 = {457, 415, 366, 54};

	img->getgline(d1);
	img->getgline(d2);
	img->getgline(d3);
	img->getgline(d4);

	SDL_Event e;
	bool exit = false;
	int currentChoose = 1;
	while( !exit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT ) 
				return -1;
            else if  (e.type == SDL_KEYDOWN) 
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        currentChoose = (currentChoose > 1 ? currentChoose - 1 : 4);
                        break;
                    case SDLK_DOWN:
                        currentChoose = (currentChoose < 4 ? currentChoose + 1 : 1);
                        break;
                    case SDLK_RETURN:
						if (currentChoose == 3)
							isPlayMusic = !isPlayMusic;
                        return currentChoose;
					case SDLK_ESCAPE:
						return 1;
                }
		}
	
		SDL_Rect d;
		d.h = 66;
		d.w = 410;
		d.x = 435;
        img->getgMenu();

		switch (currentChoose) {
			case 1:
                img->getgline(d2);
	            img->getgline(d3);
				img->getgline(d4);
				d.y = 144;
				break;
			case 2:
                img->getgline(d1);
	            img->getgline(d3);
				img->getgline(d4);
				d.y = 219;
				break;
			case 3:
                img->getgline(d1);
	            img->getgline(d2);
				img->getgline(d4);
				d.y = 294;
				break;
			case 4:
                img->getgline(d1);
	            img->getgline(d2);
				img->getgline(d3);
				d.y = 409;
				break;
		}

		img->getgboldLine(d);

		img->getgResume(s1);
		img->getgSkip(s2);
		img->getgMusic(s3);
		if (!isPlayMusic)
			img->getgMute(s4);
		img->getgMain(s5);

		render();
	} 
	return currentChoose;
}

int Menu::getMapID() { return mapID; }
