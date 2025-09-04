/*
construct a binary tree from inorder and preorder traversal
(given : all the values of the BT are unique, thereby only 1 tree is possible)
logic:
preorder = root->left->right
inorder = left->root->right
preorder[0] is the root
in Inorder everything to the left of the preorder root is the left subtree and to the right is the right subtree
in preorder, root starting position + (number of elements to the right of the root in inorder array) is the left subtree
and further from there to the end is the right subtree
hash the inorder values, use them to find bounds on the indexes 
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
TreeNode *helper(vector<int> &pre, int preSt, int preEn, vector<int> &inorder, int inSt, int inEn, unordered_map<int, int> &inMap){
        if(preSt > preEn || inSt > inEn)
            return NULL;
        TreeNode *root = new TreeNode(pre[preSt]);
        int inRoot = inMap[pre[preSt]];
        int numsToLeft = inRoot - inSt;

        root->left = helper(pre, preSt + 1, preSt + numsToLeft, inorder, inSt, inRoot - 1, inMap);
        root->right = helper(pre, preSt + numsToLeft + 1, preEn, inorder, inRoot + 1, inEn, inMap);
        return root;
}
TreeNode *buildInPre(vector<int> &preorder, vector<int> &inorder){
    unordered_map<int, int> inMap;
    int n = inorder.size();
    
    for(int i = 0; i < n; i++){
        inMap[inorder[i]] = i;
    }
    
    TreeNode *root = helper(preorder, 0, n - 1, inorder, 0, n - 1, inMap);
    return root;

}
int main(){
    return 0;
}