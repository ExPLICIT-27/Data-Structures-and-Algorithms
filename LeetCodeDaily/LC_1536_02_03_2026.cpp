#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> Z(n);

        for(int i = 0; i < n; i++){
            int j = n - 1;

            while(j >= 0 && grid[i][j] == 0)
                j--;
            Z[i] = n - j - 1;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int req = n - i - 1;
            if(Z[i] >= req)
                continue;
            int target = -1;
            for(int j = i + 1; j < n; j++){
                if(Z[j] >= req){
                    target = j;
                    break;
                }
            }

            if(target == -1)
                return -1;
            int tmp = Z[target];
            ans += (target - i);
            for(int j = target - 1; j >= i; j--)
                Z[j + 1] = Z[j];
            Z[i] = tmp;
        }

        return ans;
    }
};

/*

N*N grid

-1 check

I need 1 row with at least n - 1 zeroes, at least n - 2 ... at least 1
if not present ans = -1


*/