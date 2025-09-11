/*
A bipartite graph is 2 colorable

A graph cannot be bipartite if it has an even length cycle
*/

#include <bits/stdc++.h>

using namespace std;

bool helperDFS(vector<vector<int>> &graph, int node, int col, vector<int> &color){
    color[node] = col;
    for(int v : graph[node]){
        if(color[v] == -1){
            if(!helperDFS(graph, v, 1 - col, color))
                return false;
        }
        else if(color[v] == color[node])
            return false;
    }
    return true;
}
bool isBipartiteDFS(vector<vector<int>> &graph){
    int n = graph.size();

    vector<int> color(n, -1);
    for(int i = 0; i < n; i++){
        if(color[i] == -1 && !helperDFS(graph, i, 1, color))
            return false;
    }
    return true;
}
bool isBipartiteBFS(vector<vector<int>> &graph){
    int n = graph.size();
    
    vector<int> color(n, -1);

    for(int i = 0; i < n; i++){
        if(color[i] == -1){
            color[i] = 1;
            queue<int> q;
            q.push(i);

            while(!q.empty()){
                int u = q.front();
                q.pop();
                
                for(int v : graph[u]){
                    if(color[v] == -1){
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if(color[v] == color[u])
                        return false;
                    
                }
            }
        }
    }

    return true;

}
int main(){
    return 0;
}