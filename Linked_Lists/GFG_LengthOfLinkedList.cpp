#include <bits/stdc++.h>

using namespace std;


class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node *tor = head;
        Node *hare = head;
        bool cycle = false;
        while(hare && hare->next){
            tor = tor->next;
            hare = hare->next->next;
            if(tor == hare){
                cycle = true;
                break;
            }
        }
        if(!cycle)
            return 0;
        Node *t2 = tor;
        int cnt = 0;
        do{
            cnt++;
            t2 = t2->next;
        }while(t2 != tor);
        
        return cnt;
    }
};