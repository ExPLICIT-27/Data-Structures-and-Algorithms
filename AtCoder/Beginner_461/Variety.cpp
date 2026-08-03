#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

/*
N gems, each gem has color Ci and value Wi

choose K from these N 
chosen gems must have at least M distinct colors

what is the maximum quantity of a type of gem that I can take

10 gems, 5 diff at least

 K - M max freq
*/
void solve() {
    

    int n, k, m; cin >> n >> k >> m;

    vector<pair<int, int>> gems(n);

    for(auto &p : gems){
        cin >> p.second >> p.first;
    }


    sort(gems.begin(), gems.end(), greater<pair<int, int>>());

    /*
    dynamically can i check if its possible or not?
    */

    map<int, int> mp; // color and its occurences

    ll res = 0;
    int variety = m; // required variety
    int cnt = 0; // i need exactly K
    for(auto &p : gems){
        if(!mp.count(p.second)){
            mp[p.second] = 1;
            res += p.first;
            variety--;
            cnt++;
        }
        else{
            /*
            can i take this?
            if i take it -> cf + 1, 
            */
            if(k - cnt - 1 >= variety){
                mp[p.second]++;
                res += p.first;
                cnt++;
            }
        }
        if(cnt == k)
            break;
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