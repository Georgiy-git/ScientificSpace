#include "MouseHighlight.hpp"

MouseHighlight::MouseHighlight(SDL_Renderer* render)
	: Object(render, -100, -100, 0, 0)
{
	set_texture("textures\\videlenie.svg", 400, 400);
}

void MouseHighlight::event_process(SDL_Event* event)
{
	if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
		down_x = event->button.x;
		down_y = event->button.y;
		size_texture_frame.x = down_x;
		size_texture_frame.y = down_y;
		down = true;
		need_render = false;
	}
	else if (event->type == SDL_EVENT_MOUSE_MOTION && down) {
		if (event->button.y > down_y) {
			size_texture_frame.h = event->button.y - size_texture_frame.y;
		}
		else {
			size_texture_frame.y = event->button.y;
			size_texture_frame.h = down_y - event->button.y;
		}
		if (event->button.x > down_x) {
			size_texture_frame.w = event->button.x - size_texture_frame.x;
		}
		else {
			size_texture_frame.x = event->button.x;
			size_texture_frame.w = down_x - event->button.x;
		}
		if (!need_render) need_render = true;
	}
	else if (event->type == SDL_EVENT_MOUSE_BUTTON_UP && down) {
		down = false;
	}
}

void MouseHighlight::iterate() {
	if (need_render && size_texture_frame.w > 1 && size_texture_frame.h > 1) {
		Object::iterate();
	}
}
