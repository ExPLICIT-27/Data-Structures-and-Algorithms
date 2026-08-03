#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int h, w, k; cin >> h >> w >> k;

    vector<vector<int>> G(h, vector<int>(w));

    for(int i = 0; i < h; i++){
        string S; cin >> S;


        for(int j = 0; j < w; j++)
            G[i][j] = S[j] - '0';
    }


    /*
    count the rectangles whose sum = K
    the grid is binary
    

    its not squares, its rects

    rectanges with at least K ones
    2D prefix sum of one

    101101
    110101

    count sqr submatrices that sum to k version ->

    */

    ll res = 0;
    

    vector<vector<int>> cpr(h + 1, vector<int>(w, 0));

    for(int j = 0; j < w; j++){
        for(int i = 0; i < h; i++){
            cpr[i + 1][j] = G[i][j] + cpr[i][j];
        }

    }

    // for(auto &r : cpr){
    //     for(int i : r)
    //         cout << i << " ";
    //     cout << nline;
    // }

    // return;

    ll ans = 0;
    for(int r1 = 0; r1 < h; r1++){
        for(int r2 = r1; r2 < h; r2++){
            // btw r1 and r2, insert the sums
            map<int, int> mp;
            int curr = 0;
            mp[0] = 1;
            for(int c = 0; c < w; c++){
                curr += cpr[r2 + 1][c] - cpr[r1][c];

                if(mp.find(curr - k) != mp.end())
                    ans += mp[curr - k];
                
                mp[curr]++;
            }
        }
    }

    cout << ans << nline;
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