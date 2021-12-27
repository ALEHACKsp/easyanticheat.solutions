#include "includes.h"
#include "curl.h"

char dlldir[320];
/*int Info_1;
int Info_2;
int Info_3;
int Info_4;
int Info_5;
int Info_6;
int HWID;
int HWID_List[69] = { 694272 , 258080 , 385072 };
void HWID_Handler() {
	SYSTEM_INFO siSysInfo;
	GetSystemInfo(&siSysInfo);
	Info_1 = siSysInfo.dwOemId;
	Info_2 = siSysInfo.dwNumberOfProcessors;
	Info_3 = siSysInfo.dwProcessorType;
	Info_4 = siSysInfo.dwActiveProcessorMask;
	Info_5 = siSysInfo.wProcessorLevel;
	Info_6 = siSysInfo.wProcessorRevision;
	int HWID_Calculator[6] = { Info_1, Info_2, Info_3, Info_4, Info_5, Info_6 };
	HWID = HWID_Calculator[0, 1, 2, 3, 4, 5] * 2 * Info_2;
}

void HWID_Checker(HINSTANCE hModule) {
	char name[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserNameW((LPWSTR)name, &username_len);
	std::string webhook_url = "https://discord.com/api/webhooks/775787141581766656/3T1huxSRxK9JUIB6ArLYHkno2cY2LIcrtLWl8xFbLkytpZ76kb7ooJ8EOM0azfeeuU9A";
	std::string avatar_url = "https://i.imgur.com/9FKjGO8.png";
	std::string winname = name;
	std::string userhwid = std::to_string(HWID);
	std::string fail = "curl --data \"username=plusminus&content=login failed: " + winname + " hwid: " + userhwid + "&avatar_url=" + avatar_url + "\" " + webhook_url;
	std::string success = "curl --data \"username=plusminus&content=login successful: " + winname + " hwid: " + userhwid + "&avatar_url=" + avatar_url + "\" " + webhook_url;

	if (HWID == HWID_List[0] || HWID == HWID_List[1] || HWID == HWID_List[2] || HWID == HWID_List[3] || HWID == HWID_List[4] || HWID == HWID_List[5] || HWID == HWID_List[6] || HWID == HWID_List[7] || HWID == HWID_List[8] || HWID == HWID_List[9] || HWID == HWID_List[10] || HWID == HWID_List[11] || HWID == HWID_List[12] || HWID == HWID_List[13] || HWID == HWID_List[14] || HWID == HWID_List[15] || HWID == HWID_List[16] || HWID == HWID_List[17] || HWID == HWID_List[18] || HWID == HWID_List[19] || HWID == HWID_List[20] || HWID == HWID_List[21] || HWID == HWID_List[22] || HWID == HWID_List[23] || HWID == HWID_List[24] || HWID == HWID_List[25]) {
		system(success.c_str());
		DisableThreadLibraryCalls(hModule);
		GetModuleFileName(hModule, (LPWSTR)dlldir, 512);
		for (size_t i = strlen(dlldir); i > 0; i--) { if (dlldir[i] == '\\') { dlldir[i + 1] = 0; break; } }
		CreateThread(NULL, 0, Start, NULL, 0, NULL);
	}
	else if (HWID != HWID_List[0] || HWID != HWID_List[1] || HWID != HWID_List[2] || HWID != HWID_List[3] || HWID != HWID_List[4] || HWID != HWID_List[5] || HWID != HWID_List[6] || HWID != HWID_List[7] || HWID != HWID_List[8] || HWID != HWID_List[9] || HWID != HWID_List[10] || HWID != HWID_List[11] || HWID != HWID_List[12] || HWID != HWID_List[13] || HWID != HWID_List[14] || HWID != HWID_List[15] || HWID != HWID_List[16] || HWID != HWID_List[17] || HWID != HWID_List[18] || HWID != HWID_List[19] || HWID != HWID_List[20] || HWID != HWID_List[21] || HWID != HWID_List[22] || HWID != HWID_List[23] || HWID != HWID_List[24] || HWID != HWID_List[25]) {
		//std::cout << "error: 0x" << HWID << std::endl;
		system(fail.c_str());
		exit(0);
	}
}*/
/* BOOL __stdcall DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved) {
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH: // A process is loading the DLL.
		//HWID_Handler();
		//HWID_Checker(hModule);
		break;
	case DLL_PROCESS_DETACH: // A process unloads the DLL.
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourDetach(&(LPVOID&)phookD3D11Present, (PBYTE)hookD3D11Present);
		DetourTransactionCommit();
		break;
	}
	return TRUE;
} */

BOOL __stdcall DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved) {
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH: // A process is loading the DLL.
		DisableThreadLibraryCalls(hModule);
		GetModuleFileName(hModule, (LPWSTR)dlldir, 512);
		for (size_t i = strlen(dlldir); i > 0; i--) { if (dlldir[i] == '\\') { dlldir[i + 1] = 0; break; } }
		CreateThread(NULL, 0, Start, NULL, 0, NULL);
		break;
	case DLL_PROCESS_DETACH: // A process unloads the DLL.
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourDetach(&(LPVOID&)phookD3D11Present, (PBYTE)hookD3D11Present);
		DetourTransactionCommit();
		break;
	}
	return TRUE;
}
