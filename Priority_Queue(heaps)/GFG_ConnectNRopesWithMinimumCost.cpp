#include <bits/stdc++.h>


using namespace std;

class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        
        int cost = 0;
        while(pq.size() > 1){
            int ff = pq.top();
            pq.pop();
            
            int ss = pq.top();
            pq.pop();
            cost += ff + ss;
            pq.push(ff + ss);
        }
        return cost;
    }
};