/*
print shortest weighted path from 1 to n in weighted Undirected Graph
output format
if it is not possible to reach n from 1
    return {-1}
otherwise return an array where the first element is the path weight and the remaining are the path elements
*/

#include <bits/stdc++.h>

using namespace std;

// helper function to backtrack and find the parents

void findPath(vector<int> &path, int src, int dest, vector<int> &parents){ 

    // base case, if we reach the destination, return
    if(src == dest){
        path.push_back(src + 1); // + 1 to account for the 1 based indexing of the graph
        return;
    }

    findPath(path, parents[src], dest, parents); // we need the order to be 1, 2, 3, so keep going for now, push into result after its done
    path.push_back(src + 1);
}
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges){ // m is the number of edges

    // if there are no edges, no path
    if(edges.empty())
        return {-1};
    
    // construct the adjacency list 
    vector<vector<pair<int, int>>> adjList(n);

    for(auto edge : edges){
        int u = edge[0] - 1, v = edge[1] - 1, w = edge[2]; // it contains nodes 1 to n

        adjList[u].push_back({v, w}); 
        adjList[v].push_back({u, w}); // undirected
    }

    // set up the dijkstra condition along with the parents
    vector<int> dist(n, INT_MAX);
    vector<int> parents(n, -1);
    set<pair<int, int>> st;

    dist[0] = 0;
    st.insert({0, 0});

    // begin the algorithm, along with keeping track of the parents
    while(!st.empty()){
        auto [d, u] = *(st.begin());
        st.erase({d, u});

        for(auto [v, w] : adjList[u]){
            if(d + w < dist[v]){
                if(dist[v] != INT_MAX)
                    st.erase({dist[v], v});
                
                dist[v] = d + w;
                parents[v] = u;
                st.insert({dist[v], v});
            }
        }
    }

    // if it is not possible to reach n, return -1
    if(dist[n - 1] == INT_MAX)
        return {-1};
    
    vector<int> path;
    path.push_back(dist[n - 1]);
    // since we are backtracking here src and dest are not used in the conventional sense, i.e we are trying to get from n to 1 using the parents array, thereby the source will be n and desination will be 1 initially
    findPath(path, n - 1, 0, parents);

    return path;

}
int main(){
    return 0;
}