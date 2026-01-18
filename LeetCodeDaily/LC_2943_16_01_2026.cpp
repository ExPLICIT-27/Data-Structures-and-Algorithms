#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int H = hBars.size(), V = vBars.size();

        int curr = 1;
        int hw = 1;
        for(int i = 1; i < H; i++){
            if(hBars[i] == hBars[i - 1] + 1)
                curr++;
            else
                curr = 1;
            hw = max(hw, curr);
        }

        int vw = 1;
        curr = 1;
        for(int i = 1; i < V; i++){
            if(vBars[i] == vBars[i - 1] + 1)
                curr++;
            else
                curr = 1;
            vw = max(vw, curr);
        }
        int ans = min(vw, hw);

        return (ans + 1)*(ans + 1);
    }
};
