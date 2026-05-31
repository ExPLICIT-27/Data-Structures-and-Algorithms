#include <bits/stdc++.h>

using namespace std;


#define ll long long
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        /*
        lazy seg trees do not allow me to maintain frequency counts

        a range query ds that kinda allows it is sqrt decomp 

        basically create root(n) maps after dividing nums2 into blocks of size root(n)
        also maintain a lazy array of size root(n) which tracks the lazy values of the maps
        which are yet to be added to a map in a particular block
        now for range updates, handle the edges (left and right edges which are not complete blocks)
        manually by changing the values in the hashmaps
        for all the complete blocks in between, update the lazy array

        now for query
        query all root(n) maps
        for every num in nums1
            add the count of mpi[tot - num - lazyi]

        ez
        */

        int n = nums2.size();
        int B = ceil(sqrt(n));
        int sz = (n + B - 1)/B;
        vector<unordered_map<ll, int>> maps(sz);
        vector<ll> lazy(sz);

        vector<ll> nums(nums2.begin(), nums2.end());
        // initial freq 
        for(int i = 0; i < n; i++){
            maps[i/B][nums[i]]++;
        }

        vector<int> ans;

        for(auto &q : queries){
            if(q[0] == 1){

                int l = q[1], r = q[2], val = q[3];

                if(r - l + 1 <= B){
                    for(int i = l; i <= r; i++){
                        maps[i/B][nums[i]]--;
                        nums[i] += val;
                        maps[i/B][nums[i]]++;
                    }
                    continue;
                }
                
                
                int L = l/B + 1;

                // left block
                int i;
                for(i = l; i < L*B; i++){
                    maps[L - 1][nums[i]]--;
                    nums[i] += val;
                    maps[L - 1][nums[i]]++;
                }

                int R = (r/B - 1);
                // lazy blocks
                for(i = L; i <= R; i++)
                    lazy[i] += val;
                
                // right blocks
                for(i = B*(r/B); i <= r; i++){
                    maps[R + 1][nums[i]]--;
                    nums[i] += val;
                    maps[R + 1][nums[i]]++;
                }
            }
            else{
                int cnt = 0;
                ll tot = q[1];
                for(int i : nums1){
                    for(int b = 0; b < sz; b++){
                        if(maps[b].count(tot - i - lazy[b]))
                            cnt += maps[b][tot - i - lazy[b]];
                    }
                }
                ans.push_back(cnt);
            }
        }
        
        return ans;
    }
};