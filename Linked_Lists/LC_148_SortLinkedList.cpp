// naive soln => take it into an array sort it reinsert
// optimal => merge sort

#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class SolutionNaive {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> tmp;
        ListNode *ll = head;
        while(ll){
            tmp.push_back(ll->val);
            ll = ll->next;
        }
        sort(tmp.begin(), tmp.end());
        ll = head;
        for(int i : tmp){
            ll->val = i;
            ll = ll->next;
        }
        return head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class SolutionOptimal {
public:
    ListNode *merge(ListNode *a, ListNode *b){
        if(!a)
            return b;
        if(!b)
            return a;
        
        ListNode *head = NULL;
        if(a->val < b->val){
            head = a;
            a = a->next;
        }
        else{
            head = b;
            b = b->next;
        }
        ListNode *curr = head;

        while(a && b){
            if(a->val < b->val){
                curr->next = a;
                a = a->next;
            }
            else{
                curr->next = b;
                b = b->next;
            }
            curr = curr->next;
        }
        curr->next = (a)? a : b;
        return head;
    }
    ListNode *mergesort(ListNode *head){
        if(!head || !head->next)
            return head;

        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = NULL;

        ListNode *left = mergesort(head);
        ListNode *right = mergesort(mid);
        return merge(left, right);
        
    }
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};