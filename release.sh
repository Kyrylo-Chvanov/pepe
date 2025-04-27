#!/usr/bin/env bash

cmake --preset release
cd build_release
make
./proj "$@"