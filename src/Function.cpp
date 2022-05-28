#include "Function.h"

void DrawString(SDL_Surface *screen, int x, int y, int k, const char *text, SDL_Surface *charset) {
    int px, py, c;
    SDL_Rect s, d;
    s.w = 8;
    s.h = 8;
    d.w = k;
    d.h = k;
    while (*text) {
        c = *text & 255;
        px = (c % 16) * 8;
        py = (c / 16) * 8;
        s.x = px;
        s.y = py;
        d.x = x;
        d.y = y;
        SDL_BlitScaled(charset, &s, screen, &d);
        x += k;
        text++;
    }
}

void DrawSurface(SDL_Surface *screen, SDL_Surface *sprite, int x, int y)  {
    SDL_Rect dest;
    dest.x = x - sprite->w / 2;
    dest.y = y - sprite->h / 2;
    dest.w = sprite->w;
    dest.h = sprite->h;
    SDL_BlitSurface(sprite, NULL, screen, &dest);
}

void DrawPixel(SDL_Surface *surface, int x, int y, Uint32 color) {
    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
    *(Uint32 *)p = color;
}

void DrawLine(SDL_Surface *screen, int x, int y, int l, int dx, int dy, Uint32 color) {
    for (int i = 0; i < l; i++) {
        DrawPixel(screen, x, y, color);
        x += dx;
        y += dy;
    }
}

void DrawRectangle(SDL_Surface *screen, int x, int y, int l, int k, Uint32 outLineColor, Uint32 fillColor) {
    DrawLine(screen, x, y, k, 0, 1, outLineColor);
    DrawLine(screen, x + l - 1, y, k, 0, 1, outLineColor);
    DrawLine(screen, x, y, l, 1, 0, outLineColor);
    DrawLine(screen, x, y + k - 1, l, 1, 0, outLineColor);
    for (int i = y + 1; i < y + k - 1; i++)
        DrawLine(screen, x + 1, i, l - 2, 1, 0, fillColor);
}