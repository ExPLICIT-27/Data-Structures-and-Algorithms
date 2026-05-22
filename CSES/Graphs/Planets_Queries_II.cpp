#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    /*
    if the constraints were small, it would be a multi src shortest path qn
    but i need an algorithm which runs in O(n) or O(nlogn) time

    there are n - 1 edges only
    at most n moves, you should reach the destination
    if you cant reach in n moves, its not connected

    okay complicated a wee bit (at least 2000 rated on CF)

    since each node has only 1 edge out of it, this can be considered a functional graph
    each node is either part of a cycle or leads to 1 of the cycles(these im calling a branch)

    3 cases for a query (a, b)

    let cyc_dist denote an array which computes the distance of a node to its nearest cycle

    1. a and b are part of a branch
        - they are in different branches or b comes before a : -1
        - else just cyc_dist[a] - cyc_dist[b]
    2. 1 in a branch, other in a cycle (reachable from a)
        - if a is in cycle and b in branch : -1
        - move a to b's cycle root (cyc_dist[a] is addded to answer initially) and perform case 3
    3. if a is before b in the cycle -> ind[b] - ind[a] (ind[x] denotes index of x in its cycle)
        else cyc_len - (ind[b] - ind[a])

    so we basically need
    cyc_dist -> distance of each node from its cycle root
    cyc_id -> id of the cycle to which each node belongs to
    cycles -> storing the cycles and their indices for ind[x] calculation

    now to efficiently jump distances, we need a binary lifting array as well

    CREDITS : USACO Guide Solution for Planet Queries II
    */

    int n, q;
    cin >> n >> q;

    vector<int> next(n); // inp array
    vector<vector<int>> rev(n); // reversed edges ; to compute distance of each node to its cycle root (easier to go from root to others)

    for(int i = 0; i < n; i++){
        int u; cin >> u;
        u--;

        next[i] = u;
        rev[u].push_back(i); // add reversed edge
    }

    vector<int> cyc_id(n, -2);// id of each nodes cycle (if its part of it)
    /*
    cyc_id = -2, we have not processed it
    cyc_id = -1, it is part of a branch
    else = id of the cycle which it is a part of
    */

    vector<map<int, int>> cycles; // actual cycles (the node in the cycle, index ind[x] is used here)

    for(int u = 0; u < n; u++){
        if(cyc_id[u] != -2)
            continue;
        
        vector<int> curr_path{u}; // curr path with initially just u in it

        int curr = u;

        while(cyc_id[next[curr]] == -2){
            curr = next[curr];
            cyc_id[curr] = -3;
            curr_path.push_back(curr);
        }

        map<int, int> cyc;

        // it might be of the form 1->2->3->4
        //                               |  |
        //                                6<-5
        // curr will be at 6,
        // 1
        bool inCycle = false;

        for(int v : curr_path){
            inCycle = (inCycle || (v == next[curr]));
            
            if(inCycle){
                cyc[v] = cyc.size();
                cyc_id[v] = cycles.size();
            }
            else
                cyc_id[v] = -1; // branch
        }

        cycles.push_back(cyc);
    }

    // now i Have
    // the cycles and the non cycles
    // each node is mapped to its cycle with its ID
    // Each cycle has its nodes along with their incycle IDs
    // now the next thing i need is the distance of these nodes from their cycles
    // i need to make use of reversed edge to calculate the distance (0 for cycle root, +1 for every other node connected to it in the rev edge)


    /*
    if a planet is part of a cycle, its dist = 0
    */

    vector<int> cyc_dist(n, 0);

    for(int u = 0; u < n; u++){
        
        /*
        if current node in cycle (id != -1), ignore dist = 0
        if not in cycle and in branch, next node not inside cycle, dont process yet, continue
        start process if next is inside cycle 
        */
        if(cyc_id[u] != -1 || cyc_id[next[u]] == -1) 
            continue;
        cyc_dist[u] = 1;

        // now calculate the distance of the current branch from its cycle
        vector<int> stack(rev[u]); // i can use a queue as well, but it doesnt matter, its always parent distance + 1

        while(!stack.empty()){
            int v = stack.back();
            stack.pop_back();
            cyc_dist[v] = 1 + cyc_dist[next[v]]; // rev edge, so next[v] is the parent

            // insert all its neighbors
            stack.insert(stack.end(), rev[v].begin(), rev[v].end());
        }
    }

    // okay now we know 
    /*
    whether each node is part of a branch or cycle
    if part of cycle -> then we have ID's inside each cycle which can be used as distance
    if branch -> we have distance to closest cycle
    */

    // calculate binary lifting table (based on reversed edges -> cause youre jumping forward)

    int LOG = ceil(log2(n));

    vector<vector<int>> up(n, vector<int>(LOG + 1));

    for(int u = 0; u < n; u++)
        up[u][0] = next[u];
    
    for(int p = 1; p <= LOG; p++){
        for(int u = 0; u < n; u++)
            up[u][p] = up[up[u][p - 1]][p - 1];
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



    while(q--){
        int u, v; cin >> u >> v;

        u--, v--;

        // diff components
        if(cyc_id[up[u][LOG]] != cyc_id[up[v][LOG]]){
            cout << -1 << nline;
            continue;
        }
        /*
        3 cases are:
        1. both in branch
        2. both in cycle
        3. one in cycle one in branch

        handle case 2 and 3 in the same scenario by moving the one in branch into the cycle
        */  
        // both in branch      
        if(cyc_id[u] == -1 && cyc_id[v] == -1){
            int d_u = cyc_dist[u], d_v = cyc_dist[v];

            if(v == lift(u, d_u - d_v)) // alr handles v > u inside lift, it returns -1
                cout << d_u - d_v << nline;
            else
                cout << -1 << nline;
        }
        else{
            // u in cycle and v in branch, impossible
            if(cyc_id[u] != -1 && cyc_id[v] == -1){
                cout << -1 << nline;
                continue;
            }

            // handle both cases, u is branch/cycle with v

            int move = cyc_dist[u];
            u = lift(u, cyc_dist[u]);

            // if v_id > u_id, then ans is v_id - u_id
            // otherwise its cycle_size - (v_id - u_id)

            int cyc_size = cycles[cyc_id[u]].size();

            int u_id = cycles[cyc_id[u]][u];
            int v_id = cycles[cyc_id[u]][v];

            cout << move + (v_id >= u_id ? v_id - u_id : cyc_size - (u_id - v_id)) << nline;
        }
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