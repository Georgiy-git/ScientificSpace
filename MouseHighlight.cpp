#include "MouseHighlight.hpp"

MouseHighlight::MouseHighlight(SDL_Renderer* render)
	: render{render}
{
	area_color[0] = 123;
	area_color[1] = 200;
	area_color[2] = 246;
	area_color[3] = 255;
}

void MouseHighlight::event_process(SDL_Event* event)
{
	if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
		down_x = event->button.x;
		down_y = event->button.y;
		area.x = down_x;
		area.y = down_y;
		down = true;
		need_render = false;
	}
	else if (event->type == SDL_EVENT_MOUSE_MOTION && down) {
		if (event->button.y > down_y) {
			area.h = event->button.y - area.y;
		}
		else {
			area.y = event->button.y;
			area.h = down_y - event->button.y;
		}
		if (event->button.x > down_x) {
			area.w = event->button.x - area.x;
		}
		else {
			area.x = event->button.x;
			area.w = down_x - event->button.x;
		}
		if (!need_render) need_render = true;
	}
	else if (event->type == SDL_EVENT_MOUSE_BUTTON_UP && down) {
		down = false;
	}
}

void MouseHighlight::iterate() {
	if (need_render && area.w > 1 && area.h > 1) {
		SDL_SetRenderDrawColor(render, area_color[0], area_color[1], area_color[2], area_color[3]);
		SDL_RenderFillRect(render, &area);
	}
}
