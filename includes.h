#pragma warning(disable : 4530)
#define _CRT_SECURE_NO_WARNINGS
#define ALLOC_CONS 0
#define StrA
#define StrW
#include <stdint.h>
#include <Windows.h>
#include <psapi.h>
#include <d3d11.h>
#include <emmintrin.h>
#include "winternl.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "offsets.h"
#include <signal.h>
#include <sstream>
#include <stdio.h>
#include <thread>
#include "xorstr.hpp"
#include "crt.h"
#include "ImGUI/imgui.h"
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
#include "sdk/utilities.h"
#include "sdk/mem.h"
#include "sdk_new/math.h"
#include "vars/vars.h"
#include "weapons.h"
#include "sdk/sdk.h"
#include "rendering.h"
#include "Minhook/include/MinHook.h"
#include "cheat_funcs/aim.h"
#include "cheat_funcs/misc.h"
#include "cheat_funcs/esp.h"
#include "cheat_funcs/entities.h"
#include "hooks.hpp"
#include "ImGUI/imgui_impl_win32.h"
#include "ImGUI/imgui_impl_dx11.h"
#include "ImGui/imgui_internal.h"
#include <d3d11.h>
#include "d3defs.h"
#include "imgui_elements.h"
//#include "font.h"
#include <Lmcons.h>

#include "Cfg/SimpleIni.h"
#include "Config.h"
#include "Init.h"
#include "Menu.h"
#include "start.h"
#pragma comment(lib, "urlmon.lib")
#include <d3d11.h>
#include <D3Dcompiler.h>
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "winmm.lib")