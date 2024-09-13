// 1552. Magnetic Force Between Two Balls
// Solved
// Medium
// Topics
// Companies
// Hint
// In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

// Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

// Given the integer array position and the integer m. Return the required force.

 

// Example 1:


// Input: position = [1,2,3,4,7], m = 3
// Output: 3
// Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
// Example 2:

// Input: position = [5,4,3,2,1,1000000000], m = 2
// Output: 999999999
// Explanation: We can use baskets 1 and 1000000000.

// Solution Algorithm :
// What i thought was finding the max separation possible by using 
// the last element - first element/(m - 1) after sorting the array
// then if that is not possible, then keep decrementing the distance
// by 1 would take too long a time to execute. Hence the binary search
// algorithm for the space is prefered to be used.
// We create a leastSpace and maxSpace variable assigning the least
// and maximum possible spaces respectively. If it is possible we check
// for greater space, and element the left half of the chosen space midpoint
// and similarly , we eliminate the right half if the current space
// is not possible
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isPossible(vector <int> &position, int distance, int m){
    int balls_placed = 1;
    int prev_pos = position[0];
    int curr_pos;
    for(int i = 1; i < position.size(); i++){
        curr_pos = position[i];
        if((curr_pos-prev_pos) >= distance){
            balls_placed++;
            prev_pos = curr_pos;
        }
        if(balls_placed == m){
            return true;
        }
    }
    return false;
}
int MagneticForce(vector <int> &position, int m){
    sort(position.begin(), position.end());
    int lowest = 1;
    int highest = (position[position.size()-1]/(m-1))+1;
    int mid;
    int result = 0;
    while(lowest <= highest){
        mid = lowest + (highest - lowest)/2;
        if(isPossible(position, mid, m)){
            result = mid;
            lowest = mid + 1;
        }
        else{
            highest = mid - 1;
        }
    }
    return result;
}
int main(){
    return 0;
}