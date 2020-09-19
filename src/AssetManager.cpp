#include "AssetManager.h"
#include "TextureManager.h"
#include "FontManager.h"

AssetManager::AssetManager(EntityManager* entityManager): mEntityManager(entityManager) {
}

void AssetManager::clearData() {
	mTextures.clear();
	mFonts.clear();
}

void AssetManager::addTexture(const std::string& textureId, const char* fileName) {
	mTextures.emplace(textureId, TextureManager::loadTexture(fileName));
}

SDL_Texture* AssetManager::getTexture(const std::string& textureId) {
	return mTextures[textureId];
}

void AssetManager::listTextures() {
	for (std::map<std::string, SDL_Texture*>::iterator iter = mTextures.begin(); iter != mTextures.end(); ++iter) {
		std::cout << "Texture (" << iter->first << ") " << iter->second << std::endl;
	}
}

void AssetManager::addFont(std::string fontId, const char* fileName, int fontSize) {
	mFonts.emplace(fontId, FontManager::loadFont(fileName, fontSize));
}

TTF_Font* AssetManager::getFont(const std::string& fontId) {
	return mFonts[fontId];
}
