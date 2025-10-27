/*
Blasphemous - nearly impossible to come up with on spot, truly genius soln
odd -> max(l1, l2)
even -> (max(l1, l2) + min(r1, r2)) / 2
*/
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    double findMedian(vector<int> &a1, vector<int> &a2, int n, int m){
        int l = 0, r = n;
        int h = (n + m + 1)/2;
        while(l <= r){
            int m1 = (l + r)/2;
            int m2 = h - m1;
            int r1 = (m1 >= n)? INT_MAX : a1[m1];
            int r2 = (m2 >= m)? INT_MAX : a2[m2];
            int l1 = (m1 <= 0)? INT_MIN : a1[m1 - 1];
            int l2 = (m2 <= 0)? INT_MIN : a2[m2 - 1];
            if(l1 > r2)
                r = m1 - 1;
            else if(l2 > r1)
                l = m1 + 1;
            else{
                if((n + m)%2)
                    return 1.0*max(l1, l2);
                else
                    return (max(l1, l2) + min(r1, r2))/2.0;
            }
        }
        return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n < m)
            return findMedian(nums1, nums2, n, m);
        return findMedian(nums2, nums1, m, n);
    }
};