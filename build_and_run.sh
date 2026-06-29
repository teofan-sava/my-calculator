#!/bin/bash

# shellcheck disable=SC2164
mkdir -p build && cd build

cmake ..
cmake --build .

# shellcheck disable=SC2162
read -p "Want to start the program now? (y/n): " answer
    if [[ "$answer" =~ ^[Yy]$ ]]; then
        ./"my-calculator"
    fi