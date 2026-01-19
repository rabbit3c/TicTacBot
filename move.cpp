#include "move.h"

Move::Move() {}

Move::Move(int y, int x, state player) : y(y), x(x), player(player) {}

string Move::toString() {
    return stateToString(player) + " at " + to_string(x) + ", " + to_string(y);
}