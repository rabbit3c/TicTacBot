#pragma once
#include <vector>
#include "board.h"
using namespace std;

class Game {
    public:
        Board board = Board();
        state player = CROSS;
        state winner = NONE;
        state evaluation = NONE;

        Game();
        Game(int compressedGame);

        int compress();

        void inputPlay();

        vector<int> findOptions();
    
    private:
        void play(int y, int x);
        void setWinner(state w);

        void checkForWin();
};