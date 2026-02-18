#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();

        if(n < m)
            a = string(m - n, '0') + a;
        if(m < n)
            b = string(n - m, '0') + b;

        string ans = "";
        int carry = 0;
        n = max(n, m);
        for(int i = n - 1; i >= 0; i--){
            int value = a[i] - '0' + b[i] - '0' + carry;

            ans += to_string(value%2);
            carry = value/2;
        }
        if(carry)
            ans += to_string(carry);
        
        reverse(ans.begin(), ans.end());

        return ans;


    }
};