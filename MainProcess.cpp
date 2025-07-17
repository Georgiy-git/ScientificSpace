

#include "MainProcess.hpp"
#include "Panel.hpp"


MainProcess::MainProcess(SDL_Renderer* render)
	: render{render}
{
	left_toolbar = std::make_shared<Panel>(
		render, 30, Object::display_h / 5, 120, 660, 'v', 20, 20, 40);
	left_toolbar->set_frame_size(1);
	left_toolbar->reset_render_frame_flag();
	objects.push_back(left_toolbar.get());

	left_toolbar->add(std::make_shared<Object>(render, 0, 0, 80, 80));
	left_toolbar->add(std::make_shared<Object>(render, 0, 0, 80, 80));
	left_toolbar->add(std::make_shared<Object>(render, 0, 0, 80, 80));
	left_toolbar->add(std::make_shared<Object>(render, 0, 0, 80, 80));
	left_toolbar->add(std::make_shared<Object>(render, 0, 0, 80, 80));
	left_toolbar->add(std::make_shared<Object>(render, 0, 0, 80, 80));

	upper_toolbar = std::make_shared<Panel>(render, 30, 10, 1410, 40, 'h', 30, 30, 5);
	upper_toolbar->set_frame_size(1);
	upper_toolbar->reset_render_frame_flag();
	objects.push_back(upper_toolbar.get());

	upper_toolbar->add(std::make_shared<Object>(render, 0, 0, 200, 30));
	upper_toolbar->add(std::make_shared<Object>(render, 0, 0, 200, 30));
	upper_toolbar->add(std::make_shared<Object>(render, 0, 0, 200, 30));
	upper_toolbar->add(std::make_shared<Object>(render, 0, 0, 200, 30));
	upper_toolbar->add(std::make_shared<Object>(render, 0, 0, 200, 30));
	upper_toolbar->add(std::make_shared<Object>(render, 0, 0, 200, 30));

	left_toolbar->objects[0]->set_texture("textures\\rect_button.png", 300, 300);
	left_toolbar->objects[0]->reset_render_frame_flag();
	for (int i = 1; i < 6; i++) {
		left_toolbar->objects[i]->set_texture("textures\\maket_button.png", 300, 300);
		left_toolbar->objects[i]->reset_render_frame_flag();
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