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
        if(!head || !k)
            return head;
        int n = 0;
        ListNode *tmp = head;
        while(tmp){
            n++;
            tmp = tmp->next;
        }
        k %= n;

        if(n - k == 0 || k == 0)
            return head;
        
        tmp = head;
        ListNode *prev = tmp;
        for(int i = 0; i < n - k; i++){
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = NULL;

        ListNode *ans = tmp;
        while(tmp != NULL && tmp->next != NULL)
            tmp = tmp->next;
        
        tmp->next = head;

        return ans;
    }
};