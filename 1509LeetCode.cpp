// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given an integer array nums.

// In one move, you can choose one element of nums and change it to any value.

// Return the minimum difference between the largest and smallest value of nums after performing at most three moves.

 

// Example 1:

// Input: nums = [5,3,2,4]
// Output: 0
// Explanation: We can make at most 3 moves.
// In the first move, change 2 to 3. nums becomes [5,3,3,4].
// In the second move, change 4 to 3. nums becomes [5,3,3,3].
// In the third move, change 5 to 3. nums becomes [3,3,3,3].
// After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.
// Example 2:

// Input: nums = [1,5,0,10,14]
// Output: 1
// Explanation: We can make at most 3 moves.
// In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
// In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
// In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
// After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
// It can be shown that there is no way to make the difference 0 in 3 moves.
// Example 3:

// Input: nums = [3,100,20]
// Output: 0
// Explanation: We can make at most 3 moves.
// In the first move, change 100 to 7. nums becomes [3,7,20].
// In the second move, change 20 to 7. nums becomes [3,7,7].
// In the third move, change 3 to 7. nums becomes [7,7,7].
// After performing 3 moves, the difference between the minimum and maximum is 7 - 7 = 0.
 

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

// The solution involves sorting the array and trying a comibnation
// of removing elements from the back and front. (Remove 3 from back
// , remove 3 from front, remove 2 back one front and so on until we
// obtain the required minimum difference)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minDiff(vector <int> &nums){
    int min_diff = INT_MAX;
    if(nums.size() <= 4){
        return 0; // Since we have 3 moves, if the size of the array is less than or equal to 4, we can always change the elements such as to obtain 0 difference
    }
    for(int left = 0; left < 4; left++){ // this is a creative way of trying out the remove combinations
        int right = nums.size() - 4 + left;
        min_diff = ((nums[right]-nums[left]) < min_diff)? (nums[right]-nums[left]) : min_diff;
    }
    return min_diff;
}
int main(){
    return 0;
}