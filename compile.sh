#!/usr/bin/env bash

clang++ -Wall -Wno-missing-braces -std=c++20 -o main main.cpp file_ops.cpp -lncurses
