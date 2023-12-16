#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/raylib.h"
#include "world/world.h"
#include "patterns/patterns.h"
#include "patterns/catalog.h"

#define CYCLE_SPEED 8

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

int main(int argc, char *argv[]) { 

    World world = InitWorld();

    // FillPercentage(&world, 33);
    DrawPattern(&world, 0, 0, Glider());

    InitWindow(SCREEN_W, SCREEN_H, "Game of Life");

    SetTargetFPS(CYCLE_SPEED);

    bool paused = false;

    while (!WindowShouldClose()) {

        if(IsKeyPressed(KEY_SPACE)) {
            if(!paused) {
                printf("INFO: SIMULATION PAUSED\n");
            } else {
                printf("INFO: SIMULATION RESUMED\n");
            }
            paused = !paused;
        }

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

        if(!paused) {
            world.flip_side = !world.flip_side;
        }

        if(IsKeyPressed(KEY_ENTER) && paused) {
            world.flip_side = !world.flip_side;
        }

        EndDrawing();
    }

    CloseWindow();    

    return 0;
}
