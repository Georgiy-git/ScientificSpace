#pragma once

#include <vector>
#include "Object.hpp"


class Panel : public Object
{
public:
	Panel(SDL_Renderer* render, float center_x, float center_y, float width, float height,
		char direction = 'h', float object_distance = 20, 
		float distance_of_border_w = 20, float distance_of_border_h = 20);

	virtual void event_process(SDL_Event* event) override;

	void iterate() override;

	Object* add(std::shared_ptr<Object> object);

	std::vector<std::shared_ptr<Object>> objects;

	void set_size_for_objects();

	size_t objects_count();

	float find_max_height();

	float find_max_width();

private:
	float distance_of_border_w;
	float distance_of_border_h;
	float volume_place = 0;
	float free_place = 0;
	float object_distance;
	char direction; // 'h' or 'v'
};

