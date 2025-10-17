#include "esp32_uart.h"

#define BAUD_RATE 115200

const uart_port_t uart_num = UART_NUM_2;

static const char *TAG = "UART";

esp_err_t uart_init(void){

    // Setup UART buffered IO with event queue
    const int uart_buffer_size = (1024 * 2);
    QueueHandle_t uart_queue; // Handle to queue that stores UART event notifications (not the actual data)

    // Install UART driver using an event queue here
    ESP_ERROR_CHECK(uart_driver_install(UART_NUM_2, uart_buffer_size, uart_buffer_size, 10, &uart_queue, 0));

    /*
    UART_NUM_2 - Specifies UART port 2 (ESP32 has multiple UART ports: 0, 1, 2)
    uart_buffer_size - RX (receive) buffer size of 2048 bytes
    uart_buffer_size - TX (transmit) buffer size of 2048 bytes
    10 - Event queue size (can hold up to 10 UART events before blocking)
    &uart_queue - Pointer to the queue handle where UART events will be posted
    0 - Interrupt allocation flags (0 = default)
    */

    uart_config_t uart_config = {
        .baud_rate = BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,    // Each byte = 8 bits (constant = 3)
        .parity = UART_PARITY_DISABLE,    // No error checking (constant = 0)
        .stop_bits = UART_STOP_BITS_1,    // 1 stop bit (constant = 1)
        .flow_ctrl = UART_HW_FLOWCTRL_CTS_RTS,  // Hardware flow control enabled
        .rx_flow_ctrl_thresh = 122, // Trigger flow control at 122 bytes
    };
    // Configure UART parameters
    ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));

    // Set UART pins(TX: IO4, RX: IO5, RTS: IO18, CTS: IO19)
   ESP_ERROR_CHECK(uart_set_pin(UART_NUM_2, 4, 5, 18, 19));

    return ESP_OK;
}


//gpio init for the screen maybe
esp_err_t print(char* string){
    //data goes out through the TX pin
    int message = uart_write_bytes(uart_num, (const char*)string, strlen(string));

    if(message<0){
        ESP_LOGE(TAG,"failed to transmit string");
        return ESP_FAIL;
        
    }
    return ESP_OK;
}

esp_err_t printBreak(char* string){

    //Function that sends a warning before printing

    int message = uart_write_bytes_with_break(uart_num, string,strlen(string), 100);
    //break len is in bit time

    if(message<0){
        ESP_LOGE(TAG,"failed to transmit string");
        return ESP_FAIL;
        
    }

    return ESP_OK;
}