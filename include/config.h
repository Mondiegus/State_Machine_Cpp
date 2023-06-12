#pragma once
#include <stdint.h>

#define INTERVAL_2SEC   2000
#define INTERVAL_1SEC   1000
#define INTERVAL_100MSEC 100

enum seq_steps
{
    step_0,
    step_1,
    step_2,
    step_3,
    step_4,
    step_5,
    step_6,
    step_7,
    step_8,
    step_9,
    step_10,
};

enum states
{
    GOTO_STATE_1,
    GOTO_STATE_2,
    GOTO_STATE_3,
    GOTO_ERROR,
    NUM_STATES,
};

extern bool states_var[NUM_STATES];