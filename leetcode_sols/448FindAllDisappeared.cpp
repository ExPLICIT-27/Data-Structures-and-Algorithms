// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]
// Example 2:

// Input: nums = [1,1]
// Output: [2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 105
// 1 <= nums[i] <= n

// The most apt solution with O(N) time complexity and O(1) space 
// complexity is the following
// Traverse through each element of the array.
// Since each element is within the range 1,n we change
// the array[abs(element)-1] position element to -element when we 
// come across each element, for duplicates we do not change
// the element if it is already negative
#include <iostream>
#include <vector>
using namespace std;
vector <int> missing(vector <int> &arr){
    vector <int> result;
    for(int i = 0; i < arr.size(); i++){
        if(arr[abs(arr[i])-1] > 0){
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
        }
    }
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > 0){
            result.push_back(i+1);
        }
    }
    return result;
}
int main(){
    return 0;
}