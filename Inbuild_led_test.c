#define LED_ON          GPIOA->BSRRL|= GPIO_BSRR_BS_5;
#define LED_OFF         GPIOA->BSRRH|= GPIO_BSRR_BS_5;

void led_init()
{
	//In build led is connected with pin PA5

	//Enabling clock for Gpio
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

	// Setting moder for OUTPUT
	GPIOA->MODER &= ~GPIO_MODER_MODER5_1;
	GPIOA->MODER |= GPIO_MODER_MODER5_0;

}
