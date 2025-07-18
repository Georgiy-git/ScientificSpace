
#include "Object.hpp"
#include "TextureHandler.hpp"


TextureHandler::TextureHandler(Object* object)
	: object{object} { }

void TextureHandler::start_anim(int num_anim, int shot_of_anim, int delay_ms)
{
	is_plaing = true;
	object->show_texture_frame.x = 0;
	object->show_texture_frame.y = num_anim * object->show_texture_frame.h;
	shot_num = 0;
	this->shot_of_anim = shot_of_anim;
	delay = std::chrono::milliseconds(delay_ms);
}

void TextureHandler::change_show_rect(int column, int row)
{
	object->show_texture_frame.x = object->show_texture_frame.w * column;
	object->show_texture_frame.y = object->show_texture_frame.h * row;
}

void TextureHandler::process()
{
	if (is_plaing) {
		if (std::chrono::steady_clock::now() - anim_start > delay) {
			if (shot_num < shot_of_anim) {
				//Сдвинуть рамку показа на ширину кадра.
				object->show_texture_frame.x += object->show_texture_frame.w;
				shot_num++;
				anim_start = std::chrono::steady_clock::now();
			}
			else {
				is_plaing = false;
				shot_num = 0;
			}
		}
	}

	SDL_RenderTexture(object->render, object->texture, 
		&object->show_texture_frame, &object->size_texture_frame);
}
