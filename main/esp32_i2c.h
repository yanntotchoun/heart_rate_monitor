#ifndef ESP32_I2C_H_
#define ESP32_I2C_H_

#include "driver/i2c_master.h"
#include "driver/i2c_slave.h"
#include "esp_err.h"  
#include "esp_log.h"
#include "esp_check.h"

esp_err_t max30102_i2c_init(void);
esp_err_t max30102_readRegister(uint8_t reg, uint8_t *data);  
esp_err_t max30102_readRegisterN(uint8_t reg, uint8_t *data, size_t N);  
esp_err_t max30102_writeRegister(const uint8_t *reg_data);  
esp_err_t max30102_writeRegisterN(const uint8_t *reg_data, size_t N); 
esp_err_t probe(uint16_t );   
#endif // ESP32_I2C_H_