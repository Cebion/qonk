// Copyright 2005 by Anthony Liekens anthony@liekens.net

#ifndef FONTS_H
#define FONTS_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <iostream>

class Font {
private:
  TTF_Font* font;
public:
  Font( char* fileName, int size );
  
  void render( SDL_Surface* screen, int x, int y, const char* text, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255 );
  void renderCenterJustified( SDL_Surface* screen, int x, int y, const char* text, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255 );
  void renderRightJustified( SDL_Surface* screen, int x, int y, const char* text, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255 );
  
  int getHeight();
};

#endif
