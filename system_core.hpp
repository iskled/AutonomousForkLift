#ifndef SYSTEM_CORE_HPP
#define SYSTEM_CORE_HPP

namespace system_core {
    extern volatile uint32_t loop_time;
    extern volatile uint32_t loop_time_prev;
    extern volatile uint8_t error_flags;
    void reset_error_flags();
}

#endif // SYSTEM_CORE_HPP
