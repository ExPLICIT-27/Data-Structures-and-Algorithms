#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        char curr = 'N';

        string dir = "NESW";
        vector<int> mp(26, 0);
        
        for(int i = 0; i < 4; i++){
            mp[dir[i] - 'A'] = i;
        }

        int ans = 0;

        set<pair<int, int>> obs;
        for(auto &o : obstacles)
            obs.insert(make_pair(o[0], o[1]));
        
        auto isOk = [&](int x, int y) -> bool {
            return !obs.count({x, y});
        };

        int x = 0, y = 0, yinc = 1, xinc = 0, k;

        auto upd = [&](int cmd) -> void {
            if(cmd == -1)
                // turn right 90
                curr = dir[(mp[curr - 'A'] + 1)%4];
            else if(cmd == -2)
                curr = dir[(mp[curr - 'A'] - 1 + 4)%4];
            else{
                switch(curr){
                    case 'N':
                        xinc = 0, yinc = 1;
                        break;
                    case 'E':
                        xinc = 1, yinc = 0;
                        break;
                    case 'W':
                        xinc = -1, yinc = 0;
                        break;
                    case 'S':
                        xinc = 0, yinc = -1;
                        break;
                }

                for(int i = 0; i < k; i++){
                    if(!isOk(x + xinc, y + yinc))
                        break;
                    x += xinc, y += yinc;
                }

                ans = max(ans, x*x + y*y);

            }
            
        };

        for(int c : commands){
            if(c > 0)
                k = c;
            upd(c);
        }

        return ans;
    }
};
