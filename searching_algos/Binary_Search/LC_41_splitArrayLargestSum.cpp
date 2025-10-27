// same logic for painter's partition, allocate books

#include <bits/stdc++.h>

using namespace std;

/*
minimize the largest split sum
a non negative integer array of size n
k >= 1, max nums.length, each case only one possible split
DP
    i can choose to make a split at a given index or move forward without splitting
    if i choose to split, and the number of splits becomes equal to k,
    return the ans
how to go about the solution: => MAJOR HINT: Max of min, min of max entitles binary search most times
consider a limiting sum value for each partition:
if a partition exceedes the limiting sum value, then dont allocate
allocate to next parttiion
Lower point : => largest value in the array
Highest point : => smallest value in the array, perform binary search
*/


class Solution {
public:
    bool trySplit(vector<int> &nums, int limit, int k){
        int partitions = 1;
        int currsum = 0;
        for(int i = 0; i < nums.size() && partitions <= k; i++){
            if(currsum + nums[i] <= limit){
                currsum += nums[i];
            }
            else{
                partitions++;
                currsum = nums[i];
            }
            if(partitions > k)
                return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k == 1)
            return accumulate(nums.begin(), nums.end(), 0);
        if(k == nums.size())
            return *max_element(nums.begin(), nums.end());
        int left = *max_element(nums.begin(), nums.end()), right = accumulate(nums.begin(), nums.end(), 0);
        while(left <= right){
            int mid = (left + right)/2;
            if(trySplit(nums, mid, k)){
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return left;
    }
    
};