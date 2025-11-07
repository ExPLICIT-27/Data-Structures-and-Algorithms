#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isPossible(vector<long long> &a, long long limit, int r, int k, int n){
        vector<long long> diff(n + 1, 0);
        for(int i = 0; i < n; i++){
            if(i)
                diff[i] += diff[i - 1];
            int right = min(n, i + r + 1);
            int left = max(0, i - r);
            long long window = a[right] - a[left] + diff[i];

            if(window < limit){
                long long req = limit - window;
                if(k < req)
                    return false;
                diff[i] += req;
                k -= req;

                if(i + 2*r + 1 < n)
                    diff[i + 2*r + 1] -= req; // diff array logic
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> prefix(n + 1, 0);
        long long lo = 0, hi = k;
        for(int i = 1; i <= n; i++){
            hi += stations[i - 1];
            prefix[i] = stations[i - 1];
            if(i)
                prefix[i] += prefix[i - 1];
            
        }
        // set a limit for the maximum possible minimum power
        while(lo <= hi){
            long long m = (lo + hi)/2;
            if(isPossible(prefix, m, r, k, n))
                lo = m + 1;
            else
                hi = m - 1;
        }
        return hi;
    }
};
/*
each index i, 
received power from stations 
in the range sum(i - r, i + r)
this can be done in O(1) time using prefix sums
now i need to maximize the minimum of all these ranges
binary search, greedily place it at the latest possible within
each window, so that the next window can take advantage of it as well
*/