void uart5_gpio_init()
{
	//pin PC12->TX(UART 5)
	//pin PD2->RX(UART 5)
	// AFR->8 both

	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	RCC->AHBENR |= RCC_AHBENR_GPIODEN;

	//Moder setup for PC12
	GPIOC->MODER &= ~GPIO_MODER_MODER12_0;
	GPIOC->MODER |= GPIO_MODER_MODER12_1;

	//Moder setup for PD2
	GPIOD->MODER &= ~GPIO_MODER_MODER2_0;
	GPIOD->MODER |= GPIO_MODER_MODER2_1;

	//AFR setup for PC12 and PD2
	GPIOC->AFR[1] = 0x00080000;
	GPIOD->AFR[0] = 0x00000800;

	//Pull up setup
	GPIOC->PUPDR |= GPIO_PUPDR_PUPDR12_0;
	GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR12_1;

	GPIOD->PUPDR |= GPIO_PUPDR_PUPDR2_0;
	GPIOD->PUPDR &= ~GPIO_PUPDR_PUPDR2_1;

	//Maximum speed setup
	GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR12_0;
	GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR12_1;

	GPIOD->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR2_0;
	GPIOD->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR2_1;
}


void uart5_init()
{
	uart5_gpio_init();
	//Enabling clock for UART
	RCC->APB1ENR |= RCC_APB1ENR_UART5EN;

	//Enabling the uart
	UART5->CR1 |= USART_CR1_UE;

	UART5->CR1 &= ~USART_CR1_M;

	//baud rate selection
	UART5->BRR = ((6 << 0) | (208 << 4));

	// enable receiver and transmitter
	UART5->CR1 |= USART_CR1_RE;
//	UART5->CR1 |= USART_CR1_TE;

//	UART5->DR = 0x61;
	obs = UART5->DR;
	while((UART5->SR & USART_SR_RXNE) == 0);
	
}
