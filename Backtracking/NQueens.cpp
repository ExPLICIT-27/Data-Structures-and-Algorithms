/*
Given an N*N chessboard, place N queens on the board such that they are never under threat from
each other

*/
#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}
void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, row, j, n))
        {
            board[row][j] = 'Q';
            nQueens(board, row + 1, n, ans);
            board[row][j] = '.';
        }
    }
}
int main()
{
    int n;
    cout << "\nEnter the number : ";
    cin >> n;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    nQueens(board, 0, n, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "\nSolution Number " << i + 1 << endl;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << ans[i][k][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}