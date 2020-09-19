#ifndef TILE_EDITOR_TEXTUREMANAGER_H
#define TILE_EDITOR_TEXTUREMANAGER_H

#include "Editor.h"

class TextureManager {
public:
	static SDL_Texture* loadTexture(const char* fileName);
	static void draw(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect, SDL_RendererFlip flip);

private:
};

#endif //TILE_EDITOR_TEXTUREMANAGER_H
