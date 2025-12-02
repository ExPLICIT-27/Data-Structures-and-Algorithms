#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        vector<int> res;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[1] != b[1])
                return a[1] < b[1];
            return a[0] > b[0];
        });
        int cnt = 2;
        int cl = intervals[0][1] - 1, cr = intervals[0][1];
        int n = intervals.size();
        for(int i = 1; i < n; i++){
            int L = intervals[i][0], R = intervals[i][1];
            if(cl >= L) continue;
            cnt++;
            if(cr < L)
                cnt++;
            cl = (cr < L)? R - 1 : cr;
            cr = R;
        }
        return cnt;
    }
};
