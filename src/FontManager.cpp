#include <iostream>
#include "FontManager.h"

TTF_Font* FontManager::loadFont(const char* fileName, int fontSize) {
	return TTF_OpenFont(fileName, fontSize);
}

void FontManager::draw(SDL_Texture* texture, SDL_Rect position) {
	if (SDL_RenderCopy(Editor::mRenderer, texture, NULL, &position) == -1) {
		std::cerr << "Error:: " << "Rendering label." << std::endl;
		exit(1);
	}
}
