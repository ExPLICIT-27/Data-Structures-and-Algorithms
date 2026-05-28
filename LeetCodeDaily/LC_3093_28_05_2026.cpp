#include <bits/stdc++.h>


using namespace std;

struct Node{
    Node *links[26] = {NULL};

    int length = INT_MAX, index = -1; // length, index (smaller, lesser)
    bool contains(char c){
        return links[c - 'a'] != NULL;
    }

    Node *get(char c){
        return links[c - 'a'];
    }

    void put(char c){
        links[c - 'a'] = new Node();
    }
};

class Trie{
    public:
    Node *root;
    int threshold;
    Trie(vector<string> &wq){
        root = new Node();
        //only threshold can stop stupid MLE
        threshold = 0;
        for(auto &s : wq)
            threshold = max(threshold, (int)s.size()); 
    }

    void insert(string &s, int index){
        int len = s.size();

        Node *curr = root;
        if(curr->length > len){
            curr->length = len;
            curr->index = index;
        }

        for(int i = len - 1; i >= 0; i--){
            char c = s[i];
            if(len - i > threshold + 1)
                break;
            if(!curr->contains(c))
                curr->put(c);
            curr = curr->get(c);

            if(curr->length > len){
                curr->length = len;
                curr->index = index;
            }
        }
    }

    int LSI(string &s){
        Node *curr = root;

        int n = s.size();

        for(int i = n - 1; i >= 0; i--){
            if(!curr->contains(s[i]))
                return curr->index;
            curr = curr->get(s[i]);
        }

        return curr->index;
    }

    // destructor reduces memory as well
    ~Trie(){}
};
class Solution {
public:
    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {
        /*
        first priority => longest suffix
        then smaller string size 
        then earlier index

        modified Trie is what i would need to efficiently solve this

        what information should i store at each node of the trie other than the links
        after i put the string in, i need to go back and put its length in as well
        just store length, index
        */

        Trie tr = Trie(wq);

        int m = wc.size();

        for(int i = 0; i < m; i++)
            tr.insert(wc[i], i);

        int n = wq.size();
        vector<int> ans(n);


        for(int i = 0; i < n; i++)
            ans[i] = tr.LSI(wq[i]);

        
        return ans;

    }
};