#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int n; cin >> n;

    vector<int> A(n);

    for(int &i : A)
        cin >> i;
    
    map<int, int> mp;
    map<int, vector<int>> ind;
    for(int i = 0; i < n; i++){
        mp[A[i]]++;

        ind[A[i]].push_back(i);
    }


    bool ok = false;
    for(auto &[x, y] : mp){
        if(y >= 2){
            ok = true;
            break;
        }
    }

    if(!ok){
        cout << -1 << nline;
        return;
    }

    if(A[0] == A[n - 1])
        cout << 0 << nline;
    else{
        // can swap adjacent elements only

        int ans = 2*n;
        for(auto &[x, y] : mp){
            if(y >= 2){
                ans = min(ans, ind[x][0] + (n - 1) - ind[x].back());
            }
        }

        cout << ans << nline;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}