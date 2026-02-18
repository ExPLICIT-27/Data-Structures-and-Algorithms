#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
       // if n is perfectly alternating, if you do n >> 1, it produces the opposite alternating sequence
       // if you xor them, you get all ones
       // if you then AND the all ones with (all ones + 1), you should get 0
       long long all_ones = (n ^ (n >> 1));

       return (all_ones & (all_ones + 1)) == 0;
    }
};