#ifndef ESP32_UART_H_
#define ESP32_UART_H_

#include "esp_err.h"  
#include "esp_log.h"
#include "esp_check.h"
#include "driver/uart.h"



esp_err_t uart_init(void);
esp_err_t print(char* string);
esp_err_t printBreak(char* string);



#endif
