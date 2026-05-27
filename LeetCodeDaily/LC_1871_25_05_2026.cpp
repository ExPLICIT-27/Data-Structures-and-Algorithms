#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        /*
        [min, max]
        */

        if(s.back() != '0')
            return false;
        
        vector<pair<int, int>> ranges;

        ranges.emplace_back(minJump, maxJump);


        auto BS = [&](int tar) -> bool {
            int L = 0, R = ranges.size() - 1;

            while(L <= R){
                int M = L + (R - L)/2;

                if(ranges[M].first <= tar && tar <= ranges[M].second)
                    return true;
                
                if(ranges[M].first > tar)
                    R = M - 1;
                else
                    L = M + 1;
            }
            return false;
        };

        int n = s.size();
        
        vector<bool> vis(n, false);
        vis[0] = true;
        for(int i = 1; i < n; i++){
            if(s[i] == '0'){
                if(BS(i)){
                    vis[i] = true;
                    ranges.emplace_back(i + minJump, i + maxJump);
                }
            }
        }

        return vis[n - 1];
    }
};