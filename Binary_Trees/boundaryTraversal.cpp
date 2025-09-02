/*
Traverse the boundary of the binary tree
take left nodes, leaf nodes and right nodes (reverse and insert them)
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int val){
        this->val = val;
        left = right = NULL;
    }
};
void findLeftSide(TreeNode *node, vector<int> &result){
    if(!node || node->left == NULL && node->right == NULL)
        return;
    result.push_back(node->val);
    if(node->left)
        findLeftSide(node->left, result);
    else if(node->right)
        findLeftSide(node->right, result);
}
void findLeaves(TreeNode *node, vector<int> &result){
    if(!node)
        return;
    if(node->left == NULL && node->right == NULL){
        result.push_back(node->val);
        return;
    }
    findLeaves(node->left, result);
    findLeaves(node->right, result);
}
void findRightSide(TreeNode *node, vector<int> &result){
    if(!node || node->left == NULL && node->right == NULL)
        return;
    if(node->right)
        findRightSide(node->right, result);
    else if(node->left)
        findRightSide(node->left, result);
    result.push_back(node->val);
}
vector<int> BoundaryTraversal(TreeNode *root){
    if(!root)
        return {};
    vector<int> result;
    result.push_back(root->val);
    findLeftSide(root->left, result);
    findLeaves(root, result);
    findRightSide(root->right, result);
    return result;
}
int main(){
    return 0;
}