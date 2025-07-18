#pragma once

#include "Panel.hpp"

class Button;

class LeftPanel : public Panel
{
public:
	LeftPanel(SDL_Renderer* render, float center_x, float center_y, float width, float height,
		char direction = 'h', float object_distance = 20,
		float distance_of_border_w = 20, float distance_of_border_h = 20);

	void process_event(SDL_Event* event) override;

	Button* make_rect_button;
	Button* make_line_button;
	Button* make_round_button;
};

