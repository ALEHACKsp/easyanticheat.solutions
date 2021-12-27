using namespace ImGui;
ImFont* font_main;
ImFont* font_menu;
void apply_fonts() {
	ImGui::CreateContext();

	font_main = ImGui::GetIO().Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Tahoma.ttf", 18);
	font_menu = ImGui::GetIO().Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Verdana.ttf", 12);
}
void HelpMarker(const char* desc)
{
	ImGui::TextDisabled("[?]");
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}
VOID ImGUI_Style()
{
	ImGuiStyle* style = &ImGui::GetStyle();
	ImVec4* colors = style->Colors;

	style->FrameRounding = 0.f;
	style->ChildRounding = 0.f;
	style->GrabRounding = 0.f;
	style->PopupRounding = 0.f;
	style->TabRounding = 0.f;
	style->WindowRounding = 0.f;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
	colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.29f, 0.48f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.16f, 0.29f, 0.48f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.24f, 0.52f, 0.88f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_Separator] = colors[ImGuiCol_Border];
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	colors[ImGuiCol_Tab] = ImLerp(colors[ImGuiCol_Header], colors[ImGuiCol_TitleBgActive], 0.80f);
	colors[ImGuiCol_TabHovered] = colors[ImGuiCol_HeaderHovered];
	colors[ImGuiCol_TabActive] = ImLerp(colors[ImGuiCol_HeaderActive], colors[ImGuiCol_TitleBgActive], 0.60f);
	colors[ImGuiCol_TabUnfocused] = ImLerp(colors[ImGuiCol_Tab], colors[ImGuiCol_TitleBg], 0.80f);
	colors[ImGuiCol_TabUnfocusedActive] = ImLerp(colors[ImGuiCol_TabActive], colors[ImGuiCol_TitleBg], 0.40f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
}
#include <mutex>
void MenuSteep() {
	ImGUI_Style();
	static int page = 0;
	if (ImGui::Begin("plusminus", &show, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize))
	{
		ImGui::SetWindowPos(ImVec2(500, 500), ImGuiCond_Once);
		ImGui::SetWindowSize(ImVec2(493, 530), ImGuiCond_Once);
		static int tabb = 0;
		if (ImGui::Button(xorstr("Aimbot")))
		{
			tabb = 0;
		}
		ImGui::SameLine();
		if (ImGui::Button(xorstr("Weapons")))
		{
			tabb = 1;
		}
		ImGui::SameLine();
		if (ImGui::Button(xorstr("Player")))
		{
			tabb = 2;
		}
		ImGui::SameLine();
		if (ImGui::Button(xorstr("Other Visuals")))
		{
			tabb = 3;
		}
		ImGui::SameLine();
		if (ImGui::Button(xorstr("Bots")))
		{
			tabb = 4;
		}
		ImGui::SameLine();
		if (ImGui::Button(xorstr("Misc")))
		{
			tabb = 5;
		}
		ImGui::SameLine();
		if (ImGui::Button(xorstr("Config")))
		{
			tabb = 6;
		}
		ImGui::Separator();
		switch (tabb) {
		case 0:
			ImGui::Checkbox(xorstr("Silent Aim"), &AimBot::silentAim);
			ImGui::SameLine();
			HelpMarker(xorstr("Shoot next to a person and the bullet will teleport to their head."));
			if (AimBot::silentAim)
			{
				ImGui::Checkbox(xorstr("Through Wall"), &AimBot::ThroughWall);
				ImGui::SameLine();
				HelpMarker(xorstr("Will make silent aim bullets go through the wall sometimes."));
			}
			ImGui::Checkbox(xorstr("Always Headshot"), &AimBot::AlwaysHeadshot);

			ImGui::Checkbox(xorstr("pSilent"), &AimBot::pSilent);
			ImGui::SameLine();
			HelpMarker(xorstr("Bullets will just fly to the targeted player."));
			ImGui::Checkbox(xorstr("Activate Aimbot"), &AimBot::Activate);
			Hotkey(xorstr("AimKey"), &Keys::aimKey, ImVec2(120.f, 0));
			ImGui::Checkbox(xorstr("Show Fov"), &AimBot::DrawFov);
			ImGui::SliderFloat(xorstr("Set Fov"), &AimBot::Fov, 20.f, 200.f);
			ImGui::SliderFloat(xorstr("Aim Distance"), &AimBot::Range, 0.f, 400.f);
			ImGui::Checkbox(xorstr("NPC Check"), &AimBot::IgnoreNpc);
			ImGui::Checkbox(xorstr("Teammate Check"), &AimBot::IgnoreTeam);
			ImGui::Checkbox(xorstr("Sleeper Check"), &AimBot::IgnoreSleepers);
			break;
		case 1:
			ImGui::Checkbox(xorstr("No Recoil"), &Weapons::NoRecoil);
			ImGui::Checkbox(xorstr("No Spread"), &Weapons::AntiSpread);
			ImGui::Checkbox(xorstr("No Sway"), &Weapons::NoSway);
			//ImGui::Checkbox("Rapid Fire", &Weapons::RapidFire);
			ImGui::Checkbox(xorstr("Thick Bullet"), &Weapons::FatBullet);
			ImGui::Checkbox(xorstr("Hold Items Anywhere"), &Weapons::canHoldItems);
			ImGui::SameLine();
			HelpMarker(xorstr("Allows you to hold items on minicopters."));
			ImGui::Checkbox(xorstr("100% Eoka"), &Weapons::SuperEoka);
			break;
		case 2:
			ImGui::Checkbox(xorstr("Name"), &PlayerEsp::name);
			ImGui::Checkbox(xorstr("Box"), &PlayerEsp::box);
			ImGui::Checkbox(xorstr("Skeleton"), &PlayerEsp::skeleton);
			ImGui::Checkbox(xorstr("Healthbar"), &PlayerEsp::healthbar);
			ImGui::Checkbox(xorstr("Weapon"), &PlayerEsp::weapon);
			ImGui::Checkbox(xorstr("Tracers"), &PlayerEsp::tracers);
			ImGui::Checkbox(xorstr("Target Tracers"), &PlayerEsp::targetline);
			ImGui::SameLine();
			HelpMarker(xorstr("Shows a line to the targeted player."));
			ImGui::Checkbox(xorstr("Ignore Sleepers"), &PlayerEsp::sleeperignore);
			break;
		case 3:

			ImGui::Checkbox(xorstr("Crosshair"), &AimBot::Crosshair);
			if (ImGui::CollapsingHeader(xorstr("Ores")))
			{
				ImGui::Checkbox(xorstr("Stone"), &Ores::Stone);
				ImGui::Checkbox(xorstr("Sulfur"), &Ores::Sulfur);
				ImGui::Checkbox(xorstr("Metal"), &Ores::Metal);
				if (Ores::Sulfur || Ores::Stone || Ores::Metal)
				{
					ImGui::SliderFloat(xorstr("Ore ESP Distance"), &Ores::oreDrawDistance, 5.f, 400.f);
					ImGui::Checkbox(xorstr("Show Distance"), &Ores::showDistance);
				}
			}
			if (ImGui::CollapsingHeader(xorstr("Other")))
			{
				if (ImGui::CollapsingHeader(xorstr("Crates")))
				{
					ImGui::Checkbox(xorstr("Airdrops"), &Visuals::Supply);
					ImGui::Checkbox(xorstr("Chinook Crates"), &Visuals::Chinook);
					if (Visuals::Supply || Visuals::Chinook)
					{
						ImGui::SliderFloat(xorstr("Crate ESP Distance"), &Visuals::drawCrateDistance, 5.f, 3000.f);
						ImGui::Checkbox(xorstr("Show Distance "), &Visuals::crateDistance);
					}
				}
				if (ImGui::CollapsingHeader(xorstr("Vehicles")))
				{
					ImGui::Checkbox(xorstr("Minicopters"), &Visuals::Minicopter);
					ImGui::Checkbox(xorstr("Scrap Helis"), &Visuals::ScrapHeli);
					ImGui::Checkbox(xorstr("Boats"), &Visuals::Boat);
					ImGui::Checkbox(xorstr("RHIB's"), &Visuals::RHIB);
					if (Visuals::Minicopter || Visuals::ScrapHeli || Visuals::Boat || Visuals::RHIB)
					{
						ImGui::SliderFloat(xorstr("Vehicle ESP Distance"), &Visuals::drawVehicleDistance, 5.f, 3000.f);
						ImGui::Checkbox(xorstr("Show Distance  "), &Visuals::vehicleDistance);
					}
				}
				if (ImGui::CollapsingHeader(xorstr("Traps")))
				{
					ImGui::Checkbox(xorstr("Auto Turrets"), &Visuals::AutoTurret);
					ImGui::Checkbox(xorstr("Flame Turrets"), &Visuals::FlameTurret);
					ImGui::Checkbox(xorstr("Shotgun Traps"), &Visuals::ShotgunTurret);
					ImGui::Checkbox(xorstr("Landmines"), &Visuals::Landmine);
					ImGui::Checkbox(xorstr("Beartraps"), &Visuals::BearTrap);
					if (Visuals::AutoTurret || Visuals::FlameTurret || Visuals::ShotgunTurret || Visuals::Landmine || Visuals::BearTrap)
					{
						ImGui::SliderFloat(xorstr("Trap ESP Distance"), &Visuals::drawTrapDistance, 5.f, 400.f);
						ImGui::Checkbox(xorstr("Show Distance   "), &Visuals::trapDistance);
					}
				}
				if (ImGui::CollapsingHeader(xorstr("Misc ")))
				{
					ImGui::Checkbox(xorstr("Patrol Heli"), &Visuals::PatrolHeli);
					ImGui::Checkbox(xorstr("Hemp"), &Visuals::Hemp);
					ImGui::Checkbox(xorstr("Corpses"), &Visuals::Corpse);
					ImGui::Checkbox(xorstr("Stashes"), &Visuals::Stash);
					if (Visuals::Corpse || Visuals::Stash || Visuals::Hemp || Visuals::PatrolHeli)
					{
						ImGui::SliderFloat(xorstr("Misc ESP Distance"), &Visuals::drawOtherDistance, 5.f, 400.f);
						ImGui::Checkbox(xorstr("Show Distance    "), &Visuals::otherDistance);
					}
				}
			}
			break;
		case 4:
			ImGui::Checkbox(xorstr("Name [b]"), &BotsEsp::name);
			ImGui::Checkbox(xorstr("Box [b]"), &BotsEsp::box);
			ImGui::Checkbox(xorstr("Skeleton [b]"), &BotsEsp::skeleton);
			ImGui::Checkbox(xorstr("Health [b]"), &BotsEsp::health);
			if (BotsEsp::health)
			{
				ImGui::Checkbox(xorstr("Healthbar [b]"), &BotsEsp::healthbar);
			}
			ImGui::Checkbox(xorstr("Weapon [b]"), &BotsEsp::weapons);
			ImGui::Checkbox(xorstr("Distance [b]"), &BotsEsp::distance);
			break;
		case 5:
			ImGui::SliderFloat(xorstr("Fov"), &Misc::SexyFuckingFovValue, 30.f, 130.f);
			ImGui::Checkbox(xorstr("Silent Walk"), &Misc::SilentWalk);
			ImGui::SameLine();
			HelpMarker(xorstr("You're like flying with noclip, but on the ground... But you're not flying."));
			ImGui::Checkbox(xorstr("Spoof OnLadder"), &Misc::Flyhack);
			ImGui::SameLine();
			HelpMarker(xorstr("Spoofs OnLadder state to true (looks funny)"));
			ImGui::Checkbox(xorstr("Anti-Aim"), &Misc::AntiAim);
			ImGui::SameLine();
			HelpMarker(xorstr("Makes you look like you're spinning on other people's screens."));
			ImGui::Checkbox(xorstr("FakeLag"), &Misc::FakeLag);
			ImGui::SameLine();
			HelpMarker(xorstr("Makes it looks like you're lagging on other people's screens."));
			ImGui::Checkbox(xorstr("FakeAdmin"), &Misc::FakeAdmin);
			ImGui::Checkbox(xorstr("Can Attack"), &Weapons::jumpAim);
			ImGui::SameLine();
			HelpMarker(xorstr("Allows you to shoot anywhere."));
			ImGui::Checkbox(xorstr("Omni-Sprint"), &Misc::omniSprint);
			ImGui::SameLine();
			HelpMarker(xorstr("Allows you to sprint in any direction."));
			ImGui::Checkbox(xorstr("Spiderman"), &Misc::SpiderMan);
			/*ImGui::Checkbox(xorstr("Custom Time"), &Misc::CustomTime);
			if (Misc::CustomTime)
			{
				ImGui::SliderFloat(xorstr("Time"), &Misc::Time, 0.f, 12.f);
			}*/
			ImGui::Checkbox(xorstr("Gravity"), &Misc::Gravity);
			if (Misc::Gravity)
			{
				ImGui::SliderFloat(xorstr("Gravity Value"), &Misc::GravityModifier, 0.f, 10.f);
				Hotkey(xorstr("Gravity Key"), &Keys::gravityKey, ImVec2(120.f, 0));
			}
			ImGui::Checkbox(xorstr("Keep Vertical Velocity"), &Misc::WalkOnWater);
			if (Misc::WalkOnWater)
			{
				Hotkey(xorstr("KVV Key"), &Keys::walkonWaterKey, ImVec2(120.f, 0));
			}
			break;
		case 6:
			ImGui::InputText("", Global::ConfigName, 0x100);
			if (ImGui::Button(xorstr("Save Config"), ImVec2(100.f, 0))) {
				SaveCFG(Global::ConfigName);
				Other::cfgSaved = true;
			}
			ImGui::SameLine();
			if (ImGui::Button(xorstr("Load Config"), ImVec2(100.f, 0))) {
				LoadCFG(Global::ConfigName);
			}
			ImGui::Checkbox(xorstr("Target Player info [top left]"), &Other::InfoTopLeft);
			if (ImGui::Button(xorstr("Panic"), ImVec2(100.f, 0))) {
				Global::Panic = true;
			}
			break;
		}
		ImGui::End();
	}
}