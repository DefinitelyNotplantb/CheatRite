#pragma once
#ifndef _MEMORY_MANAGER_H
#define _MEMORY_MANAGER_H

#include <Windows.h>
#include <tlhelp32.h>
#include <string>
#include <iostream>

class MemoryManager
{
private:
	DWORD PID;		// process ID
	const std::string BATTLERITE_EXE = "Battlerite.exe";
	const std::string MONO_DLL = "mono.dll";
	const std::string FMODSTUDIO_DLL = "fmodstudio.dll";
public:
	HANDLE handle;
	DWORD Battlerite_Base;
	DWORD MonoDll_Base;
	DWORD FmodstudioDLL_Base;

  template<class c>
  c Read(DWORD dwAddress)
  {
    c val;
    ReadProcessMemory(handle, (LPVOID)dwAddress, &val, sizeof(c), NULL);
    return val;
  }

  template<class c>
  BOOL Write(DWORD dwAddress, c ValueToWrite)
  {
    return WriteProcessMemory(handle, (LPVOID)dwAddress, &ValueToWrite, sizeof(c), NULL);
  }

	MemoryManager();
};

#endif