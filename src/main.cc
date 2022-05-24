#include "../inc/game.h"

int main() {
    // Initialize game
    Game game;

    // Each pass through this loop represents a frame
    while (game.running()) {
        game.update();
        game.render();
    }

    return 0;
}