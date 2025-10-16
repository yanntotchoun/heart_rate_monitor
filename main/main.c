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

uint8_t FIFO_R_PTR,FIFO_W_PTR;
uint8_t register_r=0x04,register_w=0x06;

//uint8_t availableSamples =(register_w-register_r)&0x1F;
//uint8_t dataSize= availableSamples*6;

void app_main(void)
{       //important to fix
    max30102_i2c_init();
   max302102_spo2_config();
   max302102_mode_config();
    max302102_int1_config();
    max302102_int2_config();
    max302102_fifo_config();

    while (1) {
        // do nothing, just yield so the idle task runs
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
