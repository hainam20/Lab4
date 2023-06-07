#include <stdio.h>
#include <inttypes.h>
#include "nvs_flash.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "string.h"


#include "wifi.h"
#include "ble_app.h"
#include "esp_mqtt.h"

extern char* MQTT_Data;

void task(void *pvParameters)
{
    wifi_start(); 
    mqtt_start();
    while (true)
    {
        if(MQTT_Data != NULL)
        {
                process_data_from_mqtt();  
                break;
        }
    }
               
}


void app_main(void)
{
    esp_err_t ret = nvs_flash_init();
    if(ret == ESP_ERR_NVS_NO_FREE_PAGES && ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    xTaskCreate(&task, "task mqtt ble", 8192, NULL, 5, NULL);

}
