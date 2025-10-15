/*
added functionalities of word count, and words starting with, delete
*/
#include <bits/stdc++.h> 

using namespace std;

struct Node{
    Node *links[26];
    int ends = 0, precnt = 0;

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
            node->precnt++;
        }
        node->ends++;
    }

    int countWordsEqualTo(string &word){
        Node *node = root;
        for(char &ch : word){
            if(!node->containsKey(ch))
                return 0;
            node = node->get(ch);
        }
        return node->ends;
    }

    int countWordsStartingWith(string &word){
        Node *node = root;
        for(char &ch : word){
            if(!node->containsKey(ch))
                return 0;
            node = node->get(ch);
        }
        return node->precnt;
    }

    void erase(string &word){
        Node *node = root;
        for(char &ch : word){
            if(!node->containsKey(ch))
                return;
            node = node->get(ch);
            node->precnt--;
        }
        node->ends--;
    }
};
