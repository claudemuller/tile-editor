#ifndef TILE_EDITOR_CONSTANTS_H
#define TILE_EDITOR_CONSTANTS_H

#include <SDL.h>

const unsigned int FPS = 60;
const unsigned int FRAME_TARGET_TIME = (1000 / FPS);

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

enum CollisionType {
	NO_COLLISION
};

enum LayerType {
	TILEMAP_LAYER
};

const unsigned int NUM_LAYERS = 1;

const SDL_Color WHITE = {255, 255, 255, 255};
const SDL_Color GREEN = {0, 255, 0, 255};

#endif //TILE_EDITOR_CONSTANTS_H
