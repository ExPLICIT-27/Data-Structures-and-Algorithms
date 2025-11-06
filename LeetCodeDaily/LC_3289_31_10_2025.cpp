#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2;

        // x + y
        int a = accumulate(nums.begin(), nums.end(), 0) - n*(n - 1)/2;

        // x1x2
        int c = (a*a + n*(n - 1)*(2*n - 1)/6 - accumulate(nums.begin(), nums.end(), 0, [](int acc, int val){
            return acc + val*val;
        }))/2;
        int d = a*a*1.0 - 4*c*1.0;
        if(d < 0)
            d = 0;
        int x1 = (a + sqrt(d))/2.0;
        int x2 = (a - sqrt(d))/2.0;
        return {x1, x2};
    }
};