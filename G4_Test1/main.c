#include "RTE_Components.h"
#include CMSIS_device_header
#include "LEDs.h"

#define FREQ	5

volatile uint64_t ticks;

volatile uint8_t copy;

int main(void){

	LEDs_Init();
	SysTick_Config(SystemCoreClock/FREQ);

	while(1){	
		ticks++;
	}
}

void SysTick_Handler(void){
	static volatile uint32_t data;
	data++;
	copy = data;
	LED_Toggle();
}

		