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
	

	
Switches ACCEPTBUTTON(ACCEPT);
Switches CANCELBUTTON(CANCEL);
Switches PROGRAM_SEL1(PROGRAM_1);
Switches PROGRAM_SEL2(PROGRAM_2);
Switches PROGRAM_SEL3(PROGRAM_3);
Switches ResetButton(SWITCH_RESET);
buzzer WMBuzzer(BUZZER);
motor WMmotorDIRECTION(MOTOR_DIRECTION);
motor WMmotorCONTROL(MOTOR_CONTROL);
door WMdoor(DOOR);
timer WMtimer;

  // Try out buzzer
  WMBuzzer.SetBuzzer();
	WMtimer.wait(1000);
	WMBuzzer.SetBuzzer();
	WMtimer.wait(1000);
	
	//Test Accept Button Response
	if (ACCEPTBUTTON.GetSwitch() == true){
		//Output 7SEG A for 1 second
		//ON
		WMtimer.wait(1000);  
	}
		//Test Cancel Button Response
	if (CANCELBUTTON.GetSwitch() == true){
		//Output 7SEG B
	}
		//Test Program switch 1 Button Response
	if (PROGRAM_SEL1.GetSwitch() == true){
		//Output 7SEG C
	}
			//Test program switch 2 Button Response
	if (PROGRAM_SEL2.GetSwitch() == true){
		//Output 7SEG D
	}
		//Test Reset Button Response
	if (ResetButton.GetSwitch() == true){
		//reset all to zero
	}
	
		//Test door and motor direction
	if (WMdoor.GetDoorStatus() == true){
		WMmotorCONTROL.SetControlON();
		WMmotorDIRECTION.SetDirectionCW();
		WMtimer.wait(3000);
		WMmotorDIRECTION.SetDirectionACW();
		WMtimer.wait(3000);
		WMmotorDIRECTION.SetDirectionCW();
		WMtimer.wait(3000);
		WMmotorDIRECTION.SetDirectionACW();
	}
	else if (WMdoor.GetDoorStatus() == false){
		WMmotorCONTROL.SetControlOFF();
	}
}


