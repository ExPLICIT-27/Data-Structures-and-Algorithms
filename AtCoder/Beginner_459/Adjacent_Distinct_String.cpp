#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    string s; cin >> s;

    vector<int> F(26, 0);


    for(char c : s){
        F[c - 'a']++;
    }

    int max_f = *max_element(F.begin(), F.end());
    int n = s.size();
    if(max_f > (n + 1)/2){
        cout << "No\n";
        return;
    }

    cout << "Yes\n";

    string ans = "";

    char prev = '$';

    for(int i = 0; i < n; i++){
        char ch = '$';
        int max_f = 0;
        for(char c = 'a'; c <= 'z'; c++){
            if(c == prev || F[c - 'a'] == 0)
                continue;
            if(F[c - 'a'] > max_f){
                max_f = F[c - 'a'];
                ch = c;
            }
        }

        F[ch - 'a']--;
        prev = ch;
        ans += ch;
    }

    cout << ans << nline;
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