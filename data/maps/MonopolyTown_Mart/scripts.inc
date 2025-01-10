MonopolyTown_Mart_MapScripts::
	.byte 0

MonopolyTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MonopolyTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

MonopolyTown_Mart_Pokemart:
	.2byte ITEM_MASTER_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	pokemartlistend

MonopolyTown_Mart_EventScript_Harshi::
	lock
	faceplayer
	goto_if_unset FLAG_NIK_LORE, MonopolyTown_NoLore_Harshi_Text
	goto_if_unset FLAG_HARSHI_MAD, MonopolyTown_YesLore_Harshi_Script
	goto_if_eq NIK_HARSHI_LORE, 2, MonopolyTown_NikDefeated_Harshi_Script
	goto_if_eq NIK_HARSHI_LORE, 3, MonopolyTown_Harshi_Final_Script
	msgbox MonopolyTown_Mart_Outro_Harshi, MSGBOX_NPC
	release
	end

MonopolyTown_NoLore_Harshi_Text::
	msgbox MonopolyTown_Mart_NoLore_Text_Harshi, MSGBOX_NPC
	release
	end

MonopolyTown_YesLore_Harshi_Script::
	msgbox MonopolyTown_Mart_YesLore_Text_Harshi, MSGBOX_NPC
	setflag FLAG_HARSHI_MAD
	setvar NIK_HARSHI_LORE, 1
	release
	end

MonopolyTown_Mart_NoLore_Text_Harshi::
	.string "HARSHI: All I do daily is slave in\n" 
	.string "this shop whilst nik is outside\l"
	.string "chilling doing no work.\p"
	.string "HARSHI: He must think I'm his slave.$"

MonopolyTown_Mart_YesLore_Text_Harshi::
	.string "HARSHI: All I do daily is slave in\n" 
	.string "this shop whilst nik is outside\l"
	.string "chilling doing no work.\p"
	.string "HARSHI: He must think I'm his slave.\p"
	.string "....\p"
	.string "HARSHI: So you are telling me he has time\n"
	.string "to tell you stories?\p"
	.string "HARSHI: Thank you for letting me know.\p"
	.string "HARSHI: Just wait until I see him.$"

MonopolyTown_Mart_Outro_Harshi::
	.string "HARSHI: Slaving away as usual..$"

MonopolyTown_NikDefeated_Harshi_Script::
	msgbox MonopolyTown_NikDefeated_Harshi_Text, MSGBOX_NPC
	setvar NIK_HARSHI_LORE, 3
	setflag FLAG_REMOVE_KABI_1
	release
	end

MonopolyTown_NikDefeated_Harshi_Text::
	.string "HARSHI: You defeated Nik?\p"
	.string "HARSHI: Thank God!\p"
	.string "HARSHI: Hopefully he will finally\n"
	.string "start doing some work\l"
	.string "and I can finally get some rest.\p"
	.string "HARSHI: Thank you\p"
	.string "HARSHI: Since you are so strong\n"
	.string "maybe you can help the town too.\p"
	.string "HARSHI: I saw Gatekeeper Kabi\n"
	.string "leaving for another town!\p"
	.string "HARSHI: Save this town {PLAYER}\p"
	.string "HARSHI: We believe in you!$"

MonopolyTown_Harshi_Final_Script::
	msgbox MonopolyTown_Harshi_Final_Text, MSGBOX_NPC
	release
	end

MonopolyTown_Harshi_Final_Text::
	.string "HARSHI: Goodluck!$"	