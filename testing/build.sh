#!/bin/bash

# Use this to build until I find out how the hell `make` works..

gcc -c helpers.c -I./includes/
gcc -c characters.c -I./includes/
gcc -o main main.c -I./includes/ helpers.o characters.o
