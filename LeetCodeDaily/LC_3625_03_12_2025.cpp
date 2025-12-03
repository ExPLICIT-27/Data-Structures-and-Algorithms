// genuinely one of the most concept rich implementation heavy and satisfactory problems ever

#include <bits/stdc++.h>

using namespace std;

class Line{
    public:
        long long intercept, length;
        Line(long long intr, long long len){
            intercept = intr, length = len;
        }
};
class Solution {
public:  
    // slope normalization : to avoid precision errors, slope is calculated as a pair<x,y> new concept
    pair<int, int> normalSlope(vector<int> &A, vector<int> &B){
        int dy = A[1] - B[1], dx = A[0] - B[0];

        // vertical line
        if(dx == 0) return {1, 0};

        // horizontal line
        if(dy == 0) return {0, 1};


        int normal = gcd(abs(dx), abs(dy));

        dy /= normal;
        dx /= normal;


        if(dx < 0){
            dx = -dx;
            dy = -dy;
        }
        return {dy, dx};
    }
    int countTrapezoids(vector<vector<int>>& p) {
        // map of lines
        map<pair<int, int>, vector<Line>> mp;
        int n = p.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                auto slope = normalSlope(p[i], p[j]);
                int dx = p[i][0] - p[j][0];
                int dy = p[i][1] - p[j][1];
                long long len = 1ll*dx*dx + 1ll*dy*dy; // len for parallelogram checking
                /*
                y = mx + c
                y = dy*x/dx + c
                y*dx = dy*x + c*dx
                ydx - xdy = C

                here dx is normalized dx and dy is normalized dy
                */
                long long intercept = 1ll*p[i][1]*slope.second - 1ll*p[i][0]*slope.first;

                mp[slope].push_back(Line(intercept, len));
            }
        }

        long long ans = 0;
        long long pcount = 0;
        for(auto &[s, points] : mp){
            if(points.size() < 2)
                continue;
            int m = points.size();
            ans += 1ll*m*(m - 1)/2;

            unordered_map<long long, int> collinearLines;
            // length -> [intercept -> count], 2 lines of equal length and collinear means we subtract twice which is to be avoided
            unordered_map<long long, unordered_map<long long, int>> parallelograms;

            // count collinear lines and parallelograms
            for(auto &p : points){
                collinearLines[p.intercept]++;
                parallelograms[p.length][p.intercept]++;
            }

            for(auto &[x, y] : collinearLines){
                ans -= 1ll*y*(y - 1)/2;
            }

            for(auto &[l, ic] : parallelograms){
                long long samelen = 0;
                long long overcounts = 0;
                // samelen => total number of lines with the same length
                // within each intercept => lines with same length and same intercept aka collinear lines, we already subtracted, dont subtracted again
                for(auto &[intr, cnt] : ic){
                    samelen += cnt;
                    overcounts += 1ll*(cnt)*(cnt - 1)/2;
                }
                long long total = samelen*(samelen - 1)/2;
                pcount += total - overcounts;
            }
        }

        return ans - pcount/2;

    }
};
// group by slopes, 

// s1 : (1-2).(3-4), s2 : 1-2-5-4
// 