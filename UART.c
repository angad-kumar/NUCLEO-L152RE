void uart4_gpio_init()
{
	//pin PC10->TX(UART 4)
	//pin PC11->RX(UART 4)
	// AFR->8 both

	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;

	//Moder setup for PC10
	GPIOC->MODER &= ~GPIO_MODER_MODER10_0;
	GPIOC->MODER |= GPIO_MODER_MODER10_1;

	//Moder setup for PC11
	GPIOC->MODER &= ~GPIO_MODER_MODER11_0;
	GPIOC->MODER |= GPIO_MODER_MODER11_1;

	//AFR setup for PC10
	GPIOC->AFR[1] = 0x00008800;

	//AFR setup for PC11
//	GPIOC->AFR[1] = 0x00008000;

	//Pull up setup
	GPIOC->PUPDR |= GPIO_PUPDR_PUPDR10_0;
	GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR10_1;

	GPIOC->PUPDR |= GPIO_PUPDR_PUPDR11_0;
	GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR11_1;

	//Maximum speed setup
	GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR10_0;
	GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR10_1;

	GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR11_0;
	GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR11_1;

}



void uart4_init()
{
	uart4_gpio_init();
	//Enabling clock for UART
	RCC->APB1ENR |= RCC_APB1ENR_UART4EN;

	//Enabling the uart
	UART4->CR1 |= USART_CR1_UE;

	UART4->CR1 &= ~USART_CR1_M;

	//baud rate selection
	UART4->BRR = ((6 << 0) | (208 << 4));

	// enable receiver and transmitter
//	UART4->CR1 |= USART_CR1_RE;
	UART4->CR1 |= USART_CR1_TE;
	
	UART4->DR = 0x61;
	while((UART4->SR & USART_SR_TC) == 0);

}

