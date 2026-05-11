#include <bits/stdc++.h>


using namespace std;
#define ll long long
class SGT{
    public:
    vector<ll> S;
    
    SGT(int n){
        S.resize(4*n + 1, 0);
    }

    void pointUpd(int i, int l, int r, int tar, ll val){
        if(l == r){
            S[i] = val;
            return;
        }

        int m = l + (r - l)/2;

        if(tar <= m)
            pointUpd(2*i + 1, l, m, tar, val);
        else
            pointUpd(2*i + 2, m + 1, r, tar, val);


        S[i] = max(S[2*i + 1], S[2*i + 2]);
    }

    ll rangeQuery(int i, int l, int r, int L, int R){
        if(l > R || r < L)
            return 0;
        
        if(l >= L && r <= R)    
            return S[i];
        
        int m = l + (r - l)/2;

        ll left = rangeQuery(2*i + 1, l, m, L, R);
        ll right = rangeQuery(2*i + 2, m + 1, r, L, R);

        return max(left, right);
    }

};


class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        /*
        previdx, curridx, isAsc => O(N^2*2)
        */
        
        /*
        okay leave previdx
        can i greedily select the previous largest index and previous smallest index?

        if i build the seg tree on the dp table then how would it work?
        do i need an n*2 array?
        [i][0] stores max value such that currently it is decreasin
        [i][1] stores max value such that its currently increasin

        okay, restrictions on selecting
        given i am at i,
        my choices lie only from 0 to i - k if it exists
        this condition can be easily met
        what do i do about the alternating shit tho

        given nums[i]
        from all j in the range(0, i - k)
        for dp[i][0] i should choose j such that dp[j][2] is maximised and
        nums[j] > nums[i]

        for dp[i][1], i should choose j such that dp[j][1] is maximised and 
        nums[j] < nums[i]

        ez

        but how do i choose efficiently???
        what is the job of my second loop
        its find the largest valid value such that
        its dp is maximised


        okay strat:
        since nums[i] <= 1e5, i can build the segtree on nums[i]
        and then query all elements from 0 to nums[i] - 1 for currently inc 
        and nums[i] + 1 to max(nums) for currently dec

        insert at lag K so that whenever i query the queries are valid

        */

        int n = nums.size();
        vector<vector<ll>> dp(n, vector<ll>(2));

        ll sz = *max_element(nums.begin(), nums.end());
        SGT s0(sz + 1), s1(sz + 1);
        
        ll ans = sz;
        for(int i = 0; i < n; i++){
            dp[i][0] = dp[i][1] = nums[i];
        }


        
        for(int i = k; i < n; i++){
            // i will insert only at lag k
            s0.pointUpd(0, 0, sz, nums[i - k], dp[i - k][0]);
            s1.pointUpd(0, 0, sz, nums[i - k], dp[i - k][1]);

            ll lessT = s1.rangeQuery(0, 0, sz, 0, nums[i] - 1);
            ll greatT = s0.rangeQuery(0, 0, sz, nums[i] + 1, sz);

            dp[i][0] = lessT + nums[i];
            dp[i][1] = greatT + nums[i];

            ans = max(ans, max(dp[i][0], dp[i][1]));

        }

        return ans;

    }
};
// YOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO NICEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE