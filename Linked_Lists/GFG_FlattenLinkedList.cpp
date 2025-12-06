#include <bits/stdc++.h>

using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};


class Solution {
  public:
    Node *merge2(Node *r1, Node *r2){
        Node *dummy = new Node(-1);
        Node *res = dummy;
        while(r1 && r2){
            if(r1->data < r2->data){
                res->bottom = r1;
                r1 = r1->bottom;
            }
            else{
                res->bottom = r2;
                r2 = r2->bottom;
            }
            res = res->bottom;
            res->next = NULL;
        }
        res->bottom = r1? r1 : r2;
        return dummy->bottom;
    }
    Node *MainMerge(Node *head){
        if(head == NULL || head->next == NULL)
            return head;
        Node *merged = MainMerge(head->next);
        return merge2(head, merged);
    }
    Node *flatten(Node *root) {
        return MainMerge(root);
    }
};