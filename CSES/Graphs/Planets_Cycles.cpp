#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    /*
    well this is a subpart of planet queries

    so every node is either part of a cycle or a branch

    if its a cycle, then the ans is simply the size of the cycle
    if its a branch, its distance to nearest cycle + size of cycle
    */

    int n; cin >> n;

    vector<int> P(n);
    vector<vector<int>> rev(n); // to calculate distance to cycle

    for(int i = 0; i < n; i++){
        cin >> P[i];
        P[i]--;

        rev[P[i]].push_back(i);
    }

    
    // same as b4
    /*
    if -2 -> not processed
    -1 -> branch
    something else -> id of cycle to which it belongs
    */
    vector<int> cycles;
    vector<int> cyc_id(n, -2);
    
    for(int u = 0; u < n; u++){
        if(cyc_id[u] != -2)
            continue;

        vector<int> path{u};
        int curr = u;
        cyc_id[u] = -3;

        while(cyc_id[P[curr]] == -2){
            curr = P[curr];
            path.push_back(curr);
            cyc_id[curr] = -3;
        }

        

        int cyc = 0;

        bool inCycle = false;
        for(int p : path){
            inCycle = (inCycle || (p == P[curr]));
            if(inCycle){
                cyc_id[p] = cycles.size();
                cyc++;
            }
            else
                cyc_id[p] = -1;
        }
        
        cycles.push_back(cyc);
    }

    
    
    /*
    i have each node, which cycle it belongs to, and the size of that cycle
    */
    // now calc distance of branch to cycle, if node is in cycle, its size = cycle size
    // rev edges
    vector<int> cyc_dist(n, 0);

    for(int p = 0; p < n; p++){
        // i should be at a branch which is about to lead into a cycle
        if(cyc_id[p] != -1 || cyc_id[P[p]] == -1)
            continue;
        cyc_dist[p] = 1;
        vector<int> S(rev[p]);

        while(!S.empty()){
            int u = S.back();
            S.pop_back();

            cyc_dist[u] = cyc_dist[P[u]] + 1;

            S.insert(S.end(), rev[u].begin(), rev[u].end());
        }
    }    

    
    
    // i guess i need the binary lifting table to jump into that node to get the cycle size
    int LOG = ceil(log2(n));

    vector<vector<int>> up(n, vector<int>(LOG + 1));

    for(int i = 0; i < n; i++)
        up[i][0] = P[i];

    for(int j = 1; j <= LOG; j++){
        for(int u = 0; u < n; u++)
            up[u][j] = up[up[u][j - 1]][j - 1];
    }

    auto lift = [&](int u, int d) -> int {
        if(d < 0)
            return -1;
        
        for(int i = LOG; i >= 0; i--){
            if((d >> i) & 1)
                u = up[u][i];
        }

        return u;
    };

    for(int p = 0; p < n; p++){
        cout << cyc_dist[p] + cycles[cyc_id[lift(p, cyc_dist[p])]] << " ";
    }

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