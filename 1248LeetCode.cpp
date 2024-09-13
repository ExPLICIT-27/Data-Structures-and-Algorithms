// 1248. Count Number of Nice Subarrays
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

 

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
// Example 2:

// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There are no odd numbers in the array.
// Example 3:

// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// Output: 16
 

// Constraints:

// 1 <= nums.length <= 50000
// 1 <= nums[i] <= 10^5
// 1 <= k <= nums.length
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int NiceArrays(vector <int> &nums, int k){
    map <int, int> hash_map;
    int curr_sum = 0;
    hash_map[0] = 1;
    int num_subarrs = 0;
    for(int i = 0; i < nums.size(); i++){
        curr_sum += (nums[i]%2);
        if(hash_map.find(curr_sum-k) != hash_map.end()){
            num_subarrs += hash_map[curr_sum-k];
        }
        if(hash_map.find(curr_sum) != hash_map.end()){
            hash_map[curr_sum] += 1;
        }
        else{
            hash_map[curr_sum] = 1;
        }
    }
    return num_subarrs;
}
int main(){
    vector <int> arr = {1, 1, 2, 1, 1};
    cout << NiceArrays(arr, 3);
    return 0;
}