#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        if(m <= 1)
            return m;
        int l = 1, r = m;
        while(l <= r){
            int mid = (l + r)/2;
            if(static_cast<long long>(pow(mid, n)) == m)
                return mid;
            if(static_cast<long long>(pow(mid, n)) > m)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1; // no integer x such that x^n = m
    }
};