/*
Topological sort is Applicable only to directed acyclic graphs (DAG's)

Definition : A linear ordering of vertices in a graph such that if there is an edge between u and v,
u appears before v in the linear ordering

algorithm
- perform dfs, after completing each node push it into the result
finally reverse the result and provide
*/

#include <bits/stdc++.h>

using namespace std;

// helper dfs
void dfs(vector<vector<int>> &adjList, int node, vector<bool> &vis, vector<int> &result){
    // marking visited
    vis[node] = true;

    // go for the neighs
    for(int v : adjList[node]){
        if(!vis[v])
            dfs(adjList, v, vis, result);
    }

    // append to result
    result.push_back(node);
}
vector<int> topoSort(int V, vector<vector<int>> &edges){
    // build adjlist
    vector<vector<int>> adjList(V);
    for(auto vec : edges)
        adjList[vec[0]].push_back(vec[1]);
    
    // perform toposort
    vector<bool> vis(V, false);
    vector<int> result;
    for(int node = 0; node < V; node++){
        if(!vis[node])
            dfs(adjList, node, vis, result);
    }

    // reverse and return 
    reverse(result.begin(), result.end());
    return result;
    
}

// kahn's algorithm
/*
Algorithm:
- As you build the adjacency list, find the indegree of the nodes
- The nodes with indegree 0 are pushed into the bfs queue and the result 
- as you take out elements from the queue insert them into your result array
- as you visit each neighbor of the 0 degree nodes, decrease the degree of the visited nodes by 1
- if at any instant the indegree becomes 0, then push it into the queue
- operation is complete when the queue becomes empty
- if the result contains elements less than the total nodes, it is not a DAG and cannot be topologically sorted

Important note:
the same algorithm can be used to find Cycles in directed graphs
instead of an array for storing toposort elements, use a counter to see what elements can be toposorted
if that counter equals the number of vertices at the end, then it can be topologically sorted, hence it is a DAG, else not
*/

vector<int> KahnsAlgo(int V, vector<vector<int>> &edges){

    vector<int> indegree(V, 0);
    vector<vector<int>> adjList(V);
    for(auto edge : edges){
        adjList[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }

    queue<int> q;
    for(int i = 0; i < V; i++){
        if(!indegree[i])
            q.push(i);
    }

    vector<int> result;
    while(!q.empty()){
        int u = q.front();
        result.push_back(u);
        q.pop();

        for(int v : adjList[u]){
            indegree[v]--;
            if(!indegree[v])
                q.push(v);
        }
    }
    if(result.size() < V) return {};

    return result;
}
int main(){
    return 0;
}