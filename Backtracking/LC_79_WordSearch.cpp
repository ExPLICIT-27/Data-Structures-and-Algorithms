#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int dirx[4] = {-1, 1, 0, 0};
    int diry[4] = {0, 0, -1, 1};
    int M, N;
    bool isValid(int i, int j){
        return (i >= 0 && i < M && j >= 0 && j < N);
    }
    
    bool helper(vector<vector<char>> &board, vector<vector<int>> &vis, int x, int y, string &word, int n){
        if(n == word.size())
            return true;
    
        vis[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int nx = x + dirx[i];
            int ny = y + diry[i];
            if(isValid(nx, ny) && !vis[nx][ny] && board[nx][ny] == word[n]){
                if(helper(board, vis, nx, ny, word, n + 1))
                    return true;
                vis[nx][ny] = 0;
            }
        }
        vis[x][y] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        M = board.size(), N = board[0].size();


        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] == word[0]){
                    vector<vector<int>> vis(M, vector<int>(N, 0));
                    if(helper(board, vis, i, j, word, 1))
                        return true;
                }
            }
        }
        return false;
    }
};