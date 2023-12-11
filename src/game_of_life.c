#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/raylib.h"

#define SCREEN_W 400
#define SCREEN_H 400 
#define CELL_SIZE 20

#define INDEX(R,C) ((SCREEN_W/CELL_SIZE) * (R) + (C))

typedef struct {
    Vector2 pos;
    bool actual;
    bool old;
} Cell;

int cells = (SCREEN_W / CELL_SIZE) * (SCREEN_H / CELL_SIZE);
int rows = SCREEN_H / CELL_SIZE;
int cols = SCREEN_W / CELL_SIZE;

int RoundRow(int index) {
    return index >= 0 ? index % rows : rows + index;
}

int RoundCol(int index) {
    return index >= 0 ? index % cols : cols + index;
}

bool CheckSurroundings(Cell *world, int r, int c) {
    Cell cell = world[INDEX(r, c)];
    int count_alive = 0;

    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if(i == 0 && j == 0) {
                continue;
            }

            if(world[INDEX(RoundRow(r + i),RoundCol(c + j))].old == true) {
                count_alive++;
            }
        }
    }

    return count_alive == 3 || (count_alive == 2 && cell.old);
}

void AddBlinker(Cell *world, int r, int c) {
    //      Blinker
    //         
    //        X  
    //        X  
    //        X  
    //
    world[INDEX(RoundRow(r), RoundCol(c))].actual = true;
    world[INDEX(RoundRow(r+1), RoundCol(c))].actual = true;
    world[INDEX(RoundRow(r+2), RoundCol(c))].actual = true;
}

void AddGlider(Cell *world, int r, int c) {
    //      Glider
    //
    //      X X X
    //      X    
    //        X  
    //
    world[INDEX(RoundRow(r), RoundCol(c))].actual = true;
    world[INDEX(RoundRow(r), RoundCol(c+1))].actual = true;
    world[INDEX(RoundRow(r), RoundCol(c+2))].actual = true;
    world[INDEX(RoundRow(r+1), RoundCol(c))].actual = true;
    world[INDEX(RoundRow(r+2), RoundCol(c+1))].actual = true;
}

Cell *InitWorld() {
    Cell *world = (Cell*) malloc(cells * sizeof(Cell));
    if (world == NULL) {
        printf("ERROR: couldn't allocate world\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Cell c = {.pos = {.x = j * CELL_SIZE, .y = i * CELL_SIZE}, .actual = false, .old = false};
            world[INDEX(i, j)] = c;
        }
    }
    
    AddGlider(world, rows/2, cols/2);

    return world;
}

int main(int argc, char *argv[]) { 

    Cell *world = InitWorld();

    InitWindow(SCREEN_W, SCREEN_H, "Game of Life");

    SetTargetFPS(4);

    while (!WindowShouldClose()) {
        BeginDrawing(); 

        ClearBackground(RAYWHITE);
    
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                Cell c = world[INDEX(i, j)];
                world[INDEX(i, j)].old = c.actual;
                DrawRectangleV(c.pos, (Vector2){.x = CELL_SIZE, .y = CELL_SIZE}, c.actual ? DARKGRAY : RAYWHITE);
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                world[INDEX(i, j)].actual = CheckSurroundings(world, i, j);
            }
        }

        EndDrawing();
    }

    CloseWindow();    

    return 0;
}
