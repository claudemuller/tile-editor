#ifndef TILE_EDITOR_EDITOR_H
#define TILE_EDITOR_EDITOR_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class AssetManager;

class Editor {
public:
	static SDL_Renderer* mRenderer;
	static AssetManager* mAssetManager;
	static SDL_Event mEvent;
	static SDL_Rect mCamera;
	static bool mDebug;

	Editor();

	void init(int width, int height);
	void processInput();
	void update();
	void render();
	void handleCameraMovement();
	void checkCollisions();
	void destroy();
	bool isRunning() const { return mRunning; };

private:
	SDL_Window* mWindow;
	bool mRunning;
	int mLastFrameTime = 0;
	float mCurrentFPS = 0.0;
};

#endif //TILE_EDITOR_EDITOR_H
