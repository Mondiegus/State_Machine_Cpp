#pragma once

#include <config.h>

class iStates
{
public:
    virtual bool state_1(enum seq_steps& step) = 0;
    virtual bool state_2(enum seq_steps& step) = 0;
    virtual bool state_3(enum seq_steps& step) = 0;
    virtual bool error(enum seq_steps& step) = 0;

    virtual void state_1_step_1(enum seq_steps& step) = 0;
    virtual void state_1_step_2(enum seq_steps& step) = 0;
    virtual void state_1_step_3(enum seq_steps& step) = 0;
    virtual void state_2_step_1(enum seq_steps& step) = 0;
    virtual void state_2_step_2(enum seq_steps& step) = 0;
    virtual void state_2_step_3(enum seq_steps& step) = 0;
    virtual void state_3_step_1(enum seq_steps& step) = 0;
    virtual void state_3_step_2(enum seq_steps& step) = 0;
    virtual void state_3_step_3(enum seq_steps& step) = 0;
    virtual void state_3_step_4(enum seq_steps& step) = 0;
    virtual void state_3_step_5(enum seq_steps& step) = 0;
    virtual void state_3_step_6(enum seq_steps& step) = 0;
    virtual void error_step_1(enum seq_steps& step) = 0;

    virtual ~iStates() {};
};