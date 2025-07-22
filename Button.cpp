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
		if (inside_enter(event)) click_texture();
		if (inside_exit(event)) unclick_texture();
		if (inside_clicked(event) && flag_pressing) set_pressing();
	}
}

void Button::reset_pressing_flag()
{
	flag_pressing = !flag_pressing;
}

void Button::remove_pressing()
{
	pressing = false;
	unclick_texture();
}

void Button::set_pressing()
{
	pressing = true;
	click_texture();
}

void Button::click_texture()
{
	change_show_rect(1, 0);
}

void Button::unclick_texture()
{
	change_show_rect(0, 0);
}
