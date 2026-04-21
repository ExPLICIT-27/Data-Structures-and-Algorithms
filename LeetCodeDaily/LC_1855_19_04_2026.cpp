#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        int j = m - 1;
        int ans = 0;

        for(int i = n - 1; i >= 0; i--){
            while(j >= 0 && nums2[j] < nums1[i])
                j--;
            if(j >= 0 && nums2[j] >= nums1[i])
                ans = max(ans, j - i);
        }

        return ans;
        
    }
};