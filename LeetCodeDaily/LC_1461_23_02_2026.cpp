#include <bits/stdc++.h>

using namespace std;


#define ll long long
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        ll N = 1ll << k;

        int n = s.size();

        if(n - k + 1 < N)
            return false;
        
        unordered_set<int> S;

        ll curr = 0;
        for(int i = 0; i < k; i++){
            if(s[i] == '1')
                curr |= (1ll << (k - i - 1));
        }
        S.insert(curr);

        for(int i = k; i < n; i++){
            curr <<= 1;
            curr &= (N - 1);
            if(s[i] == '1')
                curr |= 1;
            S.insert(curr);
        }

        return S.size() == N;
    }
};