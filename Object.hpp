#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <array>
#include <string>
#include <memory>


class Object
{
	friend class TextureHandler;

public:
	//Соответственно init, iter и event.
	Object(SDL_Renderer* render, float center_x, float center_y, float width, float height);
	virtual void iterate();
	virtual void process_event(SDL_Event* event);

	~Object();

	//Инициализация размера диспленя для класса.
	static void init_display_size();
	static inline int display_w;
	static inline int display_h;

	void set_texture(std::string file_name, float w, float h);
	void change_show_rect(int column, int row);

	void set_frame_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	void set_frame_size(float x = 1);
	void reset_render_frame_flag();

	void set_size(float center_x = -1, float center_y = -1, float width = -1, float height = -1);

	//Основные параметры размеров объекта.
	float center_x, center_y, width, height,
		left_border, right_border, upper_border, lower_border;

	//Обработка событий внутри объекта
	bool inside_clicked(SDL_Event* event);
	bool inside_moved(SDL_Event* event);
	bool inside_enter_exit(SDL_Event* event);
	bool inside_enter(SDL_Event* event);
	bool inside_exit(SDL_Event* event);

protected:
	virtual bool inside(float x, float y);	
	bool cursor_inside = false;;

	//Отрисовщик.
	void set_render_draw_color(std::array<uint8_t, 4> RGBA);
	SDL_Renderer* render = nullptr;
	static std::array<uint8_t, 4> unpack_from_uint8(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	//Обратока изображения.
	void start_anim(int num_anim = 0, int shot_of_anim = 1, int delay_ms = 50);
	std::shared_ptr<TextureHandler> texture_handler = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_FRect show_texture_frame;
	SDL_FRect size_texture_frame;
public:
	//Рамка выделения объекта.
	void render_frame();
	bool flag_render_frame = false;
	std::array<uint8_t, 4> frame_color = { 0, 255, 0, 255 };
	float multiplier;
	SDL_FRect frame;
};

