#ifndef WORLD_H
#define WORLD_H

#include "../include/raylib.h"

#define SCREEN_W 400
#define SCREEN_H 400 
#define CELL_SIZE 10 
#define ROWS (SCREEN_H/CELL_SIZE)
#define COLS (SCREEN_W/CELL_SIZE)

typedef struct {
    Vector2 pos;
    bool front;
    bool back;
} Cell;

typedef struct {
    Cell map[ROWS][COLS];
    bool flip_side;
    int rows, cols;
} World;


int GetRowIndex(float y);
int GetColIndex(float x);
int RoundRow(int index);
int RoundCol(int index);
World InitWorld();

#endif // !WORLD_H
