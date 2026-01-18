#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    const int MOD = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int H = hFences.size(), V = vFences.size();

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> S;
        for(int i = 0; i < H; i++){
            for(int j = i; j < H; j++){
                int left = (i - 1 < 0)? 1 : hFences[i - 1];
                int right = (j + 1 >= H)? m : hFences[j + 1];
                S.insert(right - left);
            }
        }
        S.insert(hFences[0] - 1);
        for(int i = 1; i < H; i++)
            S.insert(hFences[i] - hFences[i - 1]);
        S.insert(m - hFences[H - 1]);
        long long ans = -1;
        for(int i = 0; i < V; i++){
            for(int j = i; j < V; j++){
                int left = (i - 1 < 0)? 1 : vFences[i - 1];
                int right = (j + 1 >= V)? n : vFences[j + 1];
                int tar = right - left;

                if(S.count(tar))
                    ans = max(ans, 1ll*tar*tar);
            }
        }
        if(S.count(vFences[0] - 1)){
            int tar = vFences[0] - 1;
            ans = max(ans, 1ll*tar*tar);
        }
        for(int i = 1; i < V; i++){
            int tar = vFences[i] - vFences[i - 1];

            if(S.count(tar))
                ans = max(ans, 1ll*tar*tar);
        }
        if(S.count(n - vFences[V - 1])){
            int tar = n - vFences[V - 1];
            ans = max(ans, 1ll*tar*tar);
        }
        return ans == 0 ? -1 : ans%MOD;
    }
};