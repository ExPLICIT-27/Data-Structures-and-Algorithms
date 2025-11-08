#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        int n = 0;
        while(temp){
            temp = temp->next;
            n++;
        }
        temp = head;
        ListNode *prevHead = nullptr;
        ListNode *res = nullptr;
        for(int i = 0; i + k <= n; i += k){
            int t = k - 1;
            ListNode *first = temp;
            ListNode *prev = temp;
            temp = temp->next;
            while(t--){
                ListNode *nxt = temp->next;
                temp->next = prev;
                prev = temp;
                temp = nxt;
            }
            if(prevHead){
                prevHead->next = prev;
            }
            prevHead = first;
            if(!res)
                res = prev;
        }
        if(prevHead) prevHead->next = temp;
        return res;
    }
};