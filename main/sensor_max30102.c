#include "esp32_i2c.h"

#define FIFO_CONFIG_REG 0x08
#define INT_EN_REG_1 0x02
#define INT_EN_REG_2 0x03
#define FIFO_W_REG 0x04
#define FIFO_R_REG 0x06
#define FIFO_DATA_REG 0x07
#define INT_STAT_REG_1 0x00
#define INT_STAT_REG_2 0x01 
#define MODE_CONFIG_REG 0x09
#define SPO2_CONFIG_REG 0x0A
#define LED_AMP_CONFIG_REG_1 0x0C
#define LED_AMP_CONFIG_REG_2 0x0D
#define MULTI_LED_CONFIG_REG_1 0x11
#define MULTI_LED_CONFIG_REG_2 0x12
#define DIE_TEMP_INT_REG 0x1F
#define DIE_TEMP_FRAC_REG 0x20
#define DIE_TEMP_CONFIG_REG 0x21


//add tag for error handling
esp_error_t max302102_spo2_config(void){

    uint8_t val;
    uint8_t spo2[2];
    spo[0]=SPO2_CONFIG_REG;

    ESP_RETURN_ON_ERROR(max30102_readRegister(spo2[0],&val));

    val = (val&0x80)|0x6F;//(uint8_t) add this maybe
    spo[1]=val;

    ESP_RETURN_ON_ERROR(max30102_writeRegister(spo2));


    return ESP_OK:
}

esp_error_t max302102_mode_config(void){
    uint8_t val;
    uint8_t mode[2];
    mode[0]=MODE_CONFIG_REG;
    ESP_RETURN_ON_ERROR(max30102_readRegister(mode[0],&val));

    val = (val&0x38)|0x06;
    mode[1]=val;
    ESP_RETURN_ON_ERROR(max30102_writeRegister(mode));


    return ESP_OK:
}

