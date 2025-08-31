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
// only the function for iterative inorder
vector<int> iterative_inorder(TreeNode *root){
    vector<int> inorder;
    stack<TreeNode*> stk;
    TreeNode *node = root;
    // inorder = left, root, right
    // as long as node is not null, i insert node to stack and move left
    // when it becomes null, if the stack is empty return
    // if not, then pop the top, print its value, and move to the right leaf
    while(true){
        if(node != NULL){
            stk.push(node);
            node = node->left;
        }
        else{
            if(stk.empty())
                break;
            node = stk.top();
            stk.pop();
            inorder.push_back(node->val);
            node = node->right;
        }
    }
    return inorder;
}
int main(){
    return 0;
}