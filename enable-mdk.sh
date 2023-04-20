#!/bin/bash

echo "Retrieving submodules"
git submodule update --init --recursive

echo "Applying clock speed patch to mdk - 80 mhz"
cd mdk
git apply --ignore-space-change --ignore-whitespace ../patch.diff
cd ..


echo "Setting up environment variables for mdk compilation"
export MDK=$(pwd)/mdk
export ARCH=esp32c3
export PORT=/dev/ttyUSB0
