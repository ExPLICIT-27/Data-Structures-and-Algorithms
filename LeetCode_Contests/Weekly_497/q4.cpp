#include <bits/stdc++.h>
using namespace std;


class SGT{
    public:
    vector<int> S;

    SGT(int n){
        S.resize(4*n + 1, 0);
    }

    void upd(int idx, int low, int high, int target, int val){
        if(low == high){
            S[idx] = val;
            return;
        }

        int mid = (low + high)/2;

        if(target <= mid)
            upd(2*idx + 1, low, mid, target, val);
        else
            upd(2*idx + 2, mid + 1, high, target, val);
        
        S[idx] = gcd(S[2*idx + 1], S[2*idx + 2]);
    }

    int query(int idx, int low, int high, int L, int R){
        if(low > R || high < L)
            return 0;
        
        if(low >= L && high <= R)
            return S[idx];
        
        int mid = (low + high)/2;
        int left = query(2*idx + 1, low, mid, L, R);
        int right = query(2*idx + 2, mid + 1, high, L, R);

        return gcd(left, right);
    }
};
class Solution {
public:
    int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {
        /*
        lets see how can I find if a good subsequence exists in a decent amt of time
        
        its gcd should be p, so we can immediately not consider numbers that are not divisible by p
        if i choose all of them, i am guaranteed to get something whose gcd is minimal, the more numbers you choose, gcd never increases

        but then there's the stupid constraint which demands me to not take all no.s
        removing the largest among them should have the minimal effect- no
        removing the one with the largest no. of p's in it is optimal
        
        alr ill see to that,
        but how do i keep track of the running gcd
        IDIOT OBVIOUSLY A SEG TREE ON GCD

        okay ill brute force for the exceptional case where all elements are part of the 
        sequence
        otherwise just use seg tree
        
        maintain seg tree for divisors of p, others set it to 0
        gcd(0, a) = a, so its as if it doesnt exist there



        okay plain BF TLE's


        consider this
        good subsequence is the same as saying, after you divide every number who is divisible by p with p, you get gcd of those numbers to be 1

        suppose there are 7 such numbers
        for the gcd to increase after removing any 1 of them, i.e for it to be impossible to remove any 
        element without increasing gcd from p, 
        all numbers must have a prime factor such that it is present in all others except itself
        one such case for 7 numbers would be
        _ 5 7 11 13 17 19  if you remove this no gcd becomes 3 
        3 _ 7 11 13 17 19  if you remove this no gcd becomes 5
        3 5 _ 11 13 17 19  and so on
        3 5 7 _  13 17 19
        3 5 7 11 _  17 19
        3 5 7 11 13 _  19
        3 5 7 11 13 17 _
        3 5 7 11 13 17 19
        note that 3*5*7*11*13*17*19*p will surely exceed 5*10^4 which is the limit of each number given in qn
        hence its possible to remove a number if n > 6
        */

        int n = nums.size();
        SGT S(n);

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]%p == 0){
                S.upd(0, 0, n - 1, i, nums[i]);
                cnt++;
            }
        }

        int ans = 0;
        for(auto &q : queries){
            int idx = q[0], val = q[1];
            int prev = nums[idx];

            if(prev%p == 0)
                cnt--;
            if(val%p == 0)
                cnt++;
            nums[idx] = val;

            if(val%p != 0)
                val = 0;
            S.upd(0, 0, n - 1, idx, val);

            if(cnt < n || cnt > 6){ // or count > 6 is why this is a 7 ptr => ramseys theorem, if there are >= 6 numbers divisible by p, you can ALWAYS exclude 1 and still get gcd as p if gcd was already p
                if(S.query(0, 0, n - 1, 0, n - 1) == p)
                    ans++;
            }
            else{
                for(int i = 0; i < n; i++){
                    if(gcd(S.query(0, 0, n - 1, 0, i - 1), S.query(0, 0, n - 1, i + 1, n - 1)) == p){
                        ans++;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};