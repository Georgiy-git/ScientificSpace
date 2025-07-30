#include "PressButtonGroup.hpp"
#include "Object.hpp"


void PressButtonGroup::event_process(SDL_Event* event) {
	for (auto button : buttons) {
		if (button.first->inside_clicked(event)) {
			if (button.first != pressing) {
				press(button.first);
				state = button.second;
				break;
			}
			else {
				state = 0;
			}
		}
	}
}

void PressButtonGroup::press(Button* button)
{
	if (pressing != nullptr) pressing->remove_pressing();
	pressing = button;
}

void PressButtonGroup::add(Button* button, int state)
{
	buttons.push_back({ button, state });
	button->flag_pressing = true;
}

void PressButtonGroup::clear() {
	buttons.clear();
}
