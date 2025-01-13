#include "system_core.hpp"

namespace system_core {
    volatile uint32_t loop_time = 0;
    volatile uint32_t loop_time_prev = 0;
    volatile uint8_t error_flags = 0;

    void reset_error_flags() {
        error_flags = 0;
    }
}
