using namespace std;

enum state {
    NONE,
    CROSS,
    CIRCLE
};

class Board {
    public:
        state board[3][3] = {
            {NONE, NONE, NONE},
            {NONE, NONE, NONE},
            {NONE, NONE, NONE}
        };

        void print() {
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
        void addMark(int x, int y, state mark) {
            board[y][x] = mark;
        }
};