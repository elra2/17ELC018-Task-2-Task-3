/**  ******************************************************************************  * @file    main.cpp  * @author  Group 4: Scott Archer, Rachel Asante, Zahckoh Mitchell Dos Santos  * @version 1  * @date    Due: 23 February 2018  * @brief   Group 4 - Real Time SW Engineering Module 2017-2018 Task 2  ******************************************************************************  */ #include "main.h"#include "WM.h"#include "PORTMAP.h"#include "STM.h"
extern "C" {  // this is needed to make C++ and C work together  #include "board_startup.h"   // you DON'T need to worry about the contents of this file}
int main(void){ door WMdoor; buzzer WMbuzzer; motor WMmotor; timer WMtimer; switches WMswitches; sevenseg WMsevenseg;
   // STM32F3 Discovery Board initialization  board_startup();  //setup ports for board setupdevice(); 
  while(1) {    //ReadGetProgramStage(); //DisplayStageOnSevenSegment();     if (WMswitches.GetSwitch(ACCEPT) == 1){  // Read/Get Program 1, 2, 3 combination of 0 and 1s  // Run Program Selection   //Set counter = counter + 1;  //if counter increments, advance one stage }
  if (WMswitches.GetSwitch(CANCEL) == 1){  //CancelButtonPressed = count + 1  //GetProgramStatus();   //If running   // } 
  }   } 
