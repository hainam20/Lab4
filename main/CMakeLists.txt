idf_component_register(SRCS "ble_app.c" "wifi.c" "main.c" "esp_mqtt.c"
                    INCLUDE_DIRS ".")
target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")