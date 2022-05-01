baud_rate = 9600 # Change for desired baudrate
clock = 32000000

usart_div = clock/(16 * baud_rate)

# print(usart_div)
before_uart = hex(int(usart_div))
after_uart = int((usart_div % 1) * 16) + 1

# print(usart_div)
print(before_uart)
print(after_uart)
