
// Code
// Testcase
// Testcase
// Test Result
// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
// Solved
// Hard
// Topics
// Companies
// Hint
// Alice and Bob have an undirected graph of n nodes and three types of edges:

// Type 1: Can be traversed by Alice only.
// Type 2: Can be traversed by Bob only.
// Type 3: Can be traversed by both Alice and Bob.
// Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

// Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.

 

// Example 1:



// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
// Output: 2
// Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
// Example 2:



// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
// Output: 0
// Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
// Example 3:



// Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
// Output: -1
// Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
 

 

// Constraints:

// 1 <= n <= 105
// 1 <= edges.length <= min(105, 3 * n * (n - 1) / 2)
// edges[i].length == 3
// 1 <= typei <= 3
// 1 <= ui < vi <= n
// All tuples (typei, ui, vi) are distinct.
#include <iostream>
#include <vector>
using namespace std;
class UnionFind{
    public:
        vector <int> representatives;
        int components;
        vector <int> component_size;
        UnionFind(int n){
            components = n;
            for(int i = 0; i <= n; i++){
                representatives.push_back(i);
                component_size.push_back(1);
            }
        }
        int find_representative(int x){
            if(representatives[x] == x){
                return x;
            }
            representatives[x] = find_representative(representatives[x]);
            return representatives[x];
        }
        int unionize(int x, int y){
            x = find_representative(x);
            y = find_representative(y);
            if(x == y){
                return 0;
            }
            if(component_size[x] > component_size[y]){
                component_size[x] += component_size[y];
                representatives[y] = x;
            }
            else{
                component_size[y] += component_size[x];
                representatives[x] = y;
            }
            components--;
            return 1;
        }
        int is_traversible(){
            return components == 1;
        }
};
int edges_to_be_removed(int n, vector<vector<int>>& edges){
    UnionFind alice(n);
    UnionFind bob(n);
    int edges_req = 0;
    for(auto &edge: edges){
        if(edge[0] == 3){
            edges_req += (alice.unionize(edge[1], edge[2]) | bob.unionize(edge[1], edge[2]));
        }
    }
    for(auto &edge : edges){
        if(edge[0] == 2){
            edges_req += bob.unionize(edge[1], edge[2]);
        }
        else{
            edges_req += alice.unionize(edge[1], edge[2]);
        }
    }
    if(alice.is_traversible() && bob.is_traversible()){
        return edges.size()-edges_req;
    }
    return -1;
}
int main(){
    return 0;
}