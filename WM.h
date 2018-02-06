// Definitions for the Device Drivers on STM32F3 Discovery Board
// DJM 23/01/2018

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __WM_H
#define __WM_H

#include "stdint.h"
#include "STM.h"

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

// port base addresses
#define GPIO_C_BASE_ADDR  0x40000000 + 0x08000000 + 0x00000800
#define GPIO_D_BASE_ADDR  0x40000000 + 0x08000000 + 0x00000C00
#define GPIO_E_BASE_ADDR  0x40000000 + 0x08000000 + 0x00001000

// port register addresses
#define GPIO_C_MODE  (GPIO_C_BASE_ADDR)
#define GPIO_C_SPEED (GPIO_C_BASE_ADDR + 0x08)
#define GPIO_C_PULL  (GPIO_C_BASE_ADDR + 0x0C)
#define GPIO_C_IDR   (GPIO_C_BASE_ADDR + 0x10)
#define GPIO_C_ODR   (GPIO_C_BASE_ADDR + 0x14)

#define GPIO_D_MODE  (GPIO_D_BASE_ADDR)
#define GPIO_D_SPEED (GPIO_D_BASE_ADDR + 0x08)
#define GPIO_D_PULL  (GPIO_D_BASE_ADDR + 0x0C)
#define GPIO_D_IDR   (GPIO_D_BASE_ADDR + 0x10)
#define GPIO_D_ODR   (GPIO_D_BASE_ADDR + 0x14)

#define GPIO_E_MODE  (GPIO_E_BASE_ADDR)
#define GPIO_E_SPEED (GPIO_E_BASE_ADDR + 0x08)
#define GPIO_E_PULL  (GPIO_E_BASE_ADDR + 0x0C)
#define GPIO_E_IDR   (GPIO_E_BASE_ADDR + 0x10)
#define GPIO_E_ODR   (GPIO_E_BASE_ADDR + 0x14)

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
	bool GetDoorStatus();
	private:
  unsigned char port_map;
	bool doorstatus;
};

class buzzer {
	public:
	buzzer(unsigned char);
	bool GetBuzzerStatus();
	bool SetBuzzer();
	private:
	unsigned char port_map;
	bool buzzerstatus;
};

class programswitches
{
	public:
		programswitches(unsigned char);
		bool GetSwitches();
	private:
		unsigned char port_map;
		bool switchvalue;
};

class acceptcancelswitches
{
	public:
		acceptcancelswitches(unsigned char);
	bool GetSwitches();
	private:
		unsigned char port_map;
	bool switchvalue;
};

// pointer to port E // (0x48001000)
extern GPIOs *GPIO_E;
//pointer to port C // (0x48000800)
extern GPIOs *GPIO_C; 
//pointer to port D // (0x48000C00)
extern GPIOs *GPIO_D;




#endif /* __WM_H */
