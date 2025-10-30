#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> p1(n), p2(n);
        for(int i = 0; i < n; i++){
            p1[i] = nums[i];
            if(i)
                p1[i] += p1[i - 1];
            p2[n - i - 1] = nums[n - i - 1];
            if((n - i - 1) < n - 1)
                p2[n - i - 1] += p2[n - i];
        }

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                int left = (i - 1 < 0)? 0 : p1[i - 1];
                int right = (i + 1 < n) ? p2[i + 1] : 0;
                if(right == left)
                    res += 2;
                else if(abs(right - left) == 1)
                    res++;
            }
        }
        return res;
    }
};