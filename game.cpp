#include <iostream>
#include <vector>
#include "board.h"
#include "game.h"
using namespace std;

Game::Game() {}
Game::Game(int compressedGame) {
    board = Board(compressedGame);
    player = static_cast<state>(compressedGame >> 18 & 0b11);
    winner = static_cast<state>(compressedGame >> 20 & 0b11);
    evaluation = static_cast<state>(compressedGame >> 22 & 0b11);
}

int Game::compress() {
    int compressedGame = board.compress();
    compressedGame += (player << 18);
    compressedGame += (winner << 20);
    compressedGame += (evaluation << 22);
    return compressedGame;
}

void Game::inputPlay() {
    board.print();
    int x;
    int y;
    cout << "It's " << ((player == CROSS) ? "X'": "O's") << " turn" << endl; 
    cout << "What's your play? ";
    cin >> x;
    cin >> y;
    play(y, x);
}

vector<int> Game::findOptions() {
    vector<int> games;
    if (winner != NONE) return games;

    int compressedGame = compress();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board.board[i][j] != NONE) continue;
            Game game = Game(compressedGame);
            game.play(i, j);
            games.push_back(game.compress());
        }
    }
    return games;
}

void Game::play(int y, int x) {
    board.addMark(y, x, player);
    checkForWin();
    if (player == CROSS) player = CIRCLE;
    else player = CROSS;
}

void Game::setWinner(state w) {
    winner = w;
}

void Game::checkForWin() {
    auto b = board.board;
    for (int i = 0; i < 3; i++) {
        //Columns
        if (b[i][0] == b[i][1] && b[i][1] == b[i][2] && b[i][0] != NONE) {
            setWinner(b[i][0]);
            return;
        }
        //Rows
        if (b[0][i] == b[1][i] && b[1][i] == b[2][i] && b[0][i] != NONE) {
            setWinner(b[0][i]);
            return;
        }
    }
    //Diagonals
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[1][1] != NONE) {
        setWinner(b[1][1]);
        return;
    }
    if (b[0][2] == b[1][1] && b[1][1] == b[2][2] && b[1][3] != NONE) {
        setWinner(b[1][1]);
        return;
    }
    return;
}