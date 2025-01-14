#ifndef RC_RECEIVER_HPP
#define RC_RECEIVER_HPP

namespace rc_receiver {
    void init();
    void read_channels();
    extern volatile int16_t channel_1;
    extern volatile int16_t channel_2;
    extern volatile int16_t channel_3;
    extern volatile int16_t channel_4;
    extern volatile int16_t channel_7;
}

#endif // RC_RECEIVER_HPP
