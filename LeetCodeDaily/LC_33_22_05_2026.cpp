#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // find the pivot point

        int n = nums.size();
        if(n == 1){
            if(target == nums[0])
                return 0;
            return -1;
        }

        auto getNext = [&](int i) -> int {
            if(i == n - 1)
                return 0;
            
            return i + 1;
        };

        auto getPrev = [&](int i) -> int {
            if(i == 0)
                return n - 1;
            return i - 1;
        };


        int L = 0, R = n - 1;

        int pivot = -1;
        while(L <= R){
            int M = L + (R - L)/2;

            int pr = getPrev(M), nx = getNext(M);

            if(nums[M] < nums[pr] && nums[M] < nums[nx]){
                pivot = M;
                break;
            }

            if(nums[M] < nums[n - 1])
                R = M - 1;
            else
                L = M + 1;
        }


        auto BS = [&](int L, int R) -> int {
            
            while(L <= R){
                int M = L + (R - L)/2;

                if(nums[M] == target)
                    return M;
                
                if(nums[M] < target)
                    L = M + 1;
                else
                    R = M - 1;
            }

            return -1;
        };

        int left = BS(0, pivot - 1), right = BS(pivot, n - 1);

        return (left == -1)? ((right == -1)? -1 : right ) : left;
    }
};