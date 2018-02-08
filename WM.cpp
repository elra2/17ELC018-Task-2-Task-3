/**
  ******************************************************************************
  * @file    WM.cpp
  * @author  Group 4: Scott Archer, Rachel Asante, Zahckoh Mitchell Dos Santos
  * @version 1
  * @date    Due: 16 February 2018
  * @brief   Group 4 - Real Time SW Engineering Module 2017-2018 Task 2
  ******************************************************************************
  */

#include "WM.h"

//DOOR FUNCTIONS
door::door(unsigned char map){
	port_map = map;
}

void door::ReadDoorStatus(){
  port = (*GPIO_E_Idr_Addr) & port_map ;  // PE11 check if door open or closed
	 if (port){
		 doorstatus = true;
	 }
	 else {
		 doorstatus = false;
	 }
}

bool door::GetDoorStatus()
{
	return doorstatus;
}


//BUZZER FUNCTIONS
buzzer::buzzer(unsigned char map){
	port_map = map;
}

void buzzer::SetBuzzer(){
  *GPIO_C_Odr_Addr ^= (uint16_t) port_map;   // toggle PC6 buzzer
	}


////PROGRAM,ACCEPT,CANCEL,DOOR OPEN/CLOSE SWITCHES FUNCTIONS
Switches::Switches(unsigned char map){
	port_map = map;
}

void Switches::ReadSwitch(){
   port = (*GPIO_E_Idr_Addr) & port_map ;  //Program Switches, Accept, Cancel, Door Open/close
   if (port){
		 *GPIO_D_Odr_Addr |= (uint16_t) 0x0100;
		 switchvalue = true;
	 }
	 else {
		 *GPIO_D_Odr_Addr &= ~(uint16_t) 0x2D00;
		 switchvalue = false;
	 }
}

bool Switches::GetSwitch(){
	return switchvalue;
}

void Switches::Reset(){
  *GPIO_D_Odr_Addr &= ~(uint16_t) port_map;  // PD14 LOW OR HIGH RESET
}


//MOTOR FUNCTIONS
motor::motor(unsigned int map){
 port_map = map;
}
void motor::ReadMotorSpeed(){
	port = (*GPIO_E_Idr_Addr) & 0x8000 ; // PE15 motor speed feedback
}
