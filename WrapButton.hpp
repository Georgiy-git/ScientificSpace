#pragma once

#include "Object.hpp";

class WrapButton : public Object
{
public:
	WrapButton(SDL_Renderer* render, float center_x, float center_y, float width, float height,
		std::string texture_file_name, SDL_Window* window);

	void process_event(SDL_Event* event) override;

private:
	SDL_Window* window;
};

