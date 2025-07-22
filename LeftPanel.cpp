#include "LeftPanel.hpp"
#include "Button.hpp"
#include "draw_states.hpp"
#include "MainProcess.hpp"


LeftPanel::LeftPanel(MainProcess* process, SDL_Renderer* render, float center_x, float center_y, float width, float height,
	char direction, float object_distance, float distance_of_border_w, float distance_of_border_h)
	: Panel(render, center_x, center_y, width, height, direction, object_distance,
		distance_of_border_w, distance_of_border_h), process(process)
{
	make_rect_button = static_cast<Button*>(add(std::make_shared<Button>(render, 0, 0, 80, 80)));
	make_rect_button->set_texture("textures\\rect_button.png", 300, 300);
	button_group.add(make_rect_button, RECT_DRAW_STATE);

	make_line_button = static_cast<Button*>(add(std::make_shared<Button>(render, 0, 0, 80, 80)));
	make_line_button->set_texture("textures\\line_button.png", 300, 300);
	button_group.add(make_line_button, LINE_DRAW_STATE);

	make_round_button = static_cast<Button*>(add(std::make_shared<Button>(render, 0, 0, 80, 80)));
	make_round_button->set_texture("textures\\round_button.png", 300, 300);
	button_group.add(make_round_button, ROUND_DRAW_STATE);

	add(std::make_shared<Button>(render, 0, 0, 80, 80))->set_texture("textures\\maket_button.png", 300, 300);
	add(std::make_shared<Button>(render, 0, 0, 80, 80))->set_texture("textures\\maket_button.png", 300, 300);
	add(std::make_shared<Button>(render, 0, 0, 80, 80))->set_texture("textures\\maket_button.png", 300, 300);
}

void LeftPanel::process_event(SDL_Event* event)
{
	Panel::process_event(event);

	if (inside_clicked(event)) {
		button_group.process_event(event);
	}

	if (button_group.state != process->draw_state) {
		process->draw_state = button_group.state;
	}
}
