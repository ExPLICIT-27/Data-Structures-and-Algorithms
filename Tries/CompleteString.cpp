
/*
return the longest word that contains all of its prefixes in the array
i.e 
if the array contains : h, he, hel, hell, hello
then hello is the result as it contains all its prefixes in the array
in case of same length, return the lexicographically smaller word

to check if all its prefixes are present, while traversing the true, 
the flag must be set every time
*/

#include <bits/stdc++.h> 
using namespace std;

struct Node{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    Node *get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, Node *node){
        links[ch - 'a'] = node;
    }
};

class Trie{
    private:
    Node *root;
    
    public:
    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node *node = root;
        for(char &ch : word){
            if(!node->containsKey(ch))
                node->put(ch, new Node());
            node = node->get(ch);
        }
        node->flag = true;
    }
    bool isPresent(string &word){
        Node *node = root;
        for(char &ch : word){
            node = node->get(ch);
            if(!node->flag)
                return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie t = Trie();
    for(auto &str : a){
        t.insert(str);
    }
    string res = "";
    int len = 0;
    for(auto &str : a){
        if(str.length() < len)
            continue;
        if(t.isPresent(str)){
            if(str.length() == res.length()){
                if(str < res)
                    res = str;
            }
            else
                res = str;
            len = res.length();
        }
    }
    return res.empty() ? "None" : res;
}