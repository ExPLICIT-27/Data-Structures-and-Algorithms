#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    /*
    
    include their topping, 
    discount their non topping



    this is a boolean satisfiability problem
    the request of each person can be considered in the form of a boolean equation
    + 1 -2 => (1 or ~2)

    SAT is NP complete, no polynomial timee soln exists for it
    however 2 SAT is solvable in polynomial time
    this is a classic 2 SAT problem

    solving 2 SAT
    convert the equation into a implication graph
    a -> b = ~a or b
    hence, a or b = ~a->b (graphically we need to add ~b->a edge AS WELL)

    directed edge from ~a -> b and ~b -> a

    now obv, there exists no solution if there is a path from a->~a and ~a->a (contradiction)
    to check this efficiently, just see if they belong to the same strongly connected component

    just find all SCCs using kosarajus (keep track of SCC no for each node)

    if SCC_no[a] > SCC_no[~a], assign true (since SCC nos are assigned based on the reverse graph)
    */

    int n, m; cin >> n >> m;

    int N = 2*m;
    vector<vector<int>> G(N), rev(N);



    auto neg = [&](int u) -> int {
        return (u < m)? m + u : u - m;
    };



    // implication grph
    for(int i = 0; i < n; i++){
        char c1, c2;
        int u, v;
        cin >> c1 >> u >> c2 >> v;
        u--, v--;

        if(c1 == '-')
            u = neg(u);
        if(c2 == '-')
            v = neg(v);
        
        G[neg(u)].push_back(v);
        G[neg(v)].push_back(u);

        rev[v].push_back(neg(u));
        rev[u].push_back(neg(v));
    }

    

    vector<bool> vis(N, false);
    stack<int> stk;
    function<void(int)> topodfs;

    topodfs = [&](int u) -> void {
        vis[u] = true;
        

        for(int v : G[u]){
            if(!vis[v])
                topodfs(v);
        }

        stk.push(u);
    };

    for(int i = 0; i < N; i++){
        if(!vis[i])
            topodfs(i);
    }

    vector<int> scc_no(N);
    fill(vis.begin(), vis.end(), false);

    int cno = 0;
    while(!stk.empty()){
        int node = stk.top();
        stk.pop();

        if(!vis[node]){
            vis[node] = true;
            
            queue<int> q;
            q.push(node);

            while(!q.empty()){
                int u = q.front();
                scc_no[u] = cno;
                q.pop();

                for(int v : rev[u]){
                    if(!vis[v]){
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

            cno++;
        }
    }


    vector<char> ans(m);

    for(int i = 0; i < m; i++){
        if(scc_no[i] > scc_no[neg(i)]){
            ans[i] = '+';
        }
        else if(scc_no[i] < scc_no[neg(i)]){
            ans[i] = '-';
        }
        else{
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    for(char c : ans)
        cout << c << " ";
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