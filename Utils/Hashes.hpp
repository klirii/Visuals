#pragma once
#include <iostream>
#include <Windows.h>
#include <VersionHelpers.h>
#include <comdef.h>
#include <Wbemidl.h>

#include <md5.h>
#include <md5.cpp>

#pragma comment(lib, "Wbemuuid.lib")
#pragma warning(disable:6386)

namespace Utils {
	class Hashes {
	private:
		static std::wstring GetWMIProperty(const wchar_t* className, const wchar_t* propertyName) {
            HRESULT hres;
            IWbemLocator* pLoc = NULL;
            IWbemServices* pSvc = NULL;
            IWbemClassObject* pclsObj = NULL;
            IEnumWbemClassObject* pEnumerator = NULL;
            std::wstring result;
            std::wstring query;
            bool initialized = true;
            ULONG uReturn = 0;

            hres = CoInitializeEx(0, COINIT_MULTITHREADED);
            if (FAILED(hres)) {
                initialized = false;

                if (hres != RPC_E_CHANGED_MODE)
                    goto cleanup;
            }
            else {
                hres = CoInitializeSecurity(
                    NULL,
                    -1,                          // COM authentication
                    NULL,                        // Authentication services
                    NULL,                        // Reserved
                    RPC_C_AUTHN_LEVEL_DEFAULT,   // Default authentication 
                    RPC_C_IMP_LEVEL_IMPERSONATE, // Default Impersonation  
                    NULL,                        // Authentication info
                    EOAC_NONE,                   // Additional capabilities 
                    NULL                         // Reserved
                );

                if (FAILED(hres) && hres != RPC_E_TOO_LATE) {
                    goto cleanup;
                }
            }

            hres = CoCreateInstance(
                CLSID_WbemLocator,
                0,
                CLSCTX_INPROC_SERVER,
                IID_IWbemLocator, (LPVOID*)&pLoc);

            if (FAILED(hres)) {
                goto cleanup;
            }

            hres = pLoc->ConnectServer(
                bstr_t(L"ROOT\\CIMV2"),  // Object path of WMI namespace
                NULL,                    // User name. NULL = current user
                NULL,                    // User password. NULL = current
                0,                       // Locale. NULL indicates current
                NULL,                    // Security flags.
                0,                       // Authority (for example, Kerberos)
                0,                       // Context object 
                &pSvc                    // pointer to IWbemServices proxy
            );

            if (FAILED(hres)) {
                goto cleanup;
            }

            hres = CoSetProxyBlanket(
                pSvc,                        // Indicates the proxy to set
                RPC_C_AUTHN_WINNT,           // RPC_C_AUTHN_xxx
                RPC_C_AUTHZ_NONE,            // RPC_C_AUTHZ_xxx
                NULL,                        // Server principal name 
                RPC_C_AUTHN_LEVEL_CALL,      // RPC_C_AUTHN_LEVEL_xxx 
                RPC_C_IMP_LEVEL_IMPERSONATE, // RPC_C_IMP_LEVEL_xxx
                NULL,                        // client identity
                EOAC_NONE                    // proxy capabilities 
            );

            if (FAILED(hres)) {
                goto cleanup;
            }

            query = L"SELECT * FROM " + std::wstring(className);

            hres = pSvc->ExecQuery(
                bstr_t("WQL"),
                bstr_t(query.c_str()),
                WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
                NULL,
                &pEnumerator);

            if (FAILED(hres)) {
                goto cleanup;
            }

            while (pEnumerator) {
                HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

                if (uReturn == 0) {
                    break;
                }

                VARIANT vtProp = {};

                hr = pclsObj->Get(propertyName, 0, &vtProp, 0, 0);
                if (SUCCEEDED(hr) && vtProp.vt == VT_BSTR) {
                    result = vtProp.bstrVal;
                    break;
                }

                VariantClear(&vtProp);

                pclsObj->Release();
            }

        cleanup:

            if (pSvc)
                pSvc->Release();
            if (pLoc)
                pLoc->Release();
            if (pEnumerator)
                pEnumerator->Release();
            if (initialized)
                CoUninitialize();

            return result;
        }

		static std::string GetRegValue(HKEY hKey, const std::wstring& valueName) {
			std::wstring wValue;
			WCHAR szBuffer[256];
			DWORD dwBufferSize = sizeof(szBuffer);

			LSTATUS status = RegQueryValueExW(hKey, valueName.c_str(), nullptr, nullptr, (LPBYTE)szBuffer, &dwBufferSize);
            if (status != ERROR_SUCCESS) exit(0);

			wValue = szBuffer;
			return std::string(wValue.begin(), wValue.end());
		}

		static std::string GetCompName() {
			WCHAR szBuffer[256];
			DWORD dwBufferSize = sizeof(szBuffer);

			LSTATUS status = GetComputerNameW(szBuffer, &dwBufferSize);
            if (status != TRUE) exit(0);

			std::wstring wCompName = szBuffer;
			return std::string(wCompName.begin(), wCompName.end());
		}
	public:
		static __forceinline std::string GetUnHash() {
			return md5(md5(getenv("USERNAME")));
		}

		static __forceinline std::string GetReHash() {
			HKEY hKey;
            std::string osuuid;
			const wchar_t* lpSubKey = nullptr;

			// Get VimeWorld OSUUID
            
			if (IsWindows10OrGreater()) lpSubKey = L"SOFTWARE\\VimeWorld"; 
			else if (IsWindows7OrGreater()) lpSubKey = L"Software\\VimeWorld";

			LSTATUS status = RegOpenKeyExW(HKEY_CURRENT_USER, lpSubKey, NULL, KEY_READ, &hKey);
            if (status == ERROR_SUCCESS) osuuid = GetRegValue(hKey, L"osuuid");

			// Get hardware guid
			status = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\IDConfigDB\\Hardware Profiles\\0001", NULL, KEY_READ, &hKey);
            if (status != ERROR_SUCCESS) exit(0);

			std::string hardware = GetRegValue(hKey, L"HwProfileGuid");
			hardware = std::string(hardware.begin() + 1, hardware.end() - 1);

			// Get motherboard product
            std::wstring wmotherboard = GetWMIProperty(L"Win32_BaseBoard", L"Product");
			std::string motherboard = std::string(wmotherboard.begin(), wmotherboard.end());

			// Get computer name
			std::string compName = GetCompName();
			std::string bind = motherboard + hardware + compName + osuuid;
			return md5(md5(bind));
		}
	};
}