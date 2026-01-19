#pragma once
#include "state.h"

class Move {
    public:
        int x;
        int y;
        state player = NONE;

        Move();
        Move(int y, int x, state player);

        string toString();
};