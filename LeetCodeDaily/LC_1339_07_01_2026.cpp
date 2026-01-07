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
    const int MOD = 1e9 + 7;
    ll tsum = 0, ans = 0;
    ll totalSum(TreeNode *root){
        if(!root)
            return 0;
        
        return 1ll*root->val + totalSum(root->left) + totalSum(root->right);
    }
    ll helper(TreeNode *root){
        if(!root)
            return 0;
        ll lsum = helper(root->left);
        ll rsum = helper(root->right);

        ans = max(ans, (tsum - lsum)*lsum);
        ans = max(ans, (tsum - rsum)*rsum);

        return 1ll*root->val + lsum + rsum;
    }
    int maxProduct(TreeNode* root) {
        tsum = totalSum(root);
        helper(root);
        return ans%MOD;
    }
};