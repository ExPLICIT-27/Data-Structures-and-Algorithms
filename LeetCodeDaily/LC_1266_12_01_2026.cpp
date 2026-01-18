#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int x = points[0][0], y = points[0][1];

        int n = points.size();

        int ans = 0;
        for(int i = 1; i < n; i++){
            int d, r;
            if(abs(points[i][0] - x) < abs(points[i][1] - y)){
                // match x
                d = abs(points[i][0] - x);
                if(points[i][1] > y)
                    r = abs(points[i][1] - (y + d));
                else
                    r = abs(points[i][1] - (y - d));
            }
            else{
                d = abs(points[i][1] - y);
                if(points[i][0] > x)
                    r = abs(points[i][0] - (x + d));
                else
                    r = abs(points[i][0] - (x - d));
            }
            ans += (d + r);
            x = points[i][0], y = points[i][1];
        }

        return ans;
    }
};

// this converges to max diff between xx' and yy'
class Solution2 {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int x = points[0][0], y = points[0][1];

        int n = points.size();

        int ans = 0;
        for(int i = 1; i < n; i++){
            ans += max(abs(points[i][0] - x), abs(points[i][1] - y));
            x = points[i][0], y = points[i][1];
        }

        return ans;
    }
};