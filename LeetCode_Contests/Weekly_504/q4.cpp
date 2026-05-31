#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n = nums.size();
        
        multiset<int> sback;
        set<int> smex;

        for(int i : nums)
            sback.insert(i);

        for(int i = 0; i <= n; i++)
            smex.insert(i);
        
        vector<int> res;
        int cmex = 0;
        int prev = 0;
        
        for(int i = 0; i < n; i++){
            if(smex.contains(nums[i]))
                smex.erase(nums[i]);
                
            sback.erase(sback.find(nums[i]));
            int cmex = *(smex.begin());

            
            if(sback.contains(cmex))
                continue;
            else{
                res.push_back(cmex);
                for(int j = prev; j <= i; j++)
                    smex.insert(nums[j]);
                prev = i + 1;
            }
        }

        return res;
        
    }
};