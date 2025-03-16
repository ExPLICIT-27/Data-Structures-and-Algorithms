/*

    Given a n*m maze, where 0s represent walls and 1s represent paths, find all possible paths to the
    end of the maze (0, 0) -> (n - 1, n - 1)

*/
#include <bits/stdc++.h>

using namespace std;

string direction = "DLRU";

int dr[4] = {1, 0, 0, -1};
int dc[4] = {0, -1, 1, 0};

int isValid(int row, int col, int n, vector<vector<int>> &maze)
{
    return row >= 0 && col >= 0 && row < n && col < n && maze[row][col];
}
void SolveMaze(vector<vector<int>> &maze, int n, vector<string> &result, int row, int col, string &currDir)
{
    if (row == n - 1 && col == n - 1)
    {
        result.push_back(currDir);
        return;
    }

    maze[row][col] = 0;
    for (int i = 0; i < 4; i++)                                                                                                                                                                                                                                                                                                    
    {
        int nrow = row + dr[i];
        int ncol = col + dc[i];
        if (isValid(nrow, ncol, n, maze))
        {
            currDir += direction[i];
            SolveMaze(maze, n, result, nrow, ncol, currDir);

            currDir.pop_back(); // for backtracking
        }
    }
    maze[row][col] = 1; // for backtracking
}
int main()
{

    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    int n = maze.size();
    vector<string> result;
    string dir = "";
    SolveMaze(maze, n, result, 0, 0, dir);
    for (string res : result)
        cout << res << endl;
    return 0;
}