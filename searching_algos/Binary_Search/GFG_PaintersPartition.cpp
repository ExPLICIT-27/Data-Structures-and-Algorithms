#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool canAllot(vector<int> &arr, int k, int t){
        int curr = 0;
        int painters = 1;
        for(int i = 0; i < arr.size(); i++){
            if(curr + arr[i] > t){
                curr = arr[i];
                painters++;
            }
            else
                curr += arr[i];
            if(painters > k)
                return false;
        }
        return true;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int left = arr[0], right = 0;
        for(int i : arr){
            left = max(left, i);
            right += i;
        }
        
        while(left <= right){
            int mid = (left + right)/2;
            if(canAllot(arr, k, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};