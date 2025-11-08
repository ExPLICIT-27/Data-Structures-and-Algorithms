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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || !head)
            return head;
        ListNode *tmp = head;
        int n = 0;
        while(tmp){
            n++;
            tmp = tmp->next;
        }
        if(k%n == 0)
            return head;
        tmp = head;
        ListNode *prev = nullptr;
        while(tmp){
            ListNode *nxt = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = nxt;
        }
        ListNode *first = prev;
        tmp = prev;
        prev = nullptr;
        k %= n;
        for(int i = 0; i < k; i++){
            ListNode *nxt = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = nxt;
        }
        ListNode *res = prev;
        prev = nullptr;
        while(tmp){
            ListNode *nxt = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = nxt;
        }
        first->next = prev;
        return res;
        
    }
};