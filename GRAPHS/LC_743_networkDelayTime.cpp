/*
apply djikstras and return the maximum time to reach any node
*/
#include <bits/stdc++.h>

using namespace std;


int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // pure dijsktras
    vector<vector<pair<int, int>>> adjList(n);
    for(auto time : times){
        adjList[time[0] - 1].push_back({time[1] - 1, time[2]});
    }

    set<pair<int, int>> st;
    vector<int> dist(n, INT_MAX);
    dist[k - 1] = 0;
    st.insert({0, k - 1});

    while(!st.empty()){
        auto node = *(st.begin());
        st.erase(node);
        if(node.first == INT_MAX)
            return -1;
        for(auto [v, w] : adjList[node.second]){
            if(node.first + w < dist[v]){
                if(dist[v] != INT_MAX)
                    st.erase({dist[v], v});
                dist[v] = node.first + w;
                st.insert({dist[v], v});
            }
        }
    }

    int max_time = *max_element(dist.begin(), dist.end());

    return max_time == INT_MAX ? -1 : max_time;
}
int main(){
    return 0;
}