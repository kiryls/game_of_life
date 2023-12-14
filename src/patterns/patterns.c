#include "patterns.h"
#include <stdlib.h>

void FillPercentage(World *world, int percentage) {
    for (int i = 0; i < world->rows; ++i) {
        for (int j = 0; j < world->cols; ++j) {
            world->map[i][j].front = arc4random() % 100 < percentage;
        }
    }
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
