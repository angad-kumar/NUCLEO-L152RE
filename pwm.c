void pwm_test()
{
	// PA3 and Tim2_ch4

	//Enable clock for GPIO
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

	// set moder for GPIO
	GPIOA->MODER &= ~GPIO_MODER_MODER6_1;
	GPIOA->MODER |= GPIO_MODER_MODER6_0;

	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	TIM3->PSC = 1599;
	TIM3->ARR = 9999;
	TIM3->CNT = 0;
	TIM3->CR1 = 1;

	LED_ON
	T_ON
	while(1)
	{
		LED_ON
		GPIOA->BSRRH|= GPIO_BSRR_BS_6;
//		delay(1000);
		while(!(TIM3->SR & 1));
//		GPIOA->ODR ^= GPIO_ODR_ODR_3;
		LED_OFF;
		GPIOA->BSRRL|= GPIO_BSRR_BS_6;
//		delay(1000);
	}

}
