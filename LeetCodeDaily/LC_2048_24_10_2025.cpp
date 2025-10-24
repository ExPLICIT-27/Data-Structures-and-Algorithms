/*
manually try everything out, n <= 10^6
*/
#include <bits/stdc++.h>

using namespace std;

// 1223333
// 1, 2, 3, 4, 5, 6
class Solution {
public:
    int nextBeautifulNumber(int n) {
        if(n == 0)
            return 1;
        unordered_map<int, vector<int>> mp = {{1, {1}}, {2, {22}}, {3, {122, 333}}, {4, {1333, 4444}}, 
        {5, {14444, 22333, 55555}}, {6, {122333, 224444, 155555, 666666}}, {7, {1224444}}};

        int digits = int(log10(n)) + 1;
        if(digits == 7)
            return mp[7][0];
        
        vector<int> nums;
        for(auto &pair : mp){
            if(pair.first == 7){
                nums.push_back(pair.second[0]);
                continue;
            }
            for(int i : pair.second){
                string str = to_string(i);
                do{
                    nums.push_back(stoi(str));
                }while(next_permutation(str.begin(), str.end()));
            }
        }
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] > n)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return nums[l];

    }
};
int main(){
    return 0;
}