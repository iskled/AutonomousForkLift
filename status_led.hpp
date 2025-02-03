#ifndef STATUS_LED_HPP
#define STATUS_LED_HPP

/**
 * @file status_led.hpp
 * @brief Interface for controlling a status LED.
 * 
 * This module provides functions to initialize, turn on, turn off,
 * and blink an LED, intended for status indication for the Autonomous Fork Lift.
 */

namespace status_led {

    /**
     * @brief Initializes the status LED.
     * 
     * Configures the necessary hardware and ensures the LED is set to a known state.
     */
    void init();

    /**
     * @brief Turns the LED on.
     */
    void on();

    /**
     * @brief Turns the LED off.
     */
    void off();

    /**
     * @brief Toggles the LED state.
     */
    void toggle();

    /**
     * @brief Blinks the LED at a default rate.
     */
    void blink();

    /**
     * @brief Blinks the LED with a custom interval.
     * @param interval_ms Time in milliseconds between on/off transitions.
     */
    void blink_custom(int interval_ms);

} // namespace status_led

#endif // STATUS_LED_HPP
