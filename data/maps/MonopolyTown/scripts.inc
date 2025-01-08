.set LOCALID_NIK, 3

MonopolyTown_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MonopolyTown_OnTransition
	.byte 0

MonopolyTown_OnTransition::
	map_script_2 NIK_HARSHI_LORE, 1, MonopolyTown_NikBattle_Trigger
	releaseall
	end

MonopolyTown_NikBattle_Trigger::
	lock
	applymovement LOCALID_NIK, MonopolyTown_Nik_Confront
	waitmovement 0
	trainerbattle_single TRAINER_VICTOR, MonopolyTower_Text_IanIntro, MonopolyTower_Text_IanOutro, MonopolyTower_Nik_Set_Var
	releaseall
	end

MonopolyTower_Nik_Set_Var::
	setvar NIK_HARSHI_LORE, 2
	msgbox Monopolytown_Nik_Defeat_Text, MSGBOX_NPC
	giveitem ITEM_RARE_CANDY 1
	releaseall
	end

MonopolyTown_Nik_Confront::
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

MonopolyTown_Map_EventScript_Nik::
    lock
    faceplayer
	goto_if_unset FLAG_NIK_LORE, MonopolyTown_Map_EventScript_Nik_Lore
	goto_if_eq NIK_HARSHI_LORE, 2, MonopolyTown_Nik_Outro
	releaseall
	end	

MonopolyTown_Map_EventScript_Nik_Lore::
	msgbox MonopolyTown_Text_Nik_Intro, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MonopolyTown_Script_PlayerAnsweredYes
	msgbox MonopolyTown_Script_PlayerAnsweredNo, MSGBOX_NPC
	release
	end

MonopolyTown_Nik_Outro::
	msgbox MonopolyTown_Nik_Outro_text, MSGBOX_NPC
	release
	end

MonopolyTown_Text_Nik_Intro::
	.string "NIK: These Monopoly people\n"
	.string "ruin everything!\p"
	.string "NIK: oh...\p"
	.string "NIK: You're not one of them.\p"
	.string "NIK: This town used to be something,\n"
	.string "something great\p"
	.string "NIK: Would you like to hear\n"
	.string "the story of the history\l"
	.string "of this town?$"

MonopolyTown_Script_PlayerAnsweredNo::
	msgbox MonopolyTown_Text_Nik_No, MSGBOX_NPC
	release
	end

MonopolyTown_Text_Nik_No::
	.string "NIK: Oh, okay then.\p"
	.string "NIK: I'll be here if you\n"
	.string "change your mind.$"

MonopolyTown_Script_PlayerAnsweredYes::
	msgbox MonopolyTown_Text_Nik_Yes, MSGBOX_NPC
	setflag FLAG_NIK_LORE
	release
	end

MonopolyTown_Text_Nik_Yes::
	.string "NIK: This town was once\n"
	.string "a thriving metropolis.\p"
	.string "NIK: Then a strange group\n"
	.string "came and took over...\p"
	.string "NIK: They call themselves\n"
	.string "The Monopoly Group!\p"
	.string "NIK: They have been ruling\n"
	.string "the town for years\p"
	.string "NIK: Building strange hotels\n"
	.string "to fund their lifestyle.\p"
	.string "NIK: The only original shop that remains\n"
	.string "is my corner shop above.\p"
	.string "NIK: Please visit if you\n"
	.string "need anything.$"

MonopolyTown_Nik_Outro_text::
	.string "NIK: sigh.. back to work.$"

MonopolyTown_DawatSign::
	msgbox MonopolyTown_DawatSignText, MSGBOX_SIGN
	end

MonopolyTown_DawatSignText::
	.string "Dawat: The Monopoly Diner$"

MonopolyTown_MansionSign::
	msgbox MonopolyTown_MansionSignText, MSGBOX_SIGN
	end

MonopolyTown_MansionSignText::
	.string "The Monopoly Mansion$"

MonopolyTown_CornerShopSign::
	msgbox MonopolyTown_CornerShopSignText, MSGBOX_SIGN
	end

MonopolyTown_CornerShopSignText::
	.string "Nik's Corner Shop$"

MonopolyTown_AbdiCageSign::
	msgbox MonopolyTown_AbdiCageSignText, MSGBOX_SIGN
	end

MonopolyTown_AbdiCageSignText::
	.string "Abdi's Cage$"

MonopolyTown_LoveHotelSign::
	msgbox MonopolyTown_LoveHotelSignText, MSGBOX_SIGN
	end

MonopolyTown_LoveHotelSignText::
	.string "Monopoly Love Hotel$"

MonopolyTown_AbdiHouseSign::
	msgbox MonopolyTown_AbdiHouseSignText, MSGBOX_SIGN
	end

MonopolyTown_AbdiHouseSignText::
	.string "Abdi's House$"

MonopolyTown_NPC_EventScript::
	lock
	faceplayer
	msgbox MonopolyTown_NPC_Text, MSGBOX_NPC
	release
	end

MonopolyTown_NPC_Text::
	.string "Capturing Pokemon is\n"
	.string "a great way to make friends!$"

Monopolytown_Nik_Defeat_Text::
	.string "NIK: You're strong!\p"
	.string "NIK: Here, take this!\p"
	.string "NIK: It's a rare candy!$"

MonopolyTown_GateKeeper_Kabi_Script::
	lock
	faceplayer
	msgbox MonopolyTown_GateKeeper_Kabi_Text_1, MSGBOX_NPC
	applymovement OBJ_EVENT_ID_PLAYER, MonopolyTown_GateKeeper_Kabi_Movement
	waitmovement 0
	release
	end

MonopolyTown_GateKeeper_Kabi_Text_1::
	.string "GATEKEEPER KABI: You can't pass!$"

MonopolyTown_GateKeeper_Kabi_Movement::
	walk_down
	step_end