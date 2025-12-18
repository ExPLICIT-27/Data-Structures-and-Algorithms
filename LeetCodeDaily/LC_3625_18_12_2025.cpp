#include <bits/stdc++.h>

using namespace std;


#define ll long long
class Solution {
public:
    long long maxProfit(vector<int>& P, vector<int>& S, int k) {
        int n = P.size();
        vector<ll> PR(n);
        PR[0] = S[0]*P[0];
        vector<ll> P2(n);
        P2[0] = P[0];
        for(int i = 1; i < n; i++){
            PR[i] = PR[i - 1] + 1ll*S[i]*P[i];
            P2[i] = P2[i - 1] + 1ll*P[i];
        }
        ll ans = PR.back();
        ll final_ans = PR.back();
        for(int i = k - 1; i < n; i++){
            if(i == k - 1)
                final_ans = max(final_ans, ans - PR[i] + P2[i] - P2[i - k/2]);
            else
                final_ans = max(final_ans, ans - (PR[i] - PR[i - k]) + (P2[i] - P2[i - k/2]));
                // cout << PR[i] << " " << PR[i - k] << " " << P[i] << " " << P[i - k/2] << endl;
            
        }
        return final_ans;
    }
};