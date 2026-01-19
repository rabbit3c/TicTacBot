#pragma once
#include "state.h"

class Board {
    public: 
        Board();
        Board(int compressedBoard);
        
        state board[3][3] = {
            {NONE, NONE, NONE},
            {NONE, NONE, NONE},
            {NONE, NONE, NONE}
        };

        void print();
        void addMark(int y, int x, state mark);

        int compress();
};