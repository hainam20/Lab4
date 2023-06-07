#ifndef _ESP_MQTT_H_
#define _ESP_MQTT_H_

#define URI         "mqtt://mqtt.flespi.io"    
#define ClientId    "ESP32"
#define Username    "ji6loTZXVLuTpoekXhlgDKvuBLYuXyt4EofS54FQFXxSaC0VHb1aKksbVfuIDLA5"
#define Password    ""

void mqtt_start(void);
void mqtt_stop(void);
char* get_data_MQTT();
void process_data_from_mqtt();
#endif