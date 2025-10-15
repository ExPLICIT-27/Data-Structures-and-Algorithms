#include <bits/stdc++.h>

using namespace std;

struct Node{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node *node){
        links[ch - 'a'] = node;
    }

    Node *get(char ch){
        return links[ch - 'a'];
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

        }
        void insert(string word){
            Node *node = root;
            for(char ch : word){
                if(!node->containsKey(ch)){
                    node->put(ch, new Node);
                }
                node = node->get(ch);
            }
            node->setEnd();
        }
        bool search(string word){
            Node *node = root;
            for(char ch : word){
                if(!node->containsKey(ch))
                    return false;
                node = node->get(ch);
            }
            return node->flag;
        }
        bool startsWith(string word){
            Node *node = root;
            for(char ch : word){
                if(!node->containsKey(ch))
                    return false;
                node = node->get(ch);
            }
            return true;
        }
};
int main(){
    return 0;
}
