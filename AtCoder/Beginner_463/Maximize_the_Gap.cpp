#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    /*
    instinct tells me BS on ans

    easier accomodation is via sorting based on right ends
    '      ' '        '
    */

    int n, k; cin >> n >> k;
    
    vector<pair<int, int>> clothes(n);


    for(auto &c : clothes){
        cin >> c.first >> c.second;
    }

    sort(clothes.begin(), clothes.end(), [](pair<int, int> &a, pair<int, int> &b){
        if(a.second != b.second)
            return a.second < b.second;

        return a.first < b.first;
    });


    int L = 1, R = 1e9 + 1;


    auto canDo = [&](int M) -> bool {
        int cnt = 1;

        int prev = clothes[0].second;
        for(int i = 1; i < n; i++){
            if(clothes[i].first - prev >= M){
                cnt++;
                prev = clothes[i].second;
            }
        }

        return cnt >= k;
    };

    while(L <= R){

        int M = L + (R - L)/2;

        if(canDo(M))
            L = M + 1;
        else    
            R = M - 1;
    }

    if(canDo(1))
        cout << R << nline;
    else
        cout << -1 << nline;

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