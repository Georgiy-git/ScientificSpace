#pragma once

#include <SDL3/SDL.h>
#include <vector>
#include <memory>

class Object;
class Panel;
class LeftPanel;


class MainProcess
{
public:
	MainProcess(SDL_Renderer* render);

	void iterate();

	void event(SDL_Event* event);

private:
	SDL_Renderer* render;
	std::vector<Object*> objects;

	std::shared_ptr<LeftPanel> left_panel;
	std::shared_ptr<Panel> upper_toolbar;
};