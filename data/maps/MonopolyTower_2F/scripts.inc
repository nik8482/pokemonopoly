MonopolyTower_2F_MapScripts::
	.byte 0

MonopolyTower_2F_EventScript_Jerome::
	trainerbattle_single TRAINER_BILLY, MonopolyTower_Text_JeromeIntro, MonopolyTower_Text_JeromeOutro
	msgbox MonopolyTower_Text_JeromeOutro, MSGBOX_DEFAULT
	release
	end

MonopolyTower_2F_EventScript_Mohin::
	lock
	msgbox MonopolyTower_2F_Text_Mohin, MSGBOX_DEFAULT
	release
	end

MonopolyTower_2F_Text_Mohin::
	.string "A Wild MOHIN blocks your path.$"

MonopolyTower_2F_EventScript_ItemQuickClaw::
	finditem ITEM_QUICK_CLAW
	setflag EVENT_QUICK_CLAW_FOUND
	end

MonopolyTower_Text_JeromeIntro::
	.string "JEROME: Where the AGBs at?$"

MonopolyTower_Text_JeromeOutro::
	.string "JEROME: ...$"