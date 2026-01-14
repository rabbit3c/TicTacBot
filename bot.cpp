#include <iostream>
#include "bot.h"
#include <vector>
using namespace std;

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

int main() {
    Game game = Game(551313);
    evaluate(game);
    cout << "The game is winning for: " << endl;
    cout << ((game.evaluation == CROSS) ? "Cross" : ((game.evaluation == CIRCLE) ? "Circle" : "None")) << endl;
    return 0;
}