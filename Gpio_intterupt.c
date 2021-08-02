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

		LED_ON;
		EXTI->PR &= ~EXTI_PR_PR13;
	}
	 if((EXTI->PR & EXTI_PR_PR13) ==0)
	{

		LED_OFF;
	}
}
