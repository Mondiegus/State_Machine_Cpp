#include <config.h>
#include <stateMgr.h>

void StateMgr::checkState()
{
    if (this->state != this->prev_state || this->steps != this->prev_steps)
    {
        this->prev_state = this->state;
        this->prev_steps = this->steps;
    }
    switch (this->state) {
    case STATE_1:
    {
        states_var[STATE_1] = false;
        if (states_var[GOTO_ERROR])
        {
            this->resetVariables();
            this->state = ERROR;
        }
        else {
            if (states.state_1(this->steps))
            {
                this->resetVariables();
                this->state = STATE_2;
            }
        }
        break;
    }

    case STATE_2:
    {
        states_var[STATE_2] = false;
        if (states_var[GOTO_ERROR])
        {
            this->resetVariables();
            this->state = ERROR;
        }
        else if (states_var[GOTO_STATE_3])
        {
            this->resetVariables();
            this->state = STATE_3;
        }
        else {
            if (states.state_2(this->steps))
            {
                this->resetVariables();
                this->state = STATE_3;
            }
        }
        break;
    }

    case STATE_3:
    {
        states_var[STATE_3] = false;
        if (states_var[GOTO_ERROR])
        {
            this->resetVariables();
            this->state = ERROR;
        }
        else if (states_var[GOTO_STATE_1])
        {
            this->resetVariables();
            this->state = STATE_1;
        }
        else if (states_var[GOTO_STATE_2])
        {
            this->resetVariables();
            this->state = STATE_2;
        }
        else {
            if (states.state_3(this->steps))
            {
                this->resetVariables();
            }
        }
        break;
    }

    case ERROR:
    {
        if (states.error(this->steps))
        {
            this->resetVariables();
        }
        break;
    }

    default:
    {
        break;
    }
    }
}

void StateMgr::resetVariables() {
    this->steps = step_0;
}