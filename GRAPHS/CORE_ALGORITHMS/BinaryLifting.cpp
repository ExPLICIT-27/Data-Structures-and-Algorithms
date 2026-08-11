#include <bits/stdc++.h>

using namespace std;

/*
Binary lifting is used to find the Kth ancestor of a node in O(log(N)) time
Algorithm
for every node, we find all their ancestors in powers of 2
i.e for a node x, we will find its  1st ancestor, 2nd, 4th and so on till Log(N)
then if we want to find any kth ancestor lets say 19th ancestor of a node y
then from node y, we go to its 16th ancestor, then from there we go that node's 2nd ancestor, then from there we go to its 1st ancestor

19 = 16 + 2 + 1, voila, kth ancestor in logarithmic time

// two cases while writing code
if its guaranted the number of the parent is always < number of current node
i.e parent[i] <= i always
then code would be
up[i][j] => jth parent of ith node

for i in 0..N
    up[i][0] = parent[i]

    for j in 1..LOG(N)
        up[i][j] = up[up[i][j - 1]][j - 1]
    basically
    u[0][1] = u[u[0][0]][0]
    u[0][2] = u[u[0][1]][1]
    every next power of 2 is double the previous power,
    hence go back to the previous parent, which is 2 times behind and find its parent which is again 2 times behind
for cases where it is not guaranteed that parent[i] <= i
pre process first level parents through dfs or bfs
for i in 0..n
    up[i][0] = parent[i]
then do binary lifting level by level (keep log loop outside)
for j in 1..LOG(N)
    for i in 0..N
        up[i][j] = up[up[i][j - 1]][j - 1]
    
*/
// solution to leetcode question, 1483, Kth ancestor of a tree node,
class TreeAncestor {
public:
    vector<vector<int>> up;
    vector<int> depth;
    int LOG;
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        while((1 << LOG) <= n)
            LOG++;
        
        up = vector<vector<int>>(n, vector<int>(LOG, -1));

        for(int i = 0; i < n; i++)
            up[i][0] = parent[i];

        for(int j = 1; j < LOG; j++){
            for(int u = 0; u < n; u++){
                if(up[u][j - 1] != -1)
                    up[u][j] = up[up[u][j - 1]][j - 1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        
        
        for(int j = 0; j < LOG; j++){
            if(k & (1 << j))
                node = up[node][j];
            if(node == -1)
                break;
        }

        return node;
    }
};
// finding LCA using binary lifting
// core logic
/*
1. first bring both the nodes to the same level (same depth)
by lifting the deeper one upward

2. now keep lifting both together till you set both nodes to one below the LC
for eg
if tree is 
        A
    B       C
D             E

the LCA of D and E is A, you want to set D to B and E to C (one node below LCA)
Handle the case where one of the other nodes is the LCA of the other (after lifting you arrive at same node)
3. To find the one node below the LCA, you traverse from LOG(N) to 0, and check if you can lift both nodes such that
their parents are not equal (you have not crossed LCA), basically asking the question Can I move both nodes up by 
2^(i) steps without landing on the same ancestor?

hence the LCA would be the first parent of either one, because both are at nodes 1 below the LCA
*/
int LCA(vector<int>  &depth, int u, int v, int LOG, vector<vector<int>> &up){
    if(depth[u] > depth[v])
        swap(u, v);
    
    int diff = depth[v] - depth[u];

    //lift deeper node up to same level
    for(int i = LOG - 1; i >= 0; i--){
        if(diff & (1 << i))
            v = up[v][i];
    }

    if(u == v)
        return u;
    
    //move both to just 1 node below the lca, by seeing how high you can go without hitting an ancestor

    for(int i = LOG - 1; i >= 0; i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i], v = up[v][i];
        }
    }

    // now lca is both up[u][0] and up[v][0], return any
    return up[u][0];
}
int main(){
    return 0;
}