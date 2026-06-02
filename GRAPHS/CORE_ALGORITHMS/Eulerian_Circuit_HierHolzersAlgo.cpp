#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    /*
   this question directly asks us to find a eulerian circuit in a graph

    
    Eulerian Path : A path that visits each edge exactly once (you must choose the correct vertex as starting pos)
    conditions : Every vertex has even degree or exactly 2 vertices have odd degree

    Eulerian Circuit : A Eulerian path which is also a cycle (starts and begins at the same vertex)
    conditions : Every vertex must have even degree

    important condition for both : all the vertexes WITH EDGES must be connected


    Hierholzer's algorithm:
    works on the fact that since every vertex has even degree, you can randomly keep moving from 1
    vert to another and remove the edge as you go, when you can no longer move, its because
    you have ended up where you started (a closed sub loop), now from among the vertices you have visited,
    continue the process and merge the other sub loops to get a eulerian circuit

    algorithm:
    - if there is any vertex with odd degree -> impossible
    - start from any vertex u, keep moving till you exhaust u, add u to the path
    - now find a node v which is part of the movement you made from u, visit all its unvisited edges and it to the tour as well
    - this is basically finding all closed loops and adding them together in order
    - modified dfs can be used to do this
    */

    int n, m; cin >> n >> m;

    vector<vector<pair<int, int>>> G(n);


    vector<int> deg(n, 0);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--, v--;

        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
        deg[u]++, deg[v]++;
    }

    if(deg[0] == 0){
        cout << "IMPOSSIBLE\n";
        return;
    }

    for(int i = 0; i < n; i++){
        if(deg[i] & 1){
            cout << "IMPOSSIBLE\n"; // odd degree node
            return;
        }
    }

    vector<bool> seen(m, false); // checking edges which are deleted
    vector<int> circuit;


    function<void(int)> dfs;

    dfs = [&](int u) -> void {
        while(!G[u].empty()){
            auto [v, edge] = G[u].back();
            G[u].pop_back();

            if(seen[edge])
                continue; // alr deleted edge
            seen[edge] = true; // delete the edge
            dfs(v);
        }

        circuit.push_back(u + 1); // add node to eulerian ciruit
    };

    dfs(0);
    if(circuit.size() != m + 1){
        cout << "IMPOSSIBLE\n"; // cant visit all edges
        return;
    }


    for(int i : circuit)
        cout << i << " ";
    cout << nline;

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