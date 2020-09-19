#include <iostream>
#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* fileName) {
	SDL_Surface* surface = IMG_Load(fileName);
	if (!surface) {
		std::cerr << "Error:: " << "Could not create surface for '" << fileName << "'." << std::endl;
		exit(1);
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Editor::mRenderer, surface);
	if (!surface) {
		std::cerr << "Error:: " << "Could not create texture '" << fileName << "'." << std::endl;
		exit(1);
	}

	SDL_FreeSurface(surface);

	return texture;
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect, SDL_RendererFlip flip) {
	SDL_RenderCopyEx(Editor::mRenderer, texture, &srcRect, &destRect, 0.0f, NULL, flip);
}
