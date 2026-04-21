#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums) {
        /*
        even indices => prime
        odd => non prime
        */
        vector<bool> isP(1e5 + 1, 0);
        vector<int> primes;
        for(int i = 2; i <= 1e5; i++){
            bool ok = true;
            for(int j = 2; j*j <= i; j++){
                if(i%j == 0){
                    ok = false;
                    break;
                }
            }
            if(ok){
                isP[i] = 1;
                primes.push_back(i);
            }
        }
        
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(i & 1){
                if(!isP[nums[i]])
                    continue;
                if(nums[i] == 2)
                    ans += 2;
                else
                    ans++;
            }
            else{
                if(isP[nums[i]])
                    continue;
                if(nums[i] > primes.back()){
                    ans += (1e5+ 3 - nums[i]);
                    continue;
                }
                auto it = upper_bound(primes.begin(), primes.end(), nums[i]);

                ans += *it - nums[i];
            }
        }

        return ans;
    }
};