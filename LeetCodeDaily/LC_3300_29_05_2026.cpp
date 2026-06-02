#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minElement(vector<int>& nums) {
        
        auto getSum = [](int n) -> int {
            int sum = 0;
            while(n){
                sum += n%10;
                n /= 10;
            }
            
            return sum;
        };

        int ans = INT_MAX;
        for(int i : nums){
            ans = min(ans, getSum(i));
        }

        return ans;
    }
};