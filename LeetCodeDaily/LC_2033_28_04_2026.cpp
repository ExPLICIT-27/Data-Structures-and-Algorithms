#include <bits/stdc++.h>

using namespace std;


#define ll long long
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();

        int sz = m*n;
        vector<ll> A(sz);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
                A[i*n + j] = grid[i][j];
        }

        nth_element(A.begin(), A.begin() + sz/2, A.end()); 
        // nth element -> partial sorting algo, which finds the element which 
        // would be in the second argument if it was sorted in linear time

        int mid = A[sz/2];
        
        int rem = mid%x;

        int ans = 0;

        for(int i : A){
            if(i%x != rem)
                return -1;
            
            ans += abs(mid - i)/x;
        }

        return ans;
        
    }
};
/*
a + cx = v
b + dx = v
v - b)
*/