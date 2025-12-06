#include <bits/stdc++.h>

using namespace std;


// O(N*K) solution
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode *merge2(ListNode *h1, ListNode *h2){
        ListNode *dummy = new ListNode(-1);
        ListNode *res = dummy;

        while(h1 && h2){
            if(h1->val < h2->val){
                res->next = h1;
                h1 = h1->next;
            }
            else{
                res->next = h2;
                h2 = h2->next;
            }
            res = res->next;
        }
        res->next = h1 ? h1 : h2;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *merged = NULL;
        for(int i = 0; i < lists.size(); i++){
            merged = merge2(merged, lists[i]);
        }
        return merged;
    }
};

// optimal nlog(k) solution, using a priority queue, and inserting 1 by 1

class Optimal {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> pq;
        int n = lists.size();
        for(int i = 0; i < n; i++){
            if(lists[i])
                pq.push({lists[i]->val, lists[i]});
        }
        ListNode *ans = new ListNode(-1);
        ListNode *curr = ans;
        while(!pq.empty()){
            auto [x, y] = pq.top();
            pq.pop();
            curr->next = y;
            if(y->next){
                y = y->next;
                pq.push({y->val, y});
            }
            curr = curr->next;
        }
        return ans->next;
    }
};