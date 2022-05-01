
baud_rate = 9600 # Change for desired baudrate
clock = 32000000

usart_div = clock/(16 * baud_rate)

# print(usart_div)
before_uart = int(usart_div)
after_uart = int((usart_div % 1) * 16) + 1

# print(usart_div)
print(hex(before_uart))
print(after_uart)



print("BRR Register Value: ",hex( (before_uart<<4) | after_uart ))
# print(string(before_uart))

# print(bytes.fromhex(before_uart).decode('utf-8'))
