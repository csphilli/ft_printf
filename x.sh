#!/bin/bash
clear
make
gcc -Wall -Wextra -o main main.c libftprintf.a
./main