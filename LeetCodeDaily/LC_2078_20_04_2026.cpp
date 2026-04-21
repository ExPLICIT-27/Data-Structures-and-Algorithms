#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int first = colors[0], last = colors[n - 1];

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(first != colors[i])
                ans = max(ans, i);
            if(last != colors[i])
                ans = max(ans, n - i - 1);
        }

        return ans;
    }
};