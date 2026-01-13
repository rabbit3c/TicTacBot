#include <iostream>
#include "board.h"
using namespace std;

class Game {
    public:
        Board board = Board();
        state player = CROSS;
        state winner = NONE;

        void checkForWin() {
            auto b = board.board;
            for (int i = 0; i < 3; i++) {
                //Columns
                if (b[i][0] == b[i][1] && b[i][1] == b[i][2] && b[i][0] != NONE) {
                    winner = b[i][0];
                    return;
                }
                //Rows
                if (b[0][i] == b[1][i] && b[1][i] == b[2][i] && b[0][i] != NONE) {
                    winner = b[0][i];
                    return;
                }
            }
            //Diagonals
            if (b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[1][1] != NONE) {
                winner = b[1][1];
                return;
            }
            if (b[0][2] == b[1][1] && b[1][1] == b[2][2] && b[1][3] != NONE) {
                winner = b[1][1];
                return;
            }
            return;
        }

        void inputPlay() {
            board.print();
            int x;
            int y;
            cout << "It's " << ((player == CROSS) ? "X'": "O's") << " turn" << endl; 
            cout << "What's your play? ";
            cin >> x;
            cin >> y;
            play(x, y);
        }

        void play(int x, int y) {
            board.addMark(x, y, player);
            checkForWin();
            if (player == CROSS) player = CIRCLE;
            else player = CROSS;
        }
};