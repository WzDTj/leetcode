#!/bin/bash

clang++ $(cat compile_flags.txt) ./main.cpp && ./a.out
