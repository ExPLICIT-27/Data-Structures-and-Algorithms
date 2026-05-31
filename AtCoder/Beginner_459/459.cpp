#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int n; cin >> n;

    vector<string> V(n);

    for(auto &s : V)
        cin >> s;
    
    string res = "";

    for(auto &s : V){
        int d = (s[0] - 'a')/3;
        int diff = (s[0] - 'a');
        if(d == 0)
            res += '2';
        else if(d == 1)
            res += '3';
        else if(d == 2)
            res += '4';
        else if(d == 3)
            res += '5';
        else if(d == 4)
            res += '6';
        else if(diff >= 15 && diff <= 18)
            res += '7';
        else if(diff <= 21)
            res += '8';
        else
            res += '9';
    }

    cout << res << nline;
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