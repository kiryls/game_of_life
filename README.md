# Conway's Game of Life

![](https://upload.wikimedia.org/wikipedia/commons/e/e5/Gospers_glider_gun.gif)

## Overview
This is just a simple implementation of GoL with the standard rules:
1. Any live cell with fewer than two live neighbours dies, as if by underpopulation
2. Any live cell with two or three live neighbours lives on to the next generation
3. Any live cell with more than three live neighbours dies, as if by overpopulation
4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction

The world map uses a toroidal space (like in a Snake game, if you go beyond the right border you reappear on the left side, beyond the top side and you reappear from the bottom)

## Installation
1. make sure you have installed [raylib](https://github.com/raysan5/raylib) installed somewhere on you machine
2. build & run:
```bash
    make
    make run
```

## List of Parameters
in `./src/game_of_life.c`:
* `CYCLE_SPEED`: simulation FPS

in `./src/world/world.h`:
* `SCREEN_W`: screen width in pixels
* `SCREEN_H`: screen height in pixels
* `CELL_SIZE`: size of a single cell in pixels
* `ROWS`: cells in a row (`SCREEN_H / CELL_SIZE`)
* `COLS`: cells in a column (`SCREEN_W / CELL_SIZE`)

