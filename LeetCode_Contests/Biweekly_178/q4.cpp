#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    vector<bool> vsum;
    ll dp[16][145][2];
    Solution(){
        vsum.assign(145, false);
        for(int i = 0; i <= 144; i++){
            if(isMonotonic(i))
                vsum[i] = true;
        }
    }
    bool isMonotonic(int n){
        string s = to_string(n);

        bool inc = true, dec = true;

        for(int i = 1; i < s.size(); i++){
            if(s[i] >= s[i - 1])
                dec = false;
            if(s[i] <= s[i - 1])
                inc = false;
        }

        return dec || inc;
    }
    ll helper(string &s, int i, bool tight, int sum){
        if(i == s.size()){
            if(vsum[sum])
                return 1;
            return 0;
        }
        if(dp[i][sum][tight] != -1)
            return dp[i][sum][tight];

        int end = tight? s[i] - '0' : 9;    
        ll ans = 0;

        for(int d = 0; d <= end; d++){
            ans += helper(s, i + 1, tight && (d == end), sum + d);
        }

        return dp[i][sum][tight] = ans;
    }
    long long countFancy(long long l, long long r) {
        /*
        Observations

        The sum of any number will not exceed 9*16 as 10**15 has only 16 digits
        Hence the fancy numbers whose sum is good is limited to the values
        0 - 144. The number of such numbers can be computed using digit DP

        Now for strictly increasing/decreasing
        there are not many monotonic numbers in the range 0-10**15
        since every monotonic number has all different digits guaranteed, 
        the largest monotonic number will be of 10 digits
        formula for n digit monotonic number will be
        10Cn (choose n from 10) and arrange in ascending order/descending order (1 way only)
        if you choose 0 first, then its no longer n digit
        subtract those cases
        10Cn - 9C(n - 1) (fix 0 at front)

        summing over all n from 1 to 10, is not that large, 
        around 2000 numbers exist globally (1024 for inc, 1024 for dec approx)
        The number of such numbers can be computed using BFS, with starting input as 1, 2..9
        and then removing numbers < L from the set

        Finally we return the answer to be value obtained using DP + monotonic numbers 
        obtained using BFS not including DP obtained values (which can be checked by computing their sum and checking for monotonicity)
        */

        // precompute monotonic digit sums -> constructor
        string L = to_string(l - 1), R = to_string(r);
        memset(dp, -1, sizeof(dp));
        ll monotonic_sums = helper(R, 0, 1, 0);
        memset(dp, -1, sizeof(dp));
        monotonic_sums -= helper(L, 0, 1, 0);

        unordered_set<ll> monotonic_set;

        queue<ll> Q;

        for(ll i = 1; i < 10; i++){
            monotonic_set.insert(i);
            Q.push(i);
        }
        ll max_limit = 1e10 - 1;
        // do increasing
        while(!Q.empty()){
            ll curr = Q.front();
            Q.pop();

            int prev = curr%10;

            for(int d = prev + 1; d <= 9; d++){
                int new_d = curr*10 + d;
                if(!monotonic_set.count(new_d) && new_d <= r && new_d < max_limit){
                    Q.push(new_d);
                    monotonic_set.insert(new_d);
                }
            }
        }
        for(int i = 1; i < 10; i++)
            Q.push(i);

        // do decreasing
        while(!Q.empty()){
            ll curr = Q.front();
            Q.pop();

            int prev = curr%10;

            for(int d = prev - 1; d >= 0; d--){
                int new_d = curr*10 + d;
                if(!monotonic_set.count(new_d) && new_d <= r && new_d < max_limit){
                    Q.push(new_d);
                    monotonic_set.insert(new_d);
                }
            }
        }
        // remove elements < L and elements whose digit sum is monotonic
        
        auto getSum = [&](int num){
            int ans = 0;
            while(num){
                ans += num%10;
                num /= 10;
            }

            return ans;
        };

        ll valid_cnts = 0;
        for(ll i : monotonic_set){
            if(i < l || vsum[getSum(i)])
                continue;
            valid_cnts++;
        }


        
        return monotonic_sums + valid_cnts;
    }
};