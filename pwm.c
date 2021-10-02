void pwm_gpio_init()
{
	// Description: Pin:PB8, AFR = 3(0011), MODER = 10 , TIM10_CH1
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

	GPIOB->MODER &= ~GPIO_MODER_MODER8_0;
	GPIOB->MODER |= GPIO_MODER_MODER8_1;

	GPIOB->AFR[1] = 0x00000003;

}

void pwm_init()
{
	RCC->APB2ENR |= RCC_APB2ENR_TIM10EN;
	//up counter
	TIM10->CNT = 0;
	TIM10->ARR = 65535; // frequancy setup
	TIM10->CCMR1 = 0X0060;
	TIM10->CCER |= TIM_CCER_CC1E;
	TIM10->PSC = 0;
	TIM10->CCR1 = 32767; //duty cycle setup
	TIM10->CR1 |= TIM_CR1_CEN;


}

