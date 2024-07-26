#pragma once
#include <Windows.h>
#include <iostream>

#define METHOD_NOT_FOUND 0x01
#define CLASS_NOT_FOUND	 0x02
#define FIELD_NOT_FOUND  0x03
#define OBJECT_NOT_FOUND 0x04

#define KEYBOARD_HOOK_ERROR 0x05

namespace Utils {
	class ErrorHandler {
	public:
		static HWND window;

		static void send(INT8 error) {
			char errorMessage[11];
			sprintf_s(errorMessage, "Ошибка #%d", error);
			MessageBoxA(window, errorMessage, "Velocity", MB_ICONERROR);
		}
	};

	HWND ErrorHandler::window = nullptr;
}