/*
 * my_accessory.c
 * Define the accessory in C language using the Macro in characteristics.h
 *
 *  Created on: 2020-05-15
 *      Author: Mixiaoxiao (Wang Bin)
 */

#include <homekit/homekit.h>
#include <homekit/characteristics.h>

void my_accessory_identify(homekit_value_t _value) {
	printf("accessory identify\n");
}

homekit_characteristic_t name = HOMEKIT_CHARACTERISTIC_(NAME, "WS2812FX");

homekit_characteristic_t cha_on = HOMEKIT_CHARACTERISTIC_(ON, false);
homekit_characteristic_t cha_bright = HOMEKIT_CHARACTERISTIC_(BRIGHTNESS, 50);
homekit_characteristic_t cha_sat = HOMEKIT_CHARACTERISTIC_(SATURATION, (float) 0);
homekit_characteristic_t cha_hue = HOMEKIT_CHARACTERISTIC_(HUE, (float) 180);

homekit_characteristic_t current_mode = HOMEKIT_CHARACTERISTIC_(CURRENT_POSITION, (int16_t) 0);
homekit_characteristic_t target_mode = HOMEKIT_CHARACTERISTIC_(TARGET_POSITION, (int16_t) 0);
homekit_characteristic_t position_mode = HOMEKIT_CHARACTERISTIC_(POSITION_STATE, (int16_t) 0);

homekit_characteristic_t current_spd = HOMEKIT_CHARACTERISTIC_(CURRENT_POSITION, (int16_t) 0);
homekit_characteristic_t target_spd = HOMEKIT_CHARACTERISTIC_(TARGET_POSITION, (int16_t) 0);
homekit_characteristic_t position_spd = HOMEKIT_CHARACTERISTIC_(POSITION_STATE, (int16_t) 0);

homekit_accessory_t *accessories[] = {
    HOMEKIT_ACCESSORY(.id=1, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            &name,
            HOMEKIT_CHARACTERISTIC(MANUFACTURER, "Arduino HomeKit"),
            HOMEKIT_CHARACTERISTIC(SERIAL_NUMBER, "1000008"),
            HOMEKIT_CHARACTERISTIC(MODEL, "ESP8266"),
            HOMEKIT_CHARACTERISTIC(FIRMWARE_REVISION, "2.0"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, my_accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(LIGHTBULB, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "WS2812FX Control"),
            &cha_on,
            &cha_bright,
            &cha_sat,
            &cha_hue,
            NULL
        }),
        HOMEKIT_SERVICE(WINDOW_COVERING, .characteristics=(homekit_characteristic_t*[]){
            HOMEKIT_CHARACTERISTIC(NAME, "FX Mode"),
            &current_mode,
            &target_mode,
            &position_mode,
            NULL
        }),
        HOMEKIT_SERVICE(WINDOW_COVERING, .characteristics=(homekit_characteristic_t*[]){
            HOMEKIT_CHARACTERISTIC(NAME, "FX Speed"),
            &current_spd,
            &target_spd,
            &position_spd,
            NULL
        }),
        NULL
    }),
    NULL
};

homekit_server_config_t accessory_config = {
    .accessories = accessories,
    .password = "163-28-704"
};
