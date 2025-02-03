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
     * This function sets up the necessary hardware configurations
     * for the status LED, such as configuring the GPIO pin as output.
     */
    void init();

    /**
     * @brief Turns the status LED on.
     * 
     * Sets the corresponding GPIO pin to a high state,
     * turning the LED on.
     */
    void on();

    /**
     * @brief Turns the status LED off.
     * 
     * Sets the corresponding GPIO pin to a low state,
     * turning the LED off.
     */
    void off();

    /**
     * @brief Blinks the status LED.
     * 
     * Toggles the LED state at a predefined interval,
     * useful for indicating ongoing processes or errors.
     */
    void blink();

} // namespace status_led

#endif // STATUS_LED_HPP
