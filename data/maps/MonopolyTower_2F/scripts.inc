MonopolyTower_2F_MapScripts::
	.byte 0

MonopolyTower_2F_EventScript_Jerome::
	trainerbattle_single TRAINER_BILLY, MonopolyTower_Text_JeromeIntro, MonopolyTower_Text_JeromeOutro
	msgbox MonopolyTower_Text_JeromeOutro, MSGBOX_DEFAULT
	release
	end

MonopolyTower_2F_EventScript_ItemQuickClaw::
	finditem ITEM_QUICK_CLAW
	end