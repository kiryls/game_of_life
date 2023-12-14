#include "patterns.h"


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
