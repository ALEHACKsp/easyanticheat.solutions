typedef void(__fastcall* SendProjectileAttack_fn)(void*, void*);
inline SendProjectileAttack_fn original_sendprojectileattack{ };

typedef uintptr_t(__fastcall* create_projectile_fn)(void*, void*, Vector3, Vector3, Vector3);
inline create_projectile_fn original_create_projectile{ };

typedef bool(__fastcall* can_attack_fn)(void*, void*);
inline can_attack_fn original_canattack;

typedef void(__fastcall* clientinput_fn)(DWORD64, DWORD64);
inline clientinput_fn original_clientinput;

typedef float(__fastcall* getspeed)(float*, float*);
inline getspeed original_getspeed;

typedef bool(__fastcall* sendclienttick)(void*);
inline sendclienttick original_sendclienttick;

typedef Vector3(__fastcall* modifiedaimconedirection)(float, Vector3, bool);
inline modifiedaimconedirection original_aimconedirection;

typedef void(__fastcall* SetFlying_fn)(void*, void*);
inline SetFlying_fn original_setflying{};

typedef pUncStr(__fastcall* consoleRun)(uintptr_t, pUncStr, DWORD64);
inline consoleRun original_consolerun{};

typedef void(__fastcall* block_sprint_fn)(void*);
inline block_sprint_fn original_blocksprint;

typedef bool(__fastcall* cancan)(void*, void*);
inline cancan original_canholditems;

typedef bool(__fastcall* issemiauto)(DWORD64);
inline issemiauto original_issemiauto;

typedef void(__fastcall* HandleRunning_fn)(void*, void*, bool);
inline HandleRunning_fn original_handleRunning{};

bool __fastcall SendClientTick(void* baseplayer) {
	if (Misc::AntiAim) {
		auto input = read(baseplayer + 0x4C8, uintptr_t);
		if (!input) {
			return original_sendclienttick(baseplayer);
		}
		auto state = read(input + 0x20, uintptr_t);
		if (!state) {
			return original_sendclienttick(baseplayer);
		}
		auto current = read(state + 0x10, uintptr_t);
		if (!current) {
			return original_sendclienttick(baseplayer);
		}
		write(current + 0x18, Vector3(100, rand() % 999 + -999, rand() % 999 + -999), Vector3);
	}
	return original_sendclienttick(baseplayer);
}
inline uintptr_t __fastcall CreateProjectile(void* BaseProjectile, void* prefab_pathptr, Vector3 pos, Vector3 forward, Vector3 velocity) {
	uintptr_t projectile = original_create_projectile(BaseProjectile, prefab_pathptr, pos, forward, velocity);
	auto* TargetPlayer = reinterpret_cast<BasePlayer*>(Storage::closestPlayer);
	write(projectile + 0x114, true, bool);
	if (Weapons::FatBullet) {
		write(projectile + 0x2C, 1.f, float);
	}
	else {
		write(projectile + 0x2C, 0.1f, float);
	}
	return projectile;
}
inline bool __fastcall CanAttack(void* a1, void* a2) {
	if (Weapons::jumpAim)
		return true;

	return original_canattack(a1, a2);
}
pUncStr __fastcall Run(uintptr_t options, pUncStr strCommand, DWORD64 args) {
	bool IsFromServer = read(options + 0x6, bool);
	if (IsFromServer) {
		std::wstring cmd = std::wstring(strCommand->str);
		if (cmd.find(L"noclip") != std::wstring::npos || cmd.find(L"debugcamera") != std::wstring::npos || cmd.find(L"camspeed") != std::wstring::npos || cmd.find(L"admintime") != std::wstring::npos) {
			strCommand = nullptr;
		}
	}
	return original_consolerun(options, strCommand, args);
}
bool __fastcall get_isSemiAuto(DWORD64 BaseProjectile) {
	if (Weapons::Automatic) {
		return false;
	}
	return original_issemiauto(BaseProjectile);
}
Vector3 __fastcall GetModifiedAimConeDirection(float aimCone, Vector3 inputVec, bool anywhereInside = true) { // wanna hang myself
	auto* TargetPlayer = reinterpret_cast<BasePlayer*>(Storage::closestPlayer);
	Vector3 dir = (Prediction(LocalPlayer.BasePlayer->GetBoneByID(head), TargetPlayer, head) - LocalPlayer.BasePlayer->GetBoneByID(head)).Normalized();
	if (AimBot::pSilent && Storage::closestPlayer != NULL) {
		inputVec = dir;
	}
	if (Weapons::AntiSpread) {
		aimCone = 0.f;
	}
	return original_aimconedirection(aimCone, inputVec, anywhereInside);
}
bool waslagging = false;
void __fastcall ClientInput(DWORD64 baseplayah, DWORD64 ModelState) {
	if (!waslagging && Misc::FakeLag) {
		write(LocalPlayer.BasePlayer + 0x5C8, 0.4f, float);
		waslagging = true;
	}
	else if (waslagging && !Misc::FakeLag) {
		write(LocalPlayer.BasePlayer + 0x5C8, 0.05f, float);
		waslagging = false;
	}
	WeaponPatch();
	MiscFuncs();
	typedef void(__stdcall* ClientInput)(DWORD64, DWORD64);
	((ClientInput)original_clientinput)(baseplayah, ModelState);
	if (Misc::Flyhack)
		LocalPlayer.BasePlayer->AddFlag(32);
	if (Misc::SilentWalk)
		LocalPlayer.BasePlayer->RemoveFlag(4);
}
bool __fastcall CanHoldItems(void* a1, void* a2) {
	if (Weapons::canHoldItems)
		return true;
	return original_canholditems(a1, a2);
}
inline void __fastcall SendProjectileAttack(void* a1, void* a2) {
	uintptr_t PlayerAttack = read((uintptr_t)a2 + 0x18, uintptr_t); // PlayerAttack playerAttack;
	uintptr_t Attack = read(PlayerAttack + 0x18, uintptr_t); // public Attack attack;
	if (AimBot::silentAim) {
		if (Storage::closestPlayer != NULL) {
			write(Attack + 0x30, 698017942, uint32_t); // public uint hitBone;
			write(Attack + 0x64, 16144115, uint32_t); // public uint hitPartID;
			if (AimBot::ThroughWall) {
				write(Attack + 0x4C, Vector3(0.f, -1000.f, 0.f) * -10000.f, Vector3); // public Vector3 hitNormalWorld;
			}
			write(Attack + 0x2C, read(read(Storage::closestPlayer + 0x50, uintptr_t) + 0x10, uintptr_t), uint32_t); // public uint hitID; 
		}
	}
	if (AimBot::AlwaysHeadshot) {
		write(Attack + 0x30, 698017942, uint32_t); // public uint hitBone;
	}
	return original_sendprojectileattack(a1, a2);
}
void __fastcall HandleRunning(void* a1, void* a2, bool wantsRun) {
	wantsRun = GetAsyncKeyState(0x10) && !GetAsyncKeyState(0x41) && !GetAsyncKeyState(0x53) && !GetAsyncKeyState(0x44);
	if (Misc::omniSprint)
		wantsRun = true;
	return original_handleRunning(a1, a2, wantsRun);
}
void __fastcall SetFlying(void* a1, void* a2) { }
void HookFunction(void* Function, void** Original, void* Detour, bool autoEnable = true) {
	if (MH_Initialize() != MH_OK && MH_Initialize() != MH_ERROR_ALREADY_INITIALIZED) { std::cout << ("Failed to initialize MinHook") << std::endl; return; }
	MH_CreateHook(Function, Detour, Original);
	if (autoEnable)
		MH_EnableHook(Function);
}
inline void InitHook() {
	if (MH_Initialize() != MH_OK && MH_Initialize() != MH_ERROR_ALREADY_INITIALIZED) {
		std::cout << "Failed to initialize Hook" << std::endl;
		return;
	}
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0x17DCEB0), (void**)&original_setflying, SetFlying);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0x2A6510 /*no change */), (void**)&original_sendprojectileattack, SendProjectileAttack);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0x28EE70 /*no change */), (void**)&original_canattack, CanAttack);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0x2A5E50 /*no change */), (void**)&original_sendclienttick, SendClientTick);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0x6CDD10 /*no change */), (void**)&original_handleRunning, HandleRunning);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0x788A40), (void**)&original_aimconedirection, GetModifiedAimConeDirection);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0x58A450), (void**)&original_create_projectile, CreateProjectile);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0x61DBF0 /*no change */), (void**)&original_canholditems, CanHoldItems);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0x1B5D0E0), (void**)&original_consolerun, Run);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0x28FAC0 /*no change */), (void**)&original_clientinput, ClientInput); // internal virtual void ClientInput(InputState state) { }
}