#include <bits/stdc++.h>

using namespace std;


#define ll long long
class Solution {
public:
    
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();


        sort(nums.begin(), nums.end());
        int ans = n - 1;


        int i = 0;
        for(int j = 1; j < n; j++){
            if(1ll*nums[j] > 1ll*nums[i]*k)
                i++;
            else
                ans = min(ans, n - (j - i + 1));
        }
        return ans;
    }
};

// 1 2 6 9