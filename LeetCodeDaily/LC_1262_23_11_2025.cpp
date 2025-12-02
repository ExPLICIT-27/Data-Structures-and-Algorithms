#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        pair<int, int> o = {int(1e5), int(1e5)}, t = {int(1e5), int(1e5)};
        int tsum = 0;
        for(int i : nums){
            if(i%3 == 1){
                if(i < o.first){
                    o.second = o.first;
                    o.first = i;
                }
                else if(i < o.second)
                    o.second = i;
            }
            else if(i%3 == 2){
                if(i < t.first){
                    t.second = t.first;
                    t.first = i;
                }
                else if(i < t.second)
                    t.second = i;
            }
            tsum += i;
        }
        if(tsum%3 == 2){
            int tw = tsum, on = tsum;
            if(t.first != int(1e5))
                tw = t.first;
            if(o.first != int(1e5) && o.second != int(1e5))
                on = (o.first + o.second);
            return max(tsum - on, tsum - tw);
        }
        if(tsum%3 == 1){
            int tw = tsum, on = tsum;
            if(o.first != int(1e5))
                tw = o.first;
            if(t.first != int(1e5) && t.second != int(1e5))
                on = t.first + t.second;
            return max(tsum - on, tsum - tw);
        }
        return tsum;
    }
};