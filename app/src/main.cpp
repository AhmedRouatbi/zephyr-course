#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
 

 
#define LED_NODE  DT_ALIAS(app_led)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);

int main(void)
{
    int ret=0;
    ret +=  device_is_ready(led.port);
    if(ret!=0){LOG_INF("Error Init the device");}

    ret +=gpio_pin_configure_dt(&led,GPIO_OUTPUT);
    if(ret!=0){LOG_INF("Error Configuring  the device");}


    while (1) {
 
        gpio_pin_toggle_dt(&led);
        k_msleep(CONFIG_APP_HEART_BEAT_PERIOD);
    }
    return 0;
}
