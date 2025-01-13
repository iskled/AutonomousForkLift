#include "status_led.hpp"
#include "stm32f4xx_hal.h"

namespace status_led {
    constexpr uint16_t pin = GPIO_PIN_13;
    GPIO_TypeDef* port = GPIOC;

    void init() {
        // Initialize LED GPIO
    }

    void on() {
        HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
    }

    void off() {
        HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
    }

    void blink() {
        on();
        HAL_Delay(100);
        off();
        HAL_Delay(100);
    }
}
