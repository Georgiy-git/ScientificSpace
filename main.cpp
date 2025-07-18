#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <Windows.h>
#include <iostream>
#include <vector>

#include "EnumProcesses.hpp"
#include "MainProcess.hpp"

#include "Object.hpp"
#include "CloseButton.hpp"
#include "WrapButton.hpp"

#define CLOSE_BUTTON_TEXURE "textures\\anim_button_close.png"
#define WRAP_BUTTON_TEXURE "textures\\anim_wrap_button.png"

SDL_Window* window;
SDL_Renderer* render;
uint32_t this_process;
std::vector<Object*> objects;

MainProcess* main_process;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	Object::init_display_size();
	SDL_CreateWindowAndRenderer("Scientific Space", 0, 0, SDL_WINDOW_FULLSCREEN, &window, &render);
	objects.push_back(new CloseButton(render, Object::display_w - 75., 0., 75., 45., CLOSE_BUTTON_TEXURE));
	objects.push_back(new WrapButton(render, Object::display_w - 150., 0., 75., 45., WRAP_BUTTON_TEXURE, window));

	main_process = new MainProcess(render);
	this_process = MAIN_PROCESS;

	return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppIterate(void* appstate)
{
	SDL_SetRenderDrawColor(render, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(render);

	switch (this_process) {
	case MAIN_PROCESS:
		main_process->iterate();
	}

	for (auto object : objects) {
		object->iterate();
	}

	SDL_RenderPresent(render);
	SDL_Delay(10);
	return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
	if (event->type == SDL_EVENT_QUIT) return SDL_APP_SUCCESS;

	switch (this_process) {
	case MAIN_PROCESS:
		main_process->event(event);
	}

	for (auto object : objects) {
		object->process_event(event);
	}

	return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void* appstate, SDL_AppResult result)
{

}