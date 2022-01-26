#!/bin/sh

echo "Building shared lib that is python module ..."
rm -rf build
meson build
ninja -C build

echo "Running python script ... "
PYTHONPATH=./build python3 ./test.py
