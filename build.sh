#!/bin/bash

# Use this to build until I find out how the hell `make` works..

gcc -c helpers.c -I./includes/
gcc -c player.c -I./includes/
gcc -c enemy.c -I./includes/
gcc -c battle.c -I./includes/
gcc -c intro.c -I./includes/
gcc -c caverns.c -I./includes/
gcc -c caverns-west.c -I./includes/
gcc -o main main.c -I./includes/ helpers.o player.o enemy.o battle.o intro.o caverns.o

# clean up object files
rm *.o
