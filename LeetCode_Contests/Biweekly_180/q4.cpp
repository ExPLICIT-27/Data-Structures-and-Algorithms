#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    const int M = 1e9 + 7;
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();

        vector<pair<int, int>> S(n);

        for(int i = 0; i < n; i++)
            S[i] = {nums1[i], nums0[i]};
        
        sort(S.begin(), S.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            if(a.second == 0 && b.second == 0) // strict irreflixive property for comparators -> comp(a, a) SHOULD return false, lol
                return false;
            if(a.second == 0)
                return true;
            if(b.second == 0)
                return false;

            if(a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        });

        long long res = 0;
        const int M = 1e9 + 7;
        for(auto &[ones, zeros] : S){
            for(int i = 0; i < ones; i++)
                res = (res*2%M + 1)%M;
            for(int i = 0; i < zeros; i++)
                res = (res*2%M)%M;
        }

        return res%M;
        
            
    }
};