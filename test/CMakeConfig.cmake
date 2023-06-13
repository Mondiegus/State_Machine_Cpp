include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
message("Gtest downloaded.")

function(set_variables)
    set(MAIN_CPP
        ../src/main.cpp
        ../src/stateMgr.cpp
        ../src/states.cpp
        CACHE INTERNAL "MAIN_CPP"
        )
endfunction(set_variables)
