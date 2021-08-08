#include "stm32l1xx.h"
#include "stm32l1xx_nucleo.h"

#define LED_ON          GPIOA->BSRRL|= GPIO_BSRR_BS_5;
#define LED_OFF         GPIOA->BSRRH|= GPIO_BSRR_BS_5;
#define LED_TOGGLE      GPIOA->ODR ^= GPIO_ODR_ODR_5;

int count = 0;
int flag = 1;
int main(void)
{

	led_init();
	interrupt_init();
	while(1)
	{

	}
}

void interrupt_init()
{
	//Enabling clock for PC13
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;

	//Setting moder for INPUT
	GPIOC->MODER &= ~GPIO_MODER_MODER13_1;
	GPIOC->MODER &= ~GPIO_MODER_MODER13_0;

	//Enabling SYSCONFG register
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

	//clearing the bit
	SYSCFG->EXTICR[3] &= ~(1U<<4);
	SYSCFG->EXTICR[3] &= ~(1U<<5);
	SYSCFG->EXTICR[3] &= ~(1U<<6);
	SYSCFG->EXTICR[3] &= ~(1U<<7);
	//now setup the bit
	SYSCFG->EXTICR[3] |= (1U<<5);

	//Unmask the interrupt
	EXTI->IMR |= EXTI_IMR_MR13;

	//Falling edge trigger
	EXTI->FTSR |= EXTI_FTSR_TR13;

	//enable exti13 in NAVIC
	NVIC_EnableIRQ(EXTI15_10_IRQn);

}

void EXTI15_10_IRQHandler(void)
{
	if((EXTI->PR & EXTI_PR_PR13) !=0)
	{

//		LED_TOGGLE;
		count++;
		counter();
		EXTI->PR |= EXTI_PR_PR13;
//		count++;
//		counter();
	}

}

void led_init()
{
	//In build led is connected with pin PA5

	//Enabling clock for Gpio
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

	// Setting moder for OUTPUT
	GPIOA->MODER &= ~GPIO_MODER_MODER5_1;
	GPIOA->MODER |= GPIO_MODER_MODER5_0;

}

void counter()
{
	if(count<5)
	{
		LED_OFF;

	}
	else if(count >=10 & count <=15)
	{
		LED_ON;
	}
	else if(count>15)
	{
		LED_OFF;
	}
}
