#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'
const ll MOD = 998244353;

void solve() {
    /*
    denoting prefi as prefix xor till i
    pref[i] = 0xor1xor....i
    xor of l..r = pr[l - 1]xorpr[r]
    there is the fact that
        prefi = i, if i%4 == 0
              = 1, if i%4 == 1
              = i + 1, if i%4 == 2
              = 0, if i%4 == 3
    
    only 1 and 0 repeat
    we just need to find number of l, r pairs (l must not go beyond x)
    st pr[l] = pr[r] = 0, and pr[l] = pr[r] = 1
    */

    ll n, x; cin >> n >> x;

    auto zcnt = [&](ll i) -> ll {
        return 1ll + (i >= 3? (i - 3)/4 + 1 : 0);
    };

    auto ocnt = [&](ll i) -> ll {
        return (i >= 1? (i - 1)/4 + 1 : 0);
    };

    ll ans = (zcnt(x - 1)%MOD)*((zcnt(n) - zcnt(x - 1))%MOD)%MOD;

    ans += (ocnt(x - 1)%MOD)*((ocnt(n) - ocnt(x - 1))%MOD)%MOD;

    cout << (ans + MOD)%MOD << nline;

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