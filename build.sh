#!/bin/bash

eval cc ./src/game_of_life.c $(pkg-config --libs --cflags raylib) -o ./build/bin/game_of_life
