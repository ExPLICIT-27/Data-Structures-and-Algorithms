#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // a^k = b
        // xor with k on both sides
        // a = b^k, hence we search for this
        unordered_map<long long, long long> mp;
        int n = arr.size();
        long long curr = 0;
        long long res = 0;
        for(int i = 0; i < n; i++){
            curr ^= arr[i];
            if(curr == k)
                res++;
            if(mp.count(curr^k))
                res += mp[curr^k];
            mp[curr]++;
        }
        return res;
    }
};