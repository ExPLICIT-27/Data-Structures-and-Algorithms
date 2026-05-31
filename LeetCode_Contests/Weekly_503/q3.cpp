#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        /*
        reverse the entire array
        or left shift by 1
        0,2,1
        2,1,0

        1,2,0
        3,4,5,1,2

        4,5,1,2,3
        */

        int n = nums.size();

        int c1 = 0, c2 = 0;
        int p; // loc of 0-
        // chck if arrays is sorted and rotated (asc or desc)

        if(nums[0] < nums[n - 1])
            c1++;
        else
            c2++;
        
        if(nums[0] == 0)
            p = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i - 1])
                c1++;
            else
                c2++;

            if(nums[i] == 0)
                p = i;
        }


        if(c1 > 1 && c2 > 1)
            return -1;
        
        int ans = n + 5;
        if(c1 <= 1){
            // cost to sort asc vs cost to sort desc
            // 3,4,5,0,1,2
            // sort asc cost = p
            // 2,1,0,3,4,5
            // sort desc cost = (n - p + 2)

            ans = min(ans, min(p, n - p + 2));
        }
        
        if(c2 <= 1){
            // sort desc vs asc
            // 3,2,0,5,4
            // 4,5,0,2,3
            ans = min(ans, min(p + 2, n - p));
        }

        return ans;
    }
};
/*
0,4,3,2,1
4,3,2,1,0

*/