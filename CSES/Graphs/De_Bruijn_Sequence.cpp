#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int n; cin >> n;

    if(n == 1){
        cout << "01" << nline;
        return;
    }

    /*
    the requirement is to generate a string that contains all substrings of length n

    consider all binary strings of length n - 1, 
    we construct a directed graph which depicts the relative change in substring when a 1 or 0 is added to it

    for eg, if the current string is "01", we add 1 to it, it becomes "11", else it becomes "10" (bit string transformation)

    after making graph, what we need is to just start from one node and traverse all edges (Eulerian path or cycle)

    since each no has two directed edges out, and each node can be reached from two different previous possiblities
    the degree is even throughout and all we need to find is a eulerian cycle (i chose cycle
    cause finding cycle is easier than path)


    */
    
    int sz = (1 << (n - 1));
    vector<vector<int>> G(sz);
    
    int mask = sz - 1;
    for(int u = 0; u < sz; u++){
        // add 0 to right -> left shift, mask with n - 1 1s
        int v_0 = ((u << 1) & mask);

        // set the  lsb and add mask
        int v_1 = (((u << 1) | 1) & mask);

        G[u].push_back(v_0);
        G[u].push_back(v_1);
    }

    // now just find eulerian cycle -> hierholzers

    vector<int> circ;

    function<void(int)> dfs;

    dfs = [&](int u) -> void {
        while(!G[u].empty()){
            int v = G[u].back();
            G[u].pop_back();
            dfs(v);
        }
        
        circ.push_back(u);
        
    };


    dfs(0);
    reverse(circ.begin(), circ.end());

    circ.pop_back(); // remove the cycle end

    string ans = "";
    // push the entire first node, then 1 letter by letter

    for(int i = 0; i < n; i++)
        ans += '0';
    
    for(int i = 1; i < circ.size(); i++){
        int v_0 = ((circ[i - 1] << 1) & mask);
        
        if(v_0 == circ[i])
            ans += '0';
        else    
            ans += '1';
    }


    cout << ans << nline;
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