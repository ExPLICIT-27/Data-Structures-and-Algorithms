/*
Given inorder and postorder traversals of a unique binary tree
reconstruct the binary tree
 */
#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

unordered_map<int, int> inMap;
TreeNode *helper(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd){
    if(postStart > postEnd || inStart > inEnd)
        return NULL;
    TreeNode *root = new TreeNode(postorder[postEnd]);
    int inRoot = inMap[root->val];
    int numsToLeft = inRoot - inStart;

    root->left = helper(postorder, postStart, postStart + numsToLeft - 1, inorder, inStart, inRoot - 1);
    root->right = helper(postorder, postStart + numsToLeft, postEnd - 1, inorder, inRoot + 1, inEnd);

    return root;

}
TreeNode *buildInPost(vector<int> &inorder, vector<int> &postorder){
    for(int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i;
    TreeNode *root = helper(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);

    return root;
}
int main(){
    return 0;
}