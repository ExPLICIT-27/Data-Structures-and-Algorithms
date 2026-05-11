#include <bits/stdc++.h>

using namespace std;


#define ll long long
class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        
        /*
        [li, ri, k] queries
        need to remove all even integers present in nums within that range

        nums is sorted
        then return the kth smallest integer remaining in the sequence

        sorted so im thinking binary search
        how about assigning ranks to the numbers

        rank of 2 = 1, 4 = 2 etc

        rank k i need to find
        this rank k will be k' due the removals

        the nums array might be missing numbers as well


        2,4,6,8,10,12,14,16,18,20...
        1 2 3 4  5  6  7  8  9 10
        
        1,_,_,2,_,3

        [1, 3, 4, 6, 10, 11, 19]
        */

        int n = nums.size();
        vector<int> ec(n + 1, 0);

        for(int i = 0; i < n; i++){
            ec[i + 1] = ec[i] + (nums[i] & 1 ^ 1);
        }

        vector<int> ans;

        for(auto &q : queries){
            ll l = q[0], r = q[1], k = q[2];

            if(1ll*2*k < nums[l]){
                ans.push_back(2*k);
                continue;
            }

            ll L = 0, R = k + nums[n - 1] + 1;
            ll curr;
            while(L <= R){
                ll M = L + (R - L)/2;

                /*
                find M's rank
                */

                auto it = lower_bound(nums.begin(), nums.end(), 2*M);

                ll rank;

                if(it == nums.end())
                    rank = M - (ec[r + 1] - ec[l]);
                else if(it == nums.begin()){
                    if(*it > 2*M)
                        rank = M;
                    else{
                        if(l == 0)
                            rank = M - ec[1];
                        else
                            rank = M;
                    }
                }
                else{
                    if(*it > 2*M)
                        --it;
                    
                    int idx = it - nums.begin();

                    if(idx < l)
                        rank = M;
                    else if(idx >= l && idx <= r)
                        rank = M - (ec[idx + 1] - ec[l]);
                    else
                        rank = M - (ec[r + 1] - ec[l]);
                }

                if(rank < k)
                    L = M + 1;
                else{
                    if(rank == k)
                        curr = 2*M;
                    R = M - 1;
                }
            }

            ans.push_back(int(curr));
        }

        
        return ans;
    }
};