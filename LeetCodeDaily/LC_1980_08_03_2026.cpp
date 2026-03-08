#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(), nums.end());

        int curr = 0;
        int n = nums.size();
        auto getInt = [&](string &s) {
            int num = 0;

            for(int i = 0; i < n; i++){
                if(s[i] == '1')
                    num |= (1 << (n - i - 1));
            }

            return num;
        };
        auto getStr = [&](int num) {
            string str = "";

            while(num){
                str += string(1, '0' + num%2);
                num /= 2;
            }
            int diff = n - str.size();

            while(diff--)
                str += string(1, '0');
            reverse(str.begin(), str.end());

            return str;
        };
        for(string &s : nums){
            if(curr != getInt(s)){
                return getStr(curr);
            }
            curr++;
        }

        return getStr(curr);

    }
};