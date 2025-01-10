.set LOCALID_IAN, 1
.set LOCALID_OMAR, 2

MonopolyTower_1F_MapScripts::
	.byte 0

MonopolyTower_1F_Omar_Trigger::
	lock
	playbgm MUS_ENCOUNTER_MAY, TRUE
	addobject LOCALID_OMAR
	applymovement LOCALID_OMAR, MonopolyTower_Omar_Enter
	waitmovement 0
	lockall
	msgbox MonopolyTower_Text_OmarIntro, MSGBOX_NPC
	releaseall
	applymovement LOCALID_OMAR, MonopolyTower_Omar_Exit
	waitmovement 0
	playbgm MUS_RG_SEVII_DUNGEON, TRUE
	removeobject LOCALID_OMAR 
	setvar VAR_UNUSED_0x40F9, 1
	release
	end

MonopolyTower_1F_EventScript_Ian::
	trainerbattle_single TRAINER_CALVIN_1, MonopolyTower_Text_IanIntro, MonopolyTower_Text_IanOutro
	msgbox MonopolyTower_Text_IanDefeated, MSGBOX_DEFAULT
	release
	end

MonopolyTower_Omar_Enter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MonopolyTower_Omar_Exit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MonopolyTower_Text_OmarIntro:
	.string "OMAR: STOP!!!!\p"
	.string "OMAR: I'm Omar of the Monopoly Group!\p"
	.string "OMAR: We have been ruling\n"
	.string "the Monopoly Tower for years!\p"
	.string "OMAR: Who are you?\p"
	.string "OMAR: What are you doing here?\p"
	.string "OMAR: If you think you can\n"
	.string "beat us, you are wrong!\p"
	.string "OMAR: We are the best!\p"
	.string "OMAR: Anywys, smell you later dumb fuck.$"

MonopolyTower_Text_IanIntro::
	.string "IAN: I've been training\n"
	.string "my whole life here!$"

MonopolyTower_Text_IanOutro::
	.string "IAN: I'm washed.$"

MonopolyTower_Text_IanDefeated::
	.string "IAN: I'll keep grinding.$"