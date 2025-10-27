#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool canAllot(vector<int> &stalls, int k,long long thresh){
        k--;
        long long dist = 0;
        for(int i = 1; i < stalls.size(); i++){
            if(k <= 0)
                return true;
            dist += stalls[i] - stalls[i - 1];
            if(dist >= thresh){
                k--;
                dist = 0;
            }
        }
        return k == 0;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        long long left = 0, right = stalls.back() - stalls[0] + 1;
        
        while(left <= right){
            long long mid = (left + right)/2;
            if(canAllot(stalls, k, mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
};