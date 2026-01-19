#pragma once
#include <vector>
#include "board.h"
#include "move.h"
using namespace std;

class Game {
    public:
        Board board = Board();
        state player = CROSS;
        state winner = NONE;
        state evaluation = NONE;
        Move bestMove = Move();

        Game();
        Game(int compressedGame);

        int compress();

        void inputPlay();

        vector<int> findOptions();
        vector<Move> findMoves();

        void playMove(Move &move);
    
    private:
        void play(int y, int x);
        void setWinner(state w);

        void checkForWin();
};