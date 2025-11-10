#include <bits/stdc++.h>

using namespace std;

// first solution i made, this is slower
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        vector<int> nse(n);
        vector<int> stk;

        for(int i = n - 1; i >= 0; i--){
            while(!stk.empty() && nums[stk.back()] >= nums[i])
                stk.pop_back();
            
            nse[i] = stk.empty() ? n : stk.back();
            stk.push_back(i);
        }

        unordered_map<int, int> lastUpdate;

        int result = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                continue;
            if(!lastUpdate.count(nums[i])){
                lastUpdate[nums[i]] = nse[i];
                result++;
            }
            else{
                if(lastUpdate[nums[i]] >= i)
                    continue;
                else{
                    lastUpdate[nums[i]] = nse[i];
                    result++;
                }
            }
        }
        return result;

    }
};

// faster solution
class Solution2 {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        stack<int> stk;

        int res = 0;
        for(int i = 0; i < n; i++){
            while(!stk.empty() && stk.top() > nums[i])
                stk.pop();
            if(nums[i] == 0)
                continue;
            if(stk.empty() || stk.top() < nums[i]){
                res++;
                stk.push(nums[i]);
            }
        }
        return res;

    }
};