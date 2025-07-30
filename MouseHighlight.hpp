#pragma once

#include <SDL3/SDL.h>
#include <array>

class MouseHighlight
{
public:
	MouseHighlight(SDL_Renderer* render);

	void event_process(SDL_Event* event);

	void iterate();

	std::array<uint8_t, 4> area_color;
	
private:
	SDL_Renderer* render = nullptr;
	SDL_FRect area;
	float down_x = -1;
	float down_y = -1;
	bool down = false;
	bool need_render = false;
};

