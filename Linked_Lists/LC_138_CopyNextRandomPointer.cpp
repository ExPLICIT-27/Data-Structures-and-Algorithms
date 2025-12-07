#include <bits/stdc++.h>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


// Brute force O(n^2)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *dummy = new Node(-1);
        Node *curr = dummy;
        Node *temp = head;
        while(temp){
            curr->next = new Node(temp->val);
            curr = curr->next;
            temp = temp->next;
        }
        temp = head;
        unordered_map<int, Node*> mp;
        int i = 0;
        while(temp){
            mp[i++] = temp->random;
            temp = temp->next;
        }
        unordered_map<int, int> mp2;
        for(auto &[x, y] : mp){
            if(!y)
                continue;
            temp = head;
            i = 0;
            while(temp && temp != y){
                temp = temp->next;
                i++;
            }
            mp2[x] = i;
        }
        
        temp = dummy->next;
        i = 0;
        while(temp){
            if(!mp2.count(i)){
                i++;
                temp = temp->next;
                continue;
            }
            Node *t2 = dummy->next;
            int cnt = mp2[i];
            while(cnt--)
                t2 = t2->next;
            temp->random = t2;
            temp = temp->next;
            i++;
        }
        return dummy->next;
    }
};

// optimal easy soln : make a copy of all the nodes and start connecting

class Optimal {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        mp[NULL] = NULL;
        Node *tmp = head;

        while(tmp){
            mp[tmp] = new Node(tmp->val);
            tmp = tmp->next;
        } 
        Node *dummy = new Node(-1);
        Node *res = mp[head];
        dummy->next = res;

        while(head){
            res->next = mp[head->next];
            res->random = mp[head->random];
            res = res->next;
            head = head->next;
        }

        return dummy->next;
    }
};