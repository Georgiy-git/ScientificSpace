#pragma once

#include "Object.hpp"


class CloseButton : public Object
{
public:
	CloseButton(SDL_Renderer* render, float center_x, float center_y, float width, float height, 
		std::string texture_file_name);

	void event_process(SDL_Event* event) override;
};