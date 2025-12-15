#define ll long long
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        ll ans = 1;
        ll curr = 1;
        int n = prices.size();
        
        for(int i = 1; i < n; i++){
            if(prices[i] == prices[i - 1] - 1){
                curr++;
                ans = ans + curr;
            }
            else{
                curr = 1;
                ans = ans + curr;
            }
        }
        return ans;
        // 1 + 2 + 3 + 1
    }
};