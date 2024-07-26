#pragma once
#include <map>
#include <iostream>
#include <Windows.h>

class Keybind {
public:
	static byte GetVirtualKeyCodeByKeyName(std::string keyName) {
		std::map<std::string, byte> Keycodes = {
			{"MBUTTON", VK_MBUTTON},
			{"XBUTTON1", VK_XBUTTON1},
			{"XBUTTON2", VK_XBUTTON2},

			{"SHIFT", VK_SHIFT},
			{"LSHIFT", VK_LSHIFT},
			{"RSHIFT", VK_RSHIFT},

			{"CTRL", VK_CONTROL},
			{"LCTRL", VK_LCONTROL},
			{"RCTRL", VK_RCONTROL},

			{"ALT", VK_MENU},
			{"LALT", VK_LMENU},
			{"RALT", VK_RMENU},

			{"TAB", VK_TAB},
			{"BACKSPACE", VK_BACK},
			{"ENTER", VK_RETURN},
			{"PAUSE", VK_PAUSE},
			{"CAPS", VK_CAPITAL},
			{"ESCAPE", VK_ESCAPE},
			{"SPACE", VK_SPACE},
			{"PAGEUP", VK_PRIOR},
			{"PAGEDOWN", VK_NEXT},
			{"END", VK_END},
			{"HOME", VK_HOME},
			{"SELECT", VK_SELECT},
			{"PRINTSCREEN", VK_PRINT},
			{"NUM_LOCK", VK_NUMLOCK},
			{"SCROLL_LOCK", VK_SCROLL},

			{"0", 0x30},
			{"1", 0x31},
			{"2", 0x32},
			{"3", 0x33},
			{"4", 0x34},
			{"5", 0x35},
			{"6", 0x36},
			{"7", 0x37},
			{"8", 0x38},
			{"9", 0x39},

			{"NUMPAD_0", VK_NUMPAD0},
			{"NUMPAD_1", VK_NUMPAD1},
			{"NUMPAD_2", VK_NUMPAD2},
			{"NUMPAD_3", VK_NUMPAD3},
			{"NUMPAD_4", VK_NUMPAD4},
			{"NUMPAD_5", VK_NUMPAD5},
			{"NUMPAD_6", VK_NUMPAD6},
			{"NUMPAD_7", VK_NUMPAD7},
			{"NUMPAD_8", VK_NUMPAD8},
			{"NUMPAD_9", VK_NUMPAD9},

			{"F1", VK_F1},
			{"F2", VK_F2},
			{"F3", VK_F3},
			{"F4", VK_F4},
			{"F5", VK_F5},
			{"F6", VK_F6},
			{"F7", VK_F7},
			{"F8", VK_F8},
			{"F9", VK_F9},
			{"F10", VK_F10},
			{"F11", VK_F11},
			{"F12", VK_F12},

			{"A", 0x41},
			{"B", 0x42},
			{"C", 0x43},
			{"D", 0x44},
			{"E", 0x45},
			{"F", 0x46},
			{"G", 0x47},
			{"H", 0x48},
			{"I", 0x49},
			{"J", 0x4A},
			{"K", 0x4B},
			{"L", 0x4C},
			{"M", 0x4D},
			{"N", 0x4E},
			{"O", 0x4F},
			{"P", 0x50},
			{"Q", 0x51},
			{"R", 0x52},
			{"S", 0x53},
			{"T", 0x54},
			{"U", 0x55},
			{"V", 0x56},
			{"W", 0x57},
			{"X", 0x58},
			{"Y", 0x59},
			{"Z", 0x5A},

			{"LEFT", VK_LEFT},
			{"UP", VK_UP},
			{"RIGHT", VK_RIGHT},
			{"DOWN", VK_DOWN},
		};

		if (Keycodes.count(keyName))
			return Keycodes[keyName];

		return 0;
	}
};