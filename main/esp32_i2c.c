#include "driver/i2c_master.h"
#include "driver/i2c_slave.h"
#include "esp_err.h"  
#include "esp_log.h"
#include "esp_check.h"

#define I2C_SLAVE_SCL_IO 2
#define I2C_SLAVE_SDA_IO 3
#define ESP_ADDR 0x58
#define MAX30102_ADDR 0x57
#define I2C_MASTER_SCL_IO 22
#define I2C_MASTER_SDA_IO 21

static const char *TAG = "I2C_MAX";
static i2c_master_bus_handle_t master_bus=NULL;
static i2c_master_dev_handle_t max30102=NULL;

esp_err_t max30102_i2c_init(void){

    i2c_master_bus_config_t i2c_mst_config = {
    .clk_source = I2C_CLK_SRC_DEFAULT,
    .i2c_port = I2C_NUM_0,
    .scl_io_num = I2C_MASTER_SCL_IO,
    .sda_io_num = I2C_MASTER_SDA_IO,
    .glitch_ignore_cnt = 7,
    .flags.enable_internal_pullup = true,
    };static i2c_slave_dev_handle_t slave_handle=NULL;

    ESP_RETURN_ON_ERROR(i2c_new_master_bus(&i2c_mst_config, &master_bus),TAG,"master bus failed to create");

    i2c_device_config_t dev_cfg = {
        .dev_addr_length = 7,
        .device_address = MAX30102_ADDR,
        .scl_speed_hz = 100000,
    };

    ESP_RETURN_ON_ERROR(i2c_master_bus_add_device(master_bus, &dev_cfg, &max30102),TAG,"Failed to add MAX30102 on master bus");

    ESP_LOGI(TAG, "I2C master ready; MAX30102 @ 0x%02X", MAX30102_ADDR);
    return ESP_OK;
}

esp_err_t max30102_readData(uint8_t reg,uint8_t *val,uint8_t datasize){
    
    return i2c_master_receive(max30102,&reg,datasize,-1);
}
