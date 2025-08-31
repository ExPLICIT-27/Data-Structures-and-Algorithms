/*
Preorder, inorder and postorder in a single traversal

Rules 
Single stack with datatype Node, number

if number == 1
    insert into preorder arr, inc number
    if the node has left, push the left node
if number == 2
    insert into inorder arr, inc number
    if the node has right, push the right node
if number == 3
    pop and push into postorder 
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
vector<vector<int>> PreInPost(TreeNode *root){
    stack<pair<TreeNode *, int>> stk;
    vector<int> pre, in, post;
    stk.push({root, 1});
    while(!stk.empty()){
        auto it = stk.top();
        stk.pop();
        if(it.second == 1){
            pre.push_back(it.first->val);
            it.second++;
            stk.push(it);
            if(it.first->left)
                stk.push({it.first->left, 1});
        }
        else if(it.second == 2){
            in.push_back(it.first->val);
            it.second++;
            stk.push(it);
            if(it.first->right)
                stk.push({it.first->right, 1});
        }
        else{
            post.push_back(it.first->val);
        }

    }
    return {pre, in, post};
}
int main(){
    return 0;
}