idf_component_register(
    SRCS
        "main.c"
        "esp32_i2c.c"
    INCLUDE_DIRS
        "."
    REQUIRES
        driver          # <— pulls in I2C driver APIs
        esp_timer       # common dep for examples/logging
        esp_hw_support  # safe add, many drivers rely on this
        freertos        # you likely use tasks/delays
        esp_driver_i2c  # new I2C driver in IDF V5
        log             #i have no idea  
        esp_common      #error handling
    
)
