#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& nt) {
        int i = 0;
        int n = colors.size();
        int mcost = 0;
        while(i < n){
            int j = i + 1;
            while(j < n && colors[j] == colors[j - 1])
                j++;
            if(j - i == 1){
                i++;
                continue;
            }
            int mx = nt[i], curr_sum = nt[i];
            for(int k = i + 1; k < j; k++){
                mx = max(mx, nt[k]);
                curr_sum += nt[k];
            }
            mcost += curr_sum - mx;
            i = j;
        }
        return mcost;
    }
};