#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();

        vector<bool> vis(n, false);

        


        // shuld be O(v + e), e = 2*v, each number is connected to 2 other places 
        vis[start] = true;

        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int u = q.front(); q.pop();

            if(arr[u] == 0)
                return true;
            
            if(u + arr[u] < n && !vis[u + arr[u]]){
                vis[u + arr[u]] = true;
                q.push(u + arr[u]);
            }

            if(u - arr[u] >= 0 && !vis[u - arr[u]]){
                vis[u - arr[u]] = true;
                q.push(u - arr[u]);
            }
        }

        return false;
    }
};