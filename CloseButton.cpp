
#include "CloseButton.hpp"
#include <SDL3_image/SDL_image.h>


CloseButton::CloseButton(SDL_Renderer* render, float center_x, float center_y, float width, float height,
	std::string texture_file_name)
		: Object(render, center_x, center_y, width, height)
{
	set_texture(texture_file_name, 500, 300);
}

void CloseButton::process_event(SDL_Event* event) {
	if (inside_clicked(event)) {
		SDL_Event event_quit;
		event_quit.type = SDL_EVENT_QUIT;
		SDL_PushEvent(&event_quit);
	}

	if (inside_enter(event)) {
		start_anim(0, 5, 30);
	}
	else if (inside_exit(event)) {
		start_anim(1, 5, 30);
	}
}
