
#include "TextureHandler.hpp"
#include "Object.hpp"


Object::Object(SDL_Renderer* render, float center_x, float center_y, float width, float height)
	: render(render), center_x(center_x), center_y(center_y), width(width), height(height)
{
	left_border = center_x;
	right_border = center_x + width;
	upper_border = center_y;
	lower_border = center_y + height;

	set_frame_size();

	texture_handler = std::make_shared<TextureHandler>(this);
}

Object::~Object()
{
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
	}
}

void Object::init_display_size()
//������������� � ���������� display_bounds ������ ������
{
	SDL_Rect display_bounds;
	SDL_DisplayID id = SDL_GetPrimaryDisplay();
	SDL_GetDisplayBounds(id, &display_bounds);
	display_w = display_bounds.w;
	display_h = display_bounds.h;
}

bool Object::inside_clicked(SDL_Event* event)
//������� ���� ������ ������� �������. 
{
	if (event->type == SDL_EVENT_MOUSE_BUTTON_UP && 
		inside(event->button.x, event->button.y)) {
			return true;
		}
	return false;
}

bool Object::inside_moved(SDL_Event* event)
//�������� ���� ������ �������.
{
	if (event->type == SDL_EVENT_MOUSE_MOTION) {
		if (inside(event->button.x, event->button.y)) {
			return true;
		}
	}
	return false;
}

bool Object::inside_enter_exit(SDL_Event* event) {
	return inside_enter(event) || inside_exit(event);
}

bool Object::inside_enter(SDL_Event* event)
//��������� ������� ���� � ������� �������.
{
	if (inside_moved(event) && !cursor_inside) {
		cursor_inside = true;
		return true;
	}
	return false;
}

bool Object::inside_exit(SDL_Event* event)
//����� ������� ���� �� ������� �������.
{
	if (!inside_moved(event) && cursor_inside) {
		cursor_inside = false;
		return true;
	}
	return false;
}

bool Object::inside(float x, float y)
//����������� ������� ������� �� ���������� ..._border.
{
	if (x > left_border && x < right_border &&
		y > upper_border && y < lower_border)
	{ 
		return true; 
	}
	return false;
}

void Object::set_render_draw_color(std::array<uint8_t, 4> RGBA) {
	SDL_SetRenderDrawColor(render, RGBA[0], RGBA[1], RGBA[2], RGBA[3]);
}

std::array<uint8_t, 4> Object::unpack_from_uint8(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	return std::array<uint8_t, 4>{r, g, b, a};
}

void Object::set_texture(std::string file_name, float w, float h)
//��������� � ������������� ����������� �� ���������� ����.
// ��� ��������:
// w - ������ �����
// h - ������ �����
{
	texture = IMG_LoadTexture(render, file_name.c_str());
	size_texture_frame.x = center_x;
	size_texture_frame.y = center_y;
	size_texture_frame.w = width;
	size_texture_frame.h = height;
	show_texture_frame.x = 0;
	show_texture_frame.y = 0;
	show_texture_frame.w = w;
	show_texture_frame.h = h;
}

void Object::change_show_rect(int column, int row)
//��������� ������������� �����
{
	texture_handler->change_show_rect(column, row);
}

void Object::iterate() {
	if (texture != nullptr) { texture_handler->process(); }
	render_frame();
}

void Object::process_event(SDL_Event* event) {}

void Object::render_frame()
{
	if (flag_render_frame) {
		set_render_draw_color(frame_color);
		SDL_RenderRect(render, &frame);
	}
}

void Object::set_frame_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	frame_color = unpack_from_uint8(r, g, b, a); 
}

void Object::set_frame_size(float x)
//����� ������ ����� ��������� x.
{
	multiplier = x;
	frame.x = left_border - (right_border - left_border) * (x - 1) / 2;
	frame.y = upper_border - (lower_border - upper_border) * (x - 1) / 2;
	frame.w = (right_border - left_border) * x;
	frame.h = (lower_border - upper_border) * x;
}

void Object::reset_render_frame_flag() {
	flag_render_frame = !flag_render_frame;
}

void Object::set_size(float center_x, float center_y, float width, float height)
//��� -1.0 �������� ��������������� ����� ������������ �������.
{
	if (center_x != -1.0) { this->center_x = center_x; }
	if (center_y != -1.0) { this->center_y = center_y; }
	if (width != -1.0)	{ this->width = width; }
	if (height != -1.0) { this->height = height; }

	left_border = this->center_x;
	right_border = this->center_x + this->width;
	upper_border = this->center_y;
	lower_border = this->center_y + this->height;

	set_frame_size(multiplier);
}

void Object::start_anim(int num_anim, int shot_of_anim, int delay_ms) 
//������ ��� ������� �� ����������� �������.
{
	texture_handler->start_anim(num_anim, shot_of_anim, delay_ms);
}
