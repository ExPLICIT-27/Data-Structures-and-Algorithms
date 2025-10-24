
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        unordered_map<int, int> mp;
        int curr_sum = 0;
        int n = arr.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            curr_sum += arr[i];
            if(curr_sum == 0)
                res = max(res, i + 1);
            if(mp.count(curr_sum))
                res = max(res, i - mp[curr_sum]);
            else
                mp[curr_sum] = i;
        }
        return res;
    }
};