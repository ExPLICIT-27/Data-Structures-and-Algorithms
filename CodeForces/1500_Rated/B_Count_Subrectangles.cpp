#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    /*
    
    */

    int n, m, k; cin >> n >> m >> k;


    vector<int> A(n), B(m);

    for(int &i : A)
        cin >> i;
    
    for(int &i : B)
        cin >> i;
    
    /*
    I cannot construct C
    N*M > 1e8

    all (i, j) pairs such that i*j is K


    if A[i] is 1, then the row is = B
    else the row is completely 0


    a formula i devised


    for all tmp of k

    the no of rectangles of area k, given m columns are

    (row_no - (divisor - 1))*(m  - k/divisor + 1)
    summation for all row_no
    */

    unordered_set<int> tmp;

    for(int i = 1; 1ll*i*i <= k; i++){
        if(k%i == 0){
            tmp.insert(i);
            tmp.insert(k/i);
        }
    }

    vector<int> divisors(tmp.begin(), tmp.end());
    sort(divisors.begin(), divisors.end());

    map<int, int> cols;

    int curr = 0;

    for(int i = 0; i < m; i++){
        if(B[i])
            curr++;
        else{
            if(curr)
                cols[curr]++;
            curr = 0;
        }
    }

    if(curr)
        cols[curr]++;

    
    map<int, int> rows;

    curr = 0;
    for(int i = 0; i < n; i++){
        if(A[i])
            curr++;
        else{
            if(curr)
                rows[curr]++;
            curr = 0;
        }
    }

    if(curr)
        rows[curr]++;
    
    auto cnt = [&](int r, int c) -> ll {
        ll res = 0;
        for(int d : divisors){
            if(r - (d - 1) <= 0)
                continue;
            if(c - k/d + 1 <= 0)
                continue;
            
            res += 1ll*(r - (d - 1))*(c - k/d + 1);
        }

        return res;
    };

    ll ans = 0;
    for(auto &[r, rc] : rows){
        for(auto &[c, cc] : cols){
            ans += 1ll*rc*cc*cnt(r, c);
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