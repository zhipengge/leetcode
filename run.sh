#!/bin/bash
if [ -d build ];then
    echo "rm build"
fi
mkdir build/
cd build/
cmake ..
make -j4
./main
