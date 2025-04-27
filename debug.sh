#!/usr/bin/env bash

cmake --preset debug
cd build
make
./proj "$@"
