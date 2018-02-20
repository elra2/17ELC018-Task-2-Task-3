/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM_H
#define __STM_H

extern "C" {  // this is needed to make C++ and C work together
  #include "board_startup.h"   // you DON'T need to worry about the contents of this file
}

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

// port C - set to output
uint32_t GPIO_C_Mode = 0x55555555;  // 0b01010101010101010101010101010101  00 = input, 01 = output
uint32_t GPIO_C_Speed = 0xFFFFFFFF; // 0b11111111111111111111111111111111  11 - high speed output only
uint32_t GPIO_C_Pull = 0xaaaaaaaa;  // 0b10101010101010101010101010101010  00 none, 01 = pull up, 10 pull down

// port D - set to output
uint32_t GPIO_D_Mode = 0x55555555;  // 0b01010101010101010101010101010101  00 = input, 01 = output
uint32_t GPIO_D_Speed = 0xFFFFFFFF; // 0b11111111111111111111111111111111  11 - high speed output only
uint32_t GPIO_D_Pull = 0xaaaaaaaa;  // 0b10101010101010101010101010101010  00 none, 01 = pull up, 10 pull down

// port E - set to input
uint32_t GPIO_E_Mode = 0x00000000;  // 0b00000000000000000000000000000000  00 = input, 01 = output
uint32_t GPIO_E_Pull = 0x55555555;    // 0b10101010101010101010101010101010  00 none, 01 = pull up, 10 pull down

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


#endif /* __STM_H */
