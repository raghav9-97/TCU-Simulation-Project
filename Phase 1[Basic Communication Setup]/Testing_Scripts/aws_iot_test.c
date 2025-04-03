#include <stdio.h>
#include <string.h>
#include "esp_log.h"
#include "esp_wifi.h"
#include "mqtt_client.h"
#include "esp_event.h"
#include "nvs_flash.h"

extern const uint8_t client_cert_pem_start[] asm("_binary_client_crt_start");
extern const uint8_t client_cert_pem_end[] asm("_binary_client_crt_end");

extern const uint8_t client_key_pem_start[] asm("_binary_client_key_start");
extern const uint8_t client_key_pem_end[] asm("_binary_client_key_end");

extern const uint8_t server_cert_pem_start[] asm("_binary_server_crt_start");
extern const uint8_t server_cert_pem_end[] asm("_binary_server_crt_end");

// Configuration - Update these values!
#define WIFI_SSID "elecom-061db7"
#define WIFI_PASS "dvxfmhn42xy5"
#define AWS_IOT_ENDPOINT "a3mq2067foq75p-ats.iot.us-east-1.amazonaws.com"
#define TOPIC "test/topic"
#define MESSAGE "Hello from ESP32"

static void wifi_init(void) {
    esp_netif_init();
    esp_event_loop_create_default();
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);

    wifi_config_t wifi_config = {
        .sta = {
            .ssid = WIFI_SSID,
            .password = WIFI_PASS,
        },
    };

    esp_wifi_set_mode(WIFI_MODE_STA);
    esp_wifi_set_config(WIFI_IF_STA, &wifi_config);
    esp_wifi_start();
    esp_wifi_connect();
}

// Corrected MQTT Event Handler
static void mqtt_event_handler_cb(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data) {
    esp_mqtt_event_handle_t event = event_data;
    esp_mqtt_client_handle_t client = event->client;

    switch ((esp_mqtt_event_id_t)event_id) {
    case MQTT_EVENT_CONNECTED:
        esp_mqtt_client_publish(client, TOPIC, MESSAGE, 0, 1, 0);
        ESP_LOGI("MQTT", "Published message: %s", MESSAGE);
        break;
    case MQTT_EVENT_DISCONNECTED:
        ESP_LOGI("MQTT", "Disconnected from AWS IoT Core");
        break;
    default:
        break;
    }
}

// Corrected MQTT Initialization
static void mqtt_app_start(void) {
    const esp_mqtt_client_config_t mqtt_cfg = {
        .broker.address.uri = "mqtts://" AWS_IOT_ENDPOINT,
        .broker.verification.certificate = (const char *)server_cert_pem_start,
        .credentials = {
      .authentication = {
        .certificate = (const char *)client_cert_pem_start,
        .key = (const char *)client_key_pem_start,
            },
        }
    };
    esp_mqtt_client_handle_t client = esp_mqtt_client_init(&mqtt_cfg);
    esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler_cb, NULL);
    esp_mqtt_client_start(client);
}

void app_main(void) {
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
    wifi_init();
    mqtt_app_start();
}
