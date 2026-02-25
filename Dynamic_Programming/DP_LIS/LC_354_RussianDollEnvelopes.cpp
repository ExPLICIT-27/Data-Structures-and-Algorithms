#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        /*
        core idea : sort based on asc width then height, and just perform lis 
        on height. But this may result in overcounting as the requirement is for strictly
        increasing width and height, 
        [5,4], [5, 7] will be put inside each other if we perform lis
        on height after sorting based on width in asc order. one way to get around this is 
        to sort in decreasing order of height when width is equal.

        my approach was based on the core idea, but i compared both width and height while making LIS, hence it passed everything but TLE'd due to it begin O(N^2)
        */
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b){
            if(a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1]; // to prevent overcounts
        });

        int n = envelopes.size();
    
        vector<int> dp;
        int res = 1;
        
        dp.push_back(envelopes[0][1]);

        for(int i = 1; i < n; i++){
            if(envelopes[i][1] > dp.back()){
                res++;
                dp.push_back(envelopes[i][1]);
            }
            else{
                auto lb = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
                dp[lb - dp.begin()] = envelopes[i][1];
            }
        }

        return res;
    }
};