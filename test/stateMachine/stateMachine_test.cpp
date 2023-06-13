#include <gtest/gtest.h>
#include <Test_StateMgr_Mock.h>

#include "stateMgr.h"
#include "states.h"

#include <iostream>
using namespace std;

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Mock;
using ::testing::Return;
using ::testing::Sequence;

class stateMachineTest : public ::testing::Test {
protected:
  Mock_States& _Mock_States = *obj_Mock_States;;
  stateMachineTest() {
    Mock::AllowLeak(obj_Mock_States);
  }

  ~stateMachineTest() {
  }
  void SetUp() {
    Sequence seq;
    // code here will execute just before the test ensues 
  }

  void TearDown() {
    Mock::VerifyAndClearExpectations(obj_Mock_States);
    Mock::VerifyAndClear(obj_Mock_States);
    reset_global_variables();
  }

  // put in any custom data members that you need 
public:
  void reset_global_variables()
  {
    for (int i = 0; i < NUM_STATES; i++)
    {
      states_var[i] = false;
    }
  }
};

// // ######################################################################################## STATE_1 ########################################################################################

/*
Desc: Check if logic of staying in STATE_1 state works correctly

Initial assumptions:
  - StateMgr state: STATE_1
  - All states_var: false
  - state_1 function returns false once
Result assumptions:
  - StateMgr state: STATE_1
*/
TEST_F(stateMachineTest, StateMgr_state_1_to_state_1_00)
{
  StateMgr stateMgr(_Mock_States);
  stateMgr.state = STATE_1;

  EXPECT_CALL(_Mock_States, state_1(_)).WillOnce(Return(false));
  stateMgr.checkState();
  EXPECT_EQ(stateMgr.state, STATE_1);
}

/*
Desc: Check if logic of switching from STATE_2 to STATE_2 state because of the state_1 works correctly

Initial assumptions:
  - StateMgr state: STATE_1
  - All states_var: false
  - state_1 function returns false once
Result assumptions:
  - StateMgr state: STATE_2
*/
TEST_F(stateMachineTest, StateMgr_state_1_to_state_2_00)
{
  StateMgr stateMgr(_Mock_States);
  stateMgr.state = STATE_1;

  EXPECT_CALL(_Mock_States, state_1(_)).WillOnce(Return(true));
  stateMgr.checkState();
  EXPECT_EQ(stateMgr.state, STATE_2);
}

/*
Desc: Check if logic of switching from STATE_1 to ERROR state because of the states_var[GOTO_ERROR] works correctly

Initial assumptions:
  - StateMgr state: STATE_1
  - All states_var: false, except GOTO_ERROR: true
Result assumptions:
  - StateMgr state: ERROR
*/
TEST_F(stateMachineTest, StateMgr_state_1_to_error_00)
{
  StateMgr stateMgr(_Mock_States);
  stateMgr.state = STATE_1;
  states_var[GOTO_ERROR] = true;

  stateMgr.checkState();
  EXPECT_EQ(stateMgr.state, ERROR);
}

// // ######################################################################################## STATE_2 ########################################################################################

/*
Desc: Check if logic of staying in STATE_2 state works correctly

Initial assumptions:
  - StateMgr state: STATE_2
  - All states_var: false
  - state_1 function returns false once
Result assumptions:
  - StateMgr state: STATE_2
*/
TEST_F(stateMachineTest, StateMgr_state_2_to_state_2_00)
{
  StateMgr stateMgr(_Mock_States);
  stateMgr.state = STATE_2;

  EXPECT_CALL(_Mock_States, state_2(_)).WillOnce(Return(false));
  stateMgr.checkState();
  EXPECT_EQ(stateMgr.state, STATE_2);
}

/*
Desc: Check if logic of switching from STATE_2 to STATE_3 state because of the state_2 works correctly

Initial assumptions:
  - StateMgr state: STATE_2
  - All states_var: false
  - state_1 function returns false once
Result assumptions:
  - StateMgr state: STATE_2
*/
TEST_F(stateMachineTest, StateMgr_state_2_to_state_3_00)
{
  StateMgr stateMgr(_Mock_States);
  stateMgr.state = STATE_2;

  EXPECT_CALL(_Mock_States, state_2(_)).WillOnce(Return(true));
  stateMgr.checkState();
  EXPECT_EQ(stateMgr.state, STATE_3);
}

/*
Desc: Check if logic of switching from STATE_2 to STATE_3 state because of the states_var[GOTO_STATE_3] works correctly

Initial assumptions:
  - StateMgr state: STATE_2
  - All states_var: false, except GOTO_STATE_3: true
  - state_1 function returns false once
Result assumptions:
  - StateMgr state: STATE_2
*/
TEST_F(stateMachineTest, StateMgr_state_2_to_state_3_10)
{
  StateMgr stateMgr(_Mock_States);
  stateMgr.state = STATE_2;
  states_var[GOTO_STATE_3] = true;

  stateMgr.checkState();
  EXPECT_EQ(stateMgr.state, STATE_3);
}

/*
Desc: Check if logic of switching from STATE_2 to ERROR state because of the states_var[GOTO_ERROR] works correctly

Initial assumptions:
  - StateMgr state: STATE_2
  - All states_var: false, except GOTO_ERROR: true
Result assumptions:
  - StateMgr state: ERROR
*/
TEST_F(stateMachineTest, StateMgr_state_2_to_error_00)
{
  StateMgr stateMgr(_Mock_States);
  stateMgr.state = STATE_2;
  states_var[GOTO_ERROR] = true;

  stateMgr.checkState();
  EXPECT_EQ(stateMgr.state, ERROR);
}
// // ######################################################################################## STATE_3 ########################################################################################

/*
Desc: Check if logic of staying in STATE_3 state works correctly

Initial assumptions:
  - StateMgr state: STATE_3
  - All states_var: false
  - state_1 function returns false once
Result assumptions:
  - StateMgr state: STATE_3
*/
TEST_F(stateMachineTest, StateMgr_state_3_to_state_3_00)
{
  StateMgr stateMgr(_Mock_States);
  stateMgr.state = STATE_3;

  EXPECT_CALL(_Mock_States, state_3(_)).WillOnce(Return(false));
  stateMgr.checkState();
  EXPECT_EQ(stateMgr.state, STATE_3);
}

/*
Desc: Check if logic of switching from STATE_3 to STATE_3 state because of the state_3 works correctly

Initial assumptions:
  - StateMgr state: STATE_3
  - All states_var: false
  - state_1 function returns true once
Result assumptions:
  - StateMgr state: ERROR
*/
TEST_F(stateMachineTest, StateMgr_state_3_to_error_00)
{
  StateMgr stateMgr(_Mock_States);
  stateMgr.state = STATE_3;

  EXPECT_CALL(_Mock_States, state_3(_)).WillOnce(Return(true));
  stateMgr.checkState();
  EXPECT_EQ(stateMgr.state, ERROR);
}

/*
Desc: Check if logic of switching from STATE_3 to STATE_2 state because of the states_var[GOTO_STATE_3] works correctly

Initial assumptions:
  - StateMgr state: STATE_3
  - All states_var: false, except GOTO_STATE_2: true
  - state_1 function returns false once
Result assumptions:
  - StateMgr state: STATE_3
*/
TEST_F(stateMachineTest, StateMgr_state_3_to_state_2_00)
{
  StateMgr stateMgr(_Mock_States);
  stateMgr.state = STATE_3;
  states_var[GOTO_STATE_2] = true;

  stateMgr.checkState();
  EXPECT_EQ(stateMgr.state, STATE_2);
}

/*
Desc: Check if logic of switching from STATE_3 to STATE_1 state because of the states_var[GOTO_STATE_3] works correctly

Initial assumptions:
  - StateMgr state: STATE_3
  - All states_var: false, except GOTO_STATE_2: true
  - state_1 function returns false once
Result assumptions:
  - StateMgr state: STATE_1
*/
TEST_F(stateMachineTest, StateMgr_state_3_to_state_1_00)
{
  StateMgr stateMgr(_Mock_States);
  stateMgr.state = STATE_3;
  states_var[GOTO_STATE_1] = true;

  stateMgr.checkState();
  EXPECT_EQ(stateMgr.state, STATE_1);
}

/*
Desc: Check if logic of switching from STATE_3 to ERROR state because of the states_var[GOTO_ERROR] works correctly

Initial assumptions:
  - StateMgr state: STATE_3
  - All states_var: false, except GOTO_ERROR: true
Result assumptions:
  - StateMgr state: ERROR
*/
TEST_F(stateMachineTest, StateMgr_state_3_to_error_10)
{
  StateMgr stateMgr(_Mock_States);
  stateMgr.state = STATE_3;
  states_var[GOTO_ERROR] = true;

  stateMgr.checkState();
  EXPECT_EQ(stateMgr.state, ERROR);
}

// ######################################################################################## ERROR ########################################################################################

/*
Desc: just for nice coverage

Initial assumptions:
  - StateMgr state: DUMMY_STATE
Result assumptions:
  - StateMgr state: DUMMY_STATE
*/
TEST_F(stateMachineTest, StateMgr_error_to_error_00)
{
  StateMgr stateMgr(_Mock_States);
  stateMgr.state = ERROR;

  EXPECT_CALL(_Mock_States, error(_)).WillOnce(Return(true));
  stateMgr.checkState();
  EXPECT_EQ(stateMgr.state, ERROR);
}

/*
Desc: just for nice coverage

Initial assumptions:
  - StateMgr state: DUMMY_STATE
Result assumptions:
  - StateMgr state: DUMMY_STATE
*/
TEST_F(stateMachineTest, StateMgr_error_to_error_10)
{
  StateMgr stateMgr(_Mock_States);
  stateMgr.state = ERROR;

  EXPECT_CALL(_Mock_States, error(_)).WillOnce(Return(false));
  stateMgr.checkState();
  EXPECT_EQ(stateMgr.state, ERROR);
}

/*
Desc: just for nice coverage

Initial assumptions:
  - StateMgr state: DUMMY_STATE
Result assumptions:
  - StateMgr state: DUMMY_STATE
*/
TEST_F(stateMachineTest, StateMgr_default)
{
  StateMgr stateMgr(_Mock_States);
  stateMgr.state = DUMMY_STATE;

  stateMgr.checkState();
  EXPECT_EQ(stateMgr.state, DUMMY_STATE);
}

TEST_F(stateMachineTest, Cleanup_data)
{
  delete obj_Mock_States;
}