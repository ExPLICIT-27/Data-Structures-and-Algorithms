/*
- courses cannot be scheduled if there exists a cycle between them
- the courses represent a directed graph
- after completing all prerequisites push it into the result to get the order of completion

each node = course, attached to it are the prereqs

O(V + E)

this question can also be done use kahn's algorithm -> topological sorting
*/
#include <bits/stdc++.h>

using namespace std;

bool checkCycle(vector<vector<int>> &adjList, int node, vector<int> &vis, vector<int> &pathvis, vector<int> &result){
    // mark the path and the pathvis
    vis[node] = true, pathvis[node] = true;

    // go for the neighbours
    for(int v : adjList[node]){
        if(!vis[v]){
            if(checkCycle(adjList, v, vis, pathvis, result))
                return true;
        }
        else if(pathvis[v])
            return true;
    }

    // insert node into answer after completing all its prerequisits if any, and mark path unvisited
    result.push_back(node);
    pathvis[node] = false;
    return false;
}
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites){
    
    // create adj list
    vector<vector<int>> adjList(numCourses);
    for(auto vec : prerequisites){
        adjList[vec[0]].push_back(vec[1]);
    }

    // set up dfs arrays
    vector<int> vis(numCourses, false);
    vector<int> pathvis(numCourses, false);
    vector<int> result;

    // perform the scheduling (if possible)
    for(int node = 0; node < numCourses; node++){
        if(!vis[node] && checkCycle(adjList, node, vis, pathvis, result)) 
            return {};
    }

    return result;
}
int main(){
    return 0;
}