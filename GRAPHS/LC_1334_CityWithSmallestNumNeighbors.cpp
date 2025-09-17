/*
It is a direct implementation of floyd warshall's but the description is abysmal
*/

#include <bits/stdc++.h>

using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold){
    // distance array for the final calculation
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    // self distances are marked as 0
    for(int i = 0; i < n; i++)
        dist[i][i] = 0;

    // set up distance matrix
    for(auto edge : edges){
        int u = edge[0], v = edge[1],  w = edge[2];
        dist[u][v] = dist[v][u] = w;
    }

    // apply floyd Warshall's
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int result = 0, currLeast = INT_MAX;
    for(int i = 0; i < n; i++){
        int conns = 0;
        for(int j = 0; j < n; j++){
            if(i == j)
                continue;
            if(dist[i][j] <= distanceThreshold)
                conns++;
        }
        if(conns <= currLeast){
            currLeast = conns;
            result = i;
        }
    }

    return result;
}

int main(){
    return 0;
}