//

void InitCheat()
{
	Vector2 kek = Render::Object.CanvasSize();
	Global::ScreenWidth = kek.x;
	Global::ScreenHigh = kek.y;
	if (AimBot::Crosshair) {
		float xs = Global::ScreenWidth / 2, ys = Global::ScreenHigh / 2;
		Render::Object.Line(Vector2{ xs, ys }, Vector2{ xs + 4, ys + 4 }, D2D1::ColorF::White, 0.7f);
		Render::Object.Line(Vector2{ xs, ys }, Vector2{ xs + 4, ys - 4 }, D2D1::ColorF::White, 0.7f);
		Render::Object.Line(Vector2{ xs, ys }, Vector2{ xs - 4, ys - 4 }, D2D1::ColorF::White, 0.7f);
		Render::Object.Line(Vector2{ xs, ys }, Vector2{ xs - 4, ys + 4 }, D2D1::ColorF::White, 0.7f);

		Render::Object.Line(Vector2{ xs + 4, ys + 4 }, Vector2{ xs + 4 + 4, ys + 4 + 4 }, D2D1::ColorF::Black, 0.7f);
		Render::Object.Line(Vector2{ xs + 4, ys - 4 }, Vector2{ xs + 4 + 4, ys - 4 - 4 }, D2D1::ColorF::Black, 0.7f);
		Render::Object.Line(Vector2{ xs - 4, ys - 4 }, Vector2{ xs - 4 - 4, ys - 4 - 4 }, D2D1::ColorF::Black, 0.7f);
		Render::Object.Line(Vector2{ xs - 4, ys + 4 }, Vector2{ xs - 4 - 4, ys + 4 + 4 }, D2D1::ColorF::Black, 0.7f);
	}
	if (AimBot::DrawFov) {
		float xs = Global::ScreenWidth / 2, ys = Global::ScreenHigh / 2;
		Render::Object.Ñircle(Vector2{ xs, ys }, D2D1::ColorF::White, AimBot::Fov, 1.f);
	}
	if (Storage::closestPlayer != NULL)
	{
		auto* TargetPlayer = reinterpret_cast<BasePlayer*>(Storage::closestPlayer);
		static float screenX = GetSystemMetrics(SM_CXSCREEN);
		static float screenY = GetSystemMetrics(SM_CYSCREEN);
		static Vector2 startPos = Vector2(screenX / 2.f, screenY - 200.f);
		Vector2 ScreenPos;
		if (PlayerEsp::targetline)
		{
			if (!(TargetPlayer->GetBoneByID(spine1).x == 0 && TargetPlayer->GetBoneByID(spine1).y == 0 && TargetPlayer->GetBoneByID(spine1).z == 0)) {
				if (LocalPlayer.WorldToScreen(TargetPlayer->GetBoneByID(head), ScreenPos))
					Render::Object.Line(startPos, ScreenPos, D2D1::ColorF::Red, 1.f);
			}
		}
	}
	if (AimBot::Fov > (kek.y - 3)) AimBot::Fov = (kek.y - 3);
	wchar_t watermark[64];
	static int cases = 0;
	static float r = 1.00f, g = 0.00f, b = 1.00f;
	switch (cases)
	{
	case 0: { r -= 0.05f; if (r <= 0) cases += 1; break; }
	case 1: { g += 0.05f; b -= 0.05f; if (g >= 1) cases += 1; break; }
	case 2: { r += 0.05f; if (r >= 1) cases += 1; break; }
	case 3: { b += 0.05f; g -= 0.05f; if (b >= 1) cases = 0; break; }
	default: { r = 1.00f; g = 0.00f; b = 1.00f; break; }
	}
	_swprintf(watermark, L"plusminus");
	Render::Object.String(Vector2(100, 55), watermark, D2D1::ColorF(r, g, b, 1.f), true);
	auto* TargetPlayerA = reinterpret_cast<BasePlayer*>(Storage::closestPlayer);
	wchar_t name[64];
	if (Other::InfoTopLeft)
	{
		if (Storage::closestPlayer != NULL)
		{
			float curhealth = (int)TargetPlayerA->GetHealth();
			if (!TargetPlayerA->IsNpc())
			{
				float maxheal = 100.f;
				if ((int)TargetPlayerA->GetHealth() <= 33)
				{
					Render::Object.FillRectangle(Vector2{ 100, 90 }, Vector2{ 150 * (curhealth / maxheal), 15 }, D2D1::ColorF(255.f, 0.f, 0.f, 0.8f));
				}
				if ((int)TargetPlayerA->GetHealth() >= 34 && (int)TargetPlayerA->GetHealth() <= 66)
				{
					Render::Object.FillRectangle(Vector2{ 100, 90 }, Vector2{ 150 * (curhealth / maxheal), 15 }, D2D1::ColorF(255.f, 202.f, 0.f, 0.8f));
				}
				if ((int)TargetPlayerA->GetHealth() >= 67)
				{
					Render::Object.FillRectangle(Vector2{ 100, 90 }, Vector2{ 150 * (curhealth / maxheal), 15 }, D2D1::ColorF(0.f, 255.f, 0.f, 0.8f));
				}
			}
			else
			{
				float maxhealxd = 150.f;
				if ((int)TargetPlayerA->GetHealth() <= 33)
				{
					Render::Object.FillRectangle(Vector2{ 100, 90 }, Vector2{ 150 * (curhealth / maxhealxd), 15 }, D2D1::ColorF(255.f, 0.f, 0.f, 0.8f));
				}
				if ((int)TargetPlayerA->GetHealth() >= 34 && (int)TargetPlayerA->GetHealth() <= 66)
				{
					Render::Object.FillRectangle(Vector2{ 100, 90 }, Vector2{ 150 * (curhealth / maxhealxd), 15 }, D2D1::ColorF(255.f, 202.f, 0.f, 0.8f));
				}
				if ((int)TargetPlayerA->GetHealth() >= 67)
				{
					Render::Object.FillRectangle(Vector2{ 100, 90 }, Vector2{ 150 * (curhealth / maxhealxd), 15 }, D2D1::ColorF(0.f, 255.f, 0.f, 0.8f));
				}
			}
			WeaponData* ActWeapon = TargetPlayerA->GetActiveWeapon();
			Render::Object.Rectangle(Vector2{ 100, 90 }, Vector2{ 150, 15 }, D2D1::ColorF::Black, 0.5f);
			if (!ActWeapon)
			{
				_swprintf(name, L"%s [%d m] [%d HP] [----]", TargetPlayerA->GetName(), (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(head), TargetPlayerA->GetBoneByID(head)), (int)TargetPlayerA->GetHealth());
			}
			else
			{
				_swprintf(name, L"%s [%d m] [%d HP] [%s]", TargetPlayerA->GetName(), (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(head), TargetPlayerA->GetBoneByID(head)), (int)TargetPlayerA->GetHealth(), ActWeapon->GetName());
			}
		}
		else
		{
			_swprintf(name, L"No target");
		}
		Render::Object.String(Vector2(100, 70), name, D2D1::ColorF::White, true);
	}
	EntityZaLoop();
}