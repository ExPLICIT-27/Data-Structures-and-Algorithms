#include <bits/stdc++.h>

using namespace std;

struct Node{
    
    Node *links[10] = {NULL};

    void put(char c){
        links[c - '0'] = new Node();
    }
    
    bool contains(char c){
        return links[c - '0'] != NULL;
    }

    Node* get(char c){
        return links[c - '0'];
    }

    
};

class Trie{
    public:
    Node *root;
    Trie(){
        root = new Node();
    }

    void insert(string &s){
        Node *curr = root;
        for(char c : s){
            if(!curr->contains(c))
                curr->put(c); 
            curr = curr->get(c);
        }
    }

    int maxPrefix(string &s){
        Node *curr = root;
        int cnt = 0;

        for(char c : s){
            if(!curr->contains(c))
                return cnt;
            curr = curr->get(c);
            cnt++;
        }
        
        return cnt;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        if(arr1.size() > arr2.size())
            swap(arr1, arr2);

        Trie tr = Trie();

        for(int i : arr1){
            string s = to_string(i);
            tr.insert(s);
        }
        
        int ans = 0;
        for(int i : arr2){
            string s = to_string(i);
            ans = max(ans, tr.maxPrefix(s));
        }

        return ans;
        
        

    }
};