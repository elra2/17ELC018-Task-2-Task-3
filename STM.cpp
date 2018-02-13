#include "STM.h"
extern "C" {  // this is needed to make C++ and C work together
  #include "board_startup.h"   // you DON'T need to worry about the contents of this file
}


void setupports(void)
	{
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
	}
