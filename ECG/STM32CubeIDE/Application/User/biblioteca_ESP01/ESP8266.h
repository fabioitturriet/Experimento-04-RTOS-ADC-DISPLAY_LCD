/*
 * ESP8266.h
 *
 *  Created on: Jan 10, 2023
 *      Author: Patrick
 */

#ifndef APPLICATION_USER_BIBLIOTECA_ESP01_ESP8266_H_
#define APPLICATION_USER_BIBLIOTECA_ESP01_ESP8266_H_

#include "stm32f7xx_hal.h"
#include "main.h"

typedef enum
{
  AT_OK       = 0x00U,
  AT_ERROR    = 0x01U,
  AT_BUSY     = 0x02U
} AT_StatusTypeDef;


void ESP_init();

/*
 * Desliga o WIFI/ESP
 */
void WiFi_OFF();

/*Utiliza AT+CWLAP para buscar as redes dispíveis
 * Separa os nomes das redes e salva na struct Redes[]
 * Return o número de redes encontradas
 * Ex:
AT+CWLAP
+CWLAP:(0,"IF-PESQUISA-2.4GHz",-51,"d4:6e:0e:69:ee:f8",2,15)
+CWLAP:(0,"IF-07-TI",-89,"d4:6e:0e:69:e4:08",2,15)
+CWLAP:(0,"IF-09-ADMINISTRACAO",-83,"d4:6e:0e:69:ec:d0",10,15)

OK
Numero de redes: 3
IF-PESQUISA-2.4GHz
IF-07-TI
IF-09-ADMINISTRACAO
 */
uint8_t BuscarRedes();

void ConectarWiFi();

AT_StatusTypeDef transmitATcommand(const char *string);

AT_StatusTypeDef rodaComandoAT(char* comandoAT, uint32_t delay);

AT_StatusTypeDef VerificaErro(char *StringReceived, char *EsperarAte);

#endif /* APPLICATION_USER_BIBLIOTECA_ESP01_ESP8266_H_ */
