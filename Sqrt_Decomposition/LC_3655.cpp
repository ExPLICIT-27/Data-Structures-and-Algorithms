// kinda uses sqrt decomp idea
#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    const int M = 1e9 + 7;
    int binpow(int base, int p){
        int res = 1;

        while(p){
            if(p & 1)
                res = 1ll*res*base%M;
            base = 1ll*base*base%M;
            p >>= 1;
        }

        return res;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        /*
        difference array, but for like multiplication?
        mod inverse for division


        but the issue is k
        idx += ki is an issue
        [1, 4, 1, 1/4]
        [1,4,4,1]
        [1, 8, 24, 4]


        from l to r, with an increment of k,
        i need to update nums[i] to nums[i]*v[i]

        l, l + k, ...l + n*k, r

        how do i update in width of k????

        difference array is maintained such that i only multiply i with i - k instead of i - 1
        smort indeed
        */

        /*
        O(n*q) is expensive
        O(root(n)*q) is not

        we set a threshold
        if k >= root(n), less than root(n) els will be visited and we can use brute force
        otherwise we need to do something efficient
        we use diff arrays, 
        set diff[l] to diff[l]*v%M
        find last r that will be visited 
        l + n*k <= r
        n*k <= r - l
        n <= (r - l)/k
        hence, l + k*((r - l)/k) is the last effected index
        next of last affected index is
        l + k*((r - l)/k + 1)

        */


        int n = nums.size();
        int sqr = int(sqrt(n));
        vector<vector<vector<int>>> G(sqr);


        for(auto &q : queries){
            if(q[2] < sqr)
                G[q[2]].push_back(q);
            else{
                // brute force for k >= root(n)
                for(int i = q[0]; i <= q[1]; i += q[2])
                    nums[i] = 1ll*nums[i]*q[3]%M;
            }
        }

        vector<int> diff(n + sqr); // simply keeping n + sqrtn for no overflow

        for(int k = 0; k < sqr; k++){
            auto &g = G[k];
            if(g.empty())
                continue;
            
            fill(diff.begin(), diff.end(), 1);

            for(auto &q : g){
                int l = q[0], r = q[1], k = q[2], v = q[3];

                diff[l] = 1ll*diff[l]*v%M;

                // find next of last effected index
                int R = l + k*((r - l)/k + 1);
                diff[R] = 1ll*diff[R]*binpow(v, M - 2)%M;
            }
            

            // multiply with i - k not i - 1
            for(int i = k; i < n; i++)
                diff[i] = 1ll*diff[i]*diff[i - k]%M;
            

            for(int i = 0; i < n; i++)
                nums[i] = 1ll*nums[i]*diff[i]%M;
        }

        int xr = 0;

        for(int i : nums)
            xr ^= i;


        return xr;
    }
};