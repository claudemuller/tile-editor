#ifndef TILE_EDITOR_ASSETMANAGER_H
#define TILE_EDITOR_ASSETMANAGER_H

#include <iostream>
#include <map>
#include <SDL.h>
#include <SDL_ttf.h>
#include "EntityManager.h"

class AssetManager {
public:
	AssetManager(EntityManager* entityManager);

	void clearData();

	void addTexture(const std::string& textureId, const char* fileName);
	SDL_Texture* getTexture(const std::string& textureId);
	void listTextures();
	void addFont(std::string fontId, const char* fileName, int fontSize);
	TTF_Font* getFont(const std::string& fontId);

private:
	EntityManager* mEntityManager;
	std::map<std::string, SDL_Texture*> mTextures;
	std::map<std::string, TTF_Font*> mFonts;
};

#endif //TILE_EDITOR_ASSETMANAGER_H
