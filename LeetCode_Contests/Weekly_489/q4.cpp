#include <bits/stdc++.h>

using namespace std;


struct Trie{
    Trie *bits[2];
    int cnt;

    Trie(){
        bits[0] = bits[1] = nullptr;
        cnt = 0;
    }

    bool containsKey(int bit){
        return bits[bit] != nullptr;
    }

    void put(int bit, Trie *node){
        bits[bit] = node;
    }

    Trie *get(int bit){
        return bits[bit];
    }

    void remove(Trie *root, int num){
        Trie *node = root;

        vector<pair<Trie*, int>> path(17);

        for(int i = 16; i >= 0; i--){
            int bit = (num >> i) & 1;

            if(!node->containsKey(bit))
                return;
            path[i] = {node, bit};
            node = node->get(bit);
        }

        for(int i = 16; i >= 0; i--){
            Trie *parent = path[i].first;
            int bit = path[i].second;
            Trie *child = parent->get(bit);

            child->cnt--;

            if(child->cnt == 0){
                delete child;
                parent->bits[bit] = nullptr;
                return;
            }
        }
    }
};

class Solution {
public:
    int maxXor(vector<int>& nums, int k) {
        int n = nums.size();
        Trie *root = new Trie();
        
        multiset<int> ms;
        // will be storing prefix xors in the trie, as for each subarray till r, we 
        // are searching for a subarray 0..l which leads to max xor value
        // for each r, using whatever is present in trie, find which yeilds max xor
        // insert 0 into the trie for single sized subarrays
        
        vector<int> pre(n + 1, 0);
        int l = 0;

        int ans = 0;
        for(int r = 0; r < n; r++){
            pre[r + 1] = nums[r]^pre[r];
            ms.insert(nums[r]);

            Trie *node = root;
            ans = max(ans, nums[r]);
            // insert current prefix into trie
            for(int j = 16; j >= 0; j--){
                int bit = (pre[r] >> j) & 1;
                if(!node->containsKey(bit))
                    node->put(bit, new Trie());
                node = node->get(bit);
                node->cnt++;
            }

            // adjust trie window
            while(*(ms.rbegin()) - *(ms.begin()) > k){
                ms.erase(ms.find(nums[l]));
                root->remove(root, pre[l]);
                l++;
            }
            // find max xor achievable
            int curr = 0;
            node = root;
            for(int j = 16; j >= 0; j--){
                int req = !((pre[r + 1] >> j) & 1);
                
                if(node->containsKey(req)){
                    curr |= (1 << j);
                    node = node->get(req);
                }
                else
                    node = node->get(!req);
            }

            ans = max(ans, curr);
        }


        return ans;
    }
};