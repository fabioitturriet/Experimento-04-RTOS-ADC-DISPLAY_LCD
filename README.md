# Experimento-04-RTOS-ADC-DISPLAY_LCD

# Biblioteca PanTompkinsQRS


# Biblioteca RingBuffer

 A utilização da funções basicas para comunicação, como por exemplo a HAL_UART_Receive(), não é adquada por a comunicação é realizada em modo de bloqueio (o CPU fica "esperando" os dados chegar). Além disso, nessa função deve ser especificada o tempo que a comunicação acontece, ou seja o tempo que o CPU fica esperando os dados chegarem, o que é inviável na comunicação com o ESP já que o tempo de resposta do ESP para os comandos é variável. 
 
 A Biblioteca RingBuffer implementa funções para comunicação UART utilizando interrupção e DMA o que deixa a comunicação fluida. Algumas das funções permite copiar mensagens recebidas a partir de tags especificas, esperar até que mensagens específicas cheguem na memória, etc.
 
 Esta biblioteca foi adaptada para a plataforma F7 e implementada para comunicação com o ESP. Porém após a conexão do ESP com o Wi-Fi começou a ocorrer erros de comunicação com o ESP (Frame Error). 
 
 Como o erro não foi resolvido até o momento esta sendo utilizada as funções básicas Hal. Porém futuramente essas funções basicas podem gerar problemas de comunicação como por exemplo, em situações em que os dados sejam transmitidos enquanto são aquisitados.
