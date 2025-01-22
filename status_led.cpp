#include "status_led.hpp"
#include "stm32f4xx_hal.h"

namespace status_led {
    // Pin and port definitions for the status LED
    constexpr uint16_t pin = GPIO_PIN_13;  // Pin number for the LED
    GPIO_TypeDef* port = GPIOC;            // Port where the LED is connected

    // Initialize the GPIO pin for the LED
    void init() {
        __HAL_RCC_GPIOC_CLK_ENABLE();  // Enable clock for GPIOC

        GPIO_InitTypeDef gpio_init;
        gpio_init.Pin = pin;                      // Set the pin number
        gpio_init.Mode = GPIO_MODE_OUTPUT_PP;     // Set as push-pull output
        gpio_init.Pull = GPIO_NOPULL;             // No pull-up or pull-down
        gpio_init.Speed = GPIO_SPEED_FREQ_LOW;    // Set to low frequency

        HAL_GPIO_Init(port, &gpio_init); // Initialize the GPIO pin
    }

    // Turn the LED on
    void on() {
        HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET); // Active-low logic
    }

    // Turn the LED off
    void off() {
        HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET); // Active-low logic
    }

    // Blink the LED once with fixed timing
    void blink() {
        on();
        HAL_Delay(100); // 100 milliseconds ON
        off();
        HAL_Delay(100); // 100 milliseconds OFF
    }

    // Blink the LED a specified number of times
    void blink_times(int times, int delay_ms = 100) {
        for (int i = 0; i < times; ++i) {
            on();
            HAL_Delay(delay_ms); // Turn on for `delay_ms`
            off();
            HAL_Delay(delay_ms); // Turn off for `delay_ms`
        }
    }

    // Blink the LED in a custom pattern
    void blink_pattern(const int pattern[], int size, int unit_time_ms = 100) {
        for (int i = 0; i < size; ++i) {
            if (pattern[i] > 0) {
                on();
            } else {
                off();
            }
            HAL_Delay(abs(pattern[i]) * unit_time_ms); // Use pattern for timing
        }
        off(); // Ensure the LED is off at the end
    }

    // Fade the LED in and out using PWM
    void fade(int steps = 100, int delay_ms = 10) {
        TIM_HandleTypeDef htim;
        TIM_OC_InitTypeDef sConfigOC = {0};

        // Configure the timer
        __HAL_RCC_TIM3_CLK_ENABLE();
        htim.Instance = TIM3;
        htim.Init.Prescaler = 83;               // Assuming 84MHz clock -> 1MHz timer
        htim.Init.CounterMode = TIM_COUNTERMODE_UP;
        htim.Init.Period = 999;                 // Period for 1kHz PWM
        htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
        HAL_TIM_PWM_Init(&htim);

        // Configure PWM for the channel
        sConfigOC.OCMode = TIM_OCMODE_PWM1;
        sConfigOC.Pulse = 0;                    // Start with 0% duty cycle
        sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
        sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
        HAL_TIM_PWM_ConfigChannel(&htim, &sConfigOC, TIM_CHANNEL_1);

        // Start PWM
        HAL_TIM_PWM_Start(&htim, TIM_CHANNEL_1);

        // Fade in
        for (int i = 0; i <= steps; ++i) {
            __HAL_TIM_SET_COMPARE(&htim, TIM_CHANNEL_1, i * (htim.Init.Period / steps));
            HAL_Delay(delay_ms);
        }

        // Fade out
        for (int i = steps; i >= 0; --i) {
            __HAL_TIM_SET_COMPARE(&htim, TIM_CHANNEL_1, i * (htim.Init.Period / steps));
            HAL_Delay(delay_ms);
        }

        HAL_TIM_PWM_Stop(&htim, TIM_CHANNEL_1); // Stop PWM after fading
        __HAL_RCC_TIM3_CLK_DISABLE();           // Disable timer clock
    }

    // Toggle the LED state
    void toggle() {
        if (HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_RESET) {
            off();
        } else {
            on();
        }
    }

    // Check if the LED is currently on
    bool is_on() {
        return (HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_RESET);
    }

    // Signal an error by blinking continuously
    void error_signal() {
        while (true) {
            blink();
        }
    }

    // Demo function to showcase all functionalities
    void demo() {
        init();

        // Blink three times
        blink_times(3, 200);

        // Blink a custom pattern: short, long, short
        int pattern[] = {1, -1, 3, -3, 1, -1};
        blink_pattern(pattern, sizeof(pattern) / sizeof(pattern[0]), 100);

        // Fade in and out
        fade(50, 20);
    }

    // Test all LED features
    void test_all_features() {
        init();

        // Basic on and off
        on();
        HAL_Delay(500);
        off();
        HAL_Delay(500);

        // Toggle functionality
        toggle();
        HAL_Delay(500);
        toggle();
        HAL_Delay(500);

        // Blink a few times
        blink_times(5, 150);

        // Run the demo sequence
        demo();

        // Error signal (infinite loop, comment for testing purposes)
        // error_signal();
    }
} // namespace status_led
