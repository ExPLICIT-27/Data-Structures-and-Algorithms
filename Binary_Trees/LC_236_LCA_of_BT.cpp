/*
given 2 nodes find its lowest common ancestor

*/
#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q){
    if(!root || root == p || root == q)
        return root;
    TreeNode *left = lca(root->left, p, q);
    TreeNode *right = lca(root->right, p, q);

    if(left && right)
        return root;
    return left ? left : right;
}
int main(){
    return 0;
}