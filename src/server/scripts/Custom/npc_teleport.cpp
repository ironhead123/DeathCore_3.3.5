#include "ScriptPCH.h"
#include "ScriptMgr.h"

enum Actions
{
	// alliance
    ACTION_TITLE_PRIVATE,
    ACTION_TITLE_CORPORAL,
    ACTION_TITLE_SERGEANT,
    ACTION_TITLE_MASTER_SERGEANT,
    ACTION_TITLE_SERGEANT_MAJOR,
    ACTION_TITLE_KNIGHT,
    ACTION_TITLE_KNIGHT_LIEUTENANT,
    ACTION_TITLE_KNIGHT_CAPTAIN,
    ACTION_TITLE_KNIGHT_CHAMPION,
    ACTION_TITLE_LIEUTENANT_COMMANDER,
    ACTION_TITLE_COMMANDER,
    ACTION_TITLE_MARSHAL,
    ACTION_TITLE_FIELD_MARSHAL,
    ACTION_TITLE_GRAND_MARSHAL,
    // horde
    ACTION_TITLE_SCOUT,
    ACTION_TITLE_GRUNT,
    ACTION_TITLE_SERGEANT_H,
    ACTION_TITLE_SENIOR_SERGEANT,
    ACTION_TITLE_FIRST_SERGEANT,
    ACTION_TITLE_STONE_GUARD,
    ACTION_TITLE_BLOOD_GUARD,
    ACTION_TITLE_LEGIONNAIRE,
    ACTION_TITLE_CENTURION,
    ACTION_TITLE_CHAMPION,
    ACTION_TITLE_LIEUTENANT_GENERAL,
    ACTION_TITLE_GENERAL,
    ACTION_TITLE_WARLORD,
    ACTION_TITLE_HIGH_WARLORD
};


class Teleporter_NPC_CreatureScript : public CreatureScript
{
public:
	Teleporter_NPC_CreatureScript() : CreatureScript("Teleporter_NPC_CreatureScript") { }

	bool OnGossipHello(Player* player, Creature* creature)
	{
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff888888 -------Menu-------", GOSSIP_SENDER_MAIN, 202);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|TInterface/ICONS/Achievement_Arena_2v2_7:30|t |cff873600 Mall", GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|TInterface/ICONS/INV_Misc_Coin_01:30|t |cff873600 Profession Place", GOSSIP_SENDER_MAIN, 4);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|TInterface/ICONS/INV_Misc_Coin_01:30|t |cff873600 Arena Que Place", GOSSIP_SENDER_MAIN, 6);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff888888 ----------PVP-----------", GOSSIP_SENDER_MAIN, 201);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|TInterface/ICONS/Achievement_Arena_2v2_7:30|t |cff873600 PvP Zone", GOSSIP_SENDER_MAIN, 1);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff888888 ------Player Service------", GOSSIP_SENDER_MAIN, 200);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|TInterface/ICONS/INV_Chest_Plate13:30|t |cff873600 Player Tools", GOSSIP_SENDER_MAIN, 10);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|TInterface/ICONS/INV_Chest_Plate13:30|t |cff873600 Morph Menu", GOSSIP_SENDER_MAIN, 50);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|TInterface/ICONS/INV_Chest_Plate13:30|t |cff873600 Exchanger Menu", GOSSIP_SENDER_MAIN, 60);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|TInterface/ICONS/INV_Chest_Plate13:30|t |cff873600 Title Menu", GOSSIP_SENDER_MAIN, 70);
		player->PlayerTalkClass->SendGossipMenu(creature->GetEntry(), creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
	{
		player->PlayerTalkClass->ClearMenus();

		if (sender == GOSSIP_SENDER_MAIN)
		{
          //  player->CLOSE_GOSSIP_MENU();
         //   return true;
        }
 
		switch (action)
		{

			case 1: // Gurubashi Arena.
				switch (player->GetTeam())
				{
				case ALLIANCE:
					player->TeleportTo(0, -13249.253906f, -82.411629f, 19.811203f, 1.523279f);
					player->PlayerTalkClass->SendCloseGossip();
					break;
				case HORDE:
					player->TeleportTo(0, -13534.602539f, 85.299316f, 28.701979f, 6.278640f);
					player->PlayerTalkClass->SendCloseGossip();
					break;
				}
				break;

            case 3: // MALL.
                player->TeleportTo(1, 6457.238281f, -4244.459473f, 667.190369f, 1.446752f);
                player->PlayerTalkClass->SendCloseGossip();
                break;

			case 4: // Profession Place
                player->TeleportTo(1, -6926.818359f, -4927.274902f, 0.715203f, 3.657583f);
                player->PlayerTalkClass->SendCloseGossip();
                break;

			case 6: //Arena Que Place
                player->TeleportTo(530, -855.770020f, 6997.636230f, 34.994953f, 1.067743f);
                player->PlayerTalkClass->SendCloseGossip();
                break;

				case 10:
				player->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/Achievement_Arena_3v3_5:30|t |cff873600 <-- Back", GOSSIP_SENDER_MAIN, 1111);
				player->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/INV_Misc_Coin_05:30|t |cffFF4500 Remove my Sickness", GOSSIP_SENDER_MAIN, 31);
				player->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/INV_Misc_Coin_05:30|t |cffFF4500 Reset my Cooldowns", GOSSIP_SENDER_MAIN,32);
				player->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/INV_Misc_Coin_05:30|t |cffFF4500 Repair Items", GOSSIP_SENDER_MAIN, 33);
				player->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/INV_Misc_Coin_05:30|t |cffFF4500 Change my Faction", GOSSIP_SENDER_MAIN, 34);
				player->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/INV_Misc_Coin_05:30|t |cffFF4500 Change my Race", GOSSIP_SENDER_MAIN, 35);
				player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
				return true;

			case 50: // Morph Menu	
				player->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/Achievement_Arena_3v3_5:30|t |cff873600 <--Back", GOSSIP_SENDER_MAIN, 1111);
				player->ADD_GOSSIP_ITEM(8, "|TInterface/ICONS/Thrown_1H_Harpoon_D_01Blue:30|t |cff0000ff Gnome - Male", GOSSIP_SENDER_MAIN, 12);
				player->ADD_GOSSIP_ITEM(8, "|TInterface/ICONS/Thrown_1H_Harpoon_D_01Blue:30|t |cff0000ff Gnome - Female", GOSSIP_SENDER_MAIN, 13);
				player->ADD_GOSSIP_ITEM(8, "|TInterface/ICONS/Thrown_1H_Harpoon_D_01Blue:30|t |cff0000ff Human - Male", GOSSIP_SENDER_MAIN, 14);
		        player->ADD_GOSSIP_ITEM(8, "|TInterface/ICONS/Thrown_1H_Harpoon_D_01Blue:30|t |cff0000ff Human - Female", GOSSIP_SENDER_MAIN, 15);
				player->ADD_GOSSIP_ITEM(8, "|TInterface/ICONS/Thrown_1H_Harpoon_D_01Blue:30|t |cff0000ff Night Elf - Male", GOSSIP_SENDER_MAIN, 21);
				player->ADD_GOSSIP_ITEM(8, "|TInterface/ICONS/Thrown_1H_Harpoon_D_01Blue:30|t |cff0000ff Night Elf - Female", GOSSIP_SENDER_MAIN, 22);
				player->ADD_GOSSIP_ITEM(8, "|TInterface/ICONS/Thrown_1H_Harpoon_D_01Blue:30|t |cffff0000 Tauren - Male", GOSSIP_SENDER_MAIN, 16);
				player->ADD_GOSSIP_ITEM(8, "|TInterface/ICONS/Thrown_1H_Harpoon_D_01Blue:30|t |cffff0000 Tauren - Female", GOSSIP_SENDER_MAIN, 17);
				player->ADD_GOSSIP_ITEM(8, "|TInterface/ICONS/Thrown_1H_Harpoon_D_01Blue:30|t |cffff0000 Blood Elf - Male", GOSSIP_SENDER_MAIN, 18);
			    player->ADD_GOSSIP_ITEM(8, "|TInterface/ICONS/Thrown_1H_Harpoon_D_01Blue:30|t |cffff0000 Blood Elf - Female", GOSSIP_SENDER_MAIN, 20);
				player->ADD_GOSSIP_ITEM(8, "|TInterface/ICONS/Thrown_1H_Harpoon_D_01Blue:30|t |cffff0000 ORC [WARLOCK] - Male", GOSSIP_SENDER_MAIN, 24);
				player->ADD_GOSSIP_ITEM(8, "|TInterface/ICONS/Thrown_1H_Harpoon_D_01Blue:30|t |cffff0000 ORC [WARLOCK] - Female", GOSSIP_SENDER_MAIN, 25);
				player->ADD_GOSSIP_ITEM(8, "|TInterface/ICONS/Thrown_1H_Harpoon_D_01Blue:30|t |cffff00ff Pirate - Male", GOSSIP_SENDER_MAIN, 19);
				player->ADD_GOSSIP_ITEM(8, "|TInterface/ICONS/Thrown_1H_Harpoon_D_01Blue:30|t |cffFF4500 Remove my morph", GOSSIP_SENDER_MAIN, 30);
				player->PlayerTalkClass->SendGossipMenu(creature->GetEntry(), creature->GetGUID());
				return true;

			case 60:
				player->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/Achievement_Arena_3v3_5:30|t |cff873600 <-- Back", GOSSIP_SENDER_MAIN, 1111);
				player->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/Achievement_Arena_2v2_3:30|t |cffFF4500 Give me Money", GOSSIP_SENDER_MAIN, 36);
				player->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/Achievement_Arena_2v2_3:30|t |cffFF4500 100 PvP Badge --> 10000 Honor Pts."                     , GOSSIP_SENDER_MAIN, 37); 
				player->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/Achievement_Arena_2v2_3:30|t |cffFF4500 100 PvP Badge --> 100 Arena Pts."                     , GOSSIP_SENDER_MAIN, 38); 
				player->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/Achievement_Arena_2v2_3:30|t |cffFF4500 100 Arena Pts. --> 10000 Honor Pts."			, GOSSIP_SENDER_MAIN, 39);
				player->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/Achievement_Arena_2v2_3:30|t |cffFF4500 60000 Honor Pts. -> 300 PvP Badge"			, GOSSIP_SENDER_MAIN, 40);
				player->PlayerTalkClass->SendGossipMenu(creature->GetEntry(), creature->GetGUID());
				return true;

			case 70:
				if (player->GetTeam() == ALLIANCE)
				{
				player->ADD_GOSSIP_ITEM(4, "|cff873600 <-- Back", GOSSIP_SENDER_MAIN, 1111);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_A_01:24|t|r Private.(1 Kill)", GOSSIP_SENDER_MAIN, ACTION_TITLE_PRIVATE);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_A_02:24|t|r Corporal.(50 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_CORPORAL);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_A_03:24|t|r Sergeant.(100 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_SERGEANT);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_A_04:24|t|r Master Sergeant.(250 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_MASTER_SERGEANT);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_A_05:24|t|r Sergeant Major.(500 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_SERGEANT_MAJOR);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_A_06:24|t|r Knight.(750 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_KNIGHT);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_A_07:24|t|r Knight Lieutenant.(1000 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_KNIGHT_LIEUTENANT);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_A_08:24|t|r Knight Captain.(1500 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_KNIGHT_CAPTAIN);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_A_09:24|t|r Knight Champion.(3000 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_KNIGHT_CHAMPION);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_A_10:24|t|r Lieutenant Commander.(5000 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_LIEUTENANT_COMMANDER);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_A_11:24|t|r Commander.(7500 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_COMMANDER);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_A_12:24|t|r Marshal.(10000 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_MARSHAL);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_A_13:24|t|r Field Marshal.(15000 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_FIELD_MARSHAL);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_A_14:24|t|r Grand Marshal.(30000 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_GRAND_MARSHAL);
				}
				else
				{
				player->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/Achievement_Arena_3v3_5:30|t |cff873600 <-- Back", GOSSIP_SENDER_MAIN, 1111);

				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_H_01:24|t|r Scout.(1 Kill)", GOSSIP_SENDER_MAIN, ACTION_TITLE_SCOUT);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_H_02:24|t|r Grunt.(50 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_GRUNT);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_H_03:24|t|r Sergeant.(100 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_SERGEANT_H);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_H_04:24|t|r Senior Sergeant.(250 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_SENIOR_SERGEANT);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_H_05:24|t|r First Sergeant.(500 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_FIRST_SERGEANT);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_H_06:24|t|r Stone Guard.(750 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_STONE_GUARD);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_H_07:24|t|r Blood Guard.(1000 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_BLOOD_GUARD);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_H_08:24|t|r Legionnaire.(1500 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_LEGIONNAIRE);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_H_09:24|t|r Centurion.(3000 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_CENTURION);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_H_10:24|t|r Champion.(5000 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_CHAMPION);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_H_11:24|t|r Lieutenant General.(7500 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_LIEUTENANT_GENERAL);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_H_12:24|t|r General.(10000 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_GENERAL);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_H_13:24|t|r Warlord.(15000 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_WARLORD);
				player->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_PVP_H_14:24|t|r High Warlord.(30000 Kills)", GOSSIP_SENDER_MAIN, ACTION_TITLE_HIGH_WARLORD);
				}
				player->PlayerTalkClass->SendGossipMenu(creature->GetEntry(), creature->GetGUID());
				return true;
			case 12://Gnome - Male
				 player->CLOSE_GOSSIP_MENU();
				 player->SetDisplayId(20580);
				 break;

			case 13://Gnome - Female
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20581);
				break;

			case 14://Human - Male
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(19723);
				break;

			case 15://Tauren - Male
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20585);
				break;
  
			case 16://Tauren - Female
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20584);
				break;

			case 17://Blood Elf - Male
				 player->CLOSE_GOSSIP_MENU();
				 player->SetDisplayId(20578);
				 break;

			case 18://Blood Elf - Female
				 player->CLOSE_GOSSIP_MENU();
				 player->SetDisplayId(20579);
				 break;

			case 19://Pirate - Male
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(4620);
				break;

			case 21://Night Elf - Male
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20122);
				break;
		  
			case 22://Night Elf - Female
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20126);
				break;

			case 24://ORC [WARLOCK] - Male
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20221);
				break;

			case 25://ORC [WARLOCK] - Female
				player->CLOSE_GOSSIP_MENU();
				player->SetDisplayId(20220);
				break;


			case 30://Demorph
				player->CLOSE_GOSSIP_MENU();
				player->DeMorph();
			break;

			case 31: //Remove my siccness
				if (player->HasAura(15007))
				 player->RemoveAura(15007);
			break;
 
			case 32: // reset my CD'S
				player->RemoveAllSpellCooldown();
			break;
 
			case 33: // repair my items
				player->DurabilityRepairAll(false, 0, false);
			break;
		
			case 34:
			{
				player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
				player->PlayerTalkClass->SendCloseGossip();
			}
			break;

			case 35:
			{
				player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
				player->PlayerTalkClass->SendCloseGossip();
			}
			break;
		
			case 36:
				player->SetMoney(999999999);
			break;

			 case 37: 
                if (player->HasItemCount( 29434, 100, false ))
                {
                    player->CLOSE_GOSSIP_MENU();
                    player->DestroyItemCount(29434, 100, true, false);
                    player->ModifyHonorPoints(+10000);
                }
                else
                {
                    player->CLOSE_GOSSIP_MENU();
                    return false;
				}
				break;

            case 38: 
                if (player->HasItemCount( 29434, 100, false ))
                {
                    player->CLOSE_GOSSIP_MENU();
                    player->DestroyItemCount(29434, 100, true, false);
                    player->ModifyArenaPoints(+100);
                }
                else
                {
                    player->CLOSE_GOSSIP_MENU();
                    return false;
                }
                break;
            
			case 39: 
                if (player->GetArenaPoints () >= 100)
                {
                    player->CLOSE_GOSSIP_MENU();
                    player->ModifyArenaPoints(-100);
                    player->ModifyHonorPoints(+10000);;
                }
                else
                {
                    player->CLOSE_GOSSIP_MENU();
                    return false;
                }
                break;
			case 40: 
                if (player->GetHonorPoints () >= 60000)
                {
                    player->CLOSE_GOSSIP_MENU();
                    player->AddItem(29434,300);
                    player->ModifyHonorPoints(-60000);
                }
                else
                {
                    player->CLOSE_GOSSIP_MENU();
                    return false;
                }
                break;

			
			case 1111:
			 OnGossipHello(player, creature);
			 break;

			 default: // Close
			     player->CLOSE_GOSSIP_MENU();
				    return true;
				}
			
    }
			 /* case GOSSIP_ACTION_INFO_DEF+1:
                OnGossipHello(player, creature);
                break; */
};

void AddSC_Teleporter_NPC_CreatureScript()
{
	new Teleporter_NPC_CreatureScript();
}