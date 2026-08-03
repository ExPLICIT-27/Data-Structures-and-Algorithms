#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    /*
    N takahashi - each has a paritcular height

    okay map takahashi's to their height -> 
    sorted set of takahashi based on their leaving times
    */
    
    int n; cin >> n;
    set<pair<int, int>, greater<pair<int, int>>> ht;
    set<pair<int, int>> lt;

    for(int i = 0; i < n; i++){
        int h, l; cin >> h >> l;

        ht.insert(make_pair(h, l));
        lt.insert(make_pair(l, h));
    }

    int q; cin >> q;


    // process based on qi -> sorted

    vector<pair<int, int>> qi;

    for(int i = 0; i < q; i++){
        int ti; cin >> ti;


        qi.push_back(make_pair(ti, i));
    }

    vector<int> ans(q);
    sort(qi.begin(), qi.end());

    for(int i = 0; i < q; i++){
        int ct = qi[i].first;
        // remove all takahashis with l <= ct

        while(!lt.empty() && lt.begin()->first <= ct){
            int h = lt.begin()->second, l = lt.begin()->first;
            ht.erase(make_pair(h, l));
            lt.erase(lt.begin());
        }

        ans[qi[i].second] = ht.begin()->first;
    }

    for(int i : ans)
        cout << i << nline;
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