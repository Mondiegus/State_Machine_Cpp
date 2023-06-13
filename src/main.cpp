#include <states.h>
#include <stateMgr.h>
#include <config.h>

bool states_var[NUM_STATES];

#ifndef UNIT_TEST
int main()
{
    static States states = States();
    static StateMgr stateMgr = StateMgr(states);
}
#endif