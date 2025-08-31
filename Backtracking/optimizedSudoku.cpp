/*
Industry grade sudoku using bit masking techniques
*/
#include <bits/stdc++.h>
using namespace std;

class SudokuSolver{
    int row[9] = {0}, col[9] = {0}, box[9] = {0};
    int getBox(int r, int c){
        return (r/3)*3 + c/3;
    }

    bool solve(vector<vector<char>> &board, vector<pair<int, int>> &empty, int idx){
        if(idx == empty.size()) return true;

        auto [r, c] = empty[idx];
        int b = getBox(r, c);
        for(int d = 1; d <= 9; d++){
            int mask = 1 << d;
            if(!(row[r] & mask) && !(col[c] & mask) && !(box[b] & mask)){
                board[r][c] = '0' + d;
                row[r] |= mask;
                col[c] |= mask;
                box[b] |= mask;

                if(solve(board, empty, idx + 1)) return true;

                board[r][c] = '.';
                row[r] ^= mask;
                col[c] ^= mask;
                box[b] ^= mask;
            }
        }
        return false;
    }
    public:
        void solveSudoku(vector<vector<char>> &board){
            vector<pair<int, int>> empty;
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                    if(board[i][j] == '.'){
                        empty.push_back({i, j});
                    }
                    else{
                        int mask = 1 << (board[i][j] - '0');
                        row[i] |= mask;
                        col[j] |= mask;
                        box[getBox(i, j)] |= mask;
                    }
                }
            }
            solve(board, empty, 0);
        }
};
int main(){
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    SudokuSolver ss = SudokuSolver();
    ss.solveSudoku(board);
    for(auto row : board){
        for(auto c : row)
            cout << c << " ";
        cout << endl;

    }
    return 0;
}