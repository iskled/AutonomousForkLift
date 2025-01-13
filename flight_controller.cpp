#include "flight_controller.hpp"
#include "pid_controller.hpp"
#include "imu_sensor.hpp"
#include "motors.hpp"

namespace flight_controller {
    void init() {
        pid_controller::initialize();
        imu_sensor::calibrate();
        motors::setup();
    }

    void update() {
        // Control algorithm logic
    }
}
