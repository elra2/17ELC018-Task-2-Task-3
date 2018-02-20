extern "C" {  // this is needed to make C++ and C work together
  #include "board_startup.h"   // you DON'T need to worry about the contents of this file
}

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

//pointer to port C // (0x48000800)
extern GPIOs *GPIO_C;
//pointer to port D // (0x48000C00)
extern GPIOs *GPIO_D;
// pointer to port E // (0x48001000)
extern GPIOs *GPIO_E;

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


