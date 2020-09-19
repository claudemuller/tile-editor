#include <iostream>
#include "Editor.h"
#include "Constants.h"

SDL_Renderer* Editor::mRenderer;
SDL_Event Editor::mEvent;
SDL_Rect Editor::mCamera = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
bool Editor::mDebug;

Editor::Editor() {
	mRunning = false;
	mDebug = false;
}

void Editor::init(int width, int height) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "Failed to init SDL: " << SDL_GetError() << std::endl;
		return;
	}

	if (TTF_Init() != 0) {
		std::cerr << "Failed to init TTF: " << TTF_GetError() << std::endl;
		return;
	}

	mWindow = SDL_CreateWindow(
			NULL,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			width,
			height,
			SDL_WINDOW_BORDERLESS
	);
	if (mWindow == nullptr) {
		std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
		return;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, 0);
	if (mRenderer == nullptr) {
		std::cerr << "Failed to create render: " << SDL_GetError() << std::endl;
		return;
	}

	// TODO: If mDebug?
//	Benchmark::start();

	mRunning = true;
}

void Editor::processInput() {
	SDL_PollEvent(&mEvent);

	bool keyDown;
	switch (mEvent.key.type) {
		case SDL_QUIT: {
			mRunning = false;
			break;
		}
		case SDL_KEYDOWN: {
			if (keyDown) {
				break;
			}
			keyDown = true;
			if (mEvent.key.keysym.sym == SDLK_ESCAPE) {
				mRunning = false;
			}
			if (mEvent.key.keysym.sym == SDLK_F1) {
				mDebug = !mDebug;
			}
			break;
		}
		case SDL_KEYUP: {
			keyDown = false;
			break;
		}
		default: {
			break;
		}
	}
}

void Editor::update() {
	// Sleep the execution until the target time in milliseconds is reached.
	int timeToWait = FRAME_TARGET_TIME - SDL_GetTicks() - mLastFrameTime;
	// Only call delay if processing is too fast in the current frame.
	if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME) {
		SDL_Delay(timeToWait);
	}
	mCurrentFPS = (float)(SDL_GetTicks() - mLastFrameTime);

	// TODO: rather control this with a DEBUG_LAYER.
	if (Editor::mDebug) {
//		Entity* lblFPS = entityManager.getEntity("ui-level-name");
//		if (lblFPS != NULL) {
//			TextLabelComponent* lblFPSText = lblFPS->getComponent<TextLabelComponent>();
//			lblFPSText->setLabelText(std::to_string(mCurrentFPS), "charriot-font");
//		}
	}

	float deltaTime = mCurrentFPS / 1000.0f;
	// Clamp deltaTime to a maximum value
	deltaTime = deltaTime > 0.05f ? 0.05f : deltaTime;
	// Sets the new ticks fo the current frame to be used in the next pass
	mLastFrameTime = SDL_GetTicks();

//	entityManager.update(deltaTime);

	checkCollisions();
//	Benchmark::log();

	handleCameraMovement();
}
void Editor::render() {
	SDL_SetRenderDrawColor(mRenderer, 21, 21, 21, 255);
	SDL_RenderClear(mRenderer);

//	if (!entityManager.hasEntities()) {
//		return;
//	}
//	entityManager.render();

	SDL_RenderPresent(mRenderer);
}

void Editor::handleCameraMovement() {

}

void Editor::checkCollisions() {

}

void Editor::destroy() {
//	Benchmark::stop();

	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	TTF_Quit();
	SDL_Quit();
}
