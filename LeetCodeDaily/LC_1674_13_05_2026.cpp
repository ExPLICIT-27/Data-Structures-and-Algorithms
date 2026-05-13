#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        /*
        ans is in the range 2, 2*limit
        */

        int n = nums.size();
        int ans = 3*n;


        /*
        when would i need 2 moves
        3 cases -> figure out whether its 1 move, 2 moves or impossible

        comp[i] < target
            
        comp[i] == target
            0 moves
        comp[i] > target


        if min among 2 pairs, is > target - 1 -> 2 operations
        if max among 2 pairs < target - limit, -> 2 operations
        
        store minis and maxis of each pair, sort and then find these values
        */

        vector<int> minis, maxis;

        vector<int> cnt(2*limit + 1, 0);
        for(int i = 0; i < n/2; i++){
            int a = nums[i], b = nums[n - i - 1];

            if(a > b)
                swap(a, b);
            
            minis.push_back(a);
            maxis.push_back(b);
            
            if(a + b <= 2*limit)
                cnt[a + b]++;
        }

        sort(minis.begin(), minis.end());
        sort(maxis.begin(), maxis.end());

        for(int tar = 2; tar <= 2*limit; tar++){
            int curr = n/2; // 1 operation for every pair
            // now cnt extra ops required
            int left_ops = n/2 - (upper_bound(minis.begin(), minis.end(), tar - 1) - minis.begin());
            int right_ops = lower_bound(maxis.begin(), maxis.end(), tar - limit) - maxis.begin();

            ans = min(ans, curr + left_ops + right_ops - cnt[tar]);
            
        }
        return ans;

    }
};