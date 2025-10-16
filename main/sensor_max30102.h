#ifndef SENSOR_MAX30102_H_
#define SENSOR_MAX30102_H_
#include "esp_err.h"  
#include "esp_log.h"
#include "esp_check.h"
#include "esp32_i2c.h"


esp_err_t max302102_spo2_config(void);
esp_err_t max302102_mode_config(void);
esp_err_t max302102_int1_config(void);
esp_err_t max302102_int2_config(void);
esp_err_t max302102_fifo_config(void);
esp_err_t max302102_int1_config(void);





#endif
