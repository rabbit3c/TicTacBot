#include <iostream>
#include "bot.h"
#include <vector>
using namespace std;

void evaluate(Game &game) {
    game.evaluation = game.winner;
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

int search(Game &game) {
    vector<int> games = game.findOptions();
    if (games.empty()) return 1;

    int amount = 0;
    for (int compressedGame : games) {
        Game futureGame = Game(compressedGame);
        amount += search(futureGame);
    }
    return amount;
}