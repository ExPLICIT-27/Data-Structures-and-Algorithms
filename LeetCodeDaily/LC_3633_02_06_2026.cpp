#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int earliestFinishTime(vector<int>& land_st, vector<int>& land_dur, vector<int>& water_st, vector<int>& water_dur) {
        /*
                -------
------      --- -- --- ---- 

        sort both
        */
        // choose land with best finish time, find best combination for it
        // choose water with best finish time, find best combo for it

        int best_landet = INT_MAX, best_wateret = INT_MAX, ans = INT_MAX;

        int n = land_dur.size(), m = water_dur.size();

        for(int i = 0; i < n; i++)
            best_landet = min(best_landet, land_dur[i] + land_st[i]);
        
        for(int i = 0; i < m; i++)  
            best_wateret = min(best_wateret, water_dur[i] + water_st[i]);
        
        for(int i = 0; i < m; i++)
            ans = min(ans, max(best_landet, water_st[i]) + water_dur[i]);
        for(int i = 0; i < n; i++)
            ans = min(ans, max(best_wateret, land_st[i]) + land_dur[i]);
        
        return ans;
    }   
};