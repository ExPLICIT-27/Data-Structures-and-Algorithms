#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int n, k; cin >> n >> k;

    string S; cin >> S;

    int cnt[k][26];
    memset(cnt, 0, sizeof(cnt));

    for(int i = 0; i < n; i++)
        cnt[i%k][S[i] - 'a']++;
    
    // put whatever was already maximum at that point
    int ans = 0;


    auto getcnt = [&](int u, int v) -> int {
        int tot = 0, mx = 0;

        for(int i = 0; i < 26; i++){
            tot += cnt[u][i] + cnt[v][i];
            mx = max(cnt[u][i] + cnt[v][i], mx);
        }

        return tot - mx;
    };

    for(int i = 0; i < k; i++){
        // the values at i as well as k - i - 1 must be the same
        // find the max value in these places and subtract from total to get the cnt of changes to be made
        ans += getcnt(i, k - i - 1);
    }
    // by 2 because i, k - i - 1 im cnting twice
    cout << ans/2 << nline;
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