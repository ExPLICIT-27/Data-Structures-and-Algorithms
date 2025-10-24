/*
Extend the moore's voting algorithm with some constraints for this
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int r1 = 0, r2 = 0;
        int n = nums.size();
        for(int i : nums){
            if(cnt1 == 0 && i != r2)
                cnt1 = 1, r1 = i;
            else if(cnt2 == 0 && i != r1)
                cnt2 = 1, r2 = i;
            else if(i == r1)
                cnt1++;
            else if(i == r2)
                cnt2++;
            else
                cnt1--, cnt2--;
        }

        int c1 = 0, c2 = 0;
        for(int i : nums){
            if(i == r1)
                c1++;
            if(i == r2)
                c2++;
        }
        vector<int> res;
        if(c1 > n/3)
            res.push_back(r1);
        if(c2 > n/3 && r2 != r1)
            res.push_back(r2);
        return res;
    }
};
int main(){
    return 0;
}