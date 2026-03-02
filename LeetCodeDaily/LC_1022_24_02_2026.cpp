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
#define ll long long
class Solution {
public:
    ll ans = 0;
    void helper(TreeNode *node, ll total) {
        if(node->val == 1)
            total |= 1; 
        if(node->left == nullptr && node->right == nullptr){
            ans += total;
            return;
        }
        if(node->left)
            helper(node->left, total << 1);
        if(node->right)
            helper(node->right, total << 1);
    }
    int sumRootToLeaf(TreeNode* root) {
        helper(root, 0ll);
        return ans;
    }
};