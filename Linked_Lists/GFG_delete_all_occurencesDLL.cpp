#include <bits/stdc++.h>

using namespace std;


struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
};

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {

        while((*head_ref) && (*head_ref)->data == x){
            struct Node *del = *head_ref;
            (*head_ref) = (*head_ref)->next;
            if(*head_ref)
                (*head_ref)->prev = nullptr;
            delete del;
        }
        struct Node *temp = *head_ref;
        while(temp && temp->next){
            if(temp->next->data == x){
                struct Node *del = temp->next;
                temp->next = temp->next->next;
                delete del;
                if(temp->next)// you alr shifted temp->next to temp->next->next
                    temp->next->prev = temp;
            }
            else
                temp = temp->next;
        }
        
    }
};