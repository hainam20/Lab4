#include <stdio.h>
#include <inttypes.h>
#include "nvs_flash.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "string.h"


#include "wifi.h"
#include "ble_app.h"
#include "esp_mqtt.h"

extern uint8_t MQTT_Data[20];
extern uint8_t write_data[20];
extern bool flag;
extern bool flag2;
void task()
{
    ble_start(); 
    while (1)
    {
        if(flag == true)
        {
                wifi_start();
                mqtt_start();
                vTaskDelay(pdMS_TO_TICKS(20000));
                printf("MQTT_data: %s\n", MQTT_Data);
                flag = false;
                stop_wifi();
                while (1)
                {
                    if (flag2 == true)
                    {
                        vTaskDelay(pdMS_TO_TICKS(10000));
                        ble_stop();
                        flag2 = false;
                        break;
                    }
                }
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
    // ble_start();
    xTaskCreate(&task, "task_mqtt_ble", 8192, NULL, 5, NULL);
    // task();
}
