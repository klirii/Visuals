#define _CRT_SECURE_NO_WARNINGS

#include "Config.h"

#include <filesystem>
#include <fstream>
#include <Windows.h>

#define PARSE_ESP_TABLE(config, esp_module) {							\
	auto table = toml::find(config.unwrap(), #esp_module);				\
																		\
	esp_module::enabled = table.at("enabled").as_boolean();				\
																		\
	esp_module::mode = table.at("mode").as_string();					\
																		\
	esp_module::color = table.at("color").as_array();					\
																		\
	esp_module::outline = table.at("outline").as_boolean();				\
	esp_module::outline_color = table.at("outline_color").as_array();	\
																		\
	esp_module::filling = table.at("filling").as_boolean();				\
	esp_module::filling_color = table.at("filling_color").as_array();	\
}																		\

#define PARSE_ON_ENABLE_MODULE_TABLE(config, on_enable_module) {					\
	auto table = toml::find(config.unwrap(), #on_enable_module);					\
	OnEnableModule<on_enable_module>::enabled = table.at("enabled").as_boolean();	\
}																					\

template class ESP<PlayerESP>;
template class ESP<ChestESP>;

std::string Config::config_path = "";

template<class Derived> std::string ESP<Derived>::mode = "";
template<class Derived> toml::value::array_type ESP<Derived>::color;

template<class Derived> bool ESP<Derived>::outline = false;
template<class Derived> toml::value::array_type ESP<Derived>::outline_color;

template<class Derived> bool ESP<Derived>::filling = false;
template<class Derived> toml::value::array_type ESP<Derived>::filling_color;

template<class Derived> bool OnEnableModule<Derived>::enabled = false;

bool Chams::players = false;
bool Chams::chests = false;

void Config::initialize() {
	config_path = std::getenv("appdata") + std::string("\\.vimeworld\\minigames\\Visuals.toml");
}

void Config::read() {
	try {
		const auto config = toml::try_parse(config_path);

		if (config.is_ok()) {
			PARSE_ESP_TABLE(config, PlayerESP);
			PARSE_ESP_TABLE(config, ChestESP);

			auto chams = toml::find(config.unwrap(), "Chams");
			Chams::players = chams.at("players").as_boolean();
			Chams::chests = chams.at("chests").as_boolean();

			PARSE_ON_ENABLE_MODULE_TABLE(config, NameTags);
		}
	}
	catch (std::exception& exc) {}
}

template<class Derived>
Color ESP<Derived>::get_color() {
	return Color(
		static_cast<uint8_t>(ESP<Derived>::color[0].as_integer()),
		static_cast<uint8_t>(ESP<Derived>::color[1].as_integer()),
		static_cast<uint8_t>(ESP<Derived>::color[2].as_integer())
	);
}

template<class Derived>
Color ESP<Derived>::get_outline_color() {
	return Color(
		static_cast<uint8_t>(ESP<Derived>::outline_color[0].as_integer()),
		static_cast<uint8_t>(ESP<Derived>::outline_color[1].as_integer()),
		static_cast<uint8_t>(ESP<Derived>::outline_color[2].as_integer())
	);
}

template<class Derived>
Color ESP<Derived>::get_filling_color() {
	return Color(
		static_cast<uint8_t>(ESP<Derived>::filling_color[0].as_integer()),
		static_cast<uint8_t>(ESP<Derived>::filling_color[1].as_integer()),
		static_cast<uint8_t>(ESP<Derived>::filling_color[2].as_integer()),
		static_cast<uint8_t>(ESP<Derived>::filling_color[3].as_integer())
	);
}