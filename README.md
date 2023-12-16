# Conway's Game of Life

![](https://upload.wikimedia.org/wikipedia/commons/e/e5/Gospers_glider_gun.gif)

## Overview
This is just a simple implementation of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) with the standard rules:
1. Any live cell with fewer than two live neighbours dies, as if by underpopulation
2. Any live cell with two or three live neighbours lives on to the next generation
3. Any live cell with more than three live neighbours dies, as if by overpopulation
4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction

The world map uses a toroidal space (like in a Snake game, if you go beyond the right border you reappear on the left side, beyond the top side and you reappear from the bottom)

## Installation
1. make sure you have [raylib](https://github.com/raysan5/raylib) installed somewhere on you machine
2. clone this repo into `<your-project-folder>`:
```bash
    $ git clone https://github.com/kiryls/game_of_life.git <your-project-folder>
```
3. cd into `<your-project-folder>`:
```bash
    $ cd <your-project-folder>
```
4. from there, build & run:
```bash
    $ make
    $ make run
```
## Roadmap
- [x] bare bones implementation w/ randomly filled cells
- [x] split project into modules
- [x] implementing a catalog of patterns
- [x] spacebar pauses/resumes the simulation
- [x] Enter key moves to the next state during a pause
- [ ] variant: probabilistic rules

## List of Parameters
in `./src/game_of_life.c`:
* `CYCLE_SPEED`: simulation FPS

in `./src/world/world.h`:
* `SCREEN_W`: screen width in pixels
* `SCREEN_H`: screen height in pixels
* `CELL_SIZE`: size of a single cell in pixels
* `ROWS`: cells in a row (`SCREEN_H / CELL_SIZE`)
* `COLS`: cells in a column (`SCREEN_W / CELL_SIZE`)

