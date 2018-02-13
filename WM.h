// Definitions for the Device Drivers on STM32F3 Discovery Board
// DJM 23/01/2018

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __WM_H
#define __WM_H

extern "C" {  // this is needed to make C++ and C work together
  #include "board_startup.h"   // you DON'T need to worry about the contents of this file
}

// hold a bit value returned from a port
bool port;

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
	void ReadDoorStatus();
	private:
  unsigned char port_map;
	bool doorstatus;
};

class buzzer {
	public:
	buzzer(unsigned char);
	void SetBuzzer();
	private:
	unsigned char port_map;
	bool buzzerstatus;
};

class Switches
{
	public:
		Switches(unsigned char);
		bool GetSwitch();
	  void ReadSwitch();
	  void Reset();
	  void AcceptUserInput();
	private:
		unsigned char port_map;
		bool switchvalue;
};

class motor
{
	public: 
		motor(unsigned int);
	 int GetMotorSpeed();
	void SetControlOFF();
		void SetControlON();
	void SetDirectionCW();
		void SetDirectionACW();
	bool GetControlStatus();
	private:
		unsigned int port_map;
	int motorspeed;
	int motordirection;
	bool controlstatus;
};

class timer
{
	public:
		timer();
		void wait(unsigned int);
	private:
		int time;
};

//pointer to port C // (0x48000800)
extern GPIOs *GPIO_C; //parallel port
//pointer to port D // (0x48000C00)
extern GPIOs *GPIO_D;
// pointer to port E // (0x48001000)
extern GPIOs *GPIO_E;


#endif /* __WM_H */

