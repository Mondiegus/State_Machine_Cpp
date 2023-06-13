cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS --coverage)

include(${CMAKE_CURRENT_SOURCE_DIR}/CMakeConfig.cmake)
project(UT VERSION 0.0.1 LANGUAGES C CXX)
set_variables()
enable_testing()

add_definitions( -DUNIT_TEST=1 )
add_definitions( -D__IMXRT1062__ )

add_library(MAIN_CPP STATIC ${MAIN_CPP})
target_include_directories(MAIN_CPP PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}/../include"
)

add_executable(
  tests
  main_test.cpp
  stateMachine/stateMachine_test.cpp
  stateMachine/Test_StateMgr_Mock.cpp
)

target_include_directories(tests PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}/stateMachine/"
)

target_link_libraries(
  tests
  MAIN_CPP
  GTest::gmock 
  GTest::gtest
  GTest::gmock_main
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
