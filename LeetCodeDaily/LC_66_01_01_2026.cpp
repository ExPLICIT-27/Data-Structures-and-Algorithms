#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans(n + 1);
        int carry = 1;
        for(int i = n - 1; i >= 0; i--){
            ans[i + 1] = (carry + digits[i])%10;
            carry = (carry + digits[i])/10;
        }
        if(carry){
            ans[0] = carry;
            return ans;
        }

        return vector<int>(ans.begin() + 1, ans.end());
    }
};