#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        /*
        circular array only gives advantages to the elements at the end
        lookup tables + offline queries should work
        */

        unordered_map<int, vector<int>> mp;

        int n = nums.size();

        for(int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);
        
        vector<int> lookup(n, -1);

        for(auto &[x, y] : mp){
            if(y.size() == 1)
                continue;
            int m = y.size();

            lookup[y[0]] = min(y[1] - y[0], y[0] + n - y[m - 1]);

            for(int i = 1; i < m - 1; i++)
                lookup[y[i]] = min(y[i] - y[i - 1], y[i + 1] - y[i]);
            
            lookup[y[m - 1]] = min(y[m - 1] - y[m - 2], y[0] + n - y[m - 1]);
        }

        
        
        int q = queries.size();
        vector<int> ans(q);

        for(int i = 0; i < q; i++)
            ans[i] = lookup[queries[i]];
        
        return ans;
    }
};