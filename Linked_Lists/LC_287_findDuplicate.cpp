/*
this is an array qn, but requires detection of the starting point of cycle in a linked list
algorithm to detect the duplicate number.
No way to know this without actually trying it out on paper
*/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main(){
    return 0;
}