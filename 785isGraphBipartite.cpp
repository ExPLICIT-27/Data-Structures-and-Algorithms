#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool isGraphBipartite(vector<vector<int>> graph){
    vector<int> colors(graph.size(), -1);
    for(int i = 0; i < graph.size(); i++){
        if(colors[i] == -1){
            colors[i] = 0;
            queue<int> gqueue;
            gqueue.push(i);
            while(!gqueue.empty()){
                int u = gqueue.front();
                gqueue.pop();
                for(int v : graph[u]){
                    if(colors[v] == -1){
                        colors[v] = 1 - colors[u];
                    }
                    else if(colors[v] == colors[u]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main(){
    return 0;
}