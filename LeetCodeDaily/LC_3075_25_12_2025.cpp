#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long maximumHappinessSum(vector<int>& H, int K) {
        sort(H.begin(), H.end(), greater<int>());
        long long ans = 0;
        int cnt = 0;
        for(int i = 0; i < K && H[i] - cnt > 0; i++, cnt++){
            ans += 1ll*H[i] - cnt;
        }

        return ans;
    }
};