#include <bits/stdc++.h>
using namespace std;



#define ll long long
class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        /*
        nums is strictly increasing
        answer queries in O(1) or O(log(N))

        its strictly increasing
        
        li to ri i need to move
        if ri is the closest(x), then just return 1
        can i precompute closest indices
        bruh its always either x - 1 or x + 1

        
        */

        int n = nums.size();

        auto closest = [&](int x) -> int {
            if(x == 0)
                return 1;

            if(x == n - 1)
                return n - 2;

            int left = abs(nums[x] - nums[x - 1]), right = abs(nums[x] - nums[x + 1]);

            if(left < right)
                return x - 1;
            else if(right < left)
                return x + 1;

            return x - 1;
        };

        

        /*
        if l == r
            cost is 0

        if l < r
            i can keep moving rigth with a cost of 1 as long as closest is on the right
        else
            i can keep moving left with a cost of 1 as long as closest is on the left

        so i ago as far is i can, then 
        so precomputing the distance from each x to the end is the way to go
        for left and right
        */

        vector<ll> prel(n, 0), prer(n, 0);

        for(int i = 1; i < n; i++){
            int cl = closest(i);

            if(cl == i - 1)
                prel[i] = prel[i - 1] + 1;
            else
                prel[i] = prel[i - 1] + nums[i] - nums[i - 1];

            int ri = n - i - 1;
            cl = closest(ri);

            if(cl == ri + 1)
                prer[ri] = prer[ri + 1] + 1;
            else
                prer[ri] = prer[ri + 1] + nums[ri + 1] - nums[ri];
        }

       
        vector<int> ans;
        for(auto &q : queries){
            int l = q[0], r = q[1];

            if(l == r){
                ans.push_back(0);
                continue;
            }

            if(l < r)
                ans.push_back(int(prer[l] - prer[r]));
            else
                ans.push_back(int(prel[l] - prel[r]));
        }

        return ans;
    }
};