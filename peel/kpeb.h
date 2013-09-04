#pragma once

#include "peel.h"
#include <Windows.h>
#include <winternl.h>
#include <stddef.h>

#pragma region Structs
#   pragma pack(push, 4)
	    typedef struct _CURRENT_DIRECTORY {
		     UNICODE_STRING DosPath;
		     PVOID Handle;
	    } CURDIR; 

	    typedef struct _RTL_USER_PROCESS_PARAMETERS_X {
		     ULONG MaximumLength;
		     ULONG Length;
		     ULONG Flags;
		     ULONG DebugFlags;
		     PVOID ConsoleHandle;
		     ULONG ConsoleFlags;
		     PVOID StandardInput;
		     PVOID StandardOutput;
		     PVOID StandardError;
		     CURDIR CurrentDirectory;
		     UNICODE_STRING DllPath;
		     UNICODE_STRING ImagePathName;
		     UNICODE_STRING CommandLine;
		     PVOID Environment;
		     ULONG StartingX;
		     ULONG StartingY;
		     ULONG CountX;
		     ULONG CountY;
		     ULONG CountCharsX;
		     ULONG CountCharsY;
		     ULONG FillAttribute;
		     ULONG WindowFlags;
		     ULONG ShowWindowFlags;
		     UNICODE_STRING WindowTitle;
		     UNICODE_STRING DesktopInfo;
		     UNICODE_STRING ShellInfo;
		     UNICODE_STRING RuntimeData;
	    } PROCESS_PARAMETERS;

        typedef struct _PEB_LDR_MODULE32 {
            LIST_ENTRY              InLoadOrderModuleList;
            LIST_ENTRY              InMemoryOrderModuleList;
            LIST_ENTRY              InInitializationOrderModuleList;
            PVOID                   BaseAddress;
            PVOID                   EntryPoint;
            ULONG                   SizeOfImage;
            UNICODE_STRING          FullDllName;
            UNICODE_STRING          BaseDllName;
            ULONG                   Flags;
            SHORT                   LoadCount;
            SHORT                   TlsIndex;
            LIST_ENTRY              HashTableEntry;
            ULONG                   TimeDateStamp;
        } LDR_MODULE32;
#   pragma pack(pop)
#pragma endregion

#pragma region Prototypes
    void*         EXPORT LIBCALL KpGetCurrentPeb();
    LDR_MODULE32* EXPORT LIBCALL KpGetLdrModule(IN const wchar_t* wzName);
    wchar_t*      EXPORT LIBCALL KpGetEnvironmentVariable(IN const PEB* pPeb, IN const wchar_t* wzVar);
#pragma endregion