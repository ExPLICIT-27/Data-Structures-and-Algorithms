#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isPoss(vector<int> &batteries, int extra, int n, long long mid, long long exsum){
        for(int i = extra; i < n; i++){
            if(batteries[i] < mid){
                long long diff = mid - batteries[i];
                if(diff > exsum)
                    return false;
                exsum -= diff;
            }
        }
        return true;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        if(n == 1)
            return accumulate(batteries.begin(), batteries.end(), 0ll);
        int extra = batteries.size() - n;
        long long extrasum = 0;
        for(int i = 0; i < extra; i++)
            extrasum += batteries[i];
        // try to make each value equal to something in the range
        // batteries[extra] to batteries[extra] + extrasum
        long long l = batteries[extra], r = batteries[extra] + extrasum;
        while(l <= r){
            long long m = (l + r)/2;
            if(isPoss(batteries, extra, batteries.size(), m, extrasum))
                l = m + 1;
            else
                r = m - 1;
        }
        return r;
    }
};
// when the active battery count reaches n - 1, no more batteries can be charged
// extra units of batteries : sz(batteries) - n
// find sum of extra battery packs, add them as evenly as possible to the others
// 2 2