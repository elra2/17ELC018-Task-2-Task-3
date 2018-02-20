#ifndef __PORTMAP_H
#define __PORTMAP_H

//mapping of buzzer to port C
#define BUZZER 0x0040 //BIT 6

//mapping of outputs to port D
#define MOTOR_DIRECTION 0x00008000
#define SWITCH_RESET 0x4000
#define SEVENSEG_A 0x0100
#define SEVENSEG_B 0x0800
#define SEVENSEG_C 0x0400
#define SEVENSEG_D  0x2000
#define MOTOR_CONTROL 0x1000

// mapping of Inputs to port E
#define DOOR 0x0800
#define PROGRAM_1 0x00000100
#define PROGRAM_2 0x00000200
#define PROGRAM_3 0x00000400
#define ACCEPT 0x00001000
#define CANCEL 0x2000
#define MOTOR_SPEED 0x8000


#endif /* __PORTMAP_H */


