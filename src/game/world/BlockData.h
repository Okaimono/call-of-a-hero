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
        // GRASS
        {
            tileToUV(0, 0),  // TOP
            tileToUV(2, 0),  // BOTTOM
            tileToUV(1, 0),  // NORTH
            tileToUV(1, 0),  // SOUTH
            tileToUV(1, 0),  // EAST
            tileToUV(1, 0),  // WEST
        },
    };

    constexpr const UVCoord& getUV(BlockID block, Face face) {
        return blockUVs[(int)block][(int)face];
    }
}