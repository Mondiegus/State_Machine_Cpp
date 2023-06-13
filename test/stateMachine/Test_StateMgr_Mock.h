#include <gmock/gmock.h>
#include <iStates.h>

class iMock_States
{
public:
    // virtual void Mock_standard_C_func(int param) = 0;
    virtual ~iMock_States() {};
};

class Mock_States : public iStates, public iMock_States
{
public:
    MOCK_METHOD(bool, state_1, (enum seq_steps & step), (override));
    MOCK_METHOD(bool, state_2, (enum seq_steps & step));
    MOCK_METHOD(bool, state_3, (enum seq_steps & step), (override));
    MOCK_METHOD(bool, error, (enum seq_steps & step), (override));
    MOCK_METHOD(void, state_1_step_1, (enum seq_steps & step), (override));
    MOCK_METHOD(void, state_1_step_2, (enum seq_steps & step), (override));
    MOCK_METHOD(void, state_1_step_3, (enum seq_steps & step), (override));
    MOCK_METHOD(void, state_2_step_1, (enum seq_steps & step), (override));
    MOCK_METHOD(void, state_2_step_2, (enum seq_steps & step), (override));
    MOCK_METHOD(void, state_2_step_3, (enum seq_steps & step), (override));
    MOCK_METHOD(void, state_3_step_1, (enum seq_steps & step), (override));
    MOCK_METHOD(void, state_3_step_2, (enum seq_steps & step), (override));
    MOCK_METHOD(void, state_3_step_3, (enum seq_steps & step), (override));
    MOCK_METHOD(void, state_3_step_4, (enum seq_steps & step), (override));
    MOCK_METHOD(void, state_3_step_5, (enum seq_steps & step), (override));
    MOCK_METHOD(void, state_3_step_6, (enum seq_steps & step), (override));
    MOCK_METHOD(void, error_step_1, (enum seq_steps & step), (override));

    ~Mock_States(){};
};

extern Mock_States *obj_Mock_States;
