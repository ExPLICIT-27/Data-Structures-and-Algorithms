/*
core logic:
Observations
1. The median lies between the smallest element and the greatest element in
the matrix
2. if the total number of elements in the matrix is n, then the total number
of elements in the matrix that is less than or equal to the median is (n/2 + 1)
minimum (there can be more, but at least n/2 + 1)
3. Hence the median would turn out to be the smallest element that satisfies this
condition

Conclusion
1. Binary search over smallest and largest element
2. Find the number of elements in each row greater than or equal to the current
mid
3. check count, shift low, high pointers accordingly
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rb(vector<int> &a, int t){
        int l = 0, r = a.size() - 1;
        while(l <= r){
            int m = (l + r)/2;
            
            if(a[m] > t)
                r = m - 1;
            else
                l = m + 1;
        }
        return r;
    }
    int lessEq(vector<vector<int>> &m, int t){
        int cnt = 0;
        for(auto &a : m){
            cnt += (rb(a, t)) + 1;
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        int low = mat[0][0], high = mat[0].back();
        
        int n = mat.size(), m = mat[0].size();
        for(int i = 1; i < n; i++){
            low = min(low, mat[i][0]);
            high = max(high, mat[i].back());
        }
        int thresh = n*m/2 + 1;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            int cnt = lessEq(mat, mid);
            if(cnt >= thresh)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
        
    }
};
