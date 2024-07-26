#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING

#include "ConfigManager.hpp"

#include <Windows.h>
#include <fstream>
#include <codecvt>
#include <string>

#include <StringUtils.h>
#include <StringUtils.cpp>
#include <nlohmann/json.hpp>

#pragma warning(disable:4244)

using json = nlohmann::json;

std::string ConfigManager::Loader = "";
std::string ConfigManager::Game = "";

std::string ConfigManager::ParseUsername(bool game) {
	if (!game) {
		Loader = std::string(getenv("APPDATA")) + "\\.vimeworld\\jre-x64\\lib\\security\\java8.security";

		std::string username;
		std::getline(std::ifstream(Loader), username);

		if (username.length() > 16) return "";
		return username;
	}
	else {
		HMODULE vimeworld = GetModuleHandleA("VimeWorld.exe");

		if (vimeworld) {
			Game = std::string(getenv("APPDATA")) + "\\.vimeworld\\config";

			std::wstring username;
			std::wifstream config(Game);

			config.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
			for (uint8_t i = 0; i < 2; i++) std::getline(config, username);

			char* lineParts[2];
			StringUtils::split(std::string(username.begin(), username.end()).c_str(), ':', lineParts);

			if (std::string(lineParts[1]).empty()) return "";
			return std::string(lineParts[1]);
		}
		else {
			Game = std::string(getenv("APPDATA")) + "\\.vimeworld\\launcher.json";

			std::ifstream launcher(Game);
			json data = json::parse(launcher);

			return data["last_account"].get<std::string>();
		}
	}
}

std::string ConfigManager::ParsePassword() {
	std::ifstream config(Loader);
	std::string password;

	for (uint8_t i = 0; i < 2; i++)
		std::getline(config, password);

	return password;
}