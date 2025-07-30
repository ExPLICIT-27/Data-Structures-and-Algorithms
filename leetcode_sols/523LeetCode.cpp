// Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

// A good subarray is a subarray where:

// its length is at least two, and
// the sum of the elements of the subarray is a multiple of k.
// Note that:

// A subarray is a contiguous part of the array.
// An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
 

// Example 1:

// Input: nums = [23,2,4,6,7], k = 6
// Output: true
// Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
// Example 2:

// Input: nums = [23,2,6,4,7], k = 6
// Output: true
// Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
// 42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
// Example 3:

// Input: nums = [23,2,6,4,7], k = 13
// Output: false
// USing HashMaps aka dictionaries to implement the solution
// using prefix sum array to find the solution (in prefix sum array
// to find sum of subarray of from i to j+1 subtract i th from j th
// element of the subarray)
// if the sub array sum is divisible by the number, it means
// their remainders of the first and last element of the subarray
// would be the same -> leetcode proof is given
#include <iostream>
#include <map>
#include <vector>
using namespace std;
bool KSumSubArray(vector <int> nums, int k){
    map <int, int> remainders;
    remainders[0] = -1;
    int modulo = 0;
    for(int i = 0; i < nums.size(); i++){
        modulo = (modulo+nums[i])%k;
        if(remainders.find(modulo) != remainders.end()){
            if(i-remainders[modulo] > 1){
                return true;
            }
        }
        else{
            remainders[modulo] = i;
        }
    }
}
int main(){
    return 0;
}