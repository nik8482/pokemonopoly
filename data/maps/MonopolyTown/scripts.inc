MonopolyTown_MapScripts::
	.byte 0

MonopolyTown_Map_EventScript_Nik::
    lock
    faceplayer
	goto_if_unset FLAG_NIK_LORE, MonopolyTown_Map_EventScript_Nik_Lore
    msgbox MonopolyTown_Nik_Outro, MSGBOX_NPC
	release
	end

MonopolyTown_Map_EventScript_Nik_Lore::
	msgbox MonopolyTown_Text_Nik_Intro, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MonopolyTown_Script_PlayerAnsweredYes
	msgbox MonopolyTown_Script_PlayerAnsweredNo, MSGBOX_NPC
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
	.string "a thriving metropolis\p"
	.string "NIK: Then a strange group\n"
	.string "came and took over\p"
	.string "NIK: They call themselves\n"
	.string "The Monopoly Group!\p"
	.string "NIK: They have been ruling\n"
	.string "the town for years\p"
	.string "NIK: Building strange hotels\n"
	.string "to fund their lifestyle.\p"
	.string "NIK: The only shop that remains\n"
	.string "is my corner shop above\p"
	.string "NIK: Please visit if you\p"
	.string "need anything.$"

MonopolyTown_Nik_Outro::
	.string "NIK: Please Visit Again!$"

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

