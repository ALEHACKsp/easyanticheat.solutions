bool mfound = false;
void FindMatrix() {
	static DWORD64 dwGameObjectManager = 0;
	if (!dwGameObjectManager)
		dwGameObjectManager = RVA(FindPattern((PBYTE)"\x48\x8B\x15\x00\x00\x00\x00\x66\x39", "xxx????xx", L"UnityPlayer.dll"), 7);

	DWORD64 ObjMgr = read(dwGameObjectManager, DWORD64);
	if (!ObjMgr) return;
	UINT64 end = read(ObjMgr, UINT64);
	for (UINT64 Obj = read(ObjMgr + 0x8, UINT64); (Obj && (Obj != end)); Obj = read(Obj + 0x8, UINT64))
	{
		UINT64 GameObject = read(Obj + 0x10, UINT64);
		WORD Tag = read(GameObject + 0x54, WORD);
		if (Tag == 5)
		{
			UINT64 ObjClass = read(GameObject + 0x30, UINT64);
			UINT64	Entity = read(ObjClass + 0x18, UINT64);
			LocalPlayer.pViewMatrix = (Matrix4x4*)(Entity + 0xDC);
			printf(StrA("Found matrix!\n"));
			mfound = true;
			return;
		}
	}
}
void miscvis(DWORD64 ObjectClass, char* buff, bool boolean, bool showDistance, float drawDistance, const char* substring, const wchar_t* targettext, D2D1::ColorF color) {
	if (boolean && strstr(buff, substring)) {
		DWORD64 gameObject = read(ObjectClass + 0x30, DWORD64);
		DWORD64 transform = read(gameObject + 0x8, DWORD64);
		DWORD64 vector = read(transform + 0x38, DWORD64);
		Vector3 game_Pos = read(vector + 0x90, Vector3);
		Vector2 screen_Pos;
		if (LocalPlayer.WorldToScreen(game_Pos, screen_Pos)) {
			if ((int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(head), game_Pos) <= drawDistance) {
				wchar_t distance[64];
				_swprintf(distance, L"[ %d m ]", (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(head), game_Pos));
				wchar_t text[64];
				_swprintf(text, targettext);
				Render::Object.String({ screen_Pos.x, screen_Pos.y }, text, color, true, true);
				if (showDistance) {
					Render::Object.String(screen_Pos + Vector2(0, 15), distance, color, true, true);
				}
			}
		}
	}
}
void EntityZaLoop()
{
	float FOV = AimBot::Fov;
	float CurFOV;
	bool LP_isValid = false;
	if (!LocalPlayer.pViewMatrix || !mfound) {
		FindMatrix();
	}
	DWORD64 BaseNetworkable;
	BaseNetworkable = read(Storage::gBase + 0x29BF3E0, DWORD64); //BN 
	DWORD64 EntityRealm = read(BaseNetworkable + 0xB8, DWORD64);
	DWORD64 ClientEntities = read(EntityRealm, DWORD64);
	DWORD64 ClientEntities_list = read(ClientEntities + 0x10, DWORD64);
	DWORD64 ClientEntities_values = read(ClientEntities_list + 0x28, DWORD64);
	if (!ClientEntities_values) return;
	int EntityCount = read(ClientEntities_values + 0x10, int);
	wchar_t watermark[69];
	_swprintf(watermark, L"plusminus [ BN Size: %i ]", EntityCount);
	Render::Object.String(Vector2(100, 55), watermark, D2D1::ColorF(1.f, 1.f, 1.f, 1.f), true);
	DWORD64 EntityBuffer = read(ClientEntities_values + 0x18, DWORD64);
	for (int i = 0; i <= EntityCount; i++)
	{
		DWORD64 Entity = read(EntityBuffer + 0x20 + (i * 0x8), DWORD64);
		if (Entity <= 100000) continue;
		DWORD64 Object = read(Entity + 0x10, DWORD64);
		if (Object <= 100000) continue;
		DWORD64 ObjectClass = read(Object + 0x30, DWORD64);
		if (ObjectClass <= 100000) continue;
		pUncStr name = read(ObjectClass + 0x60, pUncStr);
		if (!name) continue;
		char* buff = name->stub;
		BasePlayer* Player = (BasePlayer*)read(Object + 0x28, DWORD64);
		if (strstr(buff, StrA("Local"))) {
			Player = (BasePlayer*)read(Object + 0x28, DWORD64);
			if (!read(Player + 0x4A8, DWORD64)) continue;
			if (Player != LocalPlayer.BasePlayer) {
				printf("LocalPlayer %lld\n", Player->GetSteamID());
				mfound = false;
			}
			LocalPlayer.BasePlayer = Player;
			LP_isValid = true;

		}
		else if (strstr(buff, "player.prefab") || (strstr(buff, "scientist")) && (!strstr(buff, "prop") && !strstr(buff, "corpse")))
		{
			BasePlayer* Player = (BasePlayer*)read(Object + 0x28, DWORD64);
			if (!read(Player + 0x4A8, DWORD64)) continue;
			ESP(Player, LocalPlayer.BasePlayer);
			if (PlayerEsp::sleeperignore && Player->HasFlags(16)) continue;
			if (AimBot::IgnoreNpc && Player->IsNpc()) continue;
			if (AimBot::IgnoreTeam && Player->IsTeamMate(LocalPlayer.BasePlayer->GetSteamID())) continue;
			if (Math::Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(head), Player->GetBoneByID(head)) > AimBot::Range) continue;

			if (FOV > (CurFOV = GetFov(Player, BoneList(Global::BoneToAim))) && !Player->IsDead()) {
				FOV = CurFOV; Storage::closestPlayer = (uintptr_t)Player;
			}
		}
		miscvis(ObjectClass, buff, Ores::Stone, Ores::showDistance, Ores::oreDrawDistance, "stone-ore.prefab", L"Stone Ore", D2D1::ColorF::Gray);
		miscvis(ObjectClass, buff, Ores::Stone, Ores::showDistance, Ores::oreDrawDistance, "stone-collectable.prefab", L"Stone Collectable", D2D1::ColorF::Gray);
		miscvis(ObjectClass, buff, Ores::Sulfur, Ores::showDistance, Ores::oreDrawDistance, "sulfur-ore.prefab", L"Sulfur Ore", D2D1::ColorF::Gold);
		miscvis(ObjectClass, buff, Ores::Sulfur, Ores::showDistance, Ores::oreDrawDistance, "sulfur-collectable.prefab", L"Sulfur Collectable", D2D1::ColorF::Gold);
		miscvis(ObjectClass, buff, Ores::Metal, Ores::showDistance, Ores::oreDrawDistance, "metal-ore.prefab", L"Metal Ore", D2D1::ColorF::SaddleBrown);
		miscvis(ObjectClass, buff, Ores::Metal, Ores::showDistance, Ores::oreDrawDistance, "metal-collectable.prefab", L"Metal Collectable", D2D1::ColorF::SaddleBrown);
		miscvis(ObjectClass, buff, Visuals::Supply, Visuals::crateDistance, Visuals::drawCrateDistance, "supply_drop.prefab", L"Airdrop", D2D1::ColorF::DarkCyan);
		miscvis(ObjectClass, buff, Visuals::Chinook, Visuals::crateDistance, Visuals::drawCrateDistance, "codelockedhackablecrate.prefab", L"Chinook Crate", D2D1::ColorF::DarkRed);
		miscvis(ObjectClass, buff, Visuals::Minicopter, Visuals::vehicleDistance, Visuals::drawVehicleDistance, "minicopter.entity.prefab", L"Minicopter", D2D1::ColorF::Blue);
		miscvis(ObjectClass, buff, Visuals::ScrapHeli, Visuals::vehicleDistance, Visuals::drawVehicleDistance, "scraptransporthelicopter.prefab", L"Scrap Heli", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Boat, Visuals::vehicleDistance, Visuals::drawVehicleDistance, "rowboat.prefab", L"Boat", D2D1::ColorF::LightBlue);
		miscvis(ObjectClass, buff, Visuals::RHIB, Visuals::vehicleDistance, Visuals::drawVehicleDistance, "rhib.prefab", L"RHIB", D2D1::ColorF::LightCyan);
		miscvis(ObjectClass, buff, Visuals::AutoTurret, Visuals::trapDistance, Visuals::drawTrapDistance, "autoturret_deployed.prefab", L"Auto Turret", D2D1::ColorF::Orange);
		miscvis(ObjectClass, buff, Visuals::FlameTurret, Visuals::trapDistance, Visuals::drawTrapDistance, "flameturret.deployed.prefab", L"Flame Turret", D2D1::ColorF::DarkOrange);
		miscvis(ObjectClass, buff, Visuals::ShotgunTurret, Visuals::trapDistance, Visuals::drawTrapDistance, "guntrap.deployed.prefab", L"Shotgun Trap", D2D1::ColorF::DimGray);
		miscvis(ObjectClass, buff, Visuals::Landmine, Visuals::trapDistance, Visuals::drawTrapDistance, "landmine.prefab", L"Landmine", D2D1::ColorF::BlueViolet);
		miscvis(ObjectClass, buff, Visuals::BearTrap, Visuals::trapDistance, Visuals::drawTrapDistance, "beartrap.prefab", L"Beartrap", D2D1::ColorF::Brown);
		miscvis(ObjectClass, buff, Visuals::Hemp, Visuals::otherDistance, Visuals::drawOtherDistance, "hemp.entity.prefab", L"Hemp", D2D1::ColorF::LimeGreen);
		miscvis(ObjectClass, buff, Visuals::Corpse, Visuals::otherDistance, Visuals::drawOtherDistance, "player_corpse.prefab", L"Corpse", D2D1::ColorF::Firebrick);
		miscvis(ObjectClass, buff, Visuals::Stash, Visuals::otherDistance, Visuals::drawOtherDistance, "small_stash_deployed.prefab", L"Stash", D2D1::ColorF::Yellow);
		miscvis(ObjectClass, buff, Visuals::PatrolHeli, Visuals::otherDistance, 4500.f, "assets/prefabs/npc/patrol helicopter/patrolhelicopter.prefab", L"Patrol Helicopter", D2D1::ColorF(0.3f, 0.34f, 1.f));
	}

	if (Storage::closestPlayer)
	{
		if (FOV < (CurFOV = GetFov((BasePlayer*)Storage::closestPlayer, BoneList(Global::BoneToAim))))
		{
			Storage::closestPlayer = 0;
		}
	}
	if (LP_isValid)
	{
		Aim((BasePlayer*)Storage::closestPlayer);
	}
	else LocalPlayer.BasePlayer = nullptr;
}