/*
Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

logic:
Since you mod the obtained product with 1e5, you can have at most 99999 unique products. Compute the number of steps to reach the different
products we come across. Since steps are an increment of 1, using a simple queue with dijstkra's bfs would suffice

*/
#include <bits/stdc++.h>

using namespace std;

int mod = int(1e5);

int minimumMultiplications(vector<int>& arr, int start, int end){

    // set up dijsktras initial conditions
    vector<int> dist(mod, INT_MAX);
    dist[start] = 0;
    queue<pair<int, int>> q;
    q.push({start, 0});

    // begin dijkstra's
    while(!q.empty()){
        auto [u, d] = q.front();
        q.pop();

        for(int m : arr){
            int v = u*m%mod;
            if(dist[v] > d + 1){
                dist[v] = d + 1;
                q.push({v, dist[v]});
            }
        }
    }

    // return -1 if impossible
    return dist[end] == INT_MAX ? -1 : dist[end];
}

int main(){
    return 0;
}