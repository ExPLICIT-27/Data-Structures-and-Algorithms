// modelled from the CSES question Mail Delivery
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
    - check even degree and connectivity first
    - create a stack which we will use for finding sub loops and temporary vertex storage
    - as long as you can move, just move and delete the edge as you move
    - when you cannot move, add the current vertex (exhausted vertex to the ans)
    find an already visited vertex to which there is an edge, continue till nothing can be processed anymore
    - print the result
    */

    int n, m; cin >> n >> m;

    vector<multiset<int>> G(n);

    vector<int> deg(n, 0);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--, v--;

        G[u].insert(v);
        G[v].insert(u);

        deg[u]++, deg[v]++;
    }

    int start;
    for(int i = 0; i < n; i++){
        if(deg[i] & 1){
            cout << "IMPOSSIBLE\n";
            return;
        }
        if(deg[i])
            start = i; // start from a node with an edge always
    }

    function<void(int)> conn_check;


    vector<bool> vis(n, false);

    conn_check = [&](int u) -> void {
        vis[u] = true;

        for(int v : G[u]){
            if(!vis[v])
                conn_check(v);
        }
    };

    conn_check(start);

    if(!vis[0]){
        cout << "IMPOSSIBLE\n";
        return;
    }
    for(int i = 0; i < n; i++){
        if(deg[i] && !vis[i]){
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    // degree and connectivity checks are complete


    stack<int> curr_path, circuit;

    curr_path.push(0);

    while(!curr_path.empty()){

        int u = curr_path.top();
        
        if(!G[u].empty()){
            int v = *G[u].begin();

            // erase edges
            G[u].erase(G[u].find(v));
            G[v].erase(G[v].find(u));
            
            curr_path.push(v);

            u = v;
        }
        else{
            circuit.push(u);
            curr_path.pop();
        }
    }

    while(!circuit.empty()){
        cout << circuit.top() + 1 << " ";
        circuit.pop();
    }

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