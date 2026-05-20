#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        /*
        similar to 3629, can be considered as a graph, djikstra can be performed on 
        it
        */

        // i + 1 and i - 1 with dist 1, as well to other indices where arr[i] = arr[j] with dist 1

        unordered_map<int, vector<int>> mp;// same nums

        int n = arr.size();

        for(int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);
        
        queue<int> q;

        vector<int> dist(n, n + 1);
        dist[0] = 0;
        q.push(0);


        vector<bool> vis(n, false); // all elements with same value can be considered a single node, if i have visited it, then ignore all other branches
        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(u - 1 >= 0){
                if(dist[u - 1] > dist[u] + 1){
                    dist[u - 1] = 1 + dist[u];
                    q.push(u - 1);
                }
            }

            if(u + 1 < n){
                if(dist[u + 1] > dist[u] + 1){
                    dist[u + 1] = 1 + dist[u];
                    q.push(u + 1);
                }
            }

            if(!vis[u]){
                vis[u] = true;

                for(int v : mp[arr[u]]){
                    vis[v] = true;
                    if(dist[v] > dist[u] + 1){
                        dist[v] = 1 + dist[u];
                        q.push(v);
                    }
                }
            }
        }


        
        return dist[n - 1];

    }
};