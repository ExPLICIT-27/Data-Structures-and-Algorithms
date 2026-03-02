#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b){
            int bits_a = __builtin_popcount(a);
            int bits_b = __builtin_popcount(b);

            if(bits_a != bits_b)
                return bits_a < bits_b;
            return a < b;
        });

        return arr;
    }
};