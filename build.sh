#!/bin/bash
sudo apt-get install cmake
rm build -r
mkdir -p build
cd build
cmake ..
make -j2
make install
