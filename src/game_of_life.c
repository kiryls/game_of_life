#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/raylib.h"
#include "world/world.h"
#include "patterns/patterns.h"
#include "patterns/catalog.h"

#define CYCLE_SPEED 8

int survival_rates[9] = {0, 0, 100, 100, 0, 0, 0, 0, 0};
int birth_rates[9] = {0, 0, 0, 100, 0, 0, 0, 0, 0};

bool CheckSurroundingsWithProbabilities(World *world, int r, int c) {
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

    return im_alive ? (arc4random() % 100 < survival_rates[count_alive]) : (arc4random() % 100 < birth_rates[count_alive]);
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

int main(int argc, char *argv[]) { 

    World world = InitWorld();
    char title[24] = "Game of Life"; 

    // FillPercentage(&world, 33);
    // DrawPattern(&world, ROWS/2, COLS/2, Glider());
    DrawPattern(&world, 1, 1, GosperGliderGun());

    InitWindow(SCREEN_W, SCREEN_H, title);

    SetTargetFPS(CYCLE_SPEED);

    bool paused = false;

    while (!WindowShouldClose()) {

        if(IsKeyPressed(KEY_SPACE)) {
            if(!paused) {
                printf("INFO: SIMULATION PAUSED\n");
                SetWindowTitle("Game of Life (PAUSED)");
            } else {
                printf("INFO: SIMULATION RESUMED\n");
                SetWindowTitle("Game of Life");
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

        if (paused) {
            Vector2 pointer = GetMousePosition();
            DrawRectangle(
                floor(pointer.x / CELL_SIZE) * CELL_SIZE, 
                floor(pointer.y / CELL_SIZE) * CELL_SIZE, 
                CELL_SIZE, 
                CELL_SIZE, 
                RED
            );

            if(IsKeyPressed(KEY_ENTER)) {
                world.flip_side = !world.flip_side;
            }

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if(world.flip_side) {
                    world.map[RoundRow(GetRowIndex(pointer.y))][RoundCol(GetColIndex(pointer.x))].back = true;
                } else {
                    world.map[RoundRow(GetRowIndex(pointer.y))][RoundCol(GetColIndex(pointer.x))].front = true;
                }
            }

            if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
                if(world.flip_side) {
                    world.map[RoundRow(GetRowIndex(pointer.y))][RoundCol(GetColIndex(pointer.x))].back = false;
                } else {
                    world.map[RoundRow(GetRowIndex(pointer.y))][RoundCol(GetColIndex(pointer.x))].front = false;
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();    

    return 0;
}
