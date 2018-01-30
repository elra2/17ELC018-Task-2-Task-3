#include "WM.h"

//DOOR FUNCTIONS
door::door(unsigned char map){
	port_map = map;
}

bool door::dooropen(){
	//open door command
	doorstatus = 1;
	return doorstatus;
}

//BUZZER FUNCTIONS
buzzer::buzzer(unsigned char map){
	port_map = map
}
