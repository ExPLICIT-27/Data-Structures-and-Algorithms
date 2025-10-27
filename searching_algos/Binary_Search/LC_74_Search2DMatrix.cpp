#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int findRow(vector<vector<int>> &a, int t){
        int l = 0, r = a.size() - 1;
        while(l <= r){
            int m = (l + r)/2;
            if(a[m][0] == t)
                return m;
            if(a[m][0] > t)
                r = m - 1;
            else
                l = m + 1;
        }
        return r;
    }
    int findCol(vector<int> &a, int t){
        int l = 0, r = a.size() - 1;
        while(l <= r){
            int m = (l + r)/2;
            if(a[m] == t)
                return m;
            if(a[m] > t)
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& m, int t) {
        if(m[0][0] > t || m.back().back() < t)
            return false;
        
        int r = findRow(m, t);
        if(m[r][0] == t)
            return true;
        int c = findCol(m[r], t);
        return (c == -1)? false : true;
    }
};