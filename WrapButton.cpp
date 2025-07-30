
#include "WrapButton.hpp"
#include <SDL3_image/SDL_image.h>


WrapButton::WrapButton(SDL_Renderer* render, float center_x, float center_y, float width, float height,
	std::string texture_file_name, SDL_Window* window)
	: Object(render, center_x, center_y, width, height), window{window}
{
	set_texture(texture_file_name, 500, 300);
}

void WrapButton::event_process(SDL_Event* event) {
	if (inside_clicked(event)) {
		SDL_MinimizeWindow(window);
	}

	if (inside_enter(event)) {
		start_anim(0, 5, 30);
	}
	else if (inside_exit(event)) {
		start_anim(1, 5, 30);
	}
}

