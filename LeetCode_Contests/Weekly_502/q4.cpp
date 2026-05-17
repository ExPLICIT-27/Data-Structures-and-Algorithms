#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

#define ll long long
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        /*
        unique subarray
        rolling hash or sum -> 

        length 1, 2, 3
        O(n) is check is possible
        via a rolling hash or sum


        
        */

        int n = nums.size();
      

        const ll m1 = 1e9 + 7, m2 = 1e9 + 9;

        // going from mn to n is a bottleneck
        
        int L = 1, R = n;
        while(L <= R){
            
            int len = L + (R - L)/2;
            ll rh1 = 0, d1 = 1000003, h1 = 1; // googled these, first 2 primes over 1e5
            ll rh2 = 0, d2 = 1000159, h2 = 1;

            unordered_map<ll, int> mp1, mp2;
            for(int i = 0; i < len - 1; i++){
                h1 = __int128(h1*d1)%m1;
                h2 = __int128(h2*d2)%m2;
            }

            for(int i = 0; i < len; i++){
                rh1 = ((__int128((__int128)rh1*d1%m1 + nums[i])%m1 + m1))%m1;
                rh2 = ((__int128((__int128)rh2*d2%m2 + nums[i])%m2 + m2))%m2;
            }

            mp1[rh1]++, mp2[rh2]++;

            for(int i = len; i < n; i++){
                rh1 = ((__int128(((__int128)rh1 - (__int128)nums[i - len]*h1)*d1%m1 + nums[i])%m1) + m1)%m1;
                rh2 = ((__int128(((__int128)rh2 - (__int128)nums[i - len]*h2)*d2%m2 + nums[i])%m2) + m2)%m2;

                mp1[rh1]++, mp2[rh2]++;
            }

            bool ok1 = false, ok2 = false;
            for(auto &[x, y] : mp1){
                if(y == 1){
                    ok1 = true;
                    break;
                }
            }

            for(auto &[x, y] : mp2){
                if(y == 1){
                    ok2 = true;
                    break;
                }
            }

            if(ok1 && ok2)
                R = len - 1;
            else
                L = len + 1;
        }

        return L;
    }
};