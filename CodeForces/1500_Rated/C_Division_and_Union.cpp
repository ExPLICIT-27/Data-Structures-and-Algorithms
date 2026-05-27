#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> V(n);

    vector<int> ind(n);

    iota(ind.begin(), ind.end(), 0);
    for(auto &p : V){
        cin >> p.first >> p.second;
    }

    sort(ind.begin(), ind.end(), [&](int a, int b){
        if(V[a].second != V[b].second)
            return V[a].second < V[b].second;

        return V[a].first < V[b].first;
    });

    // i just need to find a point which doesnt overlap with its previous neighbor if it exists

    // how about brute force trying every point
    /*
    A point x such that, there exists a partition such that,

    1 group, every single point ends before x, the other grp starts at >= x
    */

    vector<int> sfmin(n);
    sfmin[n - 1] = V[ind[n - 1]].first;

    for(int i = n - 2; i >= 0; i--){
        sfmin[i] = min(sfmin[i + 1], V[ind[i]].first);
    }

    int div = -1;

    for(int i = 1; i < n; i++){
        if(V[ind[i]].first > V[ind[i - 1]].second && sfmin[i] > V[ind[i - 1]].second){
            div = i;
            break;
        }
    }

    if(div == -1){
        cout << -1 << nline;
        return;
    }

    vector<int> ans(n);

    for(int i = 0; i < div; i++)
        ans[ind[i]] = 1;
    for(int i = div; i < n; i++)
        ans[ind[i]] = 2;
    
    for(int i : ans)
        cout << i << " ";
    cout << nline;
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