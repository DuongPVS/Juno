#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdlib.h>

#define SCREEN_WIDTH 1280    
#define SCREEN_HEIGHT 720

void DrawString(SDL_Surface *screen, int x, int y, int k, const char *text, SDL_Surface *charset);
void DrawSurface(SDL_Surface *screen, SDL_Surface *sprite, int x, int y);
void DrawPixel(SDL_Surface *surface, int x, int y, Uint32 color);
void DrawLine(SDL_Surface *screen, int x, int y, int l, int dx, int dy, Uint32 color);
void DrawRectangle(SDL_Surface *screen, int x, int y, int l, int k, Uint32 outLineColor, Uint32 fullColor);