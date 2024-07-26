#include "Utils.hpp"
#include <WinInet.h>
#pragma warning(disable:4267)

namespace RestAPI {
	std::string Utils::reverse_str(std::string str) {
		std::string reversedStr = str;
		reverse(reversedStr.begin(), reversedStr.end());
		return reversedStr;
	}

	std::vector<byte> Utils::hex2bytes(const std::string& hex) {
		std::vector<byte> bytes;

		for (unsigned int i = 0; i < hex.length(); i += 2) {
			std::string byteString = hex.substr(i, 2);
			char bytee = (char)strtol(byteString.c_str(), nullptr, 16);
			bytes.push_back(bytee);
		}

		return bytes;
	}

	std::string Utils::get_ip() {
		HINTERNET net = InternetOpenA("IP retriever", INTERNET_OPEN_TYPE_PRECONFIG, nullptr, nullptr, NULL);
		HINTERNET conn = InternetOpenUrlA(net, "https://api.ipify.org/?format=raw", nullptr, 0, INTERNET_FLAG_RELOAD, 0);

		char buffer[16];
		DWORD read = NULL;

		InternetReadFile(conn, buffer, sizeof(buffer) / sizeof(buffer[0]), &read);
		InternetCloseHandle(net);

		return std::string(buffer, read);
	}

	size_t CURLUtils::response2string(void* data, size_t size, size_t nmemb, void* userp) {
		((std::string*)userp)->append((char*)data, size * nmemb);
		return size * nmemb;
	}
}