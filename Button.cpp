#include "Button.hpp"

Button::Button(SDL_Renderer* render, float center_x, float center_y, float width, float height)
	: Object(render, center_x, center_y, width, height)
{

}

void Button::process_event(SDL_Event* event)
{
	if (pressing && inside_clicked(event) && flag_pressing) {
		remove_pressing();
	}
	else if (!pressing) {
		if (inside_enter(event)) {
			change_show_rect(1, 0);
		}
		if (inside_exit(event)) {
			change_show_rect(0, 0);
		}
		if (inside_clicked(event) && flag_pressing) {
			set_pressing();
		}
	}
}

void Button::reset_pressing_flag()
{
	flag_pressing = !flag_pressing;
}

void Button::remove_pressing()
{
	pressing = false;
	change_show_rect(0, 0);
}

void Button::set_pressing()
{
	pressing = true;
	change_show_rect(1, 0);
}
