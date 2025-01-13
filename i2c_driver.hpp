#ifndef I2C_DRIVER_HPP
#define I2C_DRIVER_HPP

#include "stm32f4xx_hal.h"

namespace i2c_driver {
    void init(I2C_HandleTypeDef* hi2c);
    void write(uint16_t address, uint8_t reg, uint8_t value);
    uint8_t read(uint16_t address, uint8_t reg);
    void check_device_ready(uint16_t address);
}

#endif // I2C_DRIVER_HPP
