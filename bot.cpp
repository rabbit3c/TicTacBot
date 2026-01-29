#include <iostream>
#include "bot.h"
#include <vector>
using namespace std;

void evaluate(Game &game) {
    game.evaluation = game.winner;
    vector<pair<Move, Game>> turns = game.findOptions();
    if (turns.empty()) return;

    state eval = inverse(game.player);
    game.bestMove = turns[0].first;

    for (pair<Move, Game> turn : turns) {
        evaluate(turn.second);
        if (turn.second.evaluation == game.player) {
            game.evaluation = game.player;
            game.bestMove = turn.first;
            return;
        } 
        if (turn.second.evaluation == NONE) {
            game.bestMove = turn.first;
            eval = NONE;
        } 
    }
    game.evaluation = eval;
    return;  
}