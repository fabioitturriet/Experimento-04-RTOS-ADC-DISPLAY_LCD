/*
 * ESP8266.c
 *
 *  Created on: Jan 10, 2023
 *      Author: Patrick
 */

/*------------------------------- INCLUDES -----------------------------*/
#include "ESP8266.h"
#include "UartRingbuffer_multi.h"
#include "stdio.h"
#include "string.h"



extern void USB_Print(char* string);

extern void bufclear(char *buf);

extern UART_HandleTypeDef huart5;

/*------------------------------- DEFINES -----------------------------*/
#define wifi_uart &huart5
#define BUFFER_READ_LEN 2048


char buffer[20];

struct SSID
{
	char NomeRede[32];
	uint16_t Senha[18];
};

struct SSID Redes[10];

extern uint16_t KeyboardSelection;


/*------------------------------- FUNÇÕES -----------------------------*/
void ESP_init()
{

//	Ringbuf_init();
//	USB_Print("\n\rRingBuffer Inicializado!\n\r");

	//********* Power up ESP **********/
	HAL_GPIO_WritePin(WIFI_CH_PD_GPIO_Port, WIFI_CH_PD_Pin, GPIO_PIN_SET);
	HAL_Delay(1000);

//	Uart_sendstring("AT+RST\r\n", wifi_uart);
	USB_Print("Resetando ESP");

	/********* AT+RST **********/
	if(rodaComandoAT("AT+RST\r\n", 5000)){
		if(rodaComandoAT("AT+RST\r\n", 5000)){
			if(rodaComandoAT("AT+RST\r\n", 5000)){
				USB_Print("\r\nError comando AT+RST\n\r\n");
			}else{
				for (int i=0; i<5; i++)
				{
					USB_Print(".");
					HAL_Delay(1000);
				}
				USB_Print("\r\nAT+RST---->OK\n\r\n");
			}
		}else{
			for (int i=0; i<5; i++)
			{
				USB_Print(".");
				HAL_Delay(1000);
			}
			USB_Print("\r\nAT+RST---->OK\n\r\n");

		}
	}else{
		for (int i=0; i<5; i++)
		{
			USB_Print(".");
			HAL_Delay(1000);
		}
		USB_Print("\r\nAT+RST---->OK\n\r\n");
	}

	/********* AT **********/
	if(rodaComandoAT("AT\r\n", 2000)){
		if(rodaComandoAT("AT\r\n", 2000)){
			if(rodaComandoAT("AT\r\n", 2000)){
				USB_Print("\r\nError comando AT\n\r\n");
			}else{
				USB_Print("\r\nAT---->OK\n\r\n");
			}
		}else{
			USB_Print("\r\nAT---->OK\n\r\n");

		}
	}else{
		USB_Print("\r\nAT---->OK\n\r\n");
	}

	/********* AT+CWMODE **********/
	if(rodaComandoAT("AT+CWMODE=1\r\n", 2000)){
		if(rodaComandoAT("AT+CWMODE=1\r\n", 2000)){
			if(rodaComandoAT("AT+CWMODE=1\r\n", 2000)){
				USB_Print("\r\nError comando AT+CWMODE\n\r\n");
			}else{
				USB_Print("\r\nAT+CWMODE---->OK\n\r\n");
			}
		}else{
			USB_Print("\r\nAT+CWMODE---->OK\n\r\n");

		}
	}else{
		USB_Print("\r\nAT+CWMODE---->OK\n\r\n");
	}

//	Uart_sendstring("AT+UART_DEF?\r\n", wifi_uart);
//	while (!(Copy_upto ("\r\n\r\n", comandosAT, wifi_uart)));
//	USB_Print(comandosAT);





//	/********* AT **********/
//	if(transmitATcommand("AT\r\n")){
//		if(transmitATcommand("AT\r\n")){
//			if(transmitATcommand("AT\r\n")){
//				USB_Print("\r\nError comando AT\n\r\n");
//			}else{
//				USB_Print("\r\nAT---->OK\n\r\n");
//			}
//		}else{
//			USB_Print("\r\nAT---->OK\n\r\n");
//
//		}
//	}else{
//		USB_Print("\r\nAT---->OK\n\r\n");
//	}
//
//	/********* AT+CWMODE=1 **********/
//	if(transmitATcommand("AT+CWMODE=1\r\n")){
//		if(transmitATcommand("AT+CWMODE=1\r\n")){
//			if(transmitATcommand("AT+CWMODE=1\r\n")){
//				USB_Print("\r\nError comando AT+CWMODE\n\r\n");
//			}else{
//				USB_Print("CW MODE---->1\n\r\n");
//			}
//		}else{
//			USB_Print("CW MODE---->1\n\r\n");
//
//		}
//	}else{
//		USB_Print("CW MODE---->1\n\r\n");
//	}

//	/********* AT **********/
//	Uart_sendstring("AT\r\n", wifi_uart);
//	while(!(Wait_for("AT\r\r\n\r\nOK\r\n", wifi_uart)));


	/********* AT+CWMODE=1 **********/
//	Uart_sendstring("AT+CWMODE=1,0\r\n", wifi_uart);
//	while (!(Wait_for("AT+CWMODE=1\r\r\n\r\nOK\r\n", wifi_uart)));
//	USB_Print("CW MODE---->1\n\r\n");


}

void WiFi_OFF()
{
	HAL_GPIO_WritePin(WIFI_CH_PD_GPIO_Port, WIFI_CH_PD_Pin, GPIO_PIN_RESET);
}

uint8_t BuscarRedes()
{
	char CWLAPResponse[700];
	char Marcador[7] = {'+', 'C', 'W', 'L', 'A', 'P', ':'};
	uint8_t count=0;
	uint8_t numCaracter=0;


	/********* AT+CWLAP **********/
	HAL_UART_Transmit(wifi_uart, "AT+CWLAP\r\n", strlen("AT+CWLAP\r\n"), HAL_MAX_DELAY);
	HAL_UART_Receive(wifi_uart, (uint8_t*)CWLAPResponse, 700, 4000);

	if(VerificaErro(CWLAPResponse, "\r\n\r\n")){
		return 0;
	}
	/********* SEPARAÇÃO DAS REDES **********/
	uint8_t NumeroRedes=-1;

	for(int i=0; i<strlen(CWLAPResponse); i++)
	{
		if(CWLAPResponse[i]==Marcador[count]){
			if(count == 6){
				count = -1;
				NumeroRedes++;
				memset(Redes[NumeroRedes].NomeRede, '\0', 32);
				while(CWLAPResponse[i]!='"') i++;
				for(int j=i+1; j<i+26; j++)
				{
					Redes[NumeroRedes].NomeRede[numCaracter] = CWLAPResponse[j];
					numCaracter++;
					if(CWLAPResponse[j+1]=='"'){
						break;
					}
				}
				numCaracter = 0;
			}
			count ++;

		}else{

			count = 0;
		}
	}


	USB_Print("pesquisa de wifi completa\n\r\n");

	return NumeroRedes+1;

}

void ConectarWiFi()
{
	char Received[500];
	char data[80];
	char senha[18];
	uint8_t len = 0;
	uint16_t *ptr = &Redes[KeyboardSelection].Senha[0];

	while(*ptr++)
		len++;

	for(uint8_t i=0; i<len; i++){
		senha[i]=Redes[KeyboardSelection].Senha[i];
	}
	senha[len] = '\0';

	/********* AT+CWJAP="SSID","PASSWD" **********/
	USB_Print("connecting... to the provided AP\n\r");
	sprintf (data, "senha,\"%s\"\n\n", senha);
	USB_Print(data);
	sprintf (data, "AT+CWJAP=\"%s\",\"%s\"\r\n", Redes[KeyboardSelection].NomeRede, senha);
	HAL_UART_Transmit(wifi_uart, data, strlen(data), HAL_MAX_DELAY);
	HAL_UART_Receive(wifi_uart, (uint8_t)Received, strlen(Received), 10000);
	if(VerificaErro(Received, "IP\r\n\r\n")){
		USB_Print("Erro de conexão com o Wi-Fi!!!");
	}else{
	sprintf (data, "Connected to,\"%s\"\n\n\r", Redes[KeyboardSelection].NomeRede);
	USB_Print(data);
	}
	for(int i=0; i<len; i++){
		senha[i]= '\0';
	}
	len = 0;
}

AT_StatusTypeDef transmitATcommand(const char *string)
{
	char ErrorCheck[15];

	Uart_sendstring(string, wifi_uart);
	while (!(Wait_for("\r\r\n\r\n", wifi_uart)));
	while (!(Copy_upto ("\r\n", ErrorCheck, wifi_uart)));

	for(uint8_t i=0; i<15; i++){
		if(ErrorCheck[i]== '\n'){
			ErrorCheck[i+1] = '\0';
			break;
		}
	}
	if(strcmp(ErrorCheck, "OK\r\n") == 0){
		return AT_OK;
	}else if(strcmp(ErrorCheck, "ERROR\r\n") == 0){
		return AT_ERROR;
	}else if(strcmp(ErrorCheck, "busy p...\r\n") == 0){
		return AT_BUSY;
	}else{
		return AT_OK;
	}
}

AT_StatusTypeDef rodaComandoAT(char* comandoAT, uint32_t delay){

	char Rx_data[BUFFER_READ_LEN];


 	uint8_t *msgtoESP;
 	uint16_t msgtoESP_size=0;


 	msgtoESP = (uint8_t *)comandoAT;
 	while(*comandoAT++)
 		msgtoESP_size++;

 	  HAL_UART_Transmit(wifi_uart, msgtoESP, msgtoESP_size, HAL_MAX_DELAY);
 	  HAL_UART_Receive(wifi_uart, (uint8_t*)Rx_data, BUFFER_READ_LEN, delay);
 	  return VerificaErro(Rx_data, "\r\r\n\r\n");
 }

AT_StatusTypeDef VerificaErro(char *StringReceived, char *EsperarAte){
	uint16_t msgReceivedLen = strlen(StringReceived);
	uint16_t EsperarAte_Counter = 0;
	uint16_t controle = strlen(EsperarAte);
	uint16_t i=0;

	uint8_t msgErrorLen=0;
	char ErrorCheck[15];

	while(i<msgReceivedLen){
		if(EsperarAte[EsperarAte_Counter] == StringReceived[i]){
			EsperarAte_Counter++;
		}else{
			EsperarAte_Counter = 0;
		}
		i++;
		if(EsperarAte_Counter == controle){
			break;
		}

	}
	if(i<msgReceivedLen){
		while(StringReceived[i] != '\n'){
			ErrorCheck[msgErrorLen]=StringReceived[i];
			msgErrorLen++;
			i++;
		}
		ErrorCheck[msgErrorLen+1]= '\n';
		ErrorCheck[msgErrorLen+2]= '\0';

		if(strcmp(ErrorCheck, "OK\r\n") == 0){
			return AT_OK;
		}else if(strcmp(ErrorCheck, "ERROR\r\n") == 0){
			return AT_ERROR;
		}else if(strcmp(ErrorCheck, "busy p...\r\n") == 0){
			return AT_BUSY;
		}else{
			return AT_OK;
		}
	}else{
		USB_Print("erro de comunicação com o ESP\r\n");
		return AT_ERROR;
	}



}

