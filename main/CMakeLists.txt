idf_component_register(
  SRCS
    "main.c"
    "esp32_i2c.c"
    "sensor_max30102.c"
  INCLUDE_DIRS
    "."
  REQUIRES
    esp_driver_i2c     # new I2C driver API (v5)
    esp_driver_gpio    # if you use the MAX30102 INT pin
    esp_timer          # delays/timestamps if you use them
    log                # ESP_LOGx() macros
    esp_common         # esp_err.h, esp_check.h (ESP_RETURN_ON_ERROR)
)
