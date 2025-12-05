#include <bits/stdc++.h>

using namespace std;
/*
you're always doing rightsum - 2*leftsum to check if its even,
hence if rightsum is even only then will there exist a partition
in conclusion, if the sum of the elements is even, ans is n - 1 else, 0
*/
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0)%2 ? 0 : nums.size() - 1;
    }
};