#pragma once

#include <SDL3/SDL.h>
#include <vector>

#include "Button.hpp"


class PressButtonGroup
{
public:
	void process_event(SDL_Event* event);
	void press(Button* button);
	void add(Button* button, int state);
	void clear();

	std::vector<std::pair<Button*, int>> buttons;
	Button* pressing = nullptr;
	int state = 0;
};

