#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int x, y; cin >> x >> y;

    vector<vector<int>> board(8, vector<int>(8, -1));

    auto isValid = [&](int x, int y) -> bool {
        return x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == -1;
    };


    
    /*
    warsndorff algorithm -> visit the nodes with least edges outward first
    avoid choking the nodes (positions) with less entry/exit points
    */

    function<bool(int, int, int)> dfs;

    auto cntMoves = [&](int x, int y) -> int {
        int tot = 0;

        for(int i1 : {-2, 2}){
            for(int i2 : {1, -1}){
                int nx = x + i1;
                int ny = y + i2;

                if(isValid(nx, ny))
                    tot++;
                nx = x + i2;
                ny = y + i1;
                if(isValid(nx, ny))
                    tot++;
            }
        }

        return tot;
    };


    dfs = [&](int x, int y, int cnt) -> bool {

        
        board[x][y] = cnt;

        if(cnt == 64){
            return true;
        }
        
        vector<array<int, 3>> valid_pos;

        for(int inc1 : {2, -2}){
            for(int inc2 : {-1, 1}){
                int nx = x + inc1;
                int ny = y + inc2;

                if(isValid(nx, ny))
                    valid_pos.push_back({cntMoves(nx, ny), nx, ny});

                nx = x + inc2, ny = y + inc1;

                if(isValid(nx, ny))
                    valid_pos.push_back({cntMoves(nx, ny), nx, ny});
            }
        }

        sort(valid_pos.begin(), valid_pos.end());

        for(auto [c, nx, ny] : valid_pos){
            if(dfs(nx, ny, cnt + 1))
                return true;
        }

        board[x][y] = -1;

        return false;
    };
    x--, y--;
    dfs(y, x, 1); // cses dumbass  -> gave col, row

    for(auto &v : board){
        for(int i : v)
            cout << i << " ";
        cout << nline;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}