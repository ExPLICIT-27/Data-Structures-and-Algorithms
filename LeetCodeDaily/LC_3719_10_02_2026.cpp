#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        for(int i = 0; i < n; i++){
            unordered_set<int> S;
            int cnt = 0;
            for(int j = i; j < n; j++){
                if(nums[j] & 1){
                    if(!S.count(nums[j]))
                        cnt++;
                }
                else{
                    if(!S.count(nums[j]))
                        cnt--;
                }
                S.insert(nums[j]);

                if(cnt == 0)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};