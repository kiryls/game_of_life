#ifndef CATALOG_H
#define CATALOG_H

#include "../world/world.h"

typedef struct {
    const char *figure;
    int h, w;
} Pattern;

////////////////////////////
///      STILL LIFE      ///
////////////////////////////

Pattern Block();
Pattern Beehive();
Pattern Loaf();
Pattern Boat();
Pattern Tub();

////////////////////////////
///      OSCILLATORS     ///
////////////////////////////

Pattern Blinker();
Pattern Toad();
Pattern Beacon();
Pattern Pulsar();
Pattern Pentadecathlon();

////////////////////////////
///      SPACESHIPS      ///
////////////////////////////

Pattern Glider();
Pattern LightweightSpaceship();
Pattern MiddleweightSpaceship();
Pattern HeavyweightSpaceship();


Pattern GosperGliderGun();


void DrawPattern(World *world, int row, int col, Pattern pattern);

#endif // !CATALOG_H
