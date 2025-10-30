#include "sensor_max30102.h"
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
#define REV_ID_REG 0xFE
#define PART_ID_REG 0xFF

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

uint8_t readWritePointer(void){
    uint8_t writePointer;
    max30102_readRegister(FIFO_W_REG,&writePointer);
    return writePointer;

}


uint8_t readReadPointer(void){
    uint8_t readPointer;
    max30102_readRegister(FIFO_R_REG,&readPointer);
    return readPointer;

}

esp_err_t readMAX30102(uint32_t *irData,uint32_t *redData){
    uint8_t data[6];// temporary buffer for 3 bytes of Red and 3 bytes of ir
    uint8_t readPointer,writePointer,samplesToRead,availableSamples;

    readPointer = readReadPointer();
    writePointer = readWritePointer();
    
    //prevent FIFO wraparound
    if(writePointer>=readPointer){
         availableSamples = (writePointer-readPointer)&0x1F;
    }else{
        availableSamples= (32-readPointer)+writePointer;
    }

    samplesToRead = availableSamples;// taking a snapshot because new data can come in while we do that
 
    if(samplesToRead > 0){
        for (size_t i = 0; i < samplesToRead; i++)
        {
             max30102_readRegisterN(FIFO_DATA_REG,data,6);

            irData[i] =(data[0]<<16) | (data[1]<<8) | data[2];
            redData[i]= (data[3]<<16) | (data[4]<<8) | data[5];

            
        }

        return ESP_OK;

    }else{
        return ESP_FAIL;
    }
    /*
    data[0] = LED1[23:16]  // Red LED, most significant byte 
    data[1] = LED1[15:8]   // Red LED, middle byte
    data[2] = LED1[7:0]    // Red LED, least significant byte
    data[3] = LED2[23:16]  // IR LED, most significant byte
    data[4] = LED2[15:8]   // IR LED, middle byte  
    data[5] = LED2[7:0]    // IR LED, least significant byte
    */

}

esp_err_t readSensor(uint8_t *partID,uint8_t *revID ){

ESP_RETURN_ON_ERROR(max30102_readRegister(PART_ID_REG,partID),TAG,"couldn't read Part ID");
ESP_RETURN_ON_ERROR(max30102_readRegister(REV_ID_REG,revID),TAG,"couldn't read Revision ID");

return ESP_OK;
}