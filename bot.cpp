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
    game.movesToFinish = turns[0].second.movesToFinish + 1;

    for (pair<Move, Game> turn : turns) {
        evaluate(turn.second);
        if (turn.second.evaluation == game.player) {
            if (eval != game.player || game.movesToFinish > turn.second.movesToFinish + 1) {
                eval = game.player;
                game.bestMove = turn.first;
                game.movesToFinish = turn.second.movesToFinish + 1;
                continue;
            }
        } 
        if (turn.second.evaluation == NONE && eval != game.player) {
            if (eval != NONE || game.movesToFinish < turn.second.movesToFinish + 1) {
                eval = NONE;
                game.bestMove = turn.first;
                game.movesToFinish = turn.second.movesToFinish + 1;
                continue;
            }
        }
        if (turn.second.evaluation == inverse(game.player) && eval == inverse(game.player)) {
            if (game.movesToFinish < turn.second.movesToFinish + 1) {
                game.bestMove = turn.first;
                game.movesToFinish = turn.second.movesToFinish + 1;
            }
        }
    }
    game.evaluation = eval;
    return;  
}