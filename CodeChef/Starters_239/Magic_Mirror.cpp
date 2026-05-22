#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int n; cin >> n;

    vector<int> black(n);

    for(int &i : black)
        cin >> i;
    
    if(n & 1){
        cout << "No\n";
        return;
    }

    // so it is at the midpoint
    /*
    x1, x2
    x1 - d = 6
    x2 + d = 7
    x1 - 6 = d
    x2 - 7 = d

    x1 - 6 = x2 - 7
    x1 - x2 = -1


    */

    
    // int x1x2 = black[n/2] + black[n/2 - 1];

    int l = black[n/2 - 1], r = black[n/2];

    
    int f = n/2 - 1, s = n/2;

    bool ok = true;
    while(f - 1 >= 0 && s + 1 < n){
        if(black[f] - black[f - 1] != black[s + 1] - black[s]){
            ok = false;
            break;
        }
        f--, s++;
    }
    if(ok)
        cout << "Yes\n";
    else
        cout << "No\n";
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