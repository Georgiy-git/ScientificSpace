#pragma once

#include <SDL3/SDL.h>
#include <array>

#include "Object.hpp"

class MouseHighlight : Object
{
public:
	MouseHighlight(SDL_Renderer* render);

	void event_process(SDL_Event* event);

	void iterate() override;
	
private:
	SDL_Renderer* render = nullptr;
	float down_x = -1;
	float down_y = -1;
	bool down = false;
	bool need_render = false;
};

