#pragma once

enum class BlockID {
    AIR = 0,
    GRASS,
    DIRT,
    STONE,
    COBBLESTONE,
    SAND,
    GRAVEL,
    OAK_LOG,
    OAK_LEAVES,
    OAK_PLANKS,
    WATER,
    GLASS,
    BEDROCK,
    COUNT
};

enum class Face {
    TOP, BOTTOM, NORTH, SOUTH, EAST, WEST,
    COUNT
};