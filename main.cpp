#include <iostream>
#include "bot.h"
using namespace std;

int main() {
    Game game = Game();
    while (game.winner == NONE) {
        game.inputPlay();
        evaluate(game);
        cout << "Game is winning for: " << endl;
        cout << ((game.evaluation == CROSS) ? "Cross" : ((game.evaluation == CIRCLE) ? "Circle" : "None")) << endl;
        cout << "Best Move: " << game.bestMove.toString() << endl;
    }
    return 0;
}
