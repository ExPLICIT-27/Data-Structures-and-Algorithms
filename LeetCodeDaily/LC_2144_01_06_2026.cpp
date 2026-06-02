#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumCost(vector<int>& cost) {
        /*
        [2,2,5,6,7,9]
        
        */

        int n = cost.size();
        
        sort(cost.begin(), cost.end(), greater<int>());

        int ans = 0;
        
        for(int i = 0; i < n; i++){
            if((i + 1)%3 == 0)
                continue;
            ans += cost[i];
        }

        return ans;
    }
};