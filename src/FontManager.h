#ifndef TILE_EDITOR_FONTMANAGER_H
#define TILE_EDITOR_FONTMANAGER_H

#include "Editor.h"

class FontManager {
public:
	static TTF_Font* loadFont(const char* fileName, int fontSize);
	static void draw(SDL_Texture* texture, SDL_Rect position);

private:
};

#endif //TILE_EDITOR_FONTMANAGER_H
