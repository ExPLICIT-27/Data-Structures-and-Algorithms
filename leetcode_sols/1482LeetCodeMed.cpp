// You are given an integer array bloomDay, an integer m and an integer k.

// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 

// Example 1:

// Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
// Output: 3
// Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
// We need 3 bouquets each should contain 1 flower.
// After day 1: [x, _, _, _, _]   // we can only make one bouquet.
// After day 2: [x, _, _, _, x]   // we can only make two bouquets.
// After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
// Example 2:

// Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
// Output: -1
// Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
// Example 3:

// Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
// Output: 12
// Explanation: We need 2 bouquets each should have 3 flowers.
// Here is the garden after the 7 and 12 days:
// After day 7: [x, x, x, x, _, x, x]
// We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
// After day 12: [x, x, x, x, x, x, x]
// It is obvious that we can make two bouquets in different ways.
 

// Constraints:

// bloomDay.length == n
// 1 <= n <= 105
// 1 <= bloomDay[i] <= 109
// 1 <= m <= 106
// 1 <= k <= n

// Algorithm :
// Binary search is what is going to be used to solve this question
// We create a variable start initialise it to 0 and a variable
// end to the max value of our bloomDay array. 
// We create a while loop start <= end. We create and assign
// a mid value (start+end//2). This mid value is what we assume
// to be our minDays to bloom m bouqets. We pass this mid value
// along with the bloomday array to a function that returns the 
// number of bouqets that can be formed within 'mid' days.
// If the returned value is >= m, then there is a chance that
// there is a day earlier than mid that might be the minDay required
// hence we change end to mid-1 and continue. Else we need more
// days to make m bouqets so we change start to mid+1. This continues
// as long as start and end do not cross each other.
// For checking whether there are consecutive bouqets.
// We traverse orderly through each element of the array and
// check whether that specific element is <= our mid. If it is, then 
// it means that surely by the end of mid, it will have bloomed
// we increment our temporary count variable. If the element is
// greater than mid, we change count = 0. If at any stage, count exceeds
// k, then we increment the number of bouqets and make count 0 again.
#include <iostream>
#include <vector>
using namespace std;
int max(vector <int> &bloomDay){
    int mx = bloomDay[0];
    for(int day : bloomDay){
        if(day > mx){
            mx = day;
        }
    }
    return mx;
}
int consecutives(vector <int> &bloomDay, int mid, int k){
    int bouqets = 0;
    int count = 0;
    for(int day: bloomDay){
        if(day <= mid){
            count++;
        }
        else{
            count = 0;
        }
        if(count == k){
            bouqets++;
        }
    }
    return bouqets;
}
int numBouqets(vector <int> &bloomDay, int m, int k){
    if(bloomDay.size() < m*k){ //if so there arent even enough flowers to make the required number of bouqets
        return -1; 
    }
    int start = 0;
    int end = max(bloomDay);
    int minDays = -1; // if we cant make the req number of bouqets, minDays wont change and we can return -1 itself
    while(start <= end){
        int mid = (start+end)/2;
        if(consecutives(bloomDay, mid, k) >= m){
            minDays = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return minDays;
}
int main(){
    return 0;
}