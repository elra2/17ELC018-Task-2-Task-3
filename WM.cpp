#include "WM.h"

//DOOR FUNCTIONS
door::door(unsigned char map){
	port_map = map;
}

bool door::GetDoorStatus(){
  port = (*GPIO_E_Idr_Addr) & port_map ;  // PE11 check if door open or closed
	 if (port){
		 doorstatus = 1;
	 }
	 else {
		 doorstatus = 0;
	 }
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

bool Switches::GetSwitch(){
   port = (*GPIO_E_Idr_Addr) & port_map ;  //Program Switches, Accept, Cancel, Door Open/close
   if (port){
		 *GPIO_D_Odr_Addr |= (uint16_t) 0x0100;
		 switchvalue = 1;
	 }
	 else {
		 *GPIO_D_Odr_Addr &= ~(uint16_t) 0x2D00;
		 switchvalue = 0;
	 }
	return switchvalue;  //returning speed or switchvalue?
}

void Switches::Reset(){
  *GPIO_D_Odr_Addr &= ~(uint16_t) port_map;  // PD14 LOW OR HIGH RESET
}


//MOTOR FUNCTIONS
bool motor::GetMotorSpeed(){
	port = (*GPIO_E_Idr_Addr) & 0x8000 ; // PE15 motor speed feedback

	return GPIO_E_Idr_Addr;
}