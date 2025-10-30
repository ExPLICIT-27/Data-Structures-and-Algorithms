#include <bits/stdc++.h>

using namespace std;


class Node {
public:
int data;
Node* next;

Node(int x) {
    data = x;
    next = nullptr;
}
};

class SolutionNaive {
  public:
    Node* segregate(Node* head) {
        int zc = 0, oc = 0, tc = 0;
        Node *tmp = head;
        
        while(tmp){
            if(tmp->data == 0)
                zc++;
            else if(tmp->data == 1)
                oc++;
            else
                tc++;
            tmp = tmp->next;
        }
        tmp = head;
        while(zc--){
            tmp->data = 0;
            tmp = tmp->next;
        }
        while(oc--){
            tmp->data = 1;
            tmp = tmp->next;
        }
        while(tc--){
            tmp->data = 2;
            tmp = tmp->next;
        }
        return head;
    }
};

/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class SolutionOnePass {
  public:
    Node* segregate(Node* head) {
        Node *z = new Node(-1);
        Node *o = new Node(-1);
        Node *t = new Node(-1);
        Node *t1 = z, *t2 = o, *t3 = t;
        Node *tmp = head;
        while(tmp){
            if(tmp->data == 0){
                t1->next = new Node(0);
                t1 = t1->next;
            }
            else if(tmp->data == 1){
                t2->next = new Node(1);
                t2 = t2->next;
            }
            else{
                t3->next = new Node(2);
                t3 = t3->next;
            }
            tmp = tmp->next;
        }
        
        t1->next = (t2->data == -1)? t->next : o->next;
        t2->next = (t3->data == -1)? NULL : t->next;
        return z->next;
        
    }
};