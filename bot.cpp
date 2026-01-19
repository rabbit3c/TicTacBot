#include <iostream>
#include "bot.h"
#include <vector>
using namespace std;

void evaluate(Game &game) {
    game.evaluation = game.winner;
    game.findOptions();
    vector<Move> moves = game.findMoves();
    if (moves.empty()) return;

    int compressedGame = game.compress();
    state eval = (game.player == CROSS) ? CIRCLE : CROSS;
    game.bestMove = moves[0];

    for (Move move : moves) {
        Game possibleGame = Game(compressedGame);
        possibleGame.playMove(move);
        evaluate(possibleGame);
        if (possibleGame.evaluation == game.player) {
            game.evaluation = game.player;
            game.bestMove = move;
            return;
        } 
        if (possibleGame.evaluation == NONE) {
            game.bestMove = move;
            eval = NONE;
        } 
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