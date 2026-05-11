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

    void put(char ch){
        links[ch - 'a'] = new Node();
    }

    void setEnd(){
        flag = true;
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
            Node *curr = root;
            for(char c : word){
                if(!curr->containsKey(c))
                    curr->put(c);
                curr = curr->get(c);
            }
            curr->setEnd();
        }

        bool dfs_helper(string &word, int i, Node *curr, int edits){
            if(edits > 2)
                return false;
            if(i == word.size())
                return curr->flag;
            

            for(char c = 'a'; c <= 'z'; c++){
                if(curr->containsKey(c)){
                    if(word[i] == c){
                        if(dfs_helper(word, i + 1, curr->get(c), edits))
                            return true;
                    }
                    else{
                        if(dfs_helper(word, i + 1, curr->get(c), edits + 1))
                            return true;
                    }
                }
            }

            return false;
        }
        
        bool dfs(string &word){
            Node *curr = root;
            return dfs_helper(word, 0, curr, 0);
        }
};
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        Trie tr = Trie();

        for(auto &s : dictionary)
            tr.insert(s);
        
        vector<string> ans;
        for(auto &s : queries){
            if(tr.dfs(s))
                ans.push_back(s);
        }

        return ans;
    }
};