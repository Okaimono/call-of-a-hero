#pragma once
#include "BlockID.h"

namespace BlockData {
    struct UVCoord {
        float uMin, uMax, vMin, vMax;
    };

    constexpr UVCoord tileToUV(int tileX, int tileY) {
        float s = 16.0f / 512.0f;
        return { tileX * s, (tileX + 1) * s, tileY * s, (tileY + 1) * s };
    }

    constexpr UVCoord blockUVs[(int)BlockID::COUNT][(int)Face::COUNT] = {
        // AIR - doesn't matter, never meshed
        {},
        // GRASS BLOCK
        {
            tileToUV(0, 0),  // TOP
            tileToUV(0, 2),  // BOTTOM
            tileToUV(0, 1),  // NORTH
            tileToUV(0, 1),  // SOUTH
            tileToUV(0, 1),  // EAST
            tileToUV(0, 1),  // WEST
        },
        // DIRT BLOCK
        {
            tileToUV(0, 2),  // TOP
            tileToUV(0, 2),  // BOTTOM
            tileToUV(0, 2),  // NORTH
            tileToUV(0, 2),  // SOUTH
            tileToUV(0, 2),  // EAST
            tileToUV(0, 2),  // WEST
        }
    };
}