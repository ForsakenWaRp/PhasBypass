// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Custom injected code entry point

#include "pch-il2cpp.h"

#define WIN32_LEAN_AND_MEAN
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
	//LogWrite("DoNothingCalled");
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

	//LogWrite("FileHooked\n");

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

	//LogWrite("DirectoryHooked\n");

	return Directory_Exists(str, method);
}

bool String_Contains_Hook(String* str, String* str2, MethodInfo* method)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> wideToNarrow;
	std::string skey = wideToNarrow.to_bytes(std::wstring((const wchar_t*)
		(&((Il2CppString*)str)->chars), ((Il2CppString*)str)->length));

	//LogWrite(skey);

	if(skey.find("MelonLoader") != std::string::npos || skey.find(NotMelonLoader) != std::string::npos)
	{
		return false;
	}

	return String_Contains(str, str2, method);
}

void* TryGetModuleHandleHook(String* str, MethodInfo* method)
{

	std::wstring_convert<std::codecvt_utf8<wchar_t>> wideToNarrow;
	std::string skey = wideToNarrow.to_bytes(std::wstring((const wchar_t*)
		(&((Il2CppString*)str)->chars), ((Il2CppString*)str)->length));

	//LogWrite(skey);

	return nullptr;
}

String* GetMelonLoaderSearchStrings(Byte__Array* theArray, bool b, MethodInfo* method)
{
	return not_melon_loader;
}

void CheckProcessesForModsFunc(MethodInfo* method)
{
	//LogWrite("CheckProcessesForMods");
}

void CheckForModsFunc(MethodInfo* method)
{
	//LogWrite("DoNothingCalled");
}

void Run()
{
	NewConsole();

	LogWrite("Starting Hooks");
	not_melon_loader = (String*)il2cpp_string_new(NotMelonLoader.c_str());
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)__104_____________9, TryGetModuleHandleHook);
	DetourAttach(&(PVOID&)__105____________, CheckProcessesForModsFunc);
	DetourAttach(&(PVOID&)__105_____________1, CheckForModsFunc);
	DetourAttach(&(PVOID&)__104____________, DoNothingMethod);
	DetourAttach(&(PVOID&)__104_____________1, DoNothingMethod);
	DetourAttach(&(PVOID&)__104_____________2, DoNothingMethod);
	DetourAttach(&(PVOID&)__104_____________4, DoNothingMethod);
	DetourAttach(&(PVOID&)__104_____________6, DoNothingMethod);
	DetourAttach(&(PVOID&)__104_____________7, DoNothingMethod);
	DetourAttach(&(PVOID&)__104_____________8, DoNothingMethod);
	DetourAttach(&(PVOID&)File_Exists, File_Exists_Hook);
	DetourAttach(&(PVOID&)Directory_Exists, Directory_Exists_Hook);
	DetourAttach(&(PVOID&)String_Contains, String_Contains_Hook);
	LONG lError = DetourTransactionCommit();
	if(lError != NO_ERROR)
	{
		LogWrite("Hook Failed");
	}

	LogWrite("Bypass hooked");
}
