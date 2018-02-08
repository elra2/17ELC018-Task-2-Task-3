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
extern "C" {  // this is needed to make C++ and C work together
  #include "board_startup.h"   // you DON'T need to worry about the contents of this file
}
#include "WM.h"
#include "STM.h"





// all the washing machine test code is in here
int main(void)
{
  // STM32F3 Discovery Board initialization
  board_startup();

  // configure port C
  *GPIO_C_Mode_Addr =  (uint32_t) GPIO_C_Mode;
  *GPIO_C_Speed_Addr = (uint32_t) GPIO_C_Speed;
  *GPIO_C_Pull_Addr =  (uint32_t) GPIO_C_Pull;

  // configure port D
  *GPIO_D_Mode_Addr =  (uint32_t) GPIO_D_Mode;
  *GPIO_D_Speed_Addr = (uint32_t) GPIO_D_Speed;
  *GPIO_D_Pull_Addr =  (uint32_t) GPIO_D_Pull;

  // configure port E
  *GPIO_E_Mode_Addr =  (uint32_t) GPIO_E_Mode;
  *GPIO_E_Pull_Addr =  (uint32_t) GPIO_E_Pull;
	
Switches ACCEPTBUTTON(ACCEPT);
Switches CANCELBUTTON(CANCEL);
Switches PROGRAM_SEL1(PROGRAM_1);
Switches PROGRAM_SEL2(PROGRAM_2);
Switches PROGRAM_SEL3(PROGRAM_3);
Switches ResetButton(SWITCH_RESET);
buzzer WMBuzzer(BUZZER);
motor WMmotor(MOTOR_SPEED);
door WMdoor(DOOR);

  // try out each washing machine device in turn
  WMBuzzer.SetBuzzer();
  HAL_Delay(100); // 100ms delay
  *GPIO_D_Odr_Addr |= (uint16_t) 0x1000;   // PD12 motor control - on
  HAL_Delay(100); // 100ms delay		
  *GPIO_D_Odr_Addr &= ~(uint16_t) 0x8000;  // PD15 motor direction - clockwise
  HAL_Delay(1900); // 100ms delay		
  *GPIO_D_Odr_Addr |= (uint16_t) 0x8000;   // PD15 motor direction - anticlockwise
  HAL_Delay(1000); // 100ms delay
  *GPIO_D_Odr_Addr &= ~(uint16_t) 0x1000;  // PD12 motor control - off 
  HAL_Delay(100); // 100ms delay	
		
  *GPIO_D_Odr_Addr &= ~(uint16_t) 0x2D00;  // turn off all 7 segments of display (display 0)
  HAL_Delay(100); // 100ms delay
  *GPIO_D_Odr_Addr |= (uint16_t) 0x2000;   // turn on bit D MSB
  HAL_Delay(100); // 100ms delay		
  *GPIO_D_Odr_Addr |= (uint16_t) 0x0400;   // turn on bit C	
  HAL_Delay(100); // 100ms delay
  *GPIO_D_Odr_Addr |= (uint16_t) 0x0800;   // turn on bit B
  HAL_Delay(100); // 100ms delay		
  *GPIO_D_Odr_Addr |= (uint16_t) 0x0100;   // turn on bit A LSB (all outputs 1 - display blank)
  HAL_Delay(100); // 100ms delay
  *GPIO_D_Odr_Addr &= ~(uint16_t) 0x2D00;  // turn off all 7 segments of display  (display 0)
  HAL_Delay(100); // 100ms delay
		
  ResetButton.Reset();
  HAL_Delay(100); // 100ms delay
  PROGRAM_SEL1.ReadSwitch();
  HAL_Delay(100); // 100ms delay
  PROGRAM_SEL1.ReadSwitch();
  HAL_Delay(100); // 100ms delay
  PROGRAM_SEL1.ReadSwitch();
  HAL_Delay(100); // 100ms delay
	WMdoor.ReadDoorStatus();
  HAL_Delay(100); // 100ms delay
	ACCEPTBUTTON.ReadSwitch();
  HAL_Delay(100); // 100ms delay
  CANCELBUTTON.ReadSwitch();
  HAL_Delay(100); // 100ms delay	
  port = (*GPIO_E_Idr_Addr) & 0x8000 ;  // PE15 motor speed feedback	
  HAL_Delay(100); // 100ms delay	
  ResetButton.Reset();  // PD14 LOW reset switches
  HAL_Delay(100); // 100ms delay

  // Only run the motor if the door is closed
  *GPIO_D_Odr_Addr &= ~(uint16_t) 0x8000;  // PD15 motor direction - set to clockwise
  while(1) {
    if (WMdoor.GetDoorStatus() == true) {
      *GPIO_D_Odr_Addr |= (uint16_t) 0x1000;  // PD12 motor control - off 
    }
    else {
      *GPIO_D_Odr_Addr &= ~(uint16_t) 0x1000;  // PD12 motor control - off 
    }
  }
}

