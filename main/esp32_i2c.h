#ifndef ESP32_I2C_H_
#define ESP32_I2C_H_

#include "driver/i2c_master.h"
#include "driver/i2c_slave.h"
#include "esp_err.h"  
#include "esp_log.h"
#include "esp_check.h"

#define I2C_SLAVE_SCL_IO 2
#define I2C_SLAVE_SDA_IO 3
#define ESP_SLAVE_ADDR 57
#define I2C_MASTER_SCL_IO 22
#define I2C_MASTER_SDA_IO 21

esp_err_t max30102_i2c_init(void){};
esp_err_t readData(i2c_master_dev_handle_t dev, uint8_t data,size_t data_size){};