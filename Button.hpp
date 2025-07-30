#pragma once

#include "Object.hpp";

class Button : public Object
{
public:
	Button(SDL_Renderer* render, float center_x, float center_y, float width, float height);

	virtual void event_process(SDL_Event* event) override;

	//Обработка фиксирования нажатия кнопки.
	void reset_pressing_flag();
	void remove_pressing();
	void set_pressing();
	bool pressing = false;
	bool flag_pressing = false;

	void click_texture();
	void unclick_texture();
};

