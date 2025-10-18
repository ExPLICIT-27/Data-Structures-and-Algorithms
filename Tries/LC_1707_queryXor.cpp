/*
Offline query + Trie Logic
*/
#include <bits/stdc++.h>

using namespace std;


// Trie blueprint
struct Trie{
    Trie *links[2] = {nullptr, nullptr};

    bool containsKey(int bit){
        return links[bit] != nullptr;
    }

    void put(int bit){
        links[bit] = new Trie();
    }

    Trie *get(int bit){
        return links[bit];
    }
};

vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
    // offline query setup
    
    sort(nums.begin(), nums.end());

    int n = q.size();
    for(int i = 0; i < n; i++){
        q[i].push_back(i);
    }

    sort(q.begin(), q.end(), [](const vector<int> &a, const vector<int> &b){
        return a[1] < b[1];
    });

    // begin processing

    Trie *root = new Trie();
    vector<int> res(n);
    int idx = 0;

    for(auto &qi : q){
        int x = qi[0], m = qi[1], i = qi[2];

    // insert elements only till each query mi
        while(idx < nums.size() && nums[idx] <= m){
            Trie *node = root;
            for(int j = 31; j >= 0; j--){
                int bit = ((nums[idx] >> j) & 1);
                if(!node->containsKey(bit))
                    node->put(bit);
                node = node->get(bit);
            }
            idx++;
        }

        if(!idx){
            res[i] = -1;
            continue;
        }

        Trie *node = root;
        int curr = 0;
        for(int j = 31; j >= 0; j--){
            int bit = ((x >> j) & 1);;
            if(node->containsKey(1 - bit)){
                curr |= (1 << j);
                node = node->get(1 - bit);
            }
            else if(node->containsKey(bit))
                node = node->get(bit);
            else
                break;
        }
        // insert at correct index
        res[i] = curr;
    }
    return res;

}

int main(){
    return 0;
}