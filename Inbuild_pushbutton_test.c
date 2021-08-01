void button_init()
{
	//In Build Push Button is connected with PC13 pin

	//Enabling clock for PC13
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;

	//Setting moder for INPUT
	GPIOC->MODER &= ~GPIO_MODER_MODER13_1;
	GPIOC->MODER &= ~GPIO_MODER_MODER13_0;
	if((GPIOC->IDR & GPIO_IDR_IDR_13) == 0 )
		{
			LED_ON;
		}
		else
		{
			LED_OFF;
		}
}
