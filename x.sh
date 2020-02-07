#!/bin/bash
clear
make
gcc -Wall -Werror -Wextra -o main main.c libftprintf.a
./main