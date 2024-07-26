#include "Client.hpp"

#include "../Utils/Utils.hpp"
#include "../../Utils/Time.hpp"

// Network
#pragma comment(lib, "wldap32.lib")
#pragma comment(lib, "crypt32.lib")
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Normaliz.lib")

#define CURL_STATICLIB
#include <curl/curl.h>

#pragma warning(disable:4267)
#include "vault.hpp"
#include "vault.cpp"

#pragma warning(disable:26812)
#pragma warning(disable:4244)

namespace RestAPI {
	std::vector<byte> rolling_xor(std::vector<byte> bytes, bool decode = false) {
		if (decode) {
			reverse(bytes.begin(), bytes.end());
			std::vector<byte> output;

			for (int i = 0; i < bytes.size(); i++) {
				if (i == (bytes.size() - 1)) output.push_back(bytes[i]);
				else output.push_back(bytes[i] ^ bytes[i + 1]);
			}

			reverse(output.begin(), output.end());
			return output;
		}
		else {
			std::vector<byte> output(1);
			output[0] = bytes[0];

			for (int i = 0; i < (bytes.size() - 1); i++) output.push_back(bytes[i + 1] ^ output[i]);
			return output;
		}
	}

	json __forceinline decrypt(json data) {
		std::string document = data["document"];
		std::string hashblocks[4] = { data["hashblock1"], data["hashblock2"], data["hashblock3"], data["hashblock4"] };

		// Снятие rolling xor
		std::string hashblock6 = data["hashblock6"];
		uint8_t rollingXors = hashblock6[3] - '0';

		std::vector<byte> documentBytes = Utils::hex2bytes(document);
		for (uint8_t i = 0; i < rollingXors; i++)
			documentBytes = rolling_xor(documentBytes, true);

		// Снятие arc4
		std::string hashblock5 = data["hashblock5"];
		uint8_t sequence[4] = {
			static_cast<uint8_t>(hashblock5[7] - '0'),
			static_cast<uint8_t>(hashblock5[15] - '0'),
			static_cast<uint8_t>(hashblock5[23] - '0'),
			static_cast<uint8_t>(hashblock5[31] - '0')
		};

		document = std::string(reinterpret_cast<const char*>(&documentBytes[0]), documentBytes.size());
		for (uint8_t i = 0; i < 4; i++) {
			std::string key = Utils::reverse_str(hashblocks[sequence[i] - 1]);
			document = vault::ARC4(document, key);
		}

		replace(document.begin(), document.end(), '\'', '\"');
		return json::parse(document);
	}

	void Client::getdocument(std::string username, std::string password, std::string session, std::string hash) {
		CURL* curl = curl_easy_init();
		CURLcode reqCode;

		std::string url = this->host + "/getdocument?login=" + username + "&password=" + password + "&session=" + session + (hash.empty() ? "" : "&hash=" + hash);
		std::string response;
		json data;

		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, RestAPI::CURLUtils::response2string);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

		reqCode = curl_easy_perform(curl);
		if (reqCode != CURLE_OK) exit(0);

		data = json::parse(response);
		this->user.data = decrypt(data);

		curl_easy_cleanup(curl);
	}

	void Client::foobar(std::string destruction_username, std::string game_username, std::string func, std::string ip) {
		CURL* curl = curl_easy_init();
		CURLcode reqCode;

		std::string url = this->host + "/foobar?foo=" + destruction_username + "&bar=" + game_username + "&baz=" + func + "&egg=" + ip;
		std::string response;
		json data;

		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, RestAPI::CURLUtils::response2string);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

		reqCode = curl_easy_perform(curl);
		if (reqCode != CURLE_OK) exit(0);

		curl_easy_cleanup(curl);
	}
}