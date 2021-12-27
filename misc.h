void WeaponPatch() {
	USHORT Hash = 0;
	WeaponData* Weapon = LocalPlayer.BasePlayer->GetActiveWeapon();
	if (Weapon) Hash = Weapon->GetNameHash();
	switch (Hash) {
	case 0x435E:
		Weapon->SuperEoka();
	}
}
void MiscFuncs() {
	LocalPlayer.BasePlayer->SetFov();
	if (Misc::SpiderMan)
		LocalPlayer.BasePlayer->SpiderMan();
	if (Weapons::NoSway)
		LocalPlayer.BasePlayer->NoSway();
	if (Misc::FakeAdmin)
		LocalPlayer.BasePlayer->FakeAdmin();
	if (Misc::WalkOnWater && GetAsyncKeyState(Keys::walkonWaterKey))
		LocalPlayer.BasePlayer->WalkWater();
	if (Weapons::NoRecoil)
		LocalPlayer.BasePlayer->SetRA();
}
