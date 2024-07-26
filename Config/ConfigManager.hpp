#pragma once
#include <iostream>

class ConfigManager {
public:
	static std::string ParseUsername(bool game = false);
	static std::string ParsePassword();
private:
	static std::string Loader;
	static std::string Game;
};