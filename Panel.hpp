#pragma once

#include <vector>
#include "Object.hpp"

//using iterator = std::vector<std::shared_ptr<Object>>::iterator;


class Panel : public Object
{
public:
	Panel(SDL_Renderer* render, float center_x, float center_y, float width, float height,
		char direction = 'h', float object_distance = 20, 
		float distance_of_border_w = 20, float distance_of_border_h = 20);

	virtual void process_event(SDL_Event* event) override;

	void iterate() override;

	Object* add(std::shared_ptr<Object> object);

	std::vector<std::shared_ptr<Object>> objects;

private:
	float distance_of_border_w;
	float distance_of_border_h;
	float volume_place = 0;
	float free_place = 0;
	float object_distance;
	char direction;
};

