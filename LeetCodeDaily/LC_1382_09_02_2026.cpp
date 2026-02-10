#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> I;
    void inorder(TreeNode *node){
        if(!node)
            return;
        inorder(node->left);
        I.push_back(node->val);
        inorder(node->right);
    }
    TreeNode *buildBST(int start, int end){
        if(start > end)
            return NULL;
        int mid = (start + end)/2;
        TreeNode *left = buildBST(start, mid - 1);
        TreeNode *right = buildBST(mid + 1, end);

        TreeNode *root = new TreeNode(I[mid], left, right);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root){
        inorder(root);
        return buildBST(0, I.size() - 1);
    }
};