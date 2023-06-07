#ifndef _WIFI_H_
#define _WIFI_H_

#include "esp_netif.h"

#define WIFI_STA_SSID           "Hai Nam"
#define WIFI_STA_PASSWORD       "23581104"
#define WIFI_MAXIMUM_RETRY      5

void wifi_start(void);
void stop_wifi(void);

#endif