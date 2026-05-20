#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        
        function<int(int, int)> DnC;

        DnC = [&](int L, int R) -> int {
            if(L == R)
                return nums[L];
            
            if(nums[L] < nums[R])
                return nums[L];


            int m = (L + R)/2;

            return min(DnC(L, m), DnC(m + 1, R));
        };

        return DnC(0, nums.size() - 1);
    }
};