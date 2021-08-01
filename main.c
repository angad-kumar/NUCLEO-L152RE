#include "stm32l1xx.h"
#include "stm32l1xx_nucleo.h"


#define LED_ON          GPIOA->BSRRL|= GPIO_BSRR_BS_5;
#define LED_OFF         GPIOA->BSRRH|= GPIO_BSRR_BS_5;
int main(void)
{
	led_init();
	while(1)
	{
	LED_ON;
	delay(1000);
	LED_OFF;
	delay(1000);
}}
