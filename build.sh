#!/bin/bash

# Use this to build until I find out how the hell `make` works..

gcc -c helpers.c -I./includes/
gcc -c player.c -I./includes/
gcc -c enemy.c -I./includes/
gcc -o main main.c -I./includes/ helpers.o player.o enemy.o
