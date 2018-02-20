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
#include "STM.h"

	// pointers to port registers
uint32_t *GPIO_C_Mode_Addr  = (uint32_t *) GPIO_C_MODE;
uint32_t *GPIO_C_Speed_Addr = (uint32_t *) GPIO_C_SPEED;
uint32_t *GPIO_C_Pull_Addr  = (uint32_t *) GPIO_C_PULL;
uint16_t *GPIO_C_Idr_Addr   = (uint16_t *) GPIO_C_IDR;
uint16_t *GPIO_C_Odr_Addr   = (uint16_t *) GPIO_C_ODR;

uint32_t *GPIO_D_Mode_Addr  = (uint32_t *) GPIO_D_MODE;
uint32_t *GPIO_D_Speed_Addr = (uint32_t *) GPIO_D_SPEED;
uint32_t *GPIO_D_Pull_Addr  = (uint32_t *) GPIO_D_PULL;
uint16_t *GPIO_D_Idr_Addr   = (uint16_t *) GPIO_D_IDR;
uint16_t *GPIO_D_Odr_Addr   = (uint16_t *) GPIO_D_ODR;

uint32_t *GPIO_E_Mode_Addr  = (uint32_t *) GPIO_E_MODE;
uint32_t *GPIO_E_Speed_Addr = (uint32_t *) GPIO_E_SPEED;
uint32_t *GPIO_E_Pull_Addr  = (uint32_t *) GPIO_E_PULL;
uint16_t *GPIO_E_Idr_Addr   = (uint16_t *) GPIO_E_IDR;
uint16_t *GPIO_E_Odr_Addr   = (uint16_t *) GPIO_E_ODR;

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

void timer::wait(unsigned int waittime){
	time = waittime;
  HAL_Delay(time); //time in ms
}

