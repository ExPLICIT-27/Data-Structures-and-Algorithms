#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {

        struct Node *temp = head;
        while(temp && temp->next){
            if(temp->data == temp->next->data){
                Node *del = temp->next;
                temp->next = temp->next->next;
                if(temp->next)
                    temp->next->prev = temp;
                delete del;
            }
            else
                temp = temp->next;
        }
        return head;
    }
};