// priority queue approach and binary search approach

#include <bits/stdc++.h>

using namespace std;


// priority queue approach
class Solution {
  public:
    
    double minMaxDist(vector<int> &stations, int K) {
        // place individually using gas stations
        priority_queue<pair<long double, int>, vector<pair<long double, int>>>  pq;
        int n = stations.size();
        vector<int> placed(n - 1, 0);
        for(int i = 0; i < n - 1; i++){
            pq.push({(long double)(stations[i + 1] - stations[i]), i});
        }
        
        for(int i = 0; i < K; i++){
            auto [dist, idx] = pq.top();
            pq.pop();
            placed[idx]++;
            long double newDist = 1.0*dist/(long double)(placed[idx] + 1);
            pq.push({newDist, idx});
            
        }
        return pq.top().first;
    }
};

// binary search variant
class Solution {
  public:
    bool canPlace(vector<int> &a, long double t, int k){
        int cnt = 0;
        for(int i = 0; i < a.size() - 1; i++){
            long double dist = (long double)(a[i + 1] - a[i]);
            if(dist > t){
                int req = int(ceil(dist/t)) - 1;
                cnt += req;
            }
            if(cnt > k)
                return false;
        }
        return true;
    }
    double minMaxDist(vector<int> &stations, int K) {
        int n = stations.size();
        if(n == 1)
            return 0.00;
        long double left = 0, right = 0;
        for(int i = 0; i < n - 1; i++){
            right = max(right, (long double)(stations[i + 1] - stations[i]));
        }
        
        while(right - left > 1e-6){
            long double mid = (left + right)/2.0;
            if(canPlace(stations, mid, K))
                right = mid;
            else
                left = mid;
        }
        return left;
    }
};