/*
the idea is exactly as expected, try to find a number whose bit is the opposite of the current numbers bit
Traverse from msb to lsb because msb makes a bigger impact
*/
#include <bits/stdc++.h>

using namespace std;


struct Trie{
    Trie *bits[2];
    bool containsKey(int bit){
        return bits[bit] != NULL;
    }
    void put(int bit, Trie *node){
        bits[bit] = node;
    }
    Trie *get(int bit){
        return bits[bit];
    }
};

int findMaximumXOR(vector<int>& nums) {
    Trie *root = new Trie();
    for(int & i : nums){
        Trie *node = root;
        for(int j = 31; j >= 0; j--){
            if(!node->containsKey(((i >> j) & 1))){
                node->put(((i >> j) & 1), new Trie());
            }
            node = node->get(((i >> j) & 1));
        }
    }
    int result = 0;
    for(int & i : nums){
        Trie *node = root;
        int val = 0;
        for(int j = 31; j >= 0; j--){
            int bit = !((i >> j) & 1);
            if(node->containsKey(bit)){
                val += bit*(1 << j);
                node = node->get(bit);
            }
            else{
                val += (!bit)*(1 << j);
                node = node->get(!bit);
            }
        }
        result = max(result, i^val);
    }
    return result;
}

int main(){
    return 0;
}