/**
  ******************************************************************************
  * @file    WM.cpp
  * @author  Group 4: Scott Archer, Rachel Asante, Zahckoh Mitchell Dos Santos
  * @version 1
  * @date    Due: 16 February 2018
  * @brief   Group 4 - Real Time SW Engineering Module 2017-2018 Task 2
  ******************************************************************************
  */
	
#include "PORTMAP.h"
#include "STM.h"
#include "WM.h"
#include "stdint.h"

// hold a bit value returned from a port
bool port;

//DOOR FUNCTIONS
door::door(){
}

void door::ReadDoorStatus(){
  port = (*GPIO_E_Idr_Addr) & DOOR ;  // PE11 check if door open or closed
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
buzzer::buzzer(){
}

void buzzer::SetBuzzer(){
  *GPIO_C_Odr_Addr ^= (uint16_t) BUZZER;   // toggle PC6 buzzer
	}

//PROGRAM, ACCEPT, CANCEL, DOOR OPEN/CLOSE SWITCHES FUNCTIONS
switches::switches(){
}

bool switches::GetSwitch(unsigned short port_map){  //address to be passed in to
	 port = (*GPIO_E_Idr_Addr) & port_map ;
   if (port){
		 *GPIO_D_Odr_Addr |= (uint16_t) SEVENSEG_A;
		 switchvalue = true;
	 }
	 else {
		 *GPIO_D_Odr_Addr &= ~(uint16_t) 0x2D00;
		 switchvalue = false;
	 }
	return switchvalue;
}

void switches::Reset(){
  *GPIO_D_Odr_Addr &= ~(uint16_t) SWITCH_RESET;  // PD14 RESET
}

void switches::AcceptUserInput(){
	*GPIO_D_Odr_Addr |= (uint16_t) SWITCH_RESET; // PD14 HIGH accept switch input
}


//MOTOR FUNCTIONS
motor::motor(){
}
int motor::GetMotorSpeed(){
		port = (*GPIO_E_Idr_Addr) & MOTOR_SPEED ; // PE15 motor speed feedback
	if (port){
		motorspeed = 1; //change to actal motor speed
	}
else {
	motorspeed = 0;  //motorspeed
}
	return motorspeed;
}

void motor::SetDirectionCW(){
	*GPIO_D_Odr_Addr &= ~(uint16_t) MOTOR_DIRECTION; // PD15 motor direction - clockwise
}

void motor::SetDirectionACW(){
	*GPIO_D_Odr_Addr |= (uint16_t) MOTOR_DIRECTION; // PD15 motor direction - anticlockwise
}

void motor::SetControlOFF(){
	*GPIO_D_Odr_Addr &= ~(uint16_t) MOTOR_CONTROL; // PD12 motor control - off
}

void motor::SetControlON(){
	*GPIO_D_Odr_Addr |= (uint16_t) MOTOR_CONTROL; // PD12 motor control - on
}

timer::timer(){
	
}
void timer::wait(unsigned int waittime){
	time = waittime;
  HAL_Delay(time); //time in ms
}

