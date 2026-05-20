#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int h, w; cin >> h >> w;

    vector<vector<int>> G(h, vector<int>(w));

    // corners
    auto isValid = [&](int x, int y) -> bool {
        return x >= 0 && x < h && y >= 0 && y < w;
    };

    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            for(int k = 0; k < 4; k++){
                int x = i + dx[k], y = j + dy[k];

                if(isValid(x, y))
                    G[i][j]++;
            }
        }
    }
    

    for(auto &r : G){
        for(int i : r)
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