// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Custom injected code entry point

#include "pch-il2cpp.h"

#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <codecvt>
#include <Windows.h>
#include <iostream>
#include <detours.h>
#include <locale>

#include "il2cpp-appdata.h"
#include "helpers.h"

using namespace app;

extern const LPCWSTR LOG_FILE = L"bypass-log.txt";

const std::string NotMelonLoader = "totally_not_melon_loader";
String* not_melon_loader;

void DoNothingMethod(MethodInfo* method)
{
#ifdef _DEEPDEBUG
	il2cppi_log_write("DoNothingMethod");
#endif
}

bool File_Exists_Hook(String* str, MethodInfo* method)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> wideToNarrow;
	std::string skey = wideToNarrow.to_bytes(std::wstring((const wchar_t*)
		(&((Il2CppString*)str)->chars), ((Il2CppString*)str)->length));
	if(skey.find("dll") != std::string::npos || skey.find(NotMelonLoader) != std::string::npos)
	{
		return false;
	}

#ifdef _DEBUG
	il2cppi_log_write("File_Exists_Hook: " + skey);
#endif

	return File_Exists(str, method);
}

bool Directory_Exists_Hook(String* str, MethodInfo* method)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> wideToNarrow;
	std::string skey = wideToNarrow.to_bytes(std::wstring((const wchar_t*)
		(&((Il2CppString*)str)->chars), ((Il2CppString*)str)->length));
	if(skey.find("MelonLoader") != std::string::npos || skey.find(NotMelonLoader) != std::string::npos)
	{
		return false;
	}

#ifdef _DEBUG
	il2cppi_log_write("Directory_Exists_Hook: " + skey);
#endif

	return Directory_Exists(str, method);
}

bool String_Contains_Hook(String* str, String* str2, MethodInfo* method)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> wideToNarrow;
	std::string skey = wideToNarrow.to_bytes(std::wstring((const wchar_t*)
		(&((Il2CppString*)str)->chars), ((Il2CppString*)str)->length));

	if(skey.find("MelonLoader") != std::string::npos
		|| skey.find(NotMelonLoader) != std::string::npos
		|| skey.find("bypass-log.txt") != std::string::npos
		|| skey.find("PhasBypass.dll") != std::string::npos
		|| skey.find("phasbypass.dll") != std::string::npos
		|| skey.find("imgui.ini") != std::string::npos
		|| skey.find("version.dll") != std::string::npos)
	{
		return false;
	}

#ifdef _DEBUG
	il2cppi_log_write("String_Contains_Hook: " + skey);
#endif

	return String_Contains(str, str2, method);
}

void* TryGetModuleHandleHook(String* str, MethodInfo* method)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> wideToNarrow;
	std::string skey = wideToNarrow.to_bytes(std::wstring((const wchar_t*)
		(&((Il2CppString*)str)->chars), ((Il2CppString*)str)->length));
	#ifdef _DEBUG
	il2cppi_log_write("TryGetModuleHandleHook: " + skey);
	#endif

	return nullptr;
}

String* GetMelonLoaderSearchStrings(Byte__Array* theArray, bool b, MethodInfo* method)
{
	#ifdef _DEBUG
		il2cppi_log_write("GetMelonLoaderSearchStrings");
	#endif
	return not_melon_loader;
}


void Run()
{
	il2cppi_new_console();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	il2cppi_log_write("[Cr:4n:kS.t4r] [C4PhasByP] !!! ONLY FOR !!! Server version: 0.3.1.0");
	il2cppi_log_write("[Cr:4n:kS.t4r] [C4PhasByP] !!! ONLY FOR !!! Steam Build ID: 7379698");
	SetConsoleTextAttribute(hConsole, 14);
	il2cppi_log_write("[Cr:4n:kS.t4r] [C4PhasByP] Creating Hooks!");
	not_melon_loader = (String*)il2cpp_string_new(NotMelonLoader.c_str());
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)__269____________, DoNothingMethod);
	DetourAttach(&(PVOID&)__269_____________1, DoNothingMethod);
	DetourAttach(&(PVOID&)__269_____________4, DoNothingMethod);
	DetourAttach(&(PVOID&)__274____________, DoNothingMethod);
	DetourAttach(&(PVOID&)__274_____________1, DoNothingMethod);
	DetourAttach(&(PVOID&)__274_____________2, DoNothingMethod);
	DetourAttach(&(PVOID&)__274_____________3, DoNothingMethod);
	DetourAttach(&(PVOID&)__274_____________4, DoNothingMethod);
	DetourAttach(&(PVOID&)__274_____________5, DoNothingMethod);
	DetourAttach(&(PVOID&)__274_____________6, DoNothingMethod);
	DetourAttach(&(PVOID&)__274_____________7, DoNothingMethod);
	DetourAttach(&(PVOID&)__274_____________8, DoNothingMethod);
	DetourAttach(&(PVOID&)__274_____________9, DoNothingMethod);
	DetourAttach(&(PVOID&)__274_____________10, TryGetModuleHandleHook);
	DetourAttach(&(PVOID&)File_Exists, File_Exists_Hook);
	DetourAttach(&(PVOID&)Directory_Exists, Directory_Exists_Hook);
	DetourAttach(&(PVOID&)String_Contains, String_Contains_Hook);

	#ifdef _DEBUG
		DetourAttach(&(PVOID&)Application_Quit_1, DoNothingMethod);
		DetourAttach(&(PVOID&)Application_Quit, DoNothingMethod);
		DetourAttach(&(PVOID&)Utils_1_ForceCrash, DoNothingMethod);
	#endif
	LONG lError = DetourTransactionCommit();
	if(lError != NO_ERROR)
	{
		SetConsoleTextAttribute(hConsole, 12);
		il2cppi_log_write("[Cr:4n:kS.t4r] [C4PhasByP] Hook creation failed!");
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 10);
		il2cppi_log_write("[Cr:4n:kS.t4r] [C4PhasByP] Hooks created!");
	}
	SetConsoleTextAttribute(hConsole, 15);
}
