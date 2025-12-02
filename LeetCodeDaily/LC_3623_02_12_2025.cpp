#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    const int MOD = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> mp;
        for(auto &p : points){
            mp[p[1]]++;
        }
        int ans = 0;
        int total = 0;
        for(auto [y, f] : mp){
            if(f < 2)
                continue;
            int ff = (1ll*f*(f - 1)/2)%MOD;
            total = (total + ff)%MOD;
        }
        for(auto [y, f] : mp){
            if(f < 2)
                continue;
            int ff = (1ll*f*(f - 1)/2)%MOD;
            total = ((total - ff)%MOD + MOD)%MOD;
            ans = (ans + (1ll*ff*total)%MOD)%MOD;
        }
        return ans;
    }
};
// map all the parallel lines : n*(n + 1)/2 trapezoids
// all same y coords?
// {0:3, 2:2}
//1...n, 1..m
//nC2*mC2