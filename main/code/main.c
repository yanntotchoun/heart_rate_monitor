/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

 // COLD JOINTS????, CHECK SOLDERING

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sensor_max30102.h"
#include "esp32_i2c.h"
#include "esp32_uart.h"

const char *TAG1="TESTING";


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

void i2cScanner(void){
   printf("Scanning ...\n");
  for(int i=1;i<=127;i++){

  esp_err_t status = probe(i);

    if(status == ESP_OK){
      printf("Device found at address  0x%02X\n",i);
   

    }

  }

  printf("Scan complete.\n");
}


void app_main(void)
{      
  
    // uint8_t part=0,rev=0;// you always have to initialise values in C
    // ESP_ERROR_CHECK(max30102_i2c_init());
    // ESP_LOGE(TAG1,"I2C is working");
    
    // vTaskDelay(pdMS_TO_TICKS(100)); // After I2C init
    // max302102_spo2_config();
    // vTaskDelay(pdMS_TO_TICKS(100)); // After I2C init
    // max302102_mode_config();
    // vTaskDelay(pdMS_TO_TICKS(100)); // After I2C init
    // max302102_int1_config();
    // max302102_int2_config();
    // max302102_fifo_config();
    // vTaskDelay(pdMS_TO_TICKS(100)); // After I2C init
    // uart_init();
    //i2cScanner();

    uint8_t part = 0, rev = 0;
    vTaskDelay(pdMS_TO_TICKS(100)); 
    ESP_ERROR_CHECK(max30102_i2c_init());
    ESP_LOGI(TAG1, "I2C is working");

    esp_err_t r1 = i2c_master_probe(master_bus, 0x57, 100);
  ESP_LOGI("DEBUG", "probe 1: %s", r1 == ESP_OK ? "FOUND" : "NOT FOUND");

    vTaskDelay(pdMS_TO_TICKS(100));  // let bus + sensor settle
    // Check 2 - after delay
esp_err_t r2 = i2c_master_probe(master_bus, 0x57, 100);
ESP_LOGI("DEBUG", "probe 2: %s", r2 == ESP_OK ? "FOUND" : "NOT FOUND");

  
    max30102_reset();

    // Check 3 - after reset attempt
    esp_err_t r3 = i2c_master_probe(master_bus, 0x57, 100);
    ESP_LOGI("DEBUG", "probe 3: %s", r3 == ESP_OK ? "FOUND" : "NOT FOUND");
    // max302102_spo2_config();
    // max302102_mode_config();
    // max302102_int1_config();
    // max302102_int2_config();
    // max302102_fifo_config();
    // vTaskDelay(pdMS_TO_TICKS(10));   // let config settle
    // i2cScanner();

    uart_init();


    while (1) {
        readSensor(&part,&rev);
        vTaskDelay(pdMS_TO_TICKS(1000));
        printf("Part ID: 0x%02X\n",part);
        printf("Revision ID: 0x%02X ",rev);
        //printf("you are a bum\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
