#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> cnt(10, 0);

        while(n){
            int d = n%10;
            cnt[d]++;
            n /= 10;
        }

        int ans = 0;

        for(int i = 1; i <= 9; i++)
            ans += i*cnt[i];

        return ans;
    }
};