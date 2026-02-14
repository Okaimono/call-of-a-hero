#include "World.h"

void World::init() {
    chunk.init();
}

Renderable World::getRenderables() {
    return chunk.getRenderable();
}