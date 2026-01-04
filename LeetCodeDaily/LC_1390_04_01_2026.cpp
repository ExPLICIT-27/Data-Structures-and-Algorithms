#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumDiv(int n){
        int cnt = 2;
        int total = 1 + n;

        for(int i = 2; i*i <= n; i++){
            if(n%i == 0){
                if(i == n/i){
                    cnt++;
                    total += i;
                }
                else{
                    total += (i + n/i);
                    cnt += 2;
                }
            }
            if(cnt > 4)
                return 0;
        }

        return (cnt == 4)? total : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i : nums){
            if(i > 5)
                ans += sumDiv(i);
        }

        return ans;
    }
};