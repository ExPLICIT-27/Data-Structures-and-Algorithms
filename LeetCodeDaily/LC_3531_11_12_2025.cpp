#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<pair<int, int>> X(n + 1, make_pair(-1, -1));
        vector<pair<int, int>> Y(n + 1, make_pair(-1, -1));
        // only store min, max for each x and y
        for(auto &b : buildings){
            if(X[b[0]].first == -1){
                X[b[0]].first = X[b[0]].second = b[1];
            }
            else
                X[b[0]].first = min(X[b[0]].first, b[1]), X[b[0]].second = max(X[b[0]].second, b[1]);
            if(Y[b[1]].first == -1){
                Y[b[1]].first = Y[b[1]].second = b[0];
            }
            else
                Y[b[1]].first = min(Y[b[1]].first, b[0]), Y[b[1]].second = max(Y[b[1]].second, b[0]);
        }
        
        int result = 0;
        // compare each building with min max across its x and y
        for(auto &b : buildings){
            if(X[b[0]].first < b[1] && X[b[0]].second > b[1] && Y[b[1]].first < b[0] && Y[b[1]].second > b[0])    
                result++;
        }
        return result;
    }
};