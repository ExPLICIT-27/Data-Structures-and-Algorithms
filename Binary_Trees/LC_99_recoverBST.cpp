/*
Given a BST with 2 nodes swapped, recover the BST without modifying original structure
*/
#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;
TreeNode *first = NULL, *second = NULL;
TreeNode *prevNode = new TreeNode(INT_MIN);
void recoverHelper(TreeNode *root){
    if(!root)
        return;
    recoverHelper(root->left);
    if(prevNode->val > root->val){
        if(!first){
            first = prevNode, second = root;
        }
        else
            second = root;
    }
    prevNode = root;
    recoverHelper(root->right);
}
void RecoverTree(TreeNode *root){
    recoverHelper(root);
    swap(first->val, second->val);
}
int main(){
    return 0;
}