#pragma once

#include <states.h>

enum states_names {
    STATE_1,
    STATE_2,
    STATE_3,
    ERROR,
};

class StateMgr
{
private:
    void resetVariables();
    enum states_names prev_state = STATE_1;
    enum seq_steps prev_steps = step_0;
#ifndef UNIT_TEST
    iStates& states;
    enum states_names state;
    enum seq_steps steps = step_0;
#else
public:
    iStates& states;
    enum seq_steps steps = step_0;
    enum states_names state;
#endif

public:
    StateMgr(iStates& _states) : states(_states), state(STATE_1) {};
    void checkState();
};
