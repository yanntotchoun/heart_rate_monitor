/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sensor_max30102.h"
#include "esp32_i2c.h"
#include "esp32_uart.h"


void vTaskUART( void * pvParameters )
{
for( ;; )
  {

  }
}

void vTaskMAX30102( void * pvParameters )
{
for( ;; )
  {

  }
}




void app_main(void)
{       //important to fix
    max30102_i2c_init();
    max302102_spo2_config();
    max302102_mode_config();
    max302102_int1_config();
    max302102_int2_config();
    max302102_fifo_config();
    uart_init();


    while (1) {
        
        printf("you are a bum\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
