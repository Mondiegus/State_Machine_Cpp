#!/bin/bash

echo "Compiling State Machine demo app"
sleep 1
if [ ! -d build ]; then
  mkdir build
fi
cd build

if [ ! -d CMakeFiles ]; then
  if [[ "$OSTYPE" == "linux-gnu" ]]; then
    cmake ..
  else
    cmake .. -G "Visual Studio 17 2022"
  fi
fi
if [[ "$OSTYPE" == "linux-gnu" ]]; then
  make
else
  cmake --build .
fi
