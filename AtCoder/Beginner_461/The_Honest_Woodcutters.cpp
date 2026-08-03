#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int n; cin >> n;

    vector<int> owner(n + 1);

    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        owner[x] = i;
    }

    vector<int> truth(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> truth[i];
    }


    for(int i = 1; i <= n; i++){
        if(truth[i] != owner[i]){
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
    
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