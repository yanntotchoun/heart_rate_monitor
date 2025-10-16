#include "sensor_max30102.h"

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

static const char *TAG = "MAX30102";

esp_err_t max302102_spo2_config(void){
    uint8_t val;
    uint8_t spo2[2];
    spo2[0] = SPO2_CONFIG_REG;

    val = 0x6F;
    spo2[1] = val;

   
    ESP_RETURN_ON_ERROR(max30102_writeRegister(spo2), TAG, "failed to write spo2");

    return ESP_OK; 
}

esp_err_t max302102_mode_config(void){
    uint8_t val;
    uint8_t mode[2];
    mode[0] = MODE_CONFIG_REG;
    

    val = 0x06;
    mode[1] = val;
    
    ESP_RETURN_ON_ERROR(max30102_writeRegister(mode), TAG, "failed to write mode");

    return ESP_OK;  
}

esp_err_t max302102_int1_config(void){
    uint8_t val;
    uint8_t intt[2];
    intt[0] = INT_EN_REG_1;

    val = 0xC0;
    intt[1] = val;
    
    ESP_RETURN_ON_ERROR(max30102_writeRegister(intt), TAG, "failed to write int1");

    return ESP_OK;  
}

esp_err_t max302102_int2_config(void){
    uint8_t val;
    uint8_t intt[2];
    intt[0] = INT_EN_REG_2;

    val = 0;
    intt[1] = val;
    
    ESP_RETURN_ON_ERROR(max30102_writeRegister(intt), TAG, "failed to write int2");

    return ESP_OK;  
}

esp_err_t max302102_fifo_config(void){
    uint8_t val;
    uint8_t fifo[2];
    fifo[0] = FIFO_CONFIG_REG;

    val = 0xF7;
    fifo[1] = val;
    
    ESP_RETURN_ON_ERROR(max30102_writeRegister(fifo), TAG, "failed to write fifo");

    return ESP_OK;  
}