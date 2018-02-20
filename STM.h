/* 
  washing machine outputs
  -----------------------
  PC6  Buzzer		
  PD8  7 segment display bit A
  PD10 7 segment display bit C
  PD11 7 segment display bit B
  PD12 motor control	
  PD13 7 segment display bit D
  PD14 reset switches
  PD15 motor direction

  washing machine inputs
  ----------------------
  PE8  programme select 1
  PE9  programme select 2
  PE10 programme select 3
  PE11 door open/close
  PE12 accept switch
  PE15 motor speed feedback
*/

//mapping of buzzer to port C
#define BUZZER 0x0040 //BIT 6

//mapping of outputs to port D
#define MOTOR_DIRECTION 0x8000
#define SWITCH_RESET 0x4000
#define SEVENSEG_A 0x0100
#define SEVENSEG_B 0x0800
#define SEVENSEG_C 0x0400
#define SEVENSEG_D  0x2000
#define MOTOR_CONTROL 0x1000

// mapping of Inputs to port E
#define DOOR 0x0800
#define PROGRAM_1 0x0100
#define PROGRAM_2 0x0200
#define PROGRAM_3 0x0400
#define ACCEPT 0x1000
#define CANCEL 0x2000
#define MOTOR_SPEED 0x8000

