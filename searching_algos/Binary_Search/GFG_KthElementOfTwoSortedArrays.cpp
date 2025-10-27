// binary search logic similar to the median qn
#include <bits/stdc++.h>

using namespace std;


class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n = a.size(), m = b.size();
        if(n > m) return kthElement(b, a, k);
        
        int l = max(0, k - m), r = min(k, n);
        int h = k;
        while(l <= r){
            int m1 = (l + r)/2;
            int m2 = k - m1;
            int r1 = (m1 >= n)? INT_MAX : a[m1];
            int r2 = (m2 >= m)? INT_MAX : b[m2];
            int l1 = (m1 <= 0)? INT_MIN : a[m1 - 1];
            int l2 = (m2 <= 0)? INT_MIN : b[m2 - 1];
            if(l1 > r2)
                r = m1 - 1;
            else if(l2 > r1)
                l = m1 + 1;
            else
                return max(l1, l2);
        }
        return -1;
    }
};
