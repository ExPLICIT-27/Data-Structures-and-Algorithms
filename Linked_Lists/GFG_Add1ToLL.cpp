
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};



class Solution {
  public:
    Node* addOne(Node* head) {
    
        Node *tmp = head;
        Node *prev = NULL;
        while(tmp){
            Node *nxt = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = nxt;
        }
        int carry = 1;
        Node *t2 = prev;
        Node *prev2 = prev;
        while(prev){
            int sm = prev->data + carry;
            prev->data = (prev->data + carry)%10;
            carry = sm/10;
            prev2 = prev;
            prev = prev->next;
        }
        if(carry){
            prev2->next = new Node(carry);
            prev2 = prev2->next;
        }
        Node *res = NULL;
        while(t2){
            Node *nxt = t2->next;
            t2->next = res;
            res = t2;
            t2 = nxt;
        }
        return res;
        
    }
};