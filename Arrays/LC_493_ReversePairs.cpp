/*
same logic as inversion count, except
since the condition is different from a simple > 
we need to sort and count separately within the merge
*/
#include <bits/stdc++.h>
using namespace std;


/*
137259
137 259
123579
*/
class Solution {
public:
    int bs(vector<int> &a, int t){
        int l = 0, r = a.size() - 1;
        while(l <= r){
            int mid = (l + r)/2;
            if(1ll*2*a[mid] < t)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r;
    }
    int merge(vector<int> &arr, vector<int> &left, vector<int> &right){
        int revp = 0;
        for(int i = 0; i < left.size(); i++){
            if(1ll*2*right[0] >= left[i]) continue;
            revp += (bs(right, left[i]) + 1);
        }
        int i = 0, l = 0, r = 0;
        while(l < left.size() && r < right.size()){
            if(left[l] <= right[r])
                arr[i++] = left[l++];
            else{
                arr[i++] = right[r++];
            }
        }
        while(l < left.size())
            arr[i++] = left[l++];
        
        while(r < right.size())
            arr[i++] = right[r++];
        
        return revp;
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
    int reversePairs(vector<int>& nums) {
        return mergesort(nums);
    }
};