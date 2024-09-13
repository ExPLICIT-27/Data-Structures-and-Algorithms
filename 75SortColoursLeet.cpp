// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.
 
// Solution Using Dutch National Flag Algorithm;
// For image explanation visit geeksForgeeks
// Create 3 pointers, low mid and high
// initialise low and mid to 0 and high to the last index
// while mid <= high , check the value of arr[mid]
// if arr[mid] == 0, then swap(arr[low], arr[mid]) and increment 
// low and mid by one
// if arr[mid] == 1, then just increment mid by 1
// if arr[mide] == 2, swap(arr[mid], arr[high]) and decrement high by 1
#include <iostream>
#include <vector> 
using namespace std;
void DutchNationalFlag(vector <int> &arr){
    int low = 0; int mid = 0;
    int high = arr.size()-1;
    int temp;
    while(mid <= high){
        switch(arr[mid]){
            case 0:
                temp = arr[low];
                arr[low] = arr[mid];
                arr[mid] = temp;
                low++, mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                temp = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp;
                high--;
                break;
        }
    }
}
int main(){
    return 0;
}