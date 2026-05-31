#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int n; cin >> n;

    n--;
    string S = "HelloWorld";


    string ans = "";

    for(int i = 0; i < S.size(); i++){
        if(i == n)
            continue;
        
        ans += S[i];
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