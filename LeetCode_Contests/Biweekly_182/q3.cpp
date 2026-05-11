#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
         /*
         select 2 distinct points, compute add them to the original set of points,
         */   
        set<vector<int>> vis(points.begin(), points.end());

        int k = 0;
        vector<vector<int>> prev;
        while(true){
            if(vis.find(target) != vis.end())
                return k;

            if(vis.size() == 1)
                break;


            vector<vector<int>> V(vis.begin(), vis.end());

            if(prev == V)
                return -1;


            for(int i = 0; i < V.size(); i++){
                for(int j = i + 1; j < V.size(); j++){
                    vector<int> tmp(3);
                    for(int k = 0; k < 3; k++)
                        tmp[k] = (V[i][k] + V[j][k])/2;
                    vis.insert(tmp);
                }
            }
            k++;
            prev = V;
        }

        return -1;
        
    }
};