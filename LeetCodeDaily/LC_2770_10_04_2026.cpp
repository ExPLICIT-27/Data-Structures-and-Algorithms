#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        /*
        lmao j > i makes it easy to brute force
        */
        vector<int> dist(n, INT_MIN);
        dist[0] = 0;

        for(int i = 0; i < n; i++){
            if(dist[i] == INT_MIN)
                continue;
            for(int j = i + 1; j < n; j++){
                if(abs(nums[j] - nums[i]) <= target)
                    dist[j] = max(dist[j], 1 + dist[i]);
            }
        }

        return dist[n - 1] == INT_MIN ? -1 : dist[n - 1];
    }
};