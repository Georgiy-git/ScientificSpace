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

void Panel::event_process(SDL_Event* event)
{
	if (inside_clicked(event) || inside_moved(event)) {
		for (auto object : objects) {
			object->event_process(event);
		}
	}
}

void Panel::iterate() {
	Object::iterate();
	for (auto object : objects) {
		object->iterate();
	}
}

Object* Panel::add(std::shared_ptr<Object> object)
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

	objects.push_back(object);
	return object.get();
}

void Panel::set_size_for_objects()
{
	float w, h;
	if (direction == 'h') {
		w = distance_of_border_w * 2;
		for (auto object : objects) {
			w += object->width;
		}
		if (objects_count() > 1) w += (objects_count() - 1) * object_distance;
		h = distance_of_border_h * 2 + find_max_height();
		set_size(-1, -1, w, h);
	}
	else if (direction == 'v') {
		float h = distance_of_border_h * 2;
		for (auto object : objects) {
			h += object->height;
		}
		if (objects_count() > 1) h += (objects_count() - 1) * object_distance;
		w = distance_of_border_w * 2 + find_max_width();
		set_size(-1, -1, w, h);
	}
}

size_t Panel::objects_count()
{
	return objects.size();
}

float Panel::find_max_height()
{
	float max = 0;
	for (auto object : objects) {
		if (object->height > max) max = object->height;
	}
	return max;
}

float Panel::find_max_width()
{
	float max = 0;
	for (auto object : objects) {
		if (object->width > max) max = object->width;
	}
	return max;
}
