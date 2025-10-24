/*
left and right bisect, then subtract 
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int lb(vector<int> &a, int t){
        int l = 0, r = a.size() - 1;
        while(l <= r){
            int mid = (l + r)/2;
            
            if(a[mid] >= t)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
    int rb(vector<int> &a, int t){
        int l = 0, r = a.size() - 1;
        while(l <= r){
            int mid = (l + r)/2;
            
            if(a[mid] <= t)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r;
    }
    int countFreq(vector<int>& arr, int target) {
        int l = lb(arr, target);
        if(arr[l] != target)
            return 0;
        int r = rb(arr, target);
        return r - l + 1;
    }
};
