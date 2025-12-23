#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int UB(vector<vector<int>> &E, int T){
        int l = 0, r = E.size() - 1;
        while(l <= r){
            int m = (l + r)/2;

            if(E[m][0] <= T)
                l = m + 1;
            else
                r = m - 1;
        }
        return l;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        });
        int ans = 0;
        int n = events.size();
        vector<int> S(n);
        S.back() = events.back()[2];

        for(int i = n - 2; i >= 0; i--){
            S[i] = max(S[i + 1], events[i][2]);
        }
        for(int i = 0; i < n; i++){
            ans = max(ans, events[i][2]);
            
            if(events.back()[0] <= events[i][1])
                continue;
            int L = UB(events, events[i][1]);
            ans = max(ans, events[i][2] + S[L]);
        }

        return ans;
    }
};