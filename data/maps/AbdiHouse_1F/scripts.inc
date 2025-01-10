.set LOCALID_ABDI, 2
.set LOCALID_NEAL, 1

AbdiHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AbdiHouse1F_OnTransition
	.byte 0

AbdiHouse1F_OnTransition::
	map_script_2 ABDI_NEAL_CUTSCENE, 0, AbdiHouse1F_Cutscene_Trigger
	.2byte 0

AbdiHouse1F_Cutscene_Trigger::
	lockall
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CameraMovement
	waitmovement 0

	msgbox AbdiNeal_Cutscene_Txt, MSGBOX_NPC

	playse SE_PIN
	applymovement LOCALID_ABDI, Common_Movement_ExclamationMark
	applymovement LOCALID_NEAL, Common_Movement_ExclamationMark
	waitmovement 0

	delay 80

	msgbox AbdiNeal_Cutscene_Txt_2, MSGBOX_NPC

	applymovement OBJ_EVENT_ID_CAMERA, CameraMovementBack
	waitmovement 0

	special RemoveCameraObject
	setvar ABDI_NEAL_CUTSCENE, 1
	releaseall
	end

CameraMovement:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CameraMovementBack:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

AbdiNeal_Cutscene_Txt::
	.string "NEAL: Slaving Pokemon aren't going\n"
	.string "to solve the problem\l"
	.string "of the rising population.\p"
	.string "NEAL: We need to find a solution\n"
	.string "to these migrants.\p"
	.string "NEAL: They're travelling here\n"
	.string "taking our jobs and resources.\p"
	.string "ABDI: You can't blame them for\n"
	.string "wanting a better life!\p"
	.string "ABDI: Monopoly has changed\n"
	.string "this town for the better.\p"
	.string "NEAL: I don't see it that way.\p"
	.string "NEAL: Our three overlords sent\n"
	.string "us here to work.\p"
	.string "NEAL: Not to be replaced by\n"
	.string "migrants.\p"
	.string "ABDI: I've never had the honor\n"
	.string "of meeting our Overlords.\p"
	.string "ABDI: What are their names again?$"

AbdiNeal_Cutscene_Txt_2::
	.string "NEAL: Who's there!\p"
	.string "ABDI: Show yourself!$"


AbdiHouse1F_AbdiBattle::
	trainerbattle_single TRAINER_KEVIN, AbdiHouse1F_Text_AbdiIntro, AbdiHouse1F_Text_AbdiOutro
	msgbox MonopolyTower_Text_JeromeOutro, MSGBOX_DEFAULT
	release
	end

AbdiHouse1F_NealBattle::
	trainerbattle_single TRAINER_FRANKLIN, AbdiHouse1F_Text_NealIntro, AbdiHouse1F_Text_NealOutro
	msgbox MonopolyTower_Text_JeromeOutro, MSGBOX_DEFAULT
	release
	end


AbdiHouse1F_Text_AbdiIntro::
	.string "ABDI: Pokemon are born to\n"
	.string "serve.\p"
	.string "ABDI: Don't you agree?$"

AbdiHouse1F_Text_AbdiOutro::
	.string "ABDI: ...$"

AbdiHouse1F_Text_NealIntro::
	.string "NEAL: You?!\p"
	.string "NEAL: When did you migrate here?\p"
	.string "NEAL: Go back to where you came from!$"

AbdiHouse1F_Text_NealOutro::
	.string "NEAL: You're strong for your kind.\p"