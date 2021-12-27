#pragma once
#include <direct.h>

CSimpleIniA cfg; //инициализируем объект

#pragma region Config Color

void SaveColorValue(const char* pSection, std::string name, float a_Value[4])
{
    int R, G, B, A;
    R = a_Value[0] * 1000;
    G = a_Value[1] * 1000;
    B = a_Value[2] * 1000;
    A = a_Value[3] * 1000;
    cfg.SetLongValue(pSection, (name + "_R").c_str(), R);
    cfg.SetLongValue(pSection, (name + "_G").c_str(), G);
    cfg.SetLongValue(pSection, (name + "_B").c_str(), B);
    cfg.SetLongValue(pSection, (name + "_A").c_str(), A);
}

void LoadColorValue(const char* pSection, std::string name, float a_Value[4])
{
    float R, G, B, A;
    R = cfg.GetLongValue(pSection, (name + "_R").c_str(), a_Value[0]);
    G = cfg.GetLongValue(pSection, (name + "_G").c_str(), a_Value[1]);
    B = cfg.GetLongValue(pSection, (name + "_B").c_str(), a_Value[2]);
    A = cfg.GetLongValue(pSection, (name + "_A").c_str(), a_Value[3]);
    a_Value[0] = R / 1000; a_Value[1] = G / 1000; a_Value[2] = B / 1000; a_Value[3] = A / 1000;
}

#pragma endregion 

inline bool folder_exists(const char* foldername)
{
    struct stat st;
    stat(foldername, &st);
    return st.st_mode & S_IFDIR;
}

void SaveCFG(const char* FileName)
{
    DWORD SerialNumber;

    GetVolumeInformation(L"C:\\", 0, 0, &SerialNumber, 0, 0, 0, 0);

    char Path[0x100];
    sprintf(Path, xorstr("C:\\Windows\\Temp\\plusminus\\"));

    if (!folder_exists(Path))
        _mkdir(Path);
    cfg.SetUnicode();
    char result[0x100];
    sprintf(result, xorstr("C:\\Windows\\Temp\\plusminus\\%s.ini"), FileName);

    cfg.SetBoolValue("Aim", "Silent Aim", AimBot::silentAim);
    cfg.SetBoolValue("Aim", "Silent Aim TW", AimBot::ThroughWall);
    cfg.SetBoolValue("Aim", "Always HS", AimBot::AlwaysHeadshot);
    cfg.SetBoolValue("Aim", "pSilent", AimBot::pSilent);
    cfg.SetBoolValue("Aim", "Activate Aimbot", AimBot::Activate);
    cfg.SetLongValue("Aim", "AimKey", Keys::aimKey);
    cfg.SetBoolValue("Aim", "Draw Fov", AimBot::DrawFov);
    cfg.SetLongValue("Aim", "Aim Fov", AimBot::Fov);
    cfg.SetLongValue("Aim", "Aim Distance", AimBot::Range);
    cfg.SetBoolValue("Aim", "Visible Check", AimBot::VisibleCheck);
    cfg.SetBoolValue("Aim", "NPC Check", AimBot::IgnoreNpc);

    cfg.SetBoolValue("Weapons", "NoRecoil", Weapons::NoRecoil);
    cfg.SetBoolValue("Weapons", "NoSpread", Weapons::AntiSpread);
    cfg.SetBoolValue("Weapons", "NoSway", Weapons::NoSway);
    //cfg.SetBoolValue("Weapons", "Automatic", Weapons::Automatic);
    //cfg.SetBoolValue("Weapons", "Rapid Fire", Weapons::RapidFire);
    cfg.SetBoolValue("Weapons", "Thick Bullets", Weapons::FatBullet);
    cfg.SetBoolValue("Weapons", "CanHoldItems", Weapons::canHoldItems);
    cfg.SetBoolValue("Weapons", "Insta-Eoka", Weapons::SuperEoka);

    cfg.SetBoolValue("Players", "Name", PlayerEsp::name);
    cfg.SetBoolValue("Players", "Box", PlayerEsp::box);
    cfg.SetBoolValue("Players", "Skeleton", PlayerEsp::skeleton);
    cfg.SetBoolValue("Players", "Healthbar", PlayerEsp::healthbar);
    cfg.SetBoolValue("Players", "Weapon", PlayerEsp::weapon);
    cfg.SetBoolValue("Players", "Tracers", PlayerEsp::tracers);
    cfg.SetBoolValue("Players", "Ignore Sleepers", PlayerEsp::sleeperignore);

    cfg.SetBoolValue("Visuals", "Crosshair", AimBot::Crosshair);

    cfg.SetBoolValue("Ores", "Stone", Ores::Stone);
    cfg.SetBoolValue("Ores", "Sulfur", Ores::Sulfur);
    cfg.SetBoolValue("Ores", "Metal", Ores::Metal);
    cfg.SetLongValue("Ores", "Draw Distance", Ores::oreDrawDistance);
    cfg.SetBoolValue("Ores", "Show Distance", Ores::showDistance);

    cfg.SetBoolValue("Crates", "Airdrops", Visuals::Supply);
    cfg.SetBoolValue("Crates", "Chinook Crates", Visuals::Chinook);
    cfg.SetLongValue("Crates", "Draw Distance", Visuals::drawCrateDistance);
    cfg.SetBoolValue("Crates", "Show Distance", Visuals::crateDistance);

    cfg.SetBoolValue("Vehicles", "Minicopters", Visuals::Minicopter);
    cfg.SetBoolValue("Vehicles", "Scrap Helis", Visuals::ScrapHeli);
    cfg.SetBoolValue("Vehicles", "Boats", Visuals::Boat);
    cfg.SetBoolValue("Vehicles", "RHIB's", Visuals::RHIB);
    cfg.SetLongValue("Vehicles", "Draw Distance", Visuals::drawVehicleDistance);
    cfg.SetBoolValue("Vehicles", "Show Distance", Visuals::vehicleDistance);

    cfg.SetBoolValue("Traps", "Auto Turrets", Visuals::AutoTurret);
    cfg.SetBoolValue("Traps", "Flame Turrets", Visuals::FlameTurret);
    cfg.SetBoolValue("Traps", "Shotgun Traps", Visuals::ShotgunTurret);
    cfg.SetBoolValue("Traps", "Landmines", Visuals::Landmine);
    cfg.SetBoolValue("Traps", "Beartraps", Visuals::BearTrap);
    cfg.SetLongValue("Traps", "Draw Distance", Visuals::drawTrapDistance);
    cfg.SetBoolValue("Traps", "Show Distance", Visuals::trapDistance);

    cfg.SetBoolValue("MiscV", "Patrol Heli", Visuals::PatrolHeli);
    cfg.SetBoolValue("MiscV", "Hemp", Visuals::Hemp);
    cfg.SetBoolValue("MiscV", "Corpses", Visuals::Corpse);
    cfg.SetBoolValue("MiscV", "Stashes", Visuals::Stash);
    cfg.SetLongValue("MiscV", "Draw Distance", Visuals::drawOtherDistance);
    cfg.SetBoolValue("MiscV", "Show Distance", Visuals::otherDistance);

    cfg.SetBoolValue("NPCs", "Name", BotsEsp::name);
    cfg.SetBoolValue("NPCs", "Box", BotsEsp::box);
    cfg.SetBoolValue("NPCs", "Skeleton", BotsEsp::skeleton);
    cfg.SetBoolValue("NPCs", "Health", BotsEsp::health);
    cfg.SetBoolValue("NPCs", "Healthbar", BotsEsp::healthbar);
    cfg.SetBoolValue("NPCs", "Weapon", BotsEsp::weapons);
    cfg.SetBoolValue("NPCs", "Distance", BotsEsp::distance);

    cfg.SetLongValue("Misc", "Fov Value", Misc::SexyFuckingFovValue);
    cfg.SetBoolValue("Misc", "Silent Walk", Misc::SilentWalk);
    cfg.SetBoolValue("Misc", "Spoof OnLadder", Misc::Flyhack);
    cfg.SetBoolValue("Misc", "Anti-Aim", Misc::AntiAim);
    cfg.SetBoolValue("Misc", "FakeLag", Misc::FakeLag);
    cfg.SetBoolValue("Misc", "FakeAdmin", Misc::FakeAdmin);
    cfg.SetBoolValue("Misc", "CanAttack", Weapons::jumpAim);
    cfg.SetBoolValue("Misc", "Omni-Sprint", Misc::omniSprint);
    cfg.SetBoolValue("Misc", "Spiderman", Misc::SpiderMan);
    cfg.SetBoolValue("Misc", "Gravity", Misc::Gravity);
    cfg.SetLongValue("Misc", "Gravity Value", Misc::GravityModifier);
    cfg.SetLongValue("Misc", "Gravity Key", Keys::gravityKey);
    cfg.SetBoolValue("Misc", "Keep Vertical Velocity", Misc::WalkOnWater);
    cfg.SetLongValue("Misc", "KVV Key", Keys::walkonWaterKey);

    cfg.SetBoolValue("Other", "Target Player Info [top left]", Other::InfoTopLeft);

    cfg.SaveFile(result);
    Beep(500, 125);
}

void LoadCFG(const char* FileName)
{
    DWORD SerialNumber;

    GetVolumeInformation(L"C:\\", 0, 0, &SerialNumber, 0, 0, 0, 0);

    char Path[0x100];
    sprintf(Path, xorstr("C:\\Windows\\Temp\\{%lu}\\"), SerialNumber);

    if (!folder_exists(Path))
        _mkdir(Path);
    cfg.SetUnicode();
    char result[0x100];
    sprintf(result, xorstr("C:\\Windows\\Temp\\{%lu}\\%s.ini"), SerialNumber, FileName);

    AimBot::silentAim = cfg.GetBoolValue("Aim", "Silent Aim", AimBot::silentAim);
    AimBot::ThroughWall = cfg.GetBoolValue("Aim", "Silent Aim TW", AimBot::ThroughWall);
    AimBot::AlwaysHeadshot = cfg.GetBoolValue("Aim", "Always HS", AimBot::AlwaysHeadshot);
    AimBot::pSilent = cfg.GetBoolValue("Aim", "pSilent", AimBot::pSilent);
    AimBot::Activate = cfg.GetBoolValue("Aim", "Activate Aimbot", AimBot::Activate);
    Keys::aimKey = cfg.GetLongValue("Aim", "AimKey", Keys::aimKey);
    AimBot::DrawFov = cfg.GetBoolValue("Aim", "Draw Fov", AimBot::DrawFov);
    AimBot::Fov = cfg.GetLongValue("Aim", "Aim Fov", AimBot::Fov);
    AimBot::Range = cfg.GetLongValue("Aim", "Aim Distance", AimBot::Range);
    AimBot::VisibleCheck = cfg.GetBoolValue("Aim", "Visible Check", AimBot::VisibleCheck);
    AimBot::IgnoreNpc = cfg.GetBoolValue("Aim", "NPC Check", AimBot::IgnoreNpc);

    Weapons::NoRecoil = cfg.GetBoolValue("Weapons", "NoRecoil", Weapons::NoRecoil);
    Weapons::AntiSpread = cfg.GetBoolValue("Weapons", "NoSpread", Weapons::AntiSpread);
    Weapons::NoSway = cfg.GetBoolValue("Weapons", "NoSway", Weapons::NoSway);
  //  Weapons::Automatic = cfg.GetBoolValue("Weapons", "Automatic", Weapons::Automatic);
 //   Weapons::RapidFire = cfg.GetBoolValue("Weapons", "Rapid Fire", Weapons::RapidFire);
    Weapons::FatBullet = cfg.GetBoolValue("Weapons", "Thick Bullets", Weapons::FatBullet);
    Weapons::canHoldItems = cfg.GetBoolValue("Weapons", "CanHoldItems", Weapons::canHoldItems);
    Weapons::SuperEoka = cfg.GetBoolValue("Weapons", "Insta-Eoka", Weapons::SuperEoka);

    PlayerEsp::name = cfg.GetBoolValue("Players", "Name", PlayerEsp::name);
    PlayerEsp::box = cfg.GetBoolValue("Players", "Box", PlayerEsp::box);
    PlayerEsp::skeleton = cfg.GetBoolValue("Players", "Skeleton", PlayerEsp::skeleton);
    PlayerEsp::healthbar = cfg.GetBoolValue("Players", "Healthbar", PlayerEsp::healthbar);
    PlayerEsp::weapon = cfg.GetBoolValue("Players", "Weapon", PlayerEsp::weapon);
    PlayerEsp::tracers = cfg.GetBoolValue("Players", "Tracers", PlayerEsp::tracers);
    PlayerEsp::sleeperignore = cfg.GetBoolValue("Players", "Ignore Sleepers", PlayerEsp::sleeperignore);

    AimBot::Crosshair = cfg.GetBoolValue("Visuals", "Crosshair", AimBot::Crosshair);

    /* cfg.GetBoolValue("Ores", "Stone", Ores::Stone);
     cfg.GetBoolValue("Ores", "Sulfur", Ores::Sulfur);
     cfg.GetBoolValue("Ores", "Metal", Ores::Metal);
     cfg.GetLongValue("Ores", "Draw Distance", Ores::oreDrawDistance);
     cfg.GetBoolValue("Ores", "Show Distance", Ores::showDistance);

     cfg.GetBoolValue("Crates", "Airdrops", Visuals::Supply);
     cfg.GetBoolValue("Crates", "Chinook Crates", Visuals::Chinook);
     cfg.GetLongValue("Crates", "Draw Distance", Visuals::drawCrateDistance);
     cfg.GetBoolValue("Crates", "Show Distance", Visuals::crateDistance);

     cfg.GetBoolValue("Vehicles", "Minicopters", Visuals::Minicopter);
     cfg.GetBoolValue("Vehicles", "Scrap Helis", Visuals::ScrapHeli);
     cfg.GetBoolValue("Vehicles", "Boats", Visuals::Boat);
     cfg.GetBoolValue("Vehicles", "RHIB's", Visuals::RHIB);
     cfg.GetLongValue("Vehicles", "Draw Distance", Visuals::drawVehicleDistance);
     cfg.GetBoolValue("Vehicles", "Show Distance", Visuals::vehicleDistance);

     cfg.GetBoolValue("Traps", "Auto Turrets", Visuals::AutoTurret);
     cfg.GetBoolValue("Traps", "Flame Turrets", Visuals::FlameTurret);
     cfg.GetBoolValue("Traps", "Shotgun Traps", Visuals::ShotgunTurret);
     cfg.GetBoolValue("Traps", "Landmines", Visuals::Landmine);
     cfg.GetBoolValue("Traps", "Beartraps", Visuals::BearTrap);
     cfg.GetLongValue("Traps", "Draw Distance", Visuals::drawTrapDistance);
     cfg.GetBoolValue("Traps", "Show Distance", Visuals::trapDistance);

     cfg.GetBoolValue("MiscV", "Patrol Heli", Visuals::PatrolHeli);
     cfg.GetBoolValue("MiscV", "Hemp", Visuals::Hemp);
     cfg.GetBoolValue("MiscV", "Corpses", Visuals::Corpse);
     cfg.GetBoolValue("MiscV", "Stashes", Visuals::Stash);
     cfg.GetLongValue("MiscV", "Draw Distance", Visuals::drawOtherDistance);
     cfg.GetBoolValue("MiscV", "Show Distance", Visuals::otherDistance);*/

    BotsEsp::name = cfg.GetBoolValue("NPCs", "Name", BotsEsp::name);
    BotsEsp::box = cfg.GetBoolValue("NPCs", "Box", BotsEsp::box);
    BotsEsp::skeleton = cfg.GetBoolValue("NPCs", "Skeleton", BotsEsp::skeleton);
    BotsEsp::health = cfg.GetBoolValue("NPCs", "Health", BotsEsp::health);
    BotsEsp::healthbar = cfg.GetBoolValue("NPCs", "Healthbar", BotsEsp::healthbar);
    BotsEsp::weapons = cfg.GetBoolValue("NPCs", "Weapon", BotsEsp::weapons);
    BotsEsp::distance = cfg.GetBoolValue("NPCs", "Distance", BotsEsp::distance);

    //Misc::SexyFuckingFov = cfg.GetBoolValue("Misc", "Custom FOV", Misc::SexyFuckingFov);
    Misc::SexyFuckingFovValue = cfg.GetLongValue("Misc", "Fov Value", Misc::SexyFuckingFovValue);
    Misc::SilentWalk = cfg.GetBoolValue("Misc", "Silent Walk", Misc::SilentWalk);
    Misc::Flyhack = cfg.GetBoolValue("Misc", "Spoof OnLadder", Misc::Flyhack);
    Misc::AntiAim = cfg.GetBoolValue("Misc", "Anti-Aim", Misc::AntiAim);
    Misc::FakeLag = cfg.GetBoolValue("Misc", "FakeLag", Misc::FakeLag);
    Misc::FakeAdmin = cfg.GetBoolValue("Misc", "FakeAdmin", Misc::FakeAdmin);
    Weapons::jumpAim = cfg.GetBoolValue("Misc", "CanAttack", Weapons::jumpAim);
    Misc::omniSprint = cfg.GetBoolValue("Misc", "Omni-Sprint", Misc::omniSprint);
    Misc::SpiderMan = cfg.GetBoolValue("Misc", "Spiderman", Misc::SpiderMan);
    Misc::CustomTime = cfg.GetBoolValue("Misc", "Custom Time", Misc::CustomTime);
    Misc::Time = cfg.GetLongValue("Misc", "Time", Misc::Time);
    Misc::Gravity = cfg.GetBoolValue("Misc", "Gravity", Misc::Gravity);
    Misc::GravityModifier = cfg.GetLongValue("Misc", "Gravity Value", Misc::GravityModifier);
    Keys::gravityKey = cfg.GetLongValue("Misc", "Gravity Key", Keys::gravityKey);
    Misc::WalkOnWater = cfg.GetBoolValue("Misc", "Keep Vertical Velocity", Misc::WalkOnWater);
    Keys::walkonWaterKey = cfg.GetLongValue("Misc", "KVV Key", Keys::walkonWaterKey);

    Other::InfoTopLeft = cfg.GetBoolValue("Other", "Target Player Info [top left]", Other::InfoTopLeft);

    cfg.LoadFile(result);
    Beep(350, 125);
};