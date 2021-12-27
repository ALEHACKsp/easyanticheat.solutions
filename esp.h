void Skeleton(BasePlayer* BasePlayer)
{
	BoneList Bones[15] = {
		/*LF*/l_foot, l_knee, l_hip,
		/*RF*/r_foot, r_knee, r_hip,
		/*BD*/spine1, neck, head,
		/*LH*/l_upperarm, l_forearm, l_hand,
		/*RH*/r_upperarm, r_forearm, r_hand
	}; Vector2 BonesPos[15];

	//get bones screen pos
	for (int j = 0; j < 15; j++) {
		if (!LocalPlayer.WorldToScreen(BasePlayer->GetBoneByID(Bones[j]), BonesPos[j]))
			return;
	}
	if ((int)BasePlayer->GetHealth() > 0)
	{
		if (LocalPlayer.BasePlayer->IsTeamMate(BasePlayer->GetSteamID()))
		{
			for (int j = 0; j < 15; j += 3) {
				Render::Object.Line(Vector2{ BonesPos[j].x, BonesPos[j].y }, Vector2{ BonesPos[j + 1].x, BonesPos[j + 1].y }, D2D1::ColorF::LimeGreen, 0.5f);
				Render::Object.Line(Vector2{ BonesPos[j].x, BonesPos[j].y }, Vector2{ BonesPos[j + 1].x, BonesPos[j + 1].y }, D2D1::ColorF::LimeGreen);
				Render::Object.Line(Vector2{ BonesPos[j + 1].x, BonesPos[j + 1].y }, Vector2{ BonesPos[j + 2].x, BonesPos[j + 2].y }, D2D1::ColorF::LimeGreen, 0.5f);
				Render::Object.Line(Vector2{ BonesPos[j + 1].x, BonesPos[j + 1].y }, Vector2{ BonesPos[j + 2].x, BonesPos[j + 2].y }, D2D1::ColorF::LimeGreen);
			}

			//draw add lines
			Render::Object.Line(Vector2{ BonesPos[2].x, BonesPos[2].y }, Vector2{ BonesPos[6].x, BonesPos[6].y }, D2D1::ColorF::LimeGreen, 0.5f);
			Render::Object.Line(Vector2{ BonesPos[2].x, BonesPos[2].y }, Vector2{ BonesPos[6].x, BonesPos[6].y }, D2D1::ColorF::LimeGreen);
			Render::Object.Line(Vector2{ BonesPos[5].x, BonesPos[5].y }, Vector2{ BonesPos[6].x, BonesPos[6].y }, D2D1::ColorF::LimeGreen, 0.5f);
			Render::Object.Line(Vector2{ BonesPos[5].x, BonesPos[5].y }, Vector2{ BonesPos[6].x, BonesPos[6].y }, D2D1::ColorF::LimeGreen);
			Render::Object.Line(Vector2{ BonesPos[9].x, BonesPos[9].y }, Vector2{ BonesPos[7].x, BonesPos[7].y }, D2D1::ColorF::LimeGreen, 0.5f);
			Render::Object.Line(Vector2{ BonesPos[9].x, BonesPos[9].y }, Vector2{ BonesPos[7].x, BonesPos[7].y }, D2D1::ColorF::LimeGreen);
			Render::Object.Line(Vector2{ BonesPos[12].x, BonesPos[12].y }, Vector2{ BonesPos[7].x, BonesPos[7].y }, D2D1::ColorF::LimeGreen, 0.5f);
			Render::Object.Line(Vector2{ BonesPos[12].x, BonesPos[12].y }, Vector2{ BonesPos[7].x, BonesPos[7].y }, D2D1::ColorF::LimeGreen);
		}
		else
		{
			for (int j = 0; j < 15; j += 3) {
				Render::Object.Line(Vector2{ BonesPos[j].x, BonesPos[j].y }, Vector2{ BonesPos[j + 1].x, BonesPos[j + 1].y }, D2D1::ColorF::White, 0.5f);
				Render::Object.Line(Vector2{ BonesPos[j].x, BonesPos[j].y }, Vector2{ BonesPos[j + 1].x, BonesPos[j + 1].y }, D2D1::ColorF::White);
				Render::Object.Line(Vector2{ BonesPos[j + 1].x, BonesPos[j + 1].y }, Vector2{ BonesPos[j + 2].x, BonesPos[j + 2].y }, D2D1::ColorF::White, 0.5f);
				Render::Object.Line(Vector2{ BonesPos[j + 1].x, BonesPos[j + 1].y }, Vector2{ BonesPos[j + 2].x, BonesPos[j + 2].y }, D2D1::ColorF::White);
			}

			//draw add lines
			Render::Object.Line(Vector2{ BonesPos[2].x, BonesPos[2].y }, Vector2{ BonesPos[6].x, BonesPos[6].y }, D2D1::ColorF::White, 0.5f);
			Render::Object.Line(Vector2{ BonesPos[2].x, BonesPos[2].y }, Vector2{ BonesPos[6].x, BonesPos[6].y }, D2D1::ColorF::White);
			Render::Object.Line(Vector2{ BonesPos[5].x, BonesPos[5].y }, Vector2{ BonesPos[6].x, BonesPos[6].y }, D2D1::ColorF::White, 0.5f);
			Render::Object.Line(Vector2{ BonesPos[5].x, BonesPos[5].y }, Vector2{ BonesPos[6].x, BonesPos[6].y }, D2D1::ColorF::White);
			Render::Object.Line(Vector2{ BonesPos[9].x, BonesPos[9].y }, Vector2{ BonesPos[7].x, BonesPos[7].y }, D2D1::ColorF::White, 0.5f);
			Render::Object.Line(Vector2{ BonesPos[9].x, BonesPos[9].y }, Vector2{ BonesPos[7].x, BonesPos[7].y }, D2D1::ColorF::White);
			Render::Object.Line(Vector2{ BonesPos[12].x, BonesPos[12].y }, Vector2{ BonesPos[7].x, BonesPos[7].y }, D2D1::ColorF::White, 0.5f);
			Render::Object.Line(Vector2{ BonesPos[12].x, BonesPos[12].y }, Vector2{ BonesPos[7].x, BonesPos[7].y }, D2D1::ColorF::White);
		}

	}
	else
	{
		for (int j = 0; j < 15; j += 3) {
			Render::Object.Line(Vector2{ BonesPos[j].x, BonesPos[j].y }, Vector2{ BonesPos[j + 1].x, BonesPos[j + 1].y }, D2D1::ColorF::Red, 0.5f);
			Render::Object.Line(Vector2{ BonesPos[j].x, BonesPos[j].y }, Vector2{ BonesPos[j + 1].x, BonesPos[j + 1].y }, D2D1::ColorF::Red);
			Render::Object.Line(Vector2{ BonesPos[j + 1].x, BonesPos[j + 1].y }, Vector2{ BonesPos[j + 2].x, BonesPos[j + 2].y }, D2D1::ColorF::Red, 0.5f);
			Render::Object.Line(Vector2{ BonesPos[j + 1].x, BonesPos[j + 1].y }, Vector2{ BonesPos[j + 2].x, BonesPos[j + 2].y }, D2D1::ColorF::Red);
		}

		//draw add lines
		Render::Object.Line(Vector2{ BonesPos[2].x, BonesPos[2].y }, Vector2{ BonesPos[6].x, BonesPos[6].y }, D2D1::ColorF::Red, 0.5f);
		Render::Object.Line(Vector2{ BonesPos[2].x, BonesPos[2].y }, Vector2{ BonesPos[6].x, BonesPos[6].y }, D2D1::ColorF::Red);
		Render::Object.Line(Vector2{ BonesPos[5].x, BonesPos[5].y }, Vector2{ BonesPos[6].x, BonesPos[6].y }, D2D1::ColorF::Red, 0.5f);
		Render::Object.Line(Vector2{ BonesPos[5].x, BonesPos[5].y }, Vector2{ BonesPos[6].x, BonesPos[6].y }, D2D1::ColorF::Red);
		Render::Object.Line(Vector2{ BonesPos[9].x, BonesPos[9].y }, Vector2{ BonesPos[7].x, BonesPos[7].y }, D2D1::ColorF::Red, 0.5f);
		Render::Object.Line(Vector2{ BonesPos[9].x, BonesPos[9].y }, Vector2{ BonesPos[7].x, BonesPos[7].y }, D2D1::ColorF::Red);
		Render::Object.Line(Vector2{ BonesPos[12].x, BonesPos[12].y }, Vector2{ BonesPos[7].x, BonesPos[7].y }, D2D1::ColorF::Red, 0.5f);
		Render::Object.Line(Vector2{ BonesPos[12].x, BonesPos[12].y }, Vector2{ BonesPos[7].x, BonesPos[7].y }, D2D1::ColorF::Red);
	}
	//draw main lines

}
inline void CornerBox(float Entity_x, float Entity_y, float Entity_w, float Entity_h, D2D1::ColorF color)
{
	Render::Object.Line({ Entity_x, Entity_y }, { Entity_x + Entity_w / 3.5f, Entity_y }, D2D1::ColorF::Black, 3.f);
	Render::Object.Line({ Entity_x, Entity_y }, { Entity_x + Entity_w / 3.5f, Entity_y }, color);
	Render::Object.Line({ Entity_x, Entity_y }, { Entity_x,Entity_y + Entity_h / 3.5f }, D2D1::ColorF::Black, 3.f);
	Render::Object.Line({ Entity_x, Entity_y }, { Entity_x,Entity_y + Entity_h / 3.5f }, color);

	Render::Object.Line({ Entity_x + Entity_w, Entity_y }, { (Entity_x + Entity_w) - Entity_w / 3.5f, Entity_y }, D2D1::ColorF::Black, 3.f);
	Render::Object.Line({ Entity_x + Entity_w, Entity_y }, { (Entity_x + Entity_w) - Entity_w / 3.5f, Entity_y }, color);
	Render::Object.Line({ Entity_x + Entity_w, Entity_y }, { Entity_x + Entity_w,Entity_y + Entity_h / 3.5f }, D2D1::ColorF::Black, 3.f);
	Render::Object.Line({ Entity_x + Entity_w, Entity_y }, { Entity_x + Entity_w,Entity_y + Entity_h / 3.5f }, color);

	Render::Object.Line({ Entity_x + Entity_w, Entity_y + Entity_h }, { (Entity_x + Entity_w) - Entity_w / 3.5f, Entity_y + Entity_h }, D2D1::ColorF::Black, 3.f);
	Render::Object.Line({ Entity_x + Entity_w, Entity_y + Entity_h }, { (Entity_x + Entity_w) - Entity_w / 3.5f, Entity_y + Entity_h }, color);
	Render::Object.Line({ Entity_x + Entity_w, Entity_y + Entity_h }, { Entity_x + Entity_w,(Entity_y + Entity_h) - Entity_h / 3.5f }, D2D1::ColorF::Black, 3.f);
	Render::Object.Line({ Entity_x + Entity_w, Entity_y + Entity_h }, { Entity_x + Entity_w,(Entity_y + Entity_h) - Entity_h / 3.5f }, color);

	Render::Object.Line({ Entity_x, Entity_y + Entity_h }, { Entity_x + Entity_w / 3.5f, Entity_y + Entity_h }, D2D1::ColorF::Black, 3.f);
	Render::Object.Line({ Entity_x, Entity_y + Entity_h }, { Entity_x + Entity_w / 3.5f, Entity_y + Entity_h }, color);
	Render::Object.Line({ Entity_x, Entity_y + Entity_h }, { Entity_x,(Entity_y + Entity_h) - Entity_h / 3.5f }, D2D1::ColorF::Black, 3.f);
	Render::Object.Line({ Entity_x, Entity_y + Entity_h }, { Entity_x,(Entity_y + Entity_h) - Entity_h / 3.5f }, color);

}
void ESP(BasePlayer* BP, BasePlayer* LP)
{
	bool PlayerSleeping = BP->HasFlags(16);
	bool PlayerWounded = BP->HasFlags(64);
	if (PlayerEsp::sleeperignore && PlayerSleeping)
		return;

	if (PlayerEsp::skeleton && !BP->IsNpc())
		Skeleton(BP);

	Vector2 tempFeetR, tempFeetL;

	if (LocalPlayer.WorldToScreen(BP->GetBoneByID(r_foot), tempFeetR) && LocalPlayer.WorldToScreen(BP->GetBoneByID(l_foot), tempFeetL))
	{
		if (tempFeetR.x == 0 && tempFeetR.y == 0) return;

		Vector2 ScreenPos;
		Vector2 tempHead;
		if (LocalPlayer.WorldToScreen(BP->GetBoneByID(jaw) + Vector3(0.f, 0.16f, 0.f), tempHead))
		{
			Vector2 leftTopCorner = tempHead - Vector2(0.4f, 0.f);
			Vector2 rightBottomCorner = tempFeetR;


			Vector2 tempFeet = (tempFeetR + tempFeetL) / 2.f;
			float Entity_h = tempHead.y - tempFeet.y;
			float w = Entity_h / 4;
			float Entity_x = tempFeet.x - w;
			float Entity_y = tempFeet.y;
			float Entity_w = Entity_h / 2;
			bool PlayerWounded = BP->HasFlags(64);
			Vector3 middlePointWorld = BP->GetBoneByID(l_foot).midPoint(BP->GetBoneByID(r_foot));
			int CurPos = 0;
			auto* TargetPlayer = reinterpret_cast<BasePlayer*>(Storage::closestPlayer);
			Vector2 middlePointPlayerTop;
			Vector2 middlePointPlayerFeet;
			if (LocalPlayer.WorldToScreen(middlePointWorld + Vector3(0, 2, 0), middlePointPlayerTop) && LocalPlayer.WorldToScreen(middlePointWorld, middlePointPlayerFeet))
			{
				if (PlayerEsp::box && !BP->IsNpc())
				{
					if ((int)BP->GetHealth() > 0)
					{
						if (LocalPlayer.BasePlayer->IsTeamMate(BP->GetSteamID()))
						{
							CornerBox(Entity_x, Entity_y, Entity_w, Entity_h, D2D1::ColorF::LimeGreen);
						}
						else
						{
							CornerBox(Entity_x, Entity_y, Entity_w, Entity_h, D2D1::ColorF::White);
						}
					}
					else
					{
						CornerBox(Entity_x, Entity_y, Entity_w, Entity_h, D2D1::ColorF::Red);
					}
				}

				if (PlayerEsp::name && !BP->IsNpc())
				{
					wchar_t name[64];
					_swprintf(name, L"%s [%d]", BP->GetName(), (int)Math::Calc3D_Dist(LP->GetBoneByID(head), BP->GetBoneByID(head)));

					if (!PlayerSleeping)
					{
						if ((int)BP->GetHealth() > 0)
						{
							if (LocalPlayer.BasePlayer->IsTeamMate(BP->GetSteamID()))
							{
								Render::Object.String(Vector2{ middlePointPlayerTop.x, middlePointPlayerTop.y }, name, D2D1::ColorF::LimeGreen, true, true);
							}
							else
							{
								Render::Object.String(Vector2{ middlePointPlayerTop.x, middlePointPlayerTop.y }, name, D2D1::ColorF::White, true, true);
							}
						}
						else
						{
							Render::Object.String(Vector2{ middlePointPlayerTop.x, middlePointPlayerTop.y }, name, D2D1::ColorF::Red, true, true);
						}
					}
					else
					{
						Render::Object.String(Vector2{ middlePointPlayerTop.x, middlePointPlayerTop.y }, name, D2D1::ColorF::Orange, true, true);
					}
					CurPos += 15;
				}
				if (PlayerEsp::weapon && !BP->IsNpc())
				{

					const wchar_t* ActiveWeaponName;
					WeaponData* ActWeapon = BP->GetActiveWeapon();
					ActiveWeaponName = ActWeapon->GetName();
					if (!ActWeapon)
					{

						ActiveWeaponName = L"";
					}
					else
					{
						ActiveWeaponName = ActWeapon->GetName();
					}
					if (!PlayerSleeping)
					{
						if ((int)BP->GetHealth() > 0)
						{
							if (LocalPlayer.BasePlayer->IsTeamMate(BP->GetSteamID()))
							{
								Render::Object.String(Vector2{ middlePointPlayerFeet.x, middlePointPlayerFeet.y + 10.f }, ActiveWeaponName, D2D1::ColorF::LimeGreen, true, true);
							}
							else
							{
								Render::Object.String(Vector2{ middlePointPlayerFeet.x, middlePointPlayerFeet.y + 10.f }, ActiveWeaponName, D2D1::ColorF::White, true, true);
							}
						}
						else
						{
							Render::Object.String(Vector2{ middlePointPlayerFeet.x, middlePointPlayerFeet.y + 10.f }, ActiveWeaponName, D2D1::ColorF::Red, true, true);
						}
					}
					else
					{
						Render::Object.String(Vector2{ middlePointPlayerFeet.x, middlePointPlayerFeet.y + 10.f }, ActiveWeaponName, D2D1::ColorF::Orange, true, true);
					}
				}
				if (PlayerEsp::healthbar && !BP->IsNpc())
				{
					int health = (int)BP->GetHealth();
					float maxheal = 100.f;
					if ((int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(head), BP->GetBoneByID(head)) < 201)
					{
						//Render::Object.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h }, D2D1::ColorF(0.f, 0.f, 0.f, 0.4f));
						//Render::Object.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h * (health / minheal) }, D2D1::ColorF::Magenta);
						if ((int)BP->GetHealth() <= 33)
						{
							Render::Object.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h * (health / maxheal) }, D2D1::ColorF(255.f, 0.f, 0.f, 0.8f));
						}
						if ((int)BP->GetHealth() >= 34 && (int)BP->GetHealth() <= 66)
						{
							Render::Object.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h * (health / maxheal) }, D2D1::ColorF(255.f, 202.f, 0.f, 0.8f));
						}
						if ((int)BP->GetHealth() >= 67)
						{
							Render::Object.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h * (health / maxheal) }, D2D1::ColorF(0.f, 255.f, 0.f, 0.8f));
						}
						Render::Object.Rectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h }, D2D1::ColorF::Black, 0.5f);
					}
				}
				if (PlayerEsp::tracers && !PlayerSleeping && !BP->IsNpc())
				{
					static float screenX = GetSystemMetrics(SM_CXSCREEN);
					static float screenY = GetSystemMetrics(SM_CYSCREEN);
					static Vector2 startPos = Vector2(screenX / 2.0f, screenY - 200.f);
					if ((int)BP->GetHealth() > 0)
					{
						if (LocalPlayer.BasePlayer->IsTeamMate(BP->GetSteamID()))
						{
							Render::Object.Line(startPos, Vector2{ Entity_x + Entity_w / 2.f, Entity_y }, D2D1::ColorF::LimeGreen, 0.5f);
						}
						else
						{
							Render::Object.Line(startPos, Vector2{ Entity_x + Entity_w / 2.f, Entity_y }, D2D1::ColorF::White, 0.5f);
						}
					}
					else
					{
						Render::Object.Line(startPos, Vector2{ Entity_x + Entity_w / 2.f, Entity_y }, D2D1::ColorF::Red, 0.5f);
					}
				}
				// GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY 
				// GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY GAY

				if (BotsEsp::box && BP->IsNpc())
				{
					CornerBox(Entity_x, Entity_y, Entity_w, Entity_h, D2D1::ColorF(1, 1, 0, 1));
				}
				if (BotsEsp::name && BP->IsNpc())
				{
					Render::Object.String(Vector2{ (Entity_x + 7), (Entity_y + Entity_h) }, L"Bot", D2D1::ColorF::Yellow, true, true);
				}
				if (BotsEsp::health && BP->IsNpc())
				{
					int health = (int)BP->GetHealth();
					float maxheal = 300.f;

					wchar_t healtht[64];
					_swprintf(healtht, L"%d HP", (int)BP->GetHealth());
					Render::Object.String(Vector2{ Entity_x + 7.f, Entity_y + Entity_h + CurPos }, healtht, D2D1::ColorF::Yellow, true, true);
					CurPos += 15;
					if (BotsEsp::healthbar)
					{
						if ((int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(head), BP->GetBoneByID(head)) < 201)
						{
							//Render::Object.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h }, D2D1::ColorF(0.f, 0.f, 0.f, 0.4f));
							//Render::Object.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h * (health / minheal) }, D2D1::ColorF::Magenta);
							if ((int)BP->GetHealth() <= 33)
							{
								Render::Object.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h * (health / maxheal) }, D2D1::ColorF(255.f, 0.f, 0.f, 0.8f));
							}
							if ((int)BP->GetHealth() >= 34 && (int)BP->GetHealth() <= 66)
							{
								Render::Object.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h * (health / maxheal) }, D2D1::ColorF(255.f, 202.f, 0.f, 0.8f));
							}
							if ((int)BP->GetHealth() >= 67)
							{
								Render::Object.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h * (health / maxheal) }, D2D1::ColorF(0.f, 255.f, 0.f, 0.8f));
							}
							Render::Object.Rectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h }, D2D1::ColorF::Black, 0.5f);
						}
					}
				}
				if (BotsEsp::weapons && BP->IsNpc())
				{
					const wchar_t* ActiveWeaponName;
					WeaponData* ActWeapon = BP->GetActiveWeapon();
					ActiveWeaponName = ActWeapon->GetName();
					if (!ActWeapon)
					{
						ActiveWeaponName = L"-----";
					}
					else
					{
						ActiveWeaponName = ActWeapon->GetName();
					}
					Render::Object.String(Vector2{ (Entity_x + 7), (Entity_y + Entity_h + CurPos) }, ActiveWeaponName, D2D1::ColorF::Yellow, true, true);
					CurPos += 15;
				}
				if (BotsEsp::distance && BP->IsNpc())
				{
					wchar_t res[64];
					_swprintf(res, L"%d m", (int)Math::Calc3D_Dist(LP->GetBoneByID(head), BP->GetBoneByID(r_foot)));
					Render::Object.String(Vector2{ Entity_x + 7.f, Entity_y + Entity_h + CurPos }, res, D2D1::ColorF::Yellow, true, true);
					CurPos += 15;
				}
			}
		}
	}
}