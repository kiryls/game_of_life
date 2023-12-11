#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/raylib.h"

#define SCREEN_W 400
#define SCREEN_H 400 
#define CELL_SIZE 20 
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
} World;

int RoundRow(int index) {
    return index >= 0 ? index % ROWS : ROWS + index;
}

int RoundCol(int index) {
    return index >= 0 ? index % COLS : COLS + index;
}

bool CheckSurroundings(World *world, int r, int c) {
    Cell cell = world->map[r][c];
    int count_alive = 0;
    bool im_alive = world->flip_side ? cell.back : cell.front;
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if(i == 0 && j == 0) {
                continue;
            }

            if (world->flip_side) {
                if(world->map[RoundRow(r + i)][RoundCol(c + j)].back == true) {
                    count_alive++;
                }
            } else {
                if(world->map[RoundRow(r + i)][RoundCol(c + j)].front == true) {
                    count_alive++;
                }
            }
        }
    }

    return count_alive == 3 || (count_alive == 2 && im_alive);
}

void AddBlinker(World *world, int r, int c) {
    //      Blinker
    //         
    //        X  
    //        X  
    //        X  
    //
    world->map[r+0][c+0].front = true;
    world->map[r+1][c+0].front = true;
    world->map[r+2][c+0].front = true;
}

void AddGlider(World *world, int r, int c) {
    //      Glider
    //
    //      X X X
    //      X    
    //        X  
    //
    world->map[r+0][c+0].front = true;
    world->map[r+0][c+1].front = true;
    world->map[r+0][c+2].front = true;
    world->map[r+1][c+0].front = true;
    world->map[r+2][c+1].front = true;
}

World InitWorld() {
    World world;
    
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            Cell c = {.pos = {.x = j * CELL_SIZE, .y = i * CELL_SIZE}, .front = false, .back = false};
            world.map[i][j] = c;
        }
    }

    world.flip_side = false;

    AddBlinker(&world, 1, 2);
    AddGlider(&world, ROWS-5, COLS-4);

    return world;
}

int main(int argc, char *argv[]) { 

    World world = InitWorld();

    InitWindow(SCREEN_W, SCREEN_H, "Game of Life");

    SetTargetFPS(4); // MEMO create a simulation speed param

    while (!WindowShouldClose()) {
        BeginDrawing(); 

        ClearBackground(RAYWHITE);
    
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                Cell c = world.map[i][j];
                if(world.flip_side) {
                    DrawRectangleV(c.pos, (Vector2){.x = CELL_SIZE, .y = CELL_SIZE}, c.back ? DARKGRAY : RAYWHITE);
                    world.map[i][j].front = CheckSurroundings(&world, i, j);
                } else {
                    DrawRectangleV(c.pos, (Vector2){.x = CELL_SIZE, .y = CELL_SIZE}, c.front ? DARKGRAY : RAYWHITE);
                    world.map[i][j].back = CheckSurroundings(&world, i, j);
                }
            }
        }

        world.flip_side = !world.flip_side;

        EndDrawing();
    }

    CloseWindow();    

    return 0;
}
