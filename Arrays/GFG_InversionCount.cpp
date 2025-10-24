#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int merge(vector<int> &arr, vector<int> &left, vector<int> &right){
        int i = 0, l = 0, r = 0;
        int inv = 0;
        while(l < left.size() && r < right.size()){
            if(left[l] <= right[r])
                arr[i++] = left[l++];
            else{
                inv += left.size() - l;
                arr[i++] = right[r++];
            }
        }
        while(l < left.size())
            arr[i++] = left[l++];
        
        while(r < right.size())
            arr[i++] = right[r++];
        
        return inv;
    }
    int mergesort(vector<int> &arr){
        if(arr.size() <= 1)
            return 0;
        
        int n = arr.size();
        int half = n/2;
        vector<int> left(arr.begin(), arr.begin() + half);
        vector<int> right(arr.begin() + half, arr.end());
        
        return mergesort(left) + mergesort(right) + merge(arr, left, right);
    }
    int inversionCount(vector<int> &arr) {
        return mergesort(arr);
    }
};