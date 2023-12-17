#include "catalog.h"
#include <stdio.h>


////////////////////////////
///      STILL LIFE      ///
////////////////////////////

Pattern Block() {
    Pattern block = {
        .h = 2,
        .w = 2,
        .figure =
        "##"
        "##"
    };
    return block;
}

Pattern Beehive() {
    Pattern beehive = {
        .h = 3,
        .w = 4,
        .figure =
        "_##_"
        "#__#"
        "_##_"
    };
    return beehive;
}

Pattern Loaf() {
    Pattern loaf = {
        .h = 4,
        .w = 4,
        .figure =
        "_##_"
        "#__#"
        "_#_#"
        "__#_"
    };
    return loaf;
}

Pattern Boat() {
    Pattern boat = {
        .h = 3,
        .w = 3,
        .figure =
        "##_"
        "#_#"
        "_#_"
    };
    return boat;
}

Pattern Tub() {
    Pattern tub = {
        .h = 3,
        .w = 3,
        .figure =
        "_#_"
        "#_#"
        "_#_"
    };
    return tub;
}


////////////////////////////
///      OSCILLATORS     ///
////////////////////////////

Pattern Blinker() {
    Pattern blinker = {
        .h = 3,
        .w = 3,
        .figure =
        "_#_"
        "_#_"
        "_#_"
    };
    return blinker;
} 

Pattern Toad() {
    Pattern toad = {
        .h = 4,
        .w = 4,
        .figure = 
        "__#_"
        "#__#"
        "#__#"
        "_#__"
    };
    return toad;
}

Pattern Beacon() {
    Pattern beacon = {
        .h = 4,
        .w = 4,
        .figure =
        "##__"
        "##__"
        "__##"
        "__##"
    };
    return beacon;
} 

Pattern Pulsar() {
    Pattern pulsar = {
        .h = 13,
        .w = 15,
        .figure =
        "___###___###___"
        "_______________"
        "_#____#_#____#_"
        "_#____#_#____#_"
        "_#____#_#____#_"
        "___###___###___"
        "_______________"
        "___###___###___"
        "_#____#_#____#_"
        "_#____#_#____#_"
        "_#____#_#____#_"
        "_______________"
        "___###___###___"
    };
    return pulsar;
}

Pattern Pentadecathlon() {
    Pattern pentadecathlon = {
        .h = 16,
        .w = 9,
        .figure =
        "____#____"
        "____#____"
        "___###___"
        "_________"
        "_________"
        "___###___"
        "____#____"
        "____#____"
        "____#____"
        "____#____"
        "___###___"
        "_________"
        "_________"
        "___###___"
        "____#____"
        "____#____"
    };
    return pentadecathlon;
}


////////////////////////////
///      SPACESHIPS      ///
////////////////////////////

Pattern Glider() {
    Pattern glider = {
        .h = 3,
        .w = 3,
        .figure =
        "_#_"
        "__#"
        "###"
    };
    return glider;
}

Pattern LightweightSpaceship() {
    Pattern lwss = {
        .h = 4,
        .w = 5,
        .figure =
        "_####"
        "#___#"
        "____#"
        "#__#_"
    };
    return lwss;
}

Pattern MiddleweightSpaceship() {
    Pattern mwss = {
        .h = 5,
        .w = 6,
        .figure =
        "_#####"
        "#____#"
        "_____#"
        "#___#_"
        "__#___"
    };
    return mwss;
} 

Pattern HeavyweightSpaceship() {
    Pattern hwss = {
        .h = 5,
        .w = 7,
        .figure =
        "_######"
        "#_____#"
        "______#"
        "#____#_"
        "__##___"
    };
    return hwss;
}

Pattern GosperGliderGun() {
    Pattern ggg = {
        .h = 9,
        .w = 36,
        .figure =
        "________________________#___________"
        "______________________#_#___________"
        "____________##______##____________##"
        "___________#___#____##____________##"
        "##________#_____#___##______________"
        "##________#___#_##____#_#___________"
        "__________#_____#_______#___________"
        "___________#___#____________________"
        "____________##______________________"
    };

    return ggg;
}

void DrawPattern(World *world, int row, int col, Pattern pattern) {
    for(int i = 0; i < pattern.h; ++i) {
        for (int j = 0; j < pattern.w; ++j) {
            world->map[RoundRow(row + i)][RoundCol(col + j)].front = pattern.figure[i * pattern.w + j] == '#';
        }
    }
}




