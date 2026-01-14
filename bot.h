#include "game.h"

void evaluate(Game &game) {
    vector<int> games = game.findOptions();
    if (games.empty()) return;

    state eval = (game.player == CROSS) ? CIRCLE : CROSS;
    for (int compressedGame : games) {
        Game possibleGame = Game(compressedGame);
        evaluate(possibleGame);
        if (possibleGame.evaluation == game.player) {
            game.evaluation = game.player;
            return;
        } 
        if (possibleGame.evaluation == NONE) eval = NONE;
    }
    game.evaluation = eval;
    return;  
}