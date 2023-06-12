#pragma once

#include <iStates.h>

class States : public iStates
{
#ifndef UNIT_TESTS
private:
    uint32_t stableTime = 0;
#else
public:
    uint32_t stableTime = 0;
#endif

public:
    bool state_1(enum seq_steps& step) override;
    bool state_2(enum seq_steps& step) override;
    bool state_3(enum seq_steps& step) override;
    bool error(enum seq_steps& step) override;
    void state_1_step_1(enum seq_steps& step) override;
    void state_1_step_2(enum seq_steps& step) override;
    void state_1_step_3(enum seq_steps& step) override;
    void state_2_step_1(enum seq_steps& step) override;
    void state_2_step_2(enum seq_steps& step) override;
    void state_2_step_3(enum seq_steps& step) override;
    void state_3_step_1(enum seq_steps& step) override;
    void state_3_step_2(enum seq_steps& step) override;
    void state_3_step_3(enum seq_steps& step) override;
    void state_3_step_4(enum seq_steps& step) override;
    void state_3_step_5(enum seq_steps& step) override;
    void state_3_step_6(enum seq_steps& step) override;
    void error_step_1(enum seq_steps& step) override;

    virtual ~States() {};
};

bool test1();
bool test2();
bool test3();