// 633. Sum of Square Numbers
// Solved
// Medium
// Topics
// Companies
// Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 

// Example 1:

// Input: c = 5
// Output: true
// Explanation: 1 * 1 + 2 * 2 = 5
// Example 2:

// Input: c = 3
// Output: false
 

// Constraints:

// 0 <= c <= 231 - 1
#include <iostream>
#include <math.h>
using namespace std;
bool validSum(long long int c){
    long long int left = 0;
    long long int right = (int)pow(c, 0.5);
    long long int sum;
    while(left <= right){
        sum = (pow(left, 2) + pow(right, 2));
        if(sum == c){
            return true;
        }
        else if(sum < c){
            left++;
        }
        else{
            right--;
        }
    }
    return false;
}
int main(){
    return 0;
}