#!/bin/bash

g++ main.cpp -o tp3
for arg in $*; do
    ./tp3 < $arg $arg
done