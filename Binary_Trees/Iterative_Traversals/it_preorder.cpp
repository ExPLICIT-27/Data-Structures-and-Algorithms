#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int val){
        this->val = val;
        *left = *right = NULL;
    }
};

vector<int> it_preorderfunc(TreeNode *root){
    vector<int> preorder;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
        preorder.push_back(stk.top()->val);
        TreeNode *node = stk.top();
        stk.pop();
        if(node->right != NULL)
            stk.push(node->right);
        
        if(node->left != NULL)
            stk.push(node->left);
    }
}
int main(){
    return 0;
}