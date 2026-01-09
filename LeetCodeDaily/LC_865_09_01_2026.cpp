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
    int findDepth(TreeNode *root){
        if(!root)
            return 0;
        
        return 1 + max(findDepth(root->left), findDepth(root->right));
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int left = findDepth(root->left);
        int right = findDepth(root->right);

        if(left == right)
            return root;
        
        if(left > right)
            return subtreeWithAllDeepest(root->left);
        return subtreeWithAllDeepest(root->right);
    }
};