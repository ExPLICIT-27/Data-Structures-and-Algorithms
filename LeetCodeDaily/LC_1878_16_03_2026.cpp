#include <bits/stdc++.h>

using namespace std;


#define ll long long
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<ll, greater<ll>> res;

        int m = grid.size(), n = grid[0].size();


        // expand rhombus from each point?
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int side_len = 0; (j + side_len < n && j - side_len >= 0) && (i + 2*side_len < m); side_len++){
                    ll total = 0;
                    int r = i, c = j;
                    for(int cnt = 0; cnt <= side_len; cnt++){
                        total += grid[r++][c--];
                    }
                    
                    r--, c++;
                    total -= grid[r][c];

                    for(int cnt = 0; cnt <= side_len; cnt++){
                        total += grid[r++][c++];
                    }
                    
                    r--, c--;
                    total -= grid[r][c];

                    for(int cnt = 0; cnt <= side_len; cnt++){
                        total += grid[r--][c++];
                    }
                    
                    r++, c--;
                    total -= grid[r][c];

                    for(int cnt = 0; cnt <= side_len; cnt++){
                        total += grid[r--][c--];
                    }
                    
                    r++, c++;
                    if(side_len > 0){
                        total -= grid[r][c];
                        
                    }
                    
                    
                    res.insert(total);

                    if(res.size() > 3)
                        res.erase(res.find(*res.rbegin()));
                }
            }
        }


        vector<int> ans;

        auto it = res.begin();
        for(int i = 0; i < 3 && it != res.end(); i++){
            ans.push_back(*it);
            ++it;
        }
        

        return ans;
    }
};