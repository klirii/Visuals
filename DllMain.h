#include <Windows.h>

#include "GL/freeglut.h"
#include "Detours.h"
#include <nlohmann/json.hpp>

#include "RestAPI/Core/Client.hpp"
#include "RestAPI/Utils/Utils.hpp"

#include "Config/ConfigManager.hpp"
#include "Utils/Hashes.hpp"
#include "Utils/ErrorHandler.hpp"

#include "Color.h"
#include "Radius.h"
#include "Position.h"
#include "Config.h"

#define DLL_VIMEWORLD_ATTACH 0x888

#define M_PI 3.14159265358979323846

typedef void(__stdcall* T_glEnable)(GLenum);
typedef void(__stdcall* T_glDisable)(GLenum);

typedef BOOL(__stdcall* T_SwapBuffers)(HDC);
typedef void(__stdcall* T_glScalef)(float, float, float);
typedef void(__stdcall* T_glTranslatef)(float, float, float);
typedef void(__stdcall* T_glOrtho)(double, double, double, double, double, double);
typedef void (APIENTRY* T_glGetFloatv)(GLenum pname, GLfloat* params);

using json = nlohmann::json;
RestAPI::Client client;