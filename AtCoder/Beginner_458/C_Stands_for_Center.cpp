#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    string S; cin >> S;

    int n = S.size();
    ll ans = 0;

    for(int i = 0; i < n; i++){
        if(S[i] == 'C'){
            ans += 1 + min(i, n - i - 1);
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