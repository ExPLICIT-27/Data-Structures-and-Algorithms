// 330. Patching Array
// Solved
// Hard
// Topics
// Companies
// Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.

// Return the minimum number of patches required.

 

// Example 1:

// Input: nums = [1,3], n = 6
// Output: 1
// Explanation:
// Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
// Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
// Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
// So we only need 1 patch.
// Example 2:

// Input: nums = [1,5,10], n = 20
// Output: 2
// Explanation: The two patches can be [2, 4].
// Example 3:

// Input: nums = [1,2,2], n = 5
// Output: 0
 

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 104
// nums is sorted in ascending order.
// 1 <= n <= 231 - 1


// Idea for the solution:
// We keep track of a minimum required patch "miss" starting with 1.
// use a while loop with condition miss <= n.
// Inside while loop, if i < nums.size() and the current element (nums[i])
// is smaller than or equal to miss, we increment miss by that number
// signifying we can obtain sums upto miss by utilising that number
// else we double miss (increment it by itself) (thereby signifying
// that we need to patch a number equal to miss), so we also increment
// the answer patches by 1. Finally we return patches
#include <iostream>
#include <vector>
using namespace std;
int MinPatches(vector <int> &nums, int n){
    long long int miss = 1;
    int i = 0;
    int patches = 0;
    while(miss <= n){
        if((i < nums.size()) && (nums[i] <= miss)){
            miss += nums[i];
            i++;
        }
        else{
            patches++;
            miss += miss;
        }
    }
    return patches;
}
int main(){
    return 0;
}