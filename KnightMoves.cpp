/*
Given a n*n chessboard, follow all valid moves of the night and see if it can come accross
all the 64 squares, if so print the move number in each square
*/
#include <bits/stdc++.h>

using namespace std;

int dirx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int diry[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isSafe(vector<vector<int>> &sol, int x, int y, int n)
{
    return x >= 0 && y >= 0 && x < n && y < n && sol[x][y] == -1;
}
bool solveKT(vector<vector<int>> &sol, int x, int y, int moveNo, int n)
{
    if (moveNo == n * n)
    {
        return true;
    }
    for (int k = 0; k < 8; k++)
    {
        int newx = x + dirx[k];
        int newy = y + diry[k];
        if (isSafe(sol, newx, newy, n))
        {
            sol[newx][newy] = moveNo;
            if (solveKT(sol, newx, newy, moveNo + 1, n))
            {
                return true;
            }
            else
            {
                sol[newx][newy] = -1;
            }
        }
    }
    return false;
}
int main()
{
    int n;
    cout << "\nEnter the number of squares : ";
    cin >> n;
    vector<vector<int>> sol(n, vector<int>(n, -1));
    sol[0][0] = 0;
    bool can = solveKT(sol, 0, 0, 1, n);
    if (can)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}