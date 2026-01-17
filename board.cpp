#include <iostream>
#include "board.h"
using namespace std;

Board::Board() {}
Board::Board(int compressedBoard) {
    board[0][0] = static_cast<state>(compressedBoard & 0b11);
    board[0][1] = static_cast<state>(compressedBoard >> 2 & 0b11);
    board[0][2] = static_cast<state>(compressedBoard >> 4 & 0b11);
    board[1][0] = static_cast<state>(compressedBoard >> 6 & 0b11);
    board[1][1] = static_cast<state>(compressedBoard >> 8 & 0b11);
    board[1][2] = static_cast<state>(compressedBoard >> 10 & 0b11);
    board[2][0] = static_cast<state>(compressedBoard >> 12 & 0b11);
    board[2][1] = static_cast<state>(compressedBoard >> 14 & 0b11);
    board[2][2] = static_cast<state>(compressedBoard >> 16 & 0b11);
}

void Board::print() {
    cout << "Current Board:" << endl;
    cout << "-------------" << endl;
    for (auto &row : board) {
        string stringRow = "| ";
        for (auto space : row) {   
            if (space == NONE) stringRow.append(" ");
            else if (space == CROSS) stringRow.append("X");
            else stringRow.append("O");
            
            stringRow.append(" | ");
        }
        cout << stringRow << endl;
        cout << "-------------" << endl;
    }
}

void Board::addMark(int y, int x, state mark) {
    board[y][x] = mark;
}

int Board::compress() {
    int compressedBoard;
    compressedBoard = board[0][0] + (board[0][1] << 2) + (board[0][2] << 4);
    compressedBoard += (board[1][0] << 6) + (board[1][1] << 8) + (board[1][2] << 10);
    compressedBoard += (board[2][0] << 12) + (board[2][1] << 14) + (board[2][2] << 16);
    return compressedBoard;
}