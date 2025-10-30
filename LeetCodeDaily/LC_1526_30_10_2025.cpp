#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int res = target[0];
        int prev = target[0];
        for(int i = 1; i < n; i++){
            int curr = target[i];
            if(curr <= prev)
                prev = curr;
            else{
                res += (curr - prev);
                prev = curr;
            }
        }
        return res;
    }
};