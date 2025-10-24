#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        long long sum1 = 1ll*n*(n + 1)/2;
        long long sum2 = 1ll*n*(n + 1)*(2*n + 1)/6;
        long long sum3 = accumulate(arr.begin(), arr.end(), 0ll);
        long long sum4 = accumulate(arr.begin(), arr.end(), 0ll, [](long long curr, int el){
            return curr + 1ll*el*el;
        });
        // y - x => y dup, x miss
        long long y_x = sum1 - sum3;
        // y^2 - x^2
        long long y2_x2 = sum2 - sum4;
        // y + x = (y^2 - x^2)/(y - x)
        long long yPx = y2_x2/y_x;
        // 2y
        long long y2 = y_x + yPx;
        long long y = y2/2;
        long long x = yPx - y;
        return {int(x), int(y)};
        
    }
};