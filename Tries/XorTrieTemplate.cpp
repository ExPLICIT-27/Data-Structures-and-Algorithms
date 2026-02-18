#include <bits/stdc++.h>

using namespace std;


struct Trie{
    Trie *bits[2];
    int passcnt;

    Trie(){
        bits[0] = bits[1] = nullptr;
        passcnt = 0;
    }
    
    bool containsKey(int bit){
        return bits[bit] != NULL;
    }

    void put(int bit, Trie *node){
        bits[bit] = node;
    }
    Trie *get(int bit){
        return bits[bit];
    }

    void deleteNum(Trie *root, int num){
        Trie *node = root;
        
        // first check if it exists, store the path in an array to come back and delete children later if it actually exists
        vector<pair<Trie*, int>> path(32);
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;

            if(!node->containsKey(bit))
                return; // number doesnt exist;
            path[i] = {node, bit};
            node = node->get(bit);
        }

        for(int i = 31; i >= 0; i--){
            Trie *parent = path[i].first;
            int bit = path[i].second;
            Trie *child = parent->get(bit);

            child->passcnt--;

            if(child->passcnt == 0){ // disconnect everything below linked to the same number and return
                delete child;
                parent->bits[bit] = nullptr;
                return;
            }
        }
    }

};

int main(){

    vector<int> N = {1, 3, 4, 5};
    Trie *root = new Trie();
    for(int i : N){
        Trie *node = root;
        for(int j = 31; j >= 0; j--){
            int bit = (i >> j) & 1;
            if(!node->containsKey(bit))
                node->put(bit, new Trie());
            node = node->get(bit);
            node->passcnt++; // inc after passing, the root is a sentinel value, same applies to everythin
        }
    }
    return 0;
}