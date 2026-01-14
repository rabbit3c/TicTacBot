#include <iostream>
#include "game.h"

int main() {
    Game game = Game();
    game.inputPlay();
    game.board.print();
    cout << game.compress();
}
