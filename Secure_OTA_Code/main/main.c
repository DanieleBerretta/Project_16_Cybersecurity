#include <stdio.h>
#include <string.h>
#include "esp_wifi.h" //for wifi connection
#include "esp_event.h"
#include "nvs_flash.h" //for wifi configuration
#include "protocol_examples_common.h" 
#include "esp_http_client.h" //using client in order to get the last update
#include "esp_https_ota.h" // for using https protocol
#include "freertos/FreeRTOS.h" //as we are required to use freertos
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_log.h"
#include "driver/gpio.h"//as we are using an interrupt to a trigger for the update

# define TAG "OTA"

xSemaphoreHandle ota_semaphore; //set a semaphore 

const int firmware_version = 2; //define the software version 

extern const uint8_t server_cert_pem_start[] asm("_binary_google_cer_start");

void when_push_button_is_pressed(void *params)
{
  xSemaphoreGiveFromISR(ota_semaphore, pdFALSE); //in order to get the semaphore from ISR 
  //we can't use xsemaphoreGive as we take the semaphore from from the isr memory 
}

esp_err_t  client_event_handler(esp_http_client_event_t *evt) // part of configurations of using http protocol
{
  return ESP_OK;
}


//here is the task that will run when the push button is pressed
void run_ota(void *params)
{
    while (true)
  {
    xSemaphoreTake(ota_semaphore, portMAX_DELAY); //take the semaphore when pushbutton is pressed
    ESP_LOGI(TAG, "Performing OTA update procees");

    //now we have to connect to the internet
    ESP_ERROR_CHECK(nvs_flash_init());
    tcpip_adapter_init();
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    ESP_ERROR_CHECK(example_connect());
    //done
   
   // as we use http protocol:
    esp_http_client_config_t clientConfig = {
      .url = "https://drive.google.com/u/0/uc?id=1fwUZZtiXXuH5mpLOeTPlF7t6bIB09o2g&export=download", // here where we have the binary file
      .event_handler = client_event_handler,
      .cert_pem = (char *)server_cert_pem_start

    };
  
  // esp_https_ota returns ok and the binary file is putted in the ota partition that we setted
    if(esp_https_ota(&clientConfig) == ESP_OK)
    {
      ESP_LOGI(TAG,"firmware update is successful now we are in version %d.",firmware_version);
      vTaskDelay(pdMS_TO_TICKS(5000)); //some delay before restarting 
      esp_restart(); //restaring our microcontroller and start from the new memory partition
    }
        ESP_LOGE(TAG,"firmware update is not successfull please try again");

  }

}



void app_main(void)

{

    ESP_LOGI("SOFTWARE VERSION", "Hello we're running version %d",firmware_version);



//in next few lines :GPIO configuration for the interrupt,we use the push button in the microcontroller 
//which is connected to pin number zero
    gpio_config_t gpioConfig = {
      .pin_bit_mask = 1ULL << GPIO_NUM_0,
      .mode = GPIO_MODE_DEF_INPUT,
      .pull_up_en = GPIO_PULLUP_ENABLE,
      .pull_down_en = GPIO_PULLUP_DISABLE,
      .intr_type = GPIO_INTR_NEGEDGE};
  gpio_config(&gpioConfig);
  gpio_install_isr_service(0);
  gpio_isr_handler_add(GPIO_NUM_0, when_push_button_is_pressed, NULL);
//gpio configuration is done 

//here is the task that will run when the push button is pressed
  ota_semaphore = xSemaphoreCreateBinary();
  xTaskCreate(run_ota, "run_ota", 1024 * 8, NULL, 2, NULL);

}


