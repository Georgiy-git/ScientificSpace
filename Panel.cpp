#include "Panel.hpp"

Panel::Panel(SDL_Renderer* render, float center_x, float center_y, float width, float height,
	char direction, float object_distance, float distance_of_border_w, float distance_of_border_h)
	: Object(render, center_x, center_y, width, height),
	object_distance{ object_distance }, direction{ direction }, 
	distance_of_border_h{ distance_of_border_h }, distance_of_border_w{ distance_of_border_w }
{
	if (direction == 'h') {
		volume_place = width - 2 * distance_of_border_w;
	}
	if (direction == 'v') {
		volume_place = height - 2 * distance_of_border_h;
	}
	free_place = volume_place;
}

void Panel::process_event(SDL_Event* event)
{
	if (inside_clicked(event)) {
		for (auto object : objects) {
			object->process_event(event);
		}
	}
}

void Panel::iterate() {
	Object::iterate();
	for (auto object : objects) {
		object->iterate();
	}
}

void Panel::add(std::shared_ptr<Object> object)
{
	if (direction == 'h') {
		object->set_size(this->center_x + volume_place - free_place + distance_of_border_w);
		object->set_size(-1.0, this->center_y + distance_of_border_h);
		free_place -= object->width + object_distance;
	}
	else if (direction == 'v') {
		object->set_size(this->center_x + distance_of_border_w);
		object->set_size(-1.0, this->center_y + volume_place - free_place + distance_of_border_h);
		free_place -= object->height + object_distance;
	}

	object->reset_render_frame_flag();

	objects.push_back(object);
}


