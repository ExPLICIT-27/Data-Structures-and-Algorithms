/*
GIven the preorder traversal of a BST, construct and return the original bst
1 Approach 1 : Iteratively insert thro the normal insert function
2 Approach 2 : Create inorder array(sort preorder) and insert using inorder + preorder technique
3 Approach 3 (optimal) : Using one sided bound technique 
    - Initialize bound to INT_MAX
    - as you move left set bound to current root value
    - if it exceeds the bound return null
    - as you move right pass the current bound forward
    - return root
*/
#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

TreeNode *helper(vector<int> &preorder, int &i, int bound){
    if(i == preorder.size() || preorder[i] > bound)
        return NULL;

    TreeNode *root = new TreeNode(preorder[i++]);
    root->left = helper(preorder, i, root->val);
    root->right = helper(preorder, i, bound);

    return root;
}
TreeNode *constructFromPre(vector<int> &preorder){
    int i = 0;
    return helper(preorder, i, INT_MAX);
}
int main(){
    return 0;
}