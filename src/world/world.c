#include "world.h"

World InitWorld() {
    World world;
    
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            Cell c = {.pos = {.x = j * CELL_SIZE, .y = i * CELL_SIZE}, .front = false, .back = false};
            world.map[i][j] = c;
        }
    }

    world.flip_side = false;

   return world;
}
