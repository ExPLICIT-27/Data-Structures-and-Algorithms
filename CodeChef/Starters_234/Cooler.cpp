#include <bits/stdc++.h>
#define nline '\n'
using namespace std;


void solve(){
    int n, m; cin >> n >> m;

    cout << n*(n + 1)/2 - m*(m + 1)/2 << nline;
}
int main(){
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}