#include "engine/Engine.h"
#include "game/game.h"



int main() {
    Game game;
    Engine engine(854, 480, "Call of a Hero", game);
    engine.run();
} 