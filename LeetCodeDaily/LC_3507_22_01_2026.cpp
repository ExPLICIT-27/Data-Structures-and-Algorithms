#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSorted(vector<int> &A){
        for(int i = 1; i < A.size(); i++){
            if(A[i] < A[i - 1])
                return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        if(isSorted(nums))
            return 0;
        vector<int> A = nums;
        int ops = 0;
        while(!isSorted(A)){
            int mnsum = INT_MAX;
            for(int i = 1; i < A.size(); i++){
                mnsum = min(mnsum, A[i] + A[i - 1]);
            }
            int i;
            for(i = 1; i < A.size(); i++){
                if(A[i] + A[i - 1] == mnsum){
                    A[i - 1] = mnsum;
                    break;
                }
            }
            for(; i < A.size() - 1; i++)
                A[i] = A[i + 1];
            A.pop_back();
            ops++;
        }
        return ops;
    }
};