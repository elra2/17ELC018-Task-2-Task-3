
// Definitions for the Device Drivers on STM32F3 Discovery Board
// DJM 23/01/2018

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __WM_H
#define __WM_H

#include "stdint.h" 

#define GPIO_C_BASE_ADDR  0x40000000 + 0x08000000 + 0x00000800
#define GPIO_D_BASE_ADDR  0x40000000 + 0x08000000 + 0x00000C00
#define GPIO_E_BASE_ADDR  0x40000000 + 0x08000000 + 0x00001000

// define the structure of the ports and port access operations
class GPIOs
{
  public:
    volatile uint32_t MODER;        /*!< GPIO port mode register,               Address offset: 0x00      */
    volatile uint32_t OTYPER;       /*!< GPIO port output type register,        Address offset: 0x04      */
    volatile uint32_t OSPEEDR;      /*!< GPIO port output speed register,       Address offset: 0x08      */
    volatile uint32_t PUPDR;        /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
    volatile uint32_t IDR;          /*!< GPIO port input data register,         Address offset: 0x10      */
    volatile uint32_t ODR;          /*!< GPIO port output data register,        Address offset: 0x14      */
    volatile uint16_t BSRRL;        /*!< GPIO port bit set/reset low register,  Address offset: 0x18      */
    volatile uint16_t BSRRH;        /*!< GPIO port bit set/reset high register, Address offset: 0x1A      */
    volatile uint32_t LCKR;         /*!< GPIO port configuration lock register, Address offset: 0x1C      */
    volatile uint32_t AFR[2];       /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
    volatile uint32_t BRR;          /*!< GPIO bit reset register,               Address offset: 0x28 */
};


class door{
	public:
	door(unsigned char);
	void opendoor();
	void closedoor();
	private:
        unsigned char port_map;
	bool doorstatus;
};

class buzzer {
	public:
	buzzer(unsigned char);
	void soundbuzzer();
	private:
	unsigned char port_map
	bool buzzerstatus;
};

//class motor{
//	public:
//};



// pointer to port E
extern GPIOs *GPIO_E;

// define a pointer to the parallel port -- from lecure notes
struct ParPort *PPort= (struct ParPort*) 0x08001000;



//mapping of buzzer to port C
#define BUZZER 0x0040 //BIT 6

//mapping of outputs to port D
#define MOTOR_DIRECTION 0x8000
#define SWITCH_RESET 0x4000
#define SEVENSEG_D  0x2000
#define SEVENSEG_A 0x0100
#define SEVENSEG_B 0x0800
#define SEVENSEG_C 0x0400
#define MOTOR_CONTROL 0x1000

// mapping of Inputs to port E
#define DOOR 0x0800
#define PROGRAM_1 0x0100
#define PROGRAM_2 0x0200
#define PROGRAM_3 0x0400
#define ACCEPT 0x1000
#define CANCEL 0x2000
#define MOTOR_SPEED 0x8000


#endif /* __WM_H */
