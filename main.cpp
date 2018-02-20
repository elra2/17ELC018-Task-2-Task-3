/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Group 4: Scott Archer, Rachel Asante, Zahckoh Mitchell Dos Santos
  * @version 1
  * @date    Due: 16 February 2018
  * @brief   Group 4 - Real Time SW Engineering Module 2017-2018 Task 2
  ******************************************************************************
  */

#include "WM.h"
#include "STM.h"

// port C - set to output
uint32_t GPIO_C_Mode = 0x55555555;  // 0b01010101010101010101010101010101  00 = input, 01 = output
uint32_t GPIO_C_Speed = 0xFFFFFFFF; // 0b11111111111111111111111111111111  11 - high speed output only
uint32_t GPIO_C_Pull = 0xaaaaaaaa;  // 0b10101010101010101010101010101010  00 none, 01 = pull up, 10 pull down

// port D - set to output
uint32_t GPIO_D_Mode = 0x55555555;  // 0b01010101010101010101010101010101  00 = input, 01 = output
uint32_t GPIO_D_Speed = 0xFFFFFFFF; // 0b11111111111111111111111111111111  11 - high speed output only
uint32_t GPIO_D_Pull = 0xaaaaaaaa;  // 0b10101010101010101010101010101010  00 none, 01 = pull up, 10 pull down

// port E - set to input
uint32_t GPIO_E_Mode = 0x00000000;  // 0b00000000000000000000000000000000  00 = input, 01 = output
uint32_t GPIO_E_Pull = 0x55555555;    // 0b10101010101010101010101010101010  00 none, 01 = pull up, 10 pull down

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
		//Setbuzzer
		
	}
	while (WMswitches.GetSwitch(PROGRAM_2) ==  true){
		//setbuzzer
		
	}
	while (WMswitches.GetSwitch(PROGRAM_3) ==  true){
		//setbuzzer
		
	}
	while (WMswitches.GetSwitch(ACCEPT) ==  true){
		//setbuzzer
		
	}
  if (WMswitches.GetSwitch(CANCEL) ==  true){
		//setbuzzer
	}
	


	

}

