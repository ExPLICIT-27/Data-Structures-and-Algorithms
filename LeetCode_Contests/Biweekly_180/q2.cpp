#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;

        for(int i : nums){
            while(i){
                int d = i%10;
                if(d == digit)
                    ans++;
                i/=10;
            }
        }

        return ans;
    }
};