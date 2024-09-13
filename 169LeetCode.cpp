// 169. Majority Element
// Solved
// Easy
// Topics
// Companies
// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

// ALGORITHM ON WHICH THE ANSWER IS BASED
 // The best solution will be of the Moores voting algorithm
 // point your ans to the first element of the array
 // create a count variable and initialise it to 0
 // if you see the ans again increment the count
 // else decrement the count
 // if the count becomes 0, then assign your answer to the current 
 //element of the array you are it and reset the count to 1
 // you will obtain the ans to be the element with the highest
 // occurances
 #include <iostream>
 #include <vector>
 using namespace std;
int MajorityElement(vector <int> nums){
    int count = 1;
    int element = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(element == nums[i]){
            count++;
        }
        else{
            count--;
        }
        if(!count){
            count = 1;
            element = nums[i];
        }
    }
    return element;
}
int main(){
    return 0;
}