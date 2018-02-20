/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Group 4: Scott Archer, Rachel Asante, Zahckoh Mitchell Dos Santos
  * @version 1
  * @date    Due: 16 February 2018
  * @brief   Group 4 - Real Time SW Engineering Module 2017-2018 Task 2
  ******************************************************************************
  */
	
#include "main.h"
#include "WM.h"
#include "PORTMAP.h"
extern "C" {  // this is needed to make C++ and C work together
  #include "board_startup.h"   // you DON'T need to worry about the contents of this file
}
	
// all the washing machine test code is in here
int main(void)
{
  // STM32F3 Discovery Board initialization
  board_startup();
	
	door WMdoor;
	buzzer WMbuzzer;
	motor WMmotor;
	timer WMtimer;
	switches WMswitches;
	
	
	/*  BUZZER TEST  */
	WMbuzzer.SetBuzzer();
	WMtimer.wait(1000);
	WMbuzzer.SetBuzzer();
	WMtimer.wait(1000);
	
	/* DOOR TEST WITH MOTOR */
	if (WMdoor.GetDoorStatus() == true){
		WMmotor.SetControlON();
		WMmotor.SetDirectionACW();
		WMtimer.wait(2000);
		WMmotor.SetDirectionACW();
		WMtimer.wait(2000);
		WMmotor.SetDirectionACW();
		WMtimer.wait(2000);
	}
	if (WMdoor.GetDoorStatus() == false){
		WMmotor.SetControlOFF();
		WMswitches.Reset();
	}

	/* SWITCHES WITH 7SEG */
	while (WMswitches.GetSwitch(PROGRAM_1) ==  true){
		//SeT7SEGMENTVALUE
		
	}
	while (WMswitches.GetSwitch(PROGRAM_2) ==  true){
		//SeT7SEGMENTVALUE
		
	}
	while (WMswitches.GetSwitch(PROGRAM_3) ==  true){
			//SeT7SEGMENTVALUE
		
	}
	while (WMswitches.GetSwitch(ACCEPT) ==  true){
		//SeT7SEGMENTVALUE
		
	}
  if (WMswitches.GetSwitch(CANCEL) ==  true){
			//SeT7SEGMENTVALUE
	}
	
}
