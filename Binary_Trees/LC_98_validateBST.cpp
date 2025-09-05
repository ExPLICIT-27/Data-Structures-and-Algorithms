/*
check if a given tree is a BST
*/
#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

bool helper(TreeNode *curr_node, long long leftLimit, long long rightLimit){
    if(!curr_node)
        return true;
    if(curr_node->val <= leftLimit || curr_node->val >= rightLimit)
        return false;
    bool left = helper(curr_node->left, leftLimit, min(rightLimit, 1LL*curr_node->val));
    bool right = helper(curr_node->right, max(leftLimit, 1LL*curr_node->val), rightLimit);
    return left && right;
}
bool isValidBST(TreeNode* root) {
    long long leftLimit = LLONG_MIN, rightLimit = LLONG_MAX;
    return helper(root, leftLimit, rightLimit);
}
int main(){
    return 0;
}