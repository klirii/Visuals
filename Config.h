#pragma once

#include <iostream>
#include <vector>
#include <toml.hpp>

#include "Color.h"

class Config {
public:
	static void initialize();
	static void read();
private:
	static std::string config_path;
};

template<class Derived>
class OnEnableModule {
public:
	static bool enabled;
};

template<class Derived>
class ESP : public OnEnableModule<Derived> {
public:
	static std::string mode;
	static toml::value::array_type color;

	static bool outline;
	static toml::value::array_type outline_color;

	static bool filling;
	static toml::value::array_type filling_color;

	static Color get_color();
	static Color get_outline_color();
	static Color get_filling_color();
};

class PlayerESP : public ESP<PlayerESP> {};
class ChestESP : public ESP<ChestESP> {};
class NameTags : public OnEnableModule<NameTags> {};

class Chams {
public:
	static bool players;
	static bool chests;
};