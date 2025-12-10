#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        int ans = 1;
        int n = complexity.size();
        for(int i = 1; i < n; i++){
            ans = (1ll*ans*i)%MOD;
            if(complexity[i] <= complexity[0])
                return 0;
        }
        return ans;
    }
};