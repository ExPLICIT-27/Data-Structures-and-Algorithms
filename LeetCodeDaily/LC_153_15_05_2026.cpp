#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'
class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
        rotating it makes it a valley
        \  /
         \/
         unique elements - so valley is a guarantee
         find dip using binary search on circular array
        */

        // dip condition -> nums[i - 1] > nums[i] < nums[i + 1]

        // compare nums[M] with nums[n - 1]
        // if < go left, else go right

        int n = nums.size();
        int L = 0, R = n - 1, pivot;

        auto getLeft = [&](int i) -> int {
            if(i == 0)
                return n - 1;
            return i - 1;
        };

        auto getRight = [&](int i) -> int {
            if(i == n - 1)
                return 0;

            return i + 1;
        };

        
        while(L <= R){
            int M = (L + R)/2;
        
            int l = getLeft(M), r = getRight(M);

            if(nums[l] > nums[M] && nums[r] > nums[M]){
                pivot = M;
                break;
            }

            if(nums[M] < nums[n - 1])
                R = M - 1;
            else
                L = M + 1;
        }

        return nums[pivot];
    }
};