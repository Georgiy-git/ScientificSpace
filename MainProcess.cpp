

#include "MainProcess.hpp"
#include "Panel.hpp"
#include "Button.hpp"
#include "LeftPanel.hpp"


MainProcess::MainProcess(SDL_Renderer* render)
	: render{render}
{
	left_panel = std::make_shared<LeftPanel>(
		this, render, 30, Object::display_h / 5, 120, 660, 'v', 20, 20, 40);
	objects.push_back(left_panel.get());


	upper_toolbar = std::make_shared<Panel>(render, 30, 10, 1410, 40, 'h', 30, 30, 5);
	upper_toolbar->reset_render_frame_flag();
	objects.push_back(upper_toolbar.get());

	upper_toolbar->add(std::make_shared<Button>(render, 0, 0, 200, 30));
	upper_toolbar->add(std::make_shared<Button>(render, 0, 0, 200, 30));
	upper_toolbar->add(std::make_shared<Button>(render, 0, 0, 200, 30));
	upper_toolbar->add(std::make_shared<Button>(render, 0, 0, 200, 30));
	upper_toolbar->add(std::make_shared<Button>(render, 0, 0, 200, 30));
	upper_toolbar->add(std::make_shared<Button>(render, 0, 0, 200, 30));

	for (auto obj : upper_toolbar->objects) {
		obj->reset_render_frame_flag();
	}
}

void MainProcess::iterate() {
	for (auto object : objects) {
		object->iterate();
	}
}

void MainProcess::event(SDL_Event* event) {
	for (auto object : objects) {
		object->process_event(event);
	}
}