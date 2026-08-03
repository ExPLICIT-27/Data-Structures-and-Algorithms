#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int n; cin >> n;

    vector<bool> vac(5, false);

    char tar; cin >> tar;

    for(int i = 0; i < n; i++){
        string s; cin >> s;

        for(int j = 0; j < 5; j++){
            if(s[j] == 'o')
                vac[j] = true;
        }
    }

    if(vac[tar - 'A'])
        cout << "Yes\n";
    else
        cout << "No\n";
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