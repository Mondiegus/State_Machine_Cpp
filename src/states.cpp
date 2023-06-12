#include <states.h>
#include <chrono>

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::system_clock;

static int millis()
{
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

bool test1() { return false; }
bool test2() { return false; }
bool test3() { return false; }

bool States::state_1(enum seq_steps& step)
{
    bool ret = false;
    void (States:: * sequence[])(enum seq_steps&) =
    {
        &States::state_1_step_1,
        &States::state_1_step_2,
        &States::state_1_step_3,
    };
    if (step == (sizeof(sequence) / sizeof(sequence[0])))
    {
        ret = true;
    }
    else
    {
        (this->*(sequence[step]))(step);
    }
    return ret;
}

bool States::state_2(enum seq_steps& step)
{
    bool ret = false;
    void (States:: * sequence[])(enum seq_steps&) =
    {
        &States::state_2_step_1,
        &States::state_2_step_2,
        &States::state_2_step_3,
    };
    if (step == (sizeof(sequence) / sizeof(sequence[0])))
    {
        ret = true;
    }
    else
    {
        (this->*(sequence[step]))(step);
    }
    return ret;
}

bool States::state_3(enum seq_steps& step)
{
    bool ret = false;
    void (States:: * sequence[])(enum seq_steps&) =
    {
        &States::state_3_step_1,
        &States::state_3_step_2,
        &States::state_3_step_3,
        &States::state_3_step_4,
        &States::state_3_step_5,
        &States::state_3_step_6,
    };
    if (step == (sizeof(sequence) / sizeof(sequence[0])))
    {
        ret = true;
    }
    else
    {
        (this->*(sequence[step]))(step);
    }
    return ret;
}

void States::state_1_step_1(enum seq_steps& step)
{
    if (stableTime == 0)
    {
        stableTime = millis();
    }
    if ((millis() - stableTime) > INTERVAL_2SEC)
    {
        step = step_1;
        stableTime = 0;
    }
}

void States::state_1_step_2(enum seq_steps& step)
{
    if (test1())
    {
        step = step_2;
    }
    else
    {
        step = step_3;
    }
}

void States::state_1_step_3(enum seq_steps& step)
{
    step = step_3;
}

void States::state_2_step_1(enum seq_steps& step)
{
    if (stableTime == 0)
    {
        stableTime = millis();
    }
    if ((millis() - stableTime) > INTERVAL_1SEC)
    {
        step = step_1;
        stableTime = 0;
    }
}

void States::state_2_step_2(enum seq_steps& step)
{
    if (test2())
    {
        step = step_2;
    }
    else
    {
        states_var[GOTO_STATE_3] = true;
    }
}

void States::state_2_step_3(enum seq_steps& step)
{
    step = step_3;
}

void States::state_3_step_1(enum seq_steps& step)
{
    if (stableTime == 0)
    {
        stableTime = millis();
    }
    if ((millis() - stableTime) > INTERVAL_100MSEC)
    {
        step = step_1;
        stableTime = 0;
    }
}

void States::state_3_step_2(enum seq_steps& step)
{
    if (test1())
    {
        step = step_2;
    }
    else
    {
        states_var[GOTO_ERROR] = true;
    }
}

void States::state_3_step_3(enum seq_steps& step)
{
    if (test2())
    {
        step = step_3;
    }
    else
    {
        step = step_6;
    }
}

void States::state_3_step_4(enum seq_steps& step)
{
    if (test3())
    {
        step = step_4;
    }
    else
    {
        states_var[GOTO_STATE_2] = true;
    }
}

void States::state_3_step_5(enum seq_steps& step)
{
    if (stableTime == 0)
    {
        stableTime = millis();
    }
    if ((millis() - stableTime) > INTERVAL_100MSEC)
    {
        step = step_5;
        stableTime = 0;
    }
}

void States::state_3_step_6(enum seq_steps& step)
{
    if (test1())
    {
        step = step_4;
    }
    else
    {
        states_var[GOTO_STATE_1] = true;
    }
}

bool States::error(enum seq_steps& step)
{
    bool ret = false;
    void (States:: * sequence[])(enum seq_steps&) =
    {
        &States::error_step_1,
    };
    if (step == (sizeof(sequence) / sizeof(sequence[0])))
    {
        ret = true;
    }
    else
    {
        (this->*(sequence[step]))(step);
    }
    return ret;
}

void States::error_step_1(enum seq_steps& step)
{
    // Probably shutdown everything
}
