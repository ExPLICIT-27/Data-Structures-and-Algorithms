#include <bits/stdc++.h>

using namespace std;

struct Comparator{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const{
        if(a.second != b.second)
            return a.second > b.second;
        return a.first > b.first;
    }
};
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> mp;
        set<pair<int, int>, Comparator> st;

        vector<int> result;

        for(int i = 0; i < k; i++){
            if(!mp.count(nums[i])){
                st.insert({nums[i], 1});
            }
            else{
                st.erase({nums[i], mp[nums[i]]});
                st.insert({nums[i], mp[nums[i]] + 1});
            }
            mp[nums[i]]++;
        }
        int t = 0;
        int csum = 0;
        for(auto &s : st){
            
            csum += s.first*s.second;
            t++;
            if(t >= x)
                break;
        }
        result.push_back(csum);
        int n = nums.size();
        for(int i = k; i < n; i++){
            st.erase({nums[i - k], mp[nums[i - k]]});
            mp[nums[i - k]]--;
            if(mp[nums[i - k]])
                st.insert({nums[i - k], mp[nums[i - k]]});
            if(!mp.count(nums[i])){
                st.insert({nums[i], 1});
            }
            else{
                st.erase({nums[i], mp[nums[i]]});
                st.insert({nums[i], mp[nums[i]] + 1});
            }
            mp[nums[i]]++;
            t = 0;
            csum = 0;
            for(auto &s : st){
                csum += s.first*s.second;
                t++;
                if(t >= x)
                    break;
            }
            result.push_back(csum);
        }
        return result;
    }
};