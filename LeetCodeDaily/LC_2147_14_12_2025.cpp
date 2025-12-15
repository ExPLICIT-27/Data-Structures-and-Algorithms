#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfWays(string corridor) {
        ll numways = 0;
        vector<int> counts;
        int cnt = 0;
        int i = 0;
        int n = corridor.size();
        while(i < n){
            if(corridor[i] == 'S')
                cnt++;
            if(cnt == 2){
                i++;
                int t = 1;
                while(i < n && corridor[i] == 'P'){
                    t++;
                    i++;
                }
                counts.push_back(t);
                cnt = 0;
            }
            else
                i++;
        }
        if(cnt != 0 || counts.empty())
            return 0;
        if(corridor.back() != 'S')
            counts.pop_back();
        ll ans = 1;
        for(int i = 0; i < counts.size(); i++){
            ans = (ans*1ll*counts[i])%MOD;
        }
        return ans;


    }
};