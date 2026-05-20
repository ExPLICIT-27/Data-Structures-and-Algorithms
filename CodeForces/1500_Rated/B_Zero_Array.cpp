#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int n; cin >> n;

    vector<int> A(n);


    for(int &i : A)
        cin >> i;
    
    // sum should be even

    ll tot = accumulate(A.begin(), A.end(), 0ll);

    if(tot & 1){
        cout << "NO\n";
        return;
    }
    
    bool ok = true;


    for(int i : A){
        if(tot - i < i){
            ok = false;
            break;
        }
    }

    if(ok)
        cout << "YES\n";
    else
        cout << "NO\n";

    // sort and 2 pointers?
    /*

    0 0 4 4 
    */

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