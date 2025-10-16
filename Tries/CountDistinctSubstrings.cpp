/*
Can be implemented using a set,
TC = O(N^2Log(N))
SC = O(N^3) nearly

with tries
TC = O(N^2)
SC = depends on the input
*/
#include <bits/stdc++.h>

using namespace std;

struct Trie{
    Trie *links[26];

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    Trie *get(char ch){
        return links[ch - 'a'];
    }

    void insert(char ch){
        links[ch - 'a'] = new Trie();
    }
};

int countDistinctSubstrings(string &s)
{
    Trie *root = new Trie();
    int n = s.length();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        Trie *node = root;
        for(int j = i; j < n; j++){
            if(!node->containsKey(s[j])){
                node->insert(s[j]);
                cnt++;
            }
            node = node->get(s[j]);
        }
    }
    return cnt + 1;
}
int main(){
    return 0;
}