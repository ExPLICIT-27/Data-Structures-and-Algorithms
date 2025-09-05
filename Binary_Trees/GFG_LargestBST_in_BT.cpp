/*
given a binary tree, find the largest BST in it
checking of current is with the:
current node's data and left.maxval not minval
similarly, current node's data and right.minval not maxval
*/
#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

class Node{
    public: 
        int minval, maxval, maxsize;
        Node(int minval, int maxval, int maxsize){
            this->minval = minval;
            this->maxval = maxval;
            this->maxsize = maxsize;
        }
};
Node helper(TreeNode *node){
    if(!node)
        return {INT_MAX, INT_MIN, 0};
    auto left = helper(node->left);
    auto right = helper(node->right);

    if(node->val > left.maxval && node->val < right.minval){
        return {min(node->val, left.minval), max(node->val, right.maxval), left.maxsize + right.maxsize + 1};
    }
    return {INT_MIN, INT_MAX, max(right.maxsize, left.maxsize)};
}
int findLargestBST(TreeNode *node){

}
int main(){
    return 0;
}