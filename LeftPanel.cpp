#include "LeftPanel.hpp"
#include "Button.hpp"

LeftPanel::LeftPanel(SDL_Renderer* render, float center_x, float center_y, float width, float height, 
	char direction, float object_distance, float distance_of_border_w, float distance_of_border_h)
	: Panel(render, center_x, center_y, width, height, direction, object_distance, 
		distance_of_border_w, distance_of_border_h)
{
	make_rect_button = static_cast<Button*>(add(std::make_shared<Button>(render, 0, 0, 80, 80)));
	make_rect_button->reset_pressing_flag();
	make_rect_button->set_texture("textures\\rect_button.png", 300, 300);

	make_line_button = static_cast<Button*>(add(std::make_shared<Button>(render, 0, 0, 80, 80)));
	make_line_button->set_texture("textures\\maket_button.png", 300, 300);

	make_round_button = static_cast<Button*>(add(std::make_shared<Button>(render, 0, 0, 80, 80)));
	make_round_button->set_texture("textures\\maket_button.png", 300, 300);

	add(std::make_shared<Button>(render, 0, 0, 80, 80))->set_texture("textures\\maket_button.png", 300, 300);
	add(std::make_shared<Button>(render, 0, 0, 80, 80))->set_texture("textures\\maket_button.png", 300, 300);
	add(std::make_shared<Button>(render, 0, 0, 80, 80))->set_texture("textures\\maket_button.png", 300, 300);
}

void LeftPanel::process_event(SDL_Event* event)
{
	Panel::process_event(event);
}
