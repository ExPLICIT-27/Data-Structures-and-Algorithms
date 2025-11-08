#include <bits/stdc++.h>

using namespace std;



class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {

        Node *tail = head;
        while(tail->next){
            tail = tail->next;
        }
        vector<pair<int, int>> vec;
        while(head != tail && head->prev != tail){
            int curr = head->data + tail->data;
            if(curr > target){
                tail = tail->prev;
            }
            else if(curr < target){
                head = head->next;
            }
            else{
                vec.push_back({head->data, tail->data});
                head = head->next;
                tail = tail->prev;
            }
        }
        return vec;
    }
};