#pragma once
#include <iostream>
#include <nlohmann/json.hpp>

namespace RestAPI {
	using json = nlohmann::json;

	class UserData {
	public:
		std::string name;
		std::string password;
		std::string session;
		json data;
	};

	class Client {
	public:
		std::string host;
		UserData user;

		void getdocument(std::string username, std::string password, std::string session, std::string hash);
		void foobar(std::string destruction_username, std::string game_username, std::string func, std::string ip);
	};
}