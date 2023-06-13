#!/bin/bash

echo "Tests are running"
sleep 1
cd test
if [ ! -d CMakeFiles ]; then
  if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    cmake -S . -B build_ux -Wno-dev
  elif [[ "$OSTYPE" == "win32" || "$OSTYPE" == "msys" ]]; then
    cmake -S . -B build_win -Wno-dev
  fi
fi
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
  cmake --build build_ux
  cd build_ux
elif [[ "$OSTYPE" == "win32" || "$OSTYPE" == "msys" ]]; then
  cmake --build build_win
  cd build_win
fi
ctest
# ./tests
