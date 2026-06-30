#!/bin/env bash

mkdir -p build && cd build || exit

rm -f CMakeCache.txt

cmake ..
cmake --build .

# shellcheck disable=SC2162
read -p "Want to start the program now? (y/n): " answer
    if [[ "$answer" =~ ^[Yy]$ ]]; then
        ./"my-calculator"
    fi
