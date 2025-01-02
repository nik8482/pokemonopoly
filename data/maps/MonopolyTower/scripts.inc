MonopolyTower_MapScripts::
	.byte 0

MonopolyTower_Map_EventScript_Ali::
    lock
    faceplayer
	goto_if_unset FLAG_ALI_GIVEN, MonopolyTower_Map_EventScript_Ali_Question
    msgbox MonopolyTower_Map_Text_Ali_Outro, MSGBOX_NPC
	release
	end

MonopolyTower_Map_EventScript_Ali_Question::
	msgbox MonopolyTower_Map_Text_Ali_Intro, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MonopolyTower_Map_Event_Script_PlayerAnsweredNo
	msgbox MonopolyTower_Map_Text_Ali_Yes, MSGBOX_NPC
	givemon SPECIES_DRAGONITE, 50, ITEM_DRAGON_FANG
	playfanfare MUS_OBTAIN_ITEM
	msgbox Text_ReceivedDragonite, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_ALI_GIVEN
	release
	end

MonopolyTower_Map_Event_Script_PlayerAnsweredNo::
	msgbox MonopolyTower_Map_Text_Ali_No, MSGBOX_NPC
	givemon SPECIES_DRAGONITE, 50, ITEM_DRAGON_FANG
	playfanfare MUS_OBTAIN_ITEM
	msgbox Text_ReceivedDragonite, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_ALI_GIVEN
	release
	end

MonopolyTower_Map_Text_Ali_Intro:
    .string "ALI: Hello, how are you\n"
    .string "doing today?\p"
    .string "ALI: My name is Ali!\p"
	.string "ALI: They call me the\n"
	.string "Turkish Terminator!\p"
	.string "ALI: Do you like Turkey?$"

MonopolyTower_Map_Text_Ali_No:
	.string "ALI: hmph.\p"
	.string "ALI: thats a shame\n"
	.string "I was going to give you\l"
	.string "a wonderful gift.\p"
	.string "ALI: I'm a nice guy\n"
	.string "so take this anyways$"

MonopolyTower_Map_Text_Ali_Yes:
	.string "ALI: Amazing take this!$"

MonopolyTower_Map_Text_Ali_Outro:
	.string "ALI: Goodluck!$"

Text_ReceivedDragonite:
	.string "{PLAYER} received a Dragonite!$"