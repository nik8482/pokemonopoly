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
	givemon SPECIES_DRAGONITE, 50, ITEM_SMOKE_BALL
	playfanfare MUS_OBTAIN_ITEM
	msgbox Text_ReceivedDragonite, MSGBOX_DEFAULT
	waitfanfare
	msgbox MonopolyTower_Map_Text_Ali_Masterball, MSGBOX_NPC
	giveitem ITEM_MASTER_BALL, 2
	setvar VAR_ALI_POKEMON, 1
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_ALI_GIVEN
	setflag FLAG_HIDE_OMAR
	release
	end

MonopolyTower_Map_Event_Script_PlayerAnsweredNo::
	msgbox MonopolyTower_Map_Text_Ali_No, MSGBOX_NPC
	givemon SPECIES_DRAGONITE, 50, ITEM_SMOKE_BALL
	playfanfare MUS_OBTAIN_ITEM
	msgbox Text_ReceivedDragonite, MSGBOX_DEFAULT
	waitfanfare
	msgbox MonopolyTower_Map_Text_Ali_Masterball, MSGBOX_NPC
	giveitem ITEM_MASTER_BALL, 2
	setvar VAR_ALI_POKEMON, 1
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_ALI_GIVEN
	setflag FLAG_HIDE_OMAR
	release
	end

MonopolyTower_EventScript_NoPokemonTrigger::
    lockall
	msgbox MonopolyTower_Text_NoPokemon, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_PLAYER, MonopolyTower_Moveplayer
	waitmovement 0
	releaseall
	end

MonopolyTower_EventScript_TownSign::
	msgbox MonopolyTower_Text_TownSign, MSGBOX_SIGN
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
	.string "ALI: Go in the cave\n"
	.string "on your left to start\l"
	.string "your journey!\p"
	.string "ALI: Goodluck!$"

MonopolyTower_Map_Text_Ali_Masterball:
	.string "ALI: Here take these\n"
	.string "masterballs!$"

Text_ReceivedDragonite:
	.string "{PLAYER} received a Dragonite!$"

MonopolyTower_Text_TownSign:
	.string "Monopoly Cave\n"
	.string "“The Cave of Fortune”$"

MonopolyTower_Text_NoPokemon:
	.string "Talk to Ali to get\n"
	.string "your first Pokemon!$"

MonopolyTower_Moveplayer:
	walk_left
	step_end