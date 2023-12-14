#ifndef PATTERNS_H
#define PATTERNS_H

#include "../world/world.h"

void FillPercentage(World *world, int percentage);

void AddBlinker(World *world, int r, int c);
void AddGlider(World *world, int r, int c);

#endif // !PATTERNS_H
